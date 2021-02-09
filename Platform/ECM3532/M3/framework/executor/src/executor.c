#include "config.h"
#include "executor_public.h"
#include "executor_config.h"
#include "executor_private.h"
#include "executor_trace.h"
#include "executor_common.h"
#include "executor_op.h"
#include "shmem.h"
#include "module_common.h"
#include "workQ_common.h"
#include "rpc.h"
#include "semphr.h"
#include "task.h"
#include <stdbool.h>
#define CONFIG_TASK_NOTIFY
#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
#define DIV_ROUND_DOWN (n,d) ((n)/ (d))

#define DYNAMIC_MAPPING

#ifdef EXEC_DBG
#define NAME(X)      #X
#define ARRAY_DUMP8(X)   {  dumpArray8( NAME(X) , (X),sizeof(X));}
#define ARRAY_DUMP16(X)   {  dumpArray16( NAME(X) , (X),sizeof(X));}

#define PTR_DUMP8(X,N)   {  dumpArray8( NAME(X) , (X),N);}
#define PTR_DUMP16(X,N)   {  dumpArray16( NAME(X) , (X),N);}
#endif
#ifdef CONFIG_TASK_NOTIFY
static TaskHandle_t xTaskToNotify = NULL;
#endif
ExecWork_t schedList[CONFIG_EXEC_MAX_SCHEDULED_WORK] ={0};
SemaphoreHandle_t schedListMutex = NULL;
SemaphoreHandle_t execDspRespSem =NULL;
QueueHandle_t executor_m3Q = NULL;
QueueHandle_t executor_dspQ = NULL;


static void ExecCompleteWork (uint8_t execWorkID);
static void HandleInputBufPostCompletion (ExecOperand_t * inbuf) ;
static void HandleOutputBufPostCompletion (ExecOperand_t * outBuf) ;
static void ExecFree(void * bufAddr,uint8_t memType);
static  void *  ExecAlloc (uint32_t size, uint8_t memType);
static void    DestroyBuf (ExecOperand_t * buf) ;
static void ExecM3Task(void *pvParameters);
static void ExecDspTask(void *pvParameters);

static int execDspNotifyResponse(uint32_t header, uint32_t data);
static int execDspNotifyEvent(uint32_t header, uint32_t data);
static int   execDspRpcInit( void);
#ifdef CONFIG_OP_DSP_CHW_2X2_CONV2D_RELU_AVGPOOL_Q7
static ExecStatus eta_conv2d_q7_CHW_ker2x2_stride1_pad0_relu_avgPool_2x2_stride2_pad0(const q7_t * inArray,  const q7_t *  wt, const q7_t * bias,  q7_t *  outArray,  q7_t *  buffIn,  const conv2d_relu_avgpool_opt opt);
#endif
#ifdef  CONFIG_OP_DSP_CHW_3X3_CONV2D_RELU_AVGPOOL_Q7
static ExecStatus eta_conv2d_q7_CHW_ker3x3_stride1_pad0_relu_avgPool_2x2_stride2_pad0(const q7_t * inArray,  const q7_t *  wt, const q7_t * bias,  q7_t *  outArray,  q7_t *  buffIn,  const conv2d_relu_avgpool_opt opt);
#endif
static  ExecStatus eta_pw_conv2d_q7_hwc_dsp( const q7_t *  inArray,  const q7_t *  wt, const q7_t * bias,  q7_t *  outArray,  q7_t *  buffIn,   conv2d_opt opt, int8_t fast);
static ExecStatus  eta_conv2d_q7_chw_relu_dsp (const q7_t * inArray,  const q7_t *  wt, const q7_t * bias,  q7_t *  outArray,  q7_t *  buffIn,  conv2d_opt opt, uint8_t opID, uint8_t depthwise);
#ifdef EXEC_DBG
void dumpToStdout ( char * arrayname, ExecOperand_t * array )
{
    int8_t * ptr ;
    int size ;
    ptr = ExecGetBufAddr(array);
    size = array-> numElements;
 int index = 0;
ecm35xx_printf (" \r\n const q7_t %s[%d] ={", arrayname, size);
for ( index = 0 ; index < size; index ++){
         if ( index == size -1)
             ecm35xx_printf("%d", ptr [index]);
         else
            ecm35xx_printf("%d,", ptr [index]);
     }
     ecm35xx_printf("};");
}

void dumpArray8 ( char * arrayname,  int8_t * ptr , unsigned int size)
{
 int index = 0;
ecm35xx_printf (" \r\n const q7_t %s[%d] ={", arrayname, size);
for ( index = 0 ; index < size; index ++){
         if ( index == size -1)
             ecm35xx_printf("%d", ptr [index]);
         else
            ecm35xx_printf("%d,", ptr [index]);
     }
     ecm35xx_printf("};");

}

void dumpArray16 ( char * arrayname,  int16_t * ptr , unsigned int size)
{
 int index = 0;
ecm35xx_printf (" \r\n const int16_t %s[%d] ={", arrayname, size);
for ( index = 0 ; index < size; index ++){
         if ( index == size -1)
             ecm35xx_printf("%d", ptr [index]);
         else
            ecm35xx_printf("%d,", ptr [index]);
     }
     ecm35xx_printf("};");

}
#endif
static void __attribute__((optimize("O3")))
ExecCompleteWork (uint8_t execWorkID)
{
	uint8_t index = 0;
	ExecWork_t * work =  & (schedList[execWorkID]);
	uint8_t memType = OPD_MEM_TYPE_M3_LOCAL;
	xSemaphoreTake (schedListMutex, portMAX_DELAY);
     //ecm35xx_printf("wait4Completion   = %d...\r\n",work->wait4Completion);
	// Deal with input and output buffers memory
      //ecm35xx_printf("work id for completing %d ...\r\n",execWorkID);
	for (index = 0; index < (work->numInputs); index++)
	{
		HandleInputBufPostCompletion ((work->inbufs)[index]);
           //ecm35xx_printf(" here 1   ...\r\n");
		(work->inbufs)[index] = 0;
	}
	HandleOutputBufPostCompletion (work->outBuf);
      // ecm35xx_printf(" here 2   ...\r\n");
	//work->outBuf = 0;
	// Deal with param memory  if any
	if (work->params)
	{
        /*
		if (work->execHwId == EXEC_HW_ID_DSP)
			memType = OPD_MEM_TYPE_SHARED; */
		ExecFree (work->params, memType);
	}
    // ecm35xx_printf(" here 3   ...\r\n");
	work->valid = WORK_ID_INVALID;
	work->numInputs = 0;
	// if someone is waiting then reset  the  flag and give semaphore
	if (work->wait4Completion == true)
	{
		  //ecm35xx_printf("giving semaphore for index = %d ...\r\n",execWorkID);
#ifdef CONFIG_BIN_SEM
        xSemaphoreGive (work->waitSem);
#endif
 #ifdef CONFIG_TASK_NOTIFY
 xTaskNotifyGive( xTaskToNotify );
#endif
        work->wait4Completion = false;
	}
    //ecm35xx_printf("done with completion  ...\r\n");
	xSemaphoreGive (schedListMutex);
}
void  ExecWaitForCompletion ( void )
{
    uint8_t index = 0;
    // wait for all currently scheduled operation to get over
    xSemaphoreTake (schedListMutex, portMAX_DELAY);
    for (index = 0; index < CONFIG_EXEC_MAX_SCHEDULED_WORK; index++)
    {
        if ((schedList[index]).valid == WORK_ID_VALID)
        {
            schedList[index].wait4Completion = true;
            xSemaphoreGive (schedListMutex);
 #ifdef CONFIG_BIN_SEM
               xSemaphoreTake (schedList[index].waitSem, portMAX_DELAY);

#endif
 #ifdef CONFIG_TASK_NOTIFY
                    ulTaskNotifyTake( pdTRUE, portMAX_DELAY );
#endif
                    //ecm35xx_printf("worke up... \r\n");
					xSemaphoreTake (schedListMutex, portMAX_DELAY);
        }
    }
    xSemaphoreGive (schedListMutex);
}

__attribute__((optimize("O3")))  uint8_t
CheckAndScheduleWork (ExecWork_t * work, uint8_t inoutExist)
{
	uint8_t index1 = 0;
	uint8_t index2 = 0;
	uint8_t freeIndex = 0;
	ExecWork_t tempWork;
    struct privateInfo *privinfo;
 #ifdef CONFIG_TASK_NOTIFY
    if (!xTaskToNotify)
    xTaskToNotify = xTaskGetCurrentTaskHandle();
#endif
	// take mutex
	xSemaphoreTake (schedListMutex, portMAX_DELAY);
	// For each input of current work
	// check them with each scheduled work's output
	//TBD: optimisation
	for (index1 = 0; index1 < (work->numInputs); index1++)
	{
		for (index2 = 0; index2 < CONFIG_EXEC_MAX_SCHEDULED_WORK; index2++)
		{
			tempWork = schedList[index2];
			if (tempWork.valid == WORK_ID_INVALID)
			{
				freeIndex = index2;
			}
			else
			{
				if ((work->inbufs)[index1] == tempWork.outBuf)
				{
					// Dependency found
					schedList[index2].wait4Completion = true;
                   // ecm35xx_printf("stalling... \r\n");
                      //ecm35xx_printf("waiting  semaphore for index = %d ...\r\n",index2);
                        //   ecm35xx_printf("wait4Completion = %d ...\r\n",schedList[index2].wait4Completion);
					// Go for Stall and release the mutex
					xSemaphoreGive (schedListMutex);
 #ifdef CONFIG_BIN_SEM
                    xSemaphoreTake (tempWork.waitSem, portMAX_DELAY);

#endif
 #ifdef CONFIG_TASK_NOTIFY
                    ulTaskNotifyTake( pdTRUE, portMAX_DELAY );
#endif
                   // ecm35xx_printf("worke up... \r\n");
					xSemaphoreTake (schedListMutex, portMAX_DELAY);
                     //ecm35xx_printf("wlocked again the mutex.. \r\n");
				}
			}
		}
	}
     //ecm35xx_printf("freeIndex %d ...\r\n",freeIndex);
	// Now we kow the freeindex where we should insert
	schedList[freeIndex].execHwId = work->execHwId;
	schedList[freeIndex].params = work->params;
	schedList[freeIndex].outBuf = work->outBuf;
   schedList[freeIndex]. opID= work->opID;
   schedList[freeIndex]. variant= work->variant;
     privinfo =  (schedList[freeIndex].outBuf )->privInfo;
     privinfo->bufState = BUF_STATE_MEM_ACTIVE;
     privinfo->bufType = BUF_TYPE_OUT;
     if (inoutExist == true)
      privinfo->bufType = BUF_TYPE_INOUT;
  privinfo->usageCount = privinfo->usageCount +1;
	schedList[freeIndex].numInputs = work->numInputs;
	for (index1 = 0; index1 < (work->numInputs); index1++)
    {
    	(schedList[freeIndex]).inbufs[index1] = (work->inbufs)[index1];
       privinfo =  (schedList[freeIndex]).inbufs[index1] ->privInfo;
       privinfo->usageCount = privinfo->usageCount +1;
       privinfo->bufState = BUF_STATE_MEM_ACTIVE;
       privinfo->bufType = BUF_TYPE_IN;
       if  (inoutExist == true)
       {
           if ((work->inbufs)[index1] == work->outBuf)
             privinfo->bufType = BUF_TYPE_INOUT;
       }
    }

    schedList[freeIndex].wait4Completion = false;
	schedList[freeIndex].valid = WORK_ID_VALID;


	xSemaphoreGive (schedListMutex);
    //ecm35xx_printf("finishing CheckAndScheduleWork.\r\n",freeIndex);
    return freeIndex;
}
 void
SubmitM3Work (uint8_t execWorkID)
{
    xQueueSendToBack(executor_m3Q, (void *) &execWorkID, portMAX_DELAY);
}

 void
SubmitDSPWork (uint8_t execWorkID)
{
    xQueueSendToBack(executor_dspQ, (void *) &execWorkID, portMAX_DELAY);
}


//Deal with input  buffers post completion of an operation
// To be called holding the schedListMutex

static void
HandleInputBufPostCompletion (ExecOperand_t * inbuf)
{
	struct privateInfo *privinfo = inbuf->privInfo;
	// only call with buffers with type IN
    privinfo->usageCount = privinfo->usageCount - 1;
	if (privinfo->bufType == BUF_TYPE_IN)
	{
		if (inbuf->memScope == OPD_MEM_SCOPE_GLOBAL)
		{

			if (!(privinfo->usageCount))
			{
				if (privinfo->tobeFreed)
				{
					DestroyBuf (inbuf);
				}
				else
				{
					privinfo->bufState = BUF_STATE_MEM_IDLE;
					privinfo->bufType = BUF_TYPE_NONE;
				}
			}
		}
		else if (inbuf->memScope == OPD_MEM_SCOPE_OPERATION)
		{

			// When usage count reaches zero destroy  the buffer
			if (!(privinfo->usageCount))
			{
				DestroyBuf (inbuf);
			}
		}
		else
		{
			// TRACE: " Wrong mem scope for input buffer
		}
	}
}
//Deal with output   buffers post completion of an operation
// To be called holding the schedListMutex
static void
HandleOutputBufPostCompletion (ExecOperand_t * outBuf)
{
	struct privateInfo *privinfo = outBuf->privInfo;
	// only applicable for  buffers with type OUT and INOUT
	if ((privinfo->bufType == BUF_TYPE_OUT)
			|| (privinfo->bufType == BUF_TYPE_INOUT))
	{
		privinfo->usageCount = privinfo->usageCount - 1;
		privinfo->bufState = BUF_STATE_MEM_IDLE;
		privinfo->bufType = BUF_TYPE_NONE;
		// we never destroy the output buffer unless already asked
		if ((!(privinfo->usageCount)) && (privinfo->tobeFreed))
		{
			DestroyBuf (outBuf);
		}
	}
}


__attribute__((optimize("O3")))  void ExecFreeMem (ExecOperand_t  *p)
{
    if ((p->origin == OPD_ORIG_INT_PERSISTENT_MEM) || (p->origin == OPD_ORIG_EXT_PERSISTENT_MEM))
    {
        // Error trace
        struct privateInfo *privinfo = p->privInfo;
        vPortFree (privinfo);
        return;
    }
    else
    {
        struct privateInfo *privinfo = p->privInfo;
        xSemaphoreTake (schedListMutex, portMAX_DELAY);
        if(privinfo->bufState ==BUF_STATE_MEM_ACTIVE)
        {
            privinfo->tobeFreed = 1;
        }
        else
        {
          DestroyBuf (p)   ;
        }
        xSemaphoreGive (schedListMutex);
    }
}

inline void * ExecGetBufAddr (ExecOperand_t  *p)
{
     struct privateInfo *privinfo = p->privInfo;
     return (privinfo->bufAddr);
}


ExecStatus  __attribute__((optimize("O3"))) ExecAllocMem(ExecOperand_t  *p, void * baseAddr, uint32_t offset )
{
    ExecStatus status = EXEC_STATUS_OK;
    struct privateInfo *privinfo ;
    int8_t * base =( int8_t*) baseAddr; ;
    // first allocate the private structure
    p->privInfo = ( struct privateInfo  * ) pvPortMalloc(sizeof (struct privateInfo ));
    if (  p->privInfo)
    {
        privinfo =  p->privInfo;
        memset(privinfo, 0, sizeof(struct privateInfo));
    }
  else
   {
     // Error trace
     status = EXEC_STATUS_ERR_MEM;
     return status;
   }
    if ( baseAddr)
    {
        privinfo->bufAddr =  (void *)  (base+ (((p->basetypeSize) +1) * offset));
    }
    else
    {
         if ((p->origin == OPD_ORIG_INT_PERSISTENT_MEM) || (p->origin == OPD_ORIG_INT_PERSISTENT_MEM))
         {
          // Error trace
            status = EXEC_STATUS_ERR_MEM;
            return status;
         }
          privinfo->bufAddr= ExecAlloc(((p->basetypeSize)+1) * (p->numElements) ,p->memType);
          if (  privinfo->bufAddr ==0)
          {
              // Error trace
            status = EXEC_STATUS_ERR_MEM;
          return status;
          }
      }
      return status;
  }

static  void *  ExecAlloc (uint32_t size, uint8_t memType)
{
    void * addr = 0;
     //ecm35xx_printf("ExecAlloc size = %d ...\r\n",size);
    if ( memType == OPD_MEM_TYPE_M3_LOCAL)
        addr = (void *) pvPortMalloc(size);

    if (!addr){
           ecm35xx_printf("memory alloc failed.\r\n");
    }
       else{
           //  ecm35xx_printf("memory alloc success.\r\n");
       }
    //TBD : handle DSP allocs
         return addr;

}
static void ExecFree(void * bufAddr,uint8_t memType)
{
     if ( memType == OPD_MEM_TYPE_M3_LOCAL)
      vPortFree(bufAddr);

  //TBD : handle DSP
}


static void
DestroyBuf (ExecOperand_t * buf)
{
	struct privateInfo *privinfo = buf->privInfo;
    if(buf->origin == OPD_ORIG_CPU)
        ExecFree (privinfo->bufAddr, buf->memType);
    privinfo->bufState = BUF_STATE_NO_MEM;
    privinfo->bufType = BUF_TYPE_NONE;
	privinfo->tobeFreed = 0;
    privinfo->usageCount = 0;
    vPortFree(privinfo);
}



static void ExecM3Task(void *pvParameters)
{
     uint8_t workIndex = 0;
      ExecWork_t  * pWork;
    while (1)
    {
        // receive from Queue
        xQueueReceive( executor_m3Q,  &( workIndex ),  portMAX_DELAY);
        // ecm35xx_printf("Got work   .. index = %d .\r\n",workIndex);
        pWork = &(schedList[workIndex]);

        switch ( pWork->opID)
        {
#ifdef  CONFIG_OP_M3_CONV2D_Q7
            case EXEC_OP_M3_CONV2D_Q7:
            {
               //  ecm35xx_printf("Got work   .. conv2d .\r\n");
                exec_conv2d_q7_t *  params =  (exec_conv2d_q7_t *) ( pWork->params);
                // ecm35xx_printf ( " pbuf_0_0 = %x, pbuf_1_0 = %x, pbuf_0_4 = %x\r\n", ExecGetBufAddr((pWork->inbufs)[0]),ExecGetBufAddr(pWork->outBuf),ExecGetBufAddr((pWork->inbufs)[1]));
                // ecm35xx_printf ( " pbuf_0_1 = %x, pbuf_0_2 = %x\r\n", params->wt,params->bias);
                eta_conv2d_q7(( const q7_t * )ExecGetBufAddr((pWork->inbufs)[0]),  ( const q7_t *) params->wt, (const q7_t *) params->bias, ( q7_t *) ExecGetBufAddr(pWork->outBuf),  ( q7_t * )ExecGetBufAddr((pWork->inbufs)[1]),  (const conv2d_opt) (params->opt));
               //  ecm35xx_printf("Done  work   ...\r\n");
                // ecm35xx_printf("wait4Completion   = %d...\r\n",pWork->wait4Completion);
                ExecCompleteWork(workIndex);

            }
            break;
#endif
#ifdef  CONFIG_OP_M3_DS_CONV2D_Q7
            case EXEC_OP_M3_DS_CONV2D_Q7:
            {
                 //  ecm35xx_printf("Got work   .. conv2d .\r\n");
                exec_conv2d_q7_t *  params =  (exec_conv2d_q7_t *) ( pWork->params);
                // ecm35xx_printf ( " pbuf_0_0 = %x, pbuf_1_0 = %x, pbuf_0_4 = %x\r\n", ExecGetBufAddr((pWork->inbufs)[0]),ExecGetBufAddr(pWork->outBuf),ExecGetBufAddr((pWork->inbufs)[1]));
                // ecm35xx_printf ( " pbuf_0_1 = %x, pbuf_0_2 = %x\r\n", params->wt,params->bias);
                eta_ds_conv2d_q7(( const q7_t * )ExecGetBufAddr((pWork->inbufs)[0]),  ( const q7_t *) params->wt, (const q7_t *) params->bias, ( q7_t *) ExecGetBufAddr(pWork->outBuf),  ( q7_t * )ExecGetBufAddr((pWork->inbufs)[1]),  (const conv2d_opt) (params->opt));
               //  ecm35xx_printf("Done  work   ...\r\n");
                // ecm35xx_printf("wait4Completion   = %d...\r\n",pWork->wait4Completion);
                ExecCompleteWork(workIndex);

            }
            break;
#endif
#ifdef CONFIG_OP_M3_DS_CONV2D_LAYER2_Q7
            case EXEC_OP_M3_DS_CONV2D_LAYER2_Q7:
            {
                //ecm35xx_printf("EXEC_OP_M3_DS_CONV2D_DEPTH1_Q7\r\n");
                exec_conv2d_q7_t *  params =  (exec_conv2d_q7_t *) ( pWork->params);
                eta_ds_conv2d_layer2_q7(( const q7_t * )ExecGetBufAddr((pWork->inbufs)[0]),
                        ( const q7_t *) params->wt,
                        (const q7_t *) params->bias,
                        ( q7_t *) ExecGetBufAddr(pWork->outBuf),
                        ( q7_t * )ExecGetBufAddr((pWork->inbufs)[1]),
                        (const conv2d_opt) (params->opt));
                ExecCompleteWork(workIndex);

            }
            break;
#endif
#ifdef CONFIG_OP_M3_AVPOOL2D_Q7
            case EXEC_OP_M3_AVPOOL2D_Q7:
            {
                 exec_avepool2d_q7_t *  params =  (exec_avepool2d_q7_t *) ( pWork->params);
                  eta_avepool2d_q7((q7_t *)ExecGetBufAddr((pWork->inbufs)[0]), (q7_t * )ExecGetBufAddr(pWork->outBuf), (pool2d_opt)  (params->opt));
                 ExecCompleteWork(workIndex);
                //  ecm35xx_printf("Done  work   ...\r\n");
            }
            break;
#endif
#ifdef CONFIG_OP_M3_MAXPOOL_Q7
            case EXEC_OP_M3_MAXPOOL_Q7:
            {
                exec_maxpool2d_q7_t *  params =  (exec_maxpool2d_q7_t *) ( pWork->params);
                eta_maxpool_q7((q7_t *)ExecGetBufAddr((pWork->inbufs)[0]), (q7_t * )ExecGetBufAddr(pWork->outBuf),
                                        (pool2d_opt)(params->opt));
                ExecCompleteWork(workIndex);

            }
            break;
#endif
#ifdef  CONFIG_OP_M3_PW_CONV2D_Q7
            case EXEC_OP_M3_PW_CONV2D_Q7:
            {
                 exec_conv2d_q7_t *  params =  (exec_conv2d_q7_t *) ( pWork->params);
                // ecm35xx_printf ( " pbuf_0_0 = %x, pbuf_1_0 = %x, pbuf_0_4 = %x\r\n", ExecGetBufAddr((pWork->inbufs)[0]),ExecGetBufAddr(pWork->outBuf),ExecGetBufAddr((pWork->inbufs)[1]));
                // ecm35xx_printf ( " pbuf_0_1 = %x, pbuf_0_2 = %x\r\n", params->wt,params->bias);
                eta_pw_conv2d_q7((  q7_t * )ExecGetBufAddr((pWork->inbufs)[0]),  ( const q7_t *) params->wt, (const q7_t *) params->bias, ( q7_t *) ExecGetBufAddr(pWork->outBuf),  ( q7_t * )ExecGetBufAddr((pWork->inbufs)[1]),  ( conv2d_opt) (params->opt));
                 //  ecm35xx_printf("Done  work   ...\r\n");
                // ecm35xx_printf("wait4Completion   = %d...\r\n",pWork->wait4Completion);
                ExecCompleteWork(workIndex);
            }
            break;
#endif
#ifdef CONFIG_OP_M3_RELU_Q7
            case EXEC_OP_M3_RELU_Q7:
            {
                ExecOperand_t tmp;
                tmp= * ((pWork->inbufs)[0]);
            eta_relu_q7((q7_t *)ExecGetBufAddr((pWork->inbufs)[0]) , (uint16_t)NUM_ELEMENTS(tmp));
             ExecCompleteWork(workIndex);
 //ecm35xx_printf("Done  work   ...\r\n");
            }
            break;
#endif
#ifdef CONFIG_OP_M3_DS_CONV2D_SB_LAYER3_Q7
            case EXEC_OP_M3_DS_CONV2D_SB_LAYER3_Q7:
            {
               //ecm35xx_printf("Work EXEC_OP_M3_DS_CONV2D_SB_Q7  ...\r\n");

              exec_conv2d_q7_t *  params =  (exec_conv2d_q7_t *) ( pWork->params);
              eta_ds_conv2d_sb_layer3_q7((q7_t * )ExecGetBufAddr((pWork->inbufs)[0]),
                        params->wt, params->bias,
                        ( q7_t * )ExecGetBufAddr((pWork->inbufs)[1]),
                        (const conv2d_opt) (params->opt));
             ExecCompleteWork(workIndex);

            }
            break;
#endif
#ifdef CONFIG_OP_M3_PW_DS_CONV2D_LAYER4AND5_Q7
            case EXEC_OP_M3_PW_DS_CONV2D_LAYER4AND5_Q7:
            {
                //ecm35xx_printf("Work EXEC_OP_M3_PW_DS_CONV2D_Q7\r\n");
                exec_pw_ds_conv2d_q7_t *  params =  (exec_pw_ds_conv2d_q7_t *) ( pWork->params);
                eta_pw_ds_conv2d_layer4and5_q7(( const q7_t * )ExecGetBufAddr((pWork->inbufs)[0]),
                        params->wt_pw, params->wt_ds,
                        params->bias_pw, params->bias_ds,
                        ( q7_t *) ExecGetBufAddr(pWork->outBuf),
                        ( q7_t * )ExecGetBufAddr((pWork->inbufs)[1]),
                        ( q7_t * )ExecGetBufAddr((pWork->inbufs)[2]),
                        ( q7_t * )ExecGetBufAddr((pWork->inbufs)[3]),
                        ( q7_t * )ExecGetBufAddr((pWork->inbufs)[4]),
                        params->opt_pw, params->opt_ds);
             ExecCompleteWork(workIndex);

            }
            break;
#endif
#ifdef CONFIG_OP_M3_CONCAT_HEIGHT_Q7
            case EXEC_OP_M3_CONCAT_HEIGHT_Q7 :
            {
                //ecm35xx_printf("work EXEC_OP_M3_CONCAT_Q7\r\n");
                uint32_t in_ptr[CONFIG_EXEC_MAX_INPUTS] = {0};

                exec_concat_q7_t *  params =  (exec_concat_q7_t *) ( pWork->params);

                eta_concat_height_q7(
                        ( q7_t * )ExecGetBufAddr((pWork->inbufs)[0]),
                        ( q7_t * )ExecGetBufAddr((pWork->inbufs)[1]),
                        ( q7_t *) ExecGetBufAddr(pWork->outBuf),
                        params->opt);
                ExecCompleteWork(workIndex);

            }
            break;
#endif
#ifdef CONFIG_OP_M3_SIGMOID_Q7
            case EXEC_OP_M3_SIGMOID_Q7 :
            {
                //ecm35xx_printf("work EXEC_OP_M3_SIGMOID_Q7\r\n");
                exec_sigmoid_q7_t *  params =  (exec_sigmoid_q7_t *) ( pWork->params);
                eta_sigmoid_q7(
                        ( q7_t * )ExecGetBufAddr((pWork->inbufs)[0]),
                        params->size, params->width
                        );
             ExecCompleteWork(workIndex);

            }
            break;
#endif
#ifdef CONFIG_OP_M3_FULLY_CONNECTED_Q7
            case EXEC_OP_M3_FULLY_CONNECTED_Q7 :
            {
                exec_fc_q7_t *params =  (exec_fc_q7_t *) (pWork->params);
                eta_fully_connected_q7((q7_t *)ExecGetBufAddr((pWork->inbufs)[0]),
                            (const q7_t *)params->wt, (const q7_t *) params->bias,
                            (q7_t *) ExecGetBufAddr(pWork->outBuf), (fc_opt)(params->opt));

                ExecCompleteWork(workIndex);

            }
            break;
#endif
#ifdef CONFIG_OP_M3_ADD_Q7
            case EXEC_OP_M3_ADD_Q7 :
            {
                exec_add_q7_t *params =  (exec_add_q7_t *) (pWork->params);
                eta_add_q7((q7_t *)ExecGetBufAddr((pWork->inbufs)[0]),(q7_t *)ExecGetBufAddr((pWork->inbufs)[1]),
                                (q7_t *) ExecGetBufAddr(pWork->outBuf), (add_opt)(params->opt));

                ExecCompleteWork(workIndex);

            }
            break;
#endif

            default:
             ecm35xx_printf("unknown case   ...\r\n");
            //TBD: Error trace
            break;
        }

    }
}

static void ExecDspTask(void *pvParameters)
{
     uint8_t workIndex = 0;
      ExecWork_t  * pWork;
      int8_t fast = 0;
    while (1)
    {
        // receive from Queue
        xQueueReceive( executor_dspQ,  &( workIndex ),  portMAX_DELAY);
        // ecm35xx_printf("Got work   .. index = %d .\r\n",workIndex);
        pWork = &(schedList[workIndex]);

        switch ( pWork->opID)
        {
#ifdef CONFIG_OP_DSP_CHW_2X2_CONV2D_RELU_AVGPOOL_Q7
            case EXEC_OP_DSP_CHW_2X2_CONV2D_RELU_AVGPOOL_Q7:
            {
                 //ecm35xx_printf("Got work   .. dsp_2x2_conv2d_relu_avgpool .\r\n");
                exec_conv2d_relu_avgpool_q7_t *  params =  (exec_conv2d_relu_avgpool_q7_t *) ( pWork->params);
                // ecm35xx_printf ( " pbuf_0_0 = %x, pbuf_1_0 = %x, pbuf_0_4 = %x\r\n", ExecGetBufAddr((pWork->inbufs)[0]),ExecGetBufAddr(pWork->outBuf),ExecGetBufAddr((pWork->inbufs)[1]));
                // ecm35xx_printf ( " pbuf_0_1 = %x, pbuf_0_2 = %x\r\n", params->wt,params->bias);
                eta_conv2d_q7_CHW_ker2x2_stride1_pad0_relu_avgPool_2x2_stride2_pad0(( const q7_t * )ExecGetBufAddr((pWork->inbufs)[0]),  ( const q7_t *) params->wt, (const q7_t *) params->bias, ( q7_t *) ExecGetBufAddr(pWork->outBuf),  ( q7_t * )ExecGetBufAddr((pWork->inbufs)[1]),  (const conv2d_relu_avgpool_opt) (params->opt));
               //  ecm35xx_printf("Done  work   ...\r\n");
                // ecm35xx_printf("wait4Completion   = %d...\r\n",pWork->wait4Completion);
                ExecCompleteWork(workIndex);
               //ecm35xx_printf("A\r\n");
            }
            break;
#endif
#ifdef  CONFIG_OP_DSP_CHW_3X3_CONV2D_RELU_AVGPOOL_Q7
            case EXEC_OP_DSP_CHW_3X3_CONV2D_RELU_AVGPOOL_Q7:
            {
                  exec_conv2d_relu_avgpool_q7_t *  params =  (exec_conv2d_relu_avgpool_q7_t *) ( pWork->params);
                 eta_conv2d_q7_CHW_ker3x3_stride1_pad0_relu_avgPool_2x2_stride2_pad0(( const q7_t * )ExecGetBufAddr((pWork->inbufs)[0]),  ( const q7_t *) params->wt, (const q7_t *) params->bias, ( q7_t *) ExecGetBufAddr(pWork->outBuf),  ( q7_t * )ExecGetBufAddr((pWork->inbufs)[1]),  (const conv2d_relu_avgpool_opt) (params->opt));
                 ExecCompleteWork(workIndex);
                //ecm35xx_printf("A\r\n");
            }

            break;
#endif
#ifdef CONFIG_OP_DSP_HWC_PW_CONV2D_Q7_FAST
            case EXEC_OP_DSP_HWC_PW_CONV2D_Q7_FAST:
                  fast = 1;
#endif
#ifdef CONFIG_OP_DSP_HWC_PW_CONV2D_Q7
            case EXEC_OP_DSP_HWC_PW_CONV2D_Q7:

            {
                exec_conv2d_q7_t *  params =  (exec_conv2d_q7_t *) ( pWork->params);


                // ecm35xx_printf ( " pbuf_0_0 = %x, pbuf_1_0 = %x, pbuf_0_4 = %x\r\n", ExecGetBufAddr((pWork->inbufs)[0]),ExecGetBufAddr(pWork->outBuf),ExecGetBufAddr((pWork->inbufs)[1]));
                // ecm35xx_printf ( " pbuf_0_1 = %x, pbuf_0_2 = %x\r\n", params->wt,params->bias);
                eta_pw_conv2d_q7_hwc_dsp(( const q7_t * )ExecGetBufAddr((pWork->inbufs)[0]),  ( const q7_t *) params->wt, (const q7_t *) params->bias, ( q7_t *) ExecGetBufAddr(pWork->outBuf),  ( q7_t * )ExecGetBufAddr((pWork->inbufs)[1]),  ( conv2d_opt) (params->opt),fast);
                 //  ecm35xx_printf("Done  work   ...\r\n");
                // ecm35xx_printf("wait4Completion   = %d...\r\n",pWork->wait4Completion);
                ExecCompleteWork(workIndex);
            }
            break;
#endif
            case  EXEC_OP_DSP_CHW_3X3_CONV2D_STRIDE2_PAD0_RELU :
            case EXEC_OP_DSP_CHW_3X3_CONV2D_STRIDE1_PAD0_RELU :
            case EXEC_OP_DSP_CHW_2X2_CONV2D_STRIDE2_PAD0_RELU  :
            case  EXEC_OP_DSP_DS_CHW_3X3_CONV2D_STRIDE2_PAD0_RELU  :
            case  EXEC_OP_DSP_DS_CHW_3X3_CONV2D_STRIDE1_PAD0_RELU    :
             case EXEC_OP_DSP_DS_CHW_2X2_CONV2D_STRIDE2_PAD0_RELU:
            {
                uint8_t variant = NORMAL_CONV_2D;
                if (pWork->variant == DEPTHWISE_CONV_2D)
                     variant = DEPTHWISE_CONV_2D;

                exec_conv2d_q7_t *  params =  (exec_conv2d_q7_t *) ( pWork->params);

                eta_conv2d_q7_chw_relu_dsp(( const q7_t * )ExecGetBufAddr((pWork->inbufs)[0]),  ( const q7_t *) params->wt, (const q7_t *) params->bias, ( q7_t *) ExecGetBufAddr(pWork->outBuf),  ( q7_t * )ExecGetBufAddr((pWork->inbufs)[1]),  ( conv2d_opt) (params->opt), pWork->opID,variant);
                ExecCompleteWork(workIndex);
            }
            break;

            default:
             ecm35xx_printf("unknown case   ...\r\n");
            //TBD: Error trace
            break;
        }

    }
}


__attribute__((section(".initSection"))) ExecStatus ExecInit (void)
{
  uint8_t index = 0;
  ExecStatus status = EXEC_STATUS_OK;
  schedListMutex = xSemaphoreCreateMutex();
  #ifdef CONFIG_BIN_SEM
  for (index= 0; index < CONFIG_EXEC_MAX_SCHEDULED_WORK; index++)
  {
       schedList[index].waitSem= xSemaphoreCreateBinary();
   }
 #endif
 execDspRpcInit();
  executor_m3Q = xQueueCreate(CONFIG_EXEC_M3_QUEUE_NUM_ELEMENTS, sizeof(uint8_t));
  executor_dspQ = xQueueCreate(CONFIG_EXEC_DSP_QUEUE_NUM_ELEMENTS, sizeof(uint8_t));
  xTaskCreate(ExecM3Task, "ExecM3Task", CONFIG_EXEC_M3_TASK_STACK_SIZE, NULL, tskIDLE_PRIORITY + 4, NULL);
  xTaskCreate(ExecDspTask, "ExecDspTask", CONFIG_EXEC_DSP_TASK_STACK_SIZE, NULL, tskIDLE_PRIORITY + 4, NULL);
  return status;
}

static int execDspNotifyResponse(uint32_t header, uint32_t data)
{
    // Give response semaphore
    xSemaphoreGive(execDspRespSem);
    return 0;
}

// Header

static int execDspNotifyEvent(uint32_t header, uint32_t data)
{
    return 0;
    //Placeholder for the time being
}

//DSP related stuff: TBD: explore can be moved to  a separate file

 static int   execDspRpcInit( void)
  {
       uint8_t      eventHeaderMask = 0;
      // create the semaphore for all response synchronisation
    execDspRespSem = xSemaphoreCreateBinary();
    if (execDspRespSem == NULL) {
        //TBD: Add trace message of error
        return -1;
    }
    SET_MODULEID(eventHeaderMask, RPC_MODULE_ID_EXECUTOR);
    SET_EVT_RSP(eventHeaderMask, RPC_RESPONSE);
    // register with RPC notification  for all responses
    rpcRegisterEventCb(eventHeaderMask, execDspNotifyResponse);
    // register with RPC notification for events
    SET_EVT_RSP(eventHeaderMask, RPC_EVENT);
    rpcRegisterEventCb(eventHeaderMask, execDspNotifyEvent);
    return 0;
  }
//TBD: Remove it later
uint16_t  g_outHeight, g_outWidth, g_outChannel;

typedef int8_t * shMemBufPtr; //TBD: changes to int8_t once works
typedef int16_t * shMemBufPtr16;
#define GET_HIGH_16(X) ((((uint32_t)(X)) & 0xFFFF0000) >> 16)
#define GET_LOW_16(X)  (((uint32_t)(X))& 0x0000FFFF)

#define DSP_WEIGHT_BIAS_MEM_LIMIT              ( 15 *1024) // they go to Ymem , which is of  max 32K. 15 K on M3 side means 30K on DSP side.
#define DSP_INOUT_MEM_LIMIT                             (12*1024) // they  go to Xmem, which is of max 32K, 12K M3 side means 24 K on DSP, rest is tack and others.


#if defined(CONFIG_OP_DSP_HWC_PW_CONV2D_Q7_FAST) ||  defined (CONFIG_OP_DSP_HWC_PW_CONV2D_Q7)
static  ExecStatus eta_pw_conv2d_q7_hwc_dsp( const q7_t *  inArray,  const q7_t *  wt, const q7_t * bias,  q7_t *  outArray,  q7_t *  buffIn,   conv2d_opt opt, int8_t fast)

{
   uint16_t inHeight , inWidth, inChannel, outHeight, outWidth, outChannel ;
  tExecutorRpcWork  * execRpcWork;
  uint32_t inArraySize, weightArraySize, biasArraySize, outArraySize;
  int index = 0;
   uint8_t opId =0;
   //uint64_t start_ms, stop_ms;
   //Make sure to change their types
   shMemBufPtr dspInArray = 0;
  shMemBufPtr dspWeight = 0;
   shMemBufPtr dspBias  = 0;
  shMemBufPtr  dspOutArray = 0;
  // find sizes of all of the arrays using the info present in opt
  inHeight = opt.in_rows;
  inWidth =  opt.in_cols;
  inChannel = opt.in_depth;
  outHeight =  inHeight;
  outWidth =  inWidth ;
  outChannel = opt.num_filt;
   // allocate memory from the shared memory
   inArraySize = inHeight*inWidth*inChannel;
   weightArraySize = inChannel *outChannel;
   biasArraySize = outChannel;
   outArraySize = outHeight * outWidth * outChannel;


    if ( ((weightArraySize + biasArraySize) > DSP_WEIGHT_BIAS_MEM_LIMIT)) {

        opId =  EXEC_OP_DSP_HWC_PW_CONV2D_Q7_WEIGHT_DONT_FIT;
        dspOutArray = (  shMemBufPtr) pvPortMalloc(outArraySize*  (sizeof (dspOutArray[0]))); // Packing Dma not working now. So keep space for 16 bit data
   //ecm35xx_printf(" weights  do not fit in memory\r\n");
   if ( ! dspOutArray)
      ecm35xx_printf("No memory for  dspOutArray...\r\n");

    }
   if ( ((weightArraySize + biasArraySize) < DSP_WEIGHT_BIAS_MEM_LIMIT) && ((inArraySize + outArraySize) >DSP_INOUT_MEM_LIMIT)) {
        //ecm35xx_printf(" inouts  do not fit in memory\r\n");
        opId =  EXEC_OP_DSP_HWC_PW_CONV2D_Q7_INOUT_DONT_FIT;
    }
      if (( (weightArraySize + biasArraySize) < DSP_WEIGHT_BIAS_MEM_LIMIT) && ((inArraySize + outArraySize) <= DSP_INOUT_MEM_LIMIT)) {
        if (!fast)
            opId = EXEC_OP_DSP_HWC_PW_CONV2D_Q7;
        else
            opId = EXEC_OP_DSP_HWC_PW_CONV2D_Q7_FAST;
    }
    execRpcWork = SharedMemAlloc(sizeof(tExecutorRpcWork));
    memset((void *) execRpcWork,0, sizeof(tExecutorRpcWork));
    if (!execRpcWork) {
        //TBD: Add trace message of error
        return -1;
    }
     execRpcWork-> status = -1;
    (execRpcWork->inbuf).ahbAddrHi = GET_HIGH_16(inArray) ;
    (execRpcWork->inbuf).ahbAddrLo = GET_LOW_16(inArray) ;
//ecm35xx_printf("in high = 0x%x...\r\n", (execRpcWork->inbuf).ahbAddrHi);
//ecm35xx_printf("in low = 0x%x...\r\n", (execRpcWork->inbuf).ahbAddrLo);
//PTR_DUMP8(inArray,inArraySize);

     if (   inArraySize ==  65536){
    (execRpcWork->inbuf).size= (uint16_t)  ( inArraySize -1);
     }    // to accomodate 65536 in 16 bits
  else{
       (execRpcWork->inbuf).size= (uint16_t)  ( inArraySize );
  }

     (execRpcWork->inbuf).mapped= 0;
    if (opId ==  EXEC_OP_DSP_HWC_PW_CONV2D_Q7_WEIGHT_DONT_FIT)
    {
        /*
      (execRpcWork->outbuf).mapped= 1;
    (execRpcWork->outbuf).offset = SharedMemGetOffset(dspOutArray);
    */
         (execRpcWork->outbuf).mapped= 0;
        (execRpcWork->outbuf).ahbAddrHi = GET_HIGH_16(dspOutArray) ;
        (execRpcWork->outbuf).ahbAddrLo = GET_LOW_16(dspOutArray) ;

    }
    else{
         (execRpcWork->outbuf).mapped= 0;
    (execRpcWork->outbuf).ahbAddrHi = GET_HIGH_16(outArray) ;
    (execRpcWork->outbuf).ahbAddrLo = GET_LOW_16(outArray) ;
    }
    if (   outArraySize ==  65536){
    (execRpcWork->outbuf).size= (uint16_t) (  outArraySize -1) ; // to accomodate 65536 in 16 bits
    }
   else {
    (execRpcWork->outbuf).size= (uint16_t) (  outArraySize ) ;
   }
    // (execRpcWork->outbuf).offset = SharedMemGetOffset(dspOutArray);
    //(execRpcWork->outbuf).size= outArraySize;

    (execRpcWork->weight).ahbAddrHi = GET_HIGH_16(wt) ;
    (execRpcWork->weight).ahbAddrLo = GET_LOW_16(wt) ;
    (execRpcWork->weight).size=  (uint16_t)weightArraySize;
    (execRpcWork->weight).mapped= 0;

    (execRpcWork->bias).ahbAddrHi = GET_HIGH_16(bias) ;
    (execRpcWork->bias).ahbAddrLo = GET_LOW_16(bias) ;
    (execRpcWork->bias).size=  (uint16_t) biasArraySize;
    (execRpcWork->bias).mapped= 0;

     {
        //TBD: can be avoided if DSP and M3 calls uses the same param structure.
        conv_pw_opt pwOpt;
        pwOpt. in_rows = opt. in_rows;
       pwOpt. in_cols   = opt. in_cols;
       pwOpt. in_depth = opt. in_depth;
       pwOpt. num_filt   = opt. num_filt;
       pwOpt. bias_lshift = opt. bias_lshift;
       pwOpt. out_rshift   = opt. out_rshift;
       pwOpt. act_min = opt. act_min;
       pwOpt. act_max   = opt. act_max;
    memcpy (&((execRpcWork->params).convPwParams),&pwOpt,sizeof(conv_pw_opt));
    }
    rpcSubmitWork(RPC_MODULE_ID_EXECUTOR, opId, (void*)execRpcWork);

    // work for wait to get over from DSP
 //  ecm35xx_printf(" S \r\n");

     xSemaphoreTake(execDspRespSem, portMAX_DELAY);
     //ecm35xx_printf(" D \r\n");
     if ( opId == EXEC_OP_DSP_HWC_PW_CONV2D_Q7_WEIGHT_DONT_FIT)
     {
         //ecm35xx_printf(" C \r\n");
         // convert the output to HWC
            //CHWq15_to_HWCq7( dspOutArray, outArray, outHeight, outWidth, outChannel);
            CHWq7_to_HWCq7_Ex(dspOutArray, outArray,
                              outHeight, outWidth, outChannel,
                              0, outChannel);
            vPortFree(dspOutArray);
            //SharedMemFree(dspOutArray);
     }
   SharedMemFree(execRpcWork);
     //ecm35xx_printf("DD\r\n");

    // PTR_DUMP16(dspOutArray,outArraySize);

    // Get back  to caller
    return EXEC_STATUS_OK;

}
#endif


static ExecStatus  eta_conv2d_q7_chw_relu_dsp (const q7_t * inArray,  const q7_t *  wt, const q7_t * bias,  q7_t *  outArray,  q7_t *  buffIn,  conv2d_opt opt, uint8_t opID, uint8_t variant)
{
  uint16_t inHeight , inWidth, inChannel,
           outHeight, outWidth, outChannel,
           kernelHeight, kernelWidth,
           stride,
           pad, leftPad, topPad, rightPad, bottomPad;
  tExecutorRpcWork  * execRpcWork = 0;
  uint32_t inArraySize, weightArraySize, biasArraySize, outArraySize,partialInArraySize,partialOutArraySize;
  int index = 0;
  int num_per_iter = 1;
  int run_input_and_dsp_in_parallel = 1;
  uint64_t start_ms, stop_ms;
  //Make sure to change their types
  shMemBufPtr dspInArray = 0;
  shMemBufPtr dspInArray1 = 0;
  shMemBufPtr dspWeight = 0;
  shMemBufPtr dspBias  = 0;
  shMemBufPtr  dspOutArray = 0;
  // find sizes of all of the arrays using the info present in opt
  kernelHeight = opt.filt_rows;
  kernelWidth = opt.filt_cols;
  inHeight = opt.in_rows;
  inWidth =  opt.in_cols;
  inChannel = opt.in_depth;
  outHeight = opt.out_rows;
  outWidth = opt.out_cols;
  outChannel = opt.num_filt;
  // allocate memory from the shared memory
  leftPad = opt.col_pad;
  topPad = opt.row_pad;
  rightPad = opt.out_cols -
             (((opt.in_cols + (2 * opt.col_pad) - opt.filt_cols) / opt.col_stride) +1) +
             opt.col_pad;
  bottomPad = opt.out_rows -
              (((opt.in_rows + (2 * opt.row_pad) - opt.filt_rows) / opt.row_stride) +1) +
              opt.row_pad;

  //inArraySize = inHeight*inWidth*inChannel;
  inArraySize = (inWidth + leftPad + rightPad) * ( inHeight + topPad + bottomPad) * inChannel;
  weightArraySize = kernelHeight*kernelWidth*inChannel * opt.num_filt;

  if (variant == NORMAL_CONV_2D) {
    biasArraySize = outChannel;
  }
  if (variant == DEPTHWISE_CONV_2D) {
    biasArraySize = inChannel * opt.num_filt;
    outChannel = inChannel * opt.num_filt;
  }
  outArraySize = outHeight * outWidth * outChannel;

  //ecm35xx_printf(" here \r\n");
  if ( ((weightArraySize + biasArraySize) > DSP_WEIGHT_BIAS_MEM_LIMIT)) {
    //TBD: We need to handle this
    ecm35xx_printf(" Weights do not fit in memory. This case is not handled yet !!! \r\n");
  }

  //ecm35xx_printf("inArraySize: %d\r\n", inArraySize);
  //ecm35xx_printf("outArraySize: %d\r\n", outArraySize);
  //ecm35xx_printf("DSP_INOUT_MEM_LIMIT: %d\r\n", DSP_INOUT_MEM_LIMIT);
  if (((weightArraySize + biasArraySize) < DSP_WEIGHT_BIAS_MEM_LIMIT) &&
      ((inArraySize + outArraySize) >DSP_INOUT_MEM_LIMIT)) {
    //ecm35xx_printf(" inouts  do not fit in memory\r\n");

    // If there are many channels where the input is not very large
    // it could be faster to process a few in parallel.
    // NOTE: It is very hard to tell what would be the fastest as it depends
    // on many different factors: conversion time, DMA time, DSP time etc.
    // There is no good way to determine how many channels per iteration
    // will be the fastest. Below computation is based on previous measurements.
    // There is no guarantee that this produce the fastest result. To get
    // the best speed, one has to manually adjust this for a specific network.
    if (inChannel < 64)
    {
      num_per_iter = 1;
    }
    else
    {
      num_per_iter = inArraySize + outArraySize;
      if (num_per_iter % DSP_INOUT_MEM_LIMIT != 0)
      {
        num_per_iter = (num_per_iter / DSP_INOUT_MEM_LIMIT) + 1;
      }
      else
      {
        num_per_iter = (num_per_iter / DSP_INOUT_MEM_LIMIT);
      }
      num_per_iter = inChannel / num_per_iter;
    }

    partialInArraySize = num_per_iter * (inWidth + leftPad + rightPad) * ( inHeight + topPad + bottomPad);
    partialOutArraySize = num_per_iter * outHeight * outWidth;

    // FIXME: Create a more general formula.
    //if ( (inWidth * inWidth + outWidth * outWidth) >= 64 * 64 + 64 * 64 ) {
      //run_input_and_dsp_in_parallel = 0;
      //ecm35xx_printf(" Cannot run input conversion and dsp in parallel\r\n");
    //}

    dspInArray = (  shMemBufPtr) pvPortMalloc(partialInArraySize*  (sizeof (dspInArray[0])));
    //ecm35xx_printf(" dspInArray [%d]\r\n", partialInArraySize );
    if ( ! dspInArray)
      ecm35xx_printf("No memory for  dspInArray...\r\n");

    if (run_input_and_dsp_in_parallel) {
      dspInArray1 = (  shMemBufPtr ) pvPortMalloc( partialInArraySize* (sizeof ( dspInArray1[0])));
      //ecm35xx_printf(" dspInArray1 [%d]\r\n", partialInArraySize );
      if ( ! dspInArray1)
        ecm35xx_printf("No memory for  dspInArray1...\r\n");
    }

    /*dspWeight = (  shMemBufPtr ) pvPortMalloc(weightArraySize* (sizeof (dspWeight[0])));
    //ecm35xx_printf(" dspWeight [%d]\r\n", weightArraySize);
    if ( ! dspWeight)
      ecm35xx_printf("No memory for  dspWeight...\r\n");*/

    /*dspBias = (  shMemBufPtr ) SharedMemAlloc(biasArraySize* (sizeof (dspBias[0])));
    //ecm35xx_printf(" dspBias [%d]\r\n", biasArraySize);
    if ( ! dspBias)
      ecm35xx_printf("No memory for  dspBias...\r\n");*/

    dspOutArray = (  shMemBufPtr ) pvPortMalloc(partialOutArraySize*  (sizeof (dspOutArray[0])));
    //ecm35xx_printf(" dspOutArray [%d]\r\n",partialOutArraySize);
    if ( ! dspOutArray)
      ecm35xx_printf("No memory for  dspOutArray...\r\n");

    /*if (variant == DEPTHWISE_CONV_2D)
      reorder_conv2d_kernel( ( int8_t* ) wt, dspWeight, kernelHeight, kernelWidth, inChannel, 1);
    else
      reorder_conv2d_kernel( ( int8_t* ) wt, dspWeight, kernelHeight, kernelWidth, inChannel, outChannel);*/

    /*for ( index =0; index<outChannel; index++){
      dspBias[index] = (int8_t) (bias[index]);
    }*/

    execRpcWork = SharedMemAlloc(sizeof(tExecutorRpcWork));
    //memset((void *) execRpcWork,0, sizeof(tExecutorRpcWork));
    if (!execRpcWork) {
      //TBD: Add trace message of error
      return -1;
    }

    // Fill in the shared data structure with DSP
    execRpcWork-> status = -1;
    //(execRpcWork->inbuf).offset = SharedMemGetOffset(dspInArray);
    (execRpcWork->inbuf).size= (uint16_t) partialInArraySize;
    (execRpcWork->inbuf).mapped= 0;
    (execRpcWork->outbuf).ahbAddrHi = GET_HIGH_16(dspOutArray);
    (execRpcWork->outbuf).ahbAddrLo = GET_LOW_16(dspOutArray);
    //(execRpcWork->outbuf).offset = SharedMemGetOffset(dspOutArray);
    (execRpcWork->outbuf).size=  (uint16_t) partialOutArraySize;
    (execRpcWork->outbuf).mapped= 0;
    //(execRpcWork->weight).ahbAddrHi = GET_HIGH_16(dspWeight) ;
    //(execRpcWork->weight).ahbAddrLo = GET_LOW_16(dspWeight) ;
    (execRpcWork->weight).ahbAddrHi = GET_HIGH_16(wt) ;
    (execRpcWork->weight).ahbAddrLo = GET_LOW_16(wt) ;
    //(execRpcWork->weight).offset = SharedMemGetOffset(dspWeight);
    (execRpcWork->weight).size= (uint16_t)  weightArraySize;
    (execRpcWork->weight).mapped= 0;
    (execRpcWork->bias).ahbAddrHi = GET_HIGH_16(bias) ;
    (execRpcWork->bias).ahbAddrLo = GET_LOW_16(bias) ;
    //(execRpcWork->bias).offset = SharedMemGetOffset(dspBias);
    (execRpcWork->bias).size= (uint16_t) biasArraySize;
    (execRpcWork->bias).mapped= 0;

    conv2d_opt temp_opt = opt;
    temp_opt.in_rows = opt.in_rows + topPad + bottomPad;
    temp_opt.in_cols = opt.in_cols + leftPad + rightPad;
    if (variant == DEPTHWISE_CONV_2D)
    {
      temp_opt.in_depth = num_per_iter;
    }
    memcpy (&((execRpcWork->params).conv2dParams),&temp_opt,sizeof(conv2d_opt));

    if (run_input_and_dsp_in_parallel) {
      // Prefill input buffer
      //start_ms = HalTmrRead(0);
      HWCq7_to_CHWq7_with_pad_partial_channels((int8_t *) inArray, dspInArray,
                                               inHeight, inWidth, inChannel,
                                               leftPad, rightPad, topPad, bottomPad,
                                               0, num_per_iter);
      //stop_ms =  HalTmrRead(0);
      //ecm35xx_printf("input converion  time= %d ms\r\n", (uint32_t) (stop_ms - start_ms));
    }
    else {
      (execRpcWork->inbuf).ahbAddrHi = GET_HIGH_16(dspInArray);
      (execRpcWork->inbuf).ahbAddrLo = GET_LOW_16(dspInArray);
    }

    for ( index = 0; index < inChannel/num_per_iter;index++)
    {
      execRpcWork->index = index * num_per_iter;

      if (run_input_and_dsp_in_parallel) {
        if ( index % 2 == 0 )
        {
          (execRpcWork->inbuf).ahbAddrHi = GET_HIGH_16(dspInArray);
          (execRpcWork->inbuf).ahbAddrLo = GET_LOW_16(dspInArray);
          //(execRpcWork->inbuf).offset = SharedMemGetOffset(dspInArray);
        }
        else
        {
          (execRpcWork->inbuf).ahbAddrHi = GET_HIGH_16(dspInArray1);
          (execRpcWork->inbuf).ahbAddrLo = GET_LOW_16(dspInArray1);
          //(execRpcWork->inbuf).offset = SharedMemGetOffset(dspInArray1);
        }
      }
      else {
        //start_ms = HalTmrRead(0);
        HWCq7_to_CHWq7_with_pad_partial_channels((int8_t *) inArray, dspInArray,
                                                 inHeight, inWidth, inChannel,
                                                 leftPad, rightPad, topPad, bottomPad,
                                                 (index)*num_per_iter, num_per_iter);
        //stop_ms =  HalTmrRead(0);
        //ecm35xx_printf("input converion  time= %d ms\r\n", (uint32_t) (stop_ms - start_ms));
      }

      // submit work

      //start_ms = HalTmrRead(0);
      rpcSubmitWork(RPC_MODULE_ID_EXECUTOR, opID, (void*)execRpcWork);
      // work for wait to get over from DSP
      //ecm35xx_printf(" S \r\n");

      if ( (index < (inChannel/num_per_iter)-1) && run_input_and_dsp_in_parallel )
      {
        if ( index % 2 == 0 )
        {
          HWCq7_to_CHWq7_with_pad_partial_channels((int8_t *) inArray, dspInArray1,
                                                   inHeight, inWidth, inChannel,
                                                   leftPad, rightPad, topPad, bottomPad,
                                                   (index+1)*num_per_iter, num_per_iter);
        }
        else
        {
          HWCq7_to_CHWq7_with_pad_partial_channels((int8_t *) inArray, dspInArray,
                                                   inHeight, inWidth, inChannel,
                                                   leftPad, rightPad, topPad, bottomPad,
                                                   (index+1)*num_per_iter, num_per_iter);
        }
      }

      xSemaphoreTake(execDspRespSem, portMAX_DELAY);

      //stop_ms =  HalTmrRead(0);
      //ecm35xx_printf("kernel  time= %d ms\r\n", (uint32_t) (stop_ms - start_ms));

      // PTR_DUMP16(dspOutArray,outArraySize);

      if (  execRpcWork->status == 0)
        //start_ms = HalTmrRead(0);
        CHWq7_to_HWCq7_Ex(dspOutArray, outArray,
                          outHeight, outWidth, outChannel,
                          index*num_per_iter, num_per_iter);
        //stop_ms =  HalTmrRead(0);
        //ecm35xx_printf("output conversion   time= %d ms\r\n", (uint32_t) (stop_ms - start_ms));

    }

  }
  // Assuming all fits into memory
  if (( (weightArraySize + biasArraySize) < DSP_WEIGHT_BIAS_MEM_LIMIT) && ((inArraySize + outArraySize) <DSP_INOUT_MEM_LIMIT))
  {
    //ecm35xx_printf(" all fit in memory\r\n");

    dspInArray = (  shMemBufPtr ) pvPortMalloc( inArraySize* (sizeof ( dspInArray[0])));
    //ecm35xx_printf(" dspInArray [%d]\r\n", inArraySize);
    if ( ! dspInArray)
      ecm35xx_printf("No memory for  dspInArray...\r\n");

    /*dspWeight = (  shMemBufPtr ) pvPortMalloc(weightArraySize* (sizeof (dspWeight[0])));
    //ecm35xx_printf(" dspWeight [%d]\r\n", weightArraySize);
    if ( ! dspWeight)
      ecm35xx_printf("No memory for  dspWeight...\r\n");

    dspBias = (  shMemBufPtr ) pvPortMalloc(biasArraySize* (sizeof (dspBias[0])));
    //ecm35xx_printf(" dspBias [%d]\r\n", biasArraySize);
    if ( ! dspBias)
      ecm35xx_printf("No memory for  dspBias...\r\n");*/

    dspOutArray = (  shMemBufPtr ) pvPortMalloc(outArraySize*  (sizeof (dspOutArray[0])));
    //ecm35xx_printf(" dspOutArray [%d]\r\n",outArraySize);
    if ( ! dspOutArray)
      ecm35xx_printf("No memory for  dspOutArray...\r\n");


    //HWCq7_to_CHWq15((int8_t *) inArray, dspInArray, inHeight, inWidth, inChannel);
    HWCq7_to_CHWq7_with_pad_partial_channels((int8_t *) inArray, dspInArray,
                                             inHeight, inWidth, inChannel,
                                             leftPad, rightPad, topPad, bottomPad,
                                             0, inChannel);

    //TBD:  this we can eliminate when compiler puts the kernel in the same format
    //stop_ms =  HalTmrRead(0);
    // ecm35xx_printf("input time= %d ms\r\n", (uint32_t) (stop_ms - start_ms));
    /*if (variant == DEPTHWISE_CONV_2D)
      reorder_conv2d_kernel( ( int8_t* ) wt, dspWeight, kernelHeight,kernelWidth, inChannel, 1);
    else
      reorder_conv2d_kernel( ( int8_t* ) wt, dspWeight, kernelHeight,kernelWidth, inChannel, outChannel);*/

    // Bias  nothing to convert.. right now converting to int6_t. remember to remove it.
    /*for ( index =0; index<outChannel; index++){
      dspBias[index] = (int8_t) (bias[index]);
    }*/
    execRpcWork = SharedMemAlloc(sizeof(tExecutorRpcWork));
    if (!execRpcWork) {
      //TBD: Add trace message of error
      return -1;
    }
    // Fill in the shared data structure with DSP
    execRpcWork-> status = -1;
    (execRpcWork->inbuf).ahbAddrHi = GET_HIGH_16(dspInArray);
    (execRpcWork->inbuf).ahbAddrLo = GET_LOW_16(dspInArray);
    //(execRpcWork->inbuf).offset = SharedMemGetOffset(dspInArray);
    (execRpcWork->inbuf).size= (uint16_t) inArraySize;
    (execRpcWork->inbuf).mapped= 0;
    (execRpcWork->outbuf).ahbAddrHi = GET_HIGH_16(dspOutArray);
    (execRpcWork->outbuf).ahbAddrLo = GET_LOW_16(dspOutArray);
    //(execRpcWork->outbuf).offset = SharedMemGetOffset(dspOutArray);
    (execRpcWork->outbuf).size=  (uint16_t) outArraySize;
    (execRpcWork->outbuf).mapped= 0;
    (execRpcWork->weight).ahbAddrHi = GET_HIGH_16(wt) ;
    (execRpcWork->weight).ahbAddrLo = GET_LOW_16(wt) ;
    //(execRpcWork->weight).ahbAddrHi = GET_HIGH_16(dspWeight) ;
    //(execRpcWork->weight).ahbAddrLo = GET_LOW_16(dspWeight) ;
    //(execRpcWork->weight).offset = SharedMemGetOffset(dspWeight);
    (execRpcWork->weight).size= (uint16_t)  weightArraySize;
    (execRpcWork->weight).mapped= 0;
    (execRpcWork->bias).ahbAddrHi = GET_HIGH_16(bias) ;
    (execRpcWork->bias).ahbAddrLo = GET_LOW_16(bias) ;
    //(execRpcWork->bias).ahbAddrHi = GET_HIGH_16(dspBias) ;
    //(execRpcWork->bias).ahbAddrLo = GET_LOW_16(dspBias) ;
    //(execRpcWork->bias).offset = SharedMemGetOffset(dspBias);
    (execRpcWork->bias).size= (uint16_t) biasArraySize;
    (execRpcWork->bias).mapped= 0;
    memcpy (&((execRpcWork->params).conv2dParams),&opt,sizeof(conv2d_opt));
    execRpcWork->index =0;
    // submit work
    /*
    start_ms = HalTmrRead(0);
    for ( index = 0; index < 100; index ++)
    {*/

    conv2d_opt temp_opt = opt;
    temp_opt.in_rows = opt.in_rows + topPad + bottomPad;
    temp_opt.in_cols = opt.in_cols + leftPad + rightPad;
    if (variant == DEPTHWISE_CONV_2D)
    {
      //temp_opt.in_depth = num_per_iter;
    }
    //ecm35xx_printf("num_per_iter: %d\r\n", num_per_iter);
    memcpy (&((execRpcWork->params).conv2dParams),&temp_opt,sizeof(conv2d_opt));

    rpcSubmitWork(RPC_MODULE_ID_EXECUTOR, opID, (void*)execRpcWork);
    // work for wait to get over from DSP
    //ecm35xx_printf(" S \r\n");

    xSemaphoreTake(execDspRespSem, portMAX_DELAY);
    /*}
    stop_ms =  HalTmrRead(0);
    ecm35xx_printf("input time= %d ms\r\n", (uint32_t) (stop_ms - start_ms));
    */
    // PTR_DUMP16(dspOutArray,outArraySize);

    if (  execRpcWork->status == 0)
      //CHWq15_to_HWCq7( dspOutArray, outArray, outHeight, outWidth, outChannel);
      CHWq7_to_HWCq7_Ex(dspOutArray, outArray,
                        outHeight, outWidth, outChannel,
                        0, outChannel);
  }
  // check status // convert back out buffer
  //PTR_DUMP8(outArray,outArraySize);
  //TBD remove it
  g_outHeight = outHeight;
  g_outWidth  = outWidth;
  g_outChannel = outChannel;
  // Free all shared memory pointers
  if ( dspInArray) vPortFree(dspInArray);
  if ( dspInArray1) vPortFree(dspInArray1);
  if ( dspWeight) vPortFree(dspWeight);
  if ( dspBias) vPortFree(dspBias);
  if ( dspOutArray)vPortFree(dspOutArray);
  if (execRpcWork)SharedMemFree(execRpcWork);
  // Get back  to caller
  return EXEC_STATUS_OK;
}
#ifdef CONFIG_OP_DSP_CHW_2X2_CONV2D_RELU_AVGPOOL_Q7
static ExecStatus eta_conv2d_q7_CHW_ker2x2_stride1_pad0_relu_avgPool_2x2_stride2_pad0(const q7_t * inArray,  const q7_t *  wt, const q7_t * bias,  q7_t *  outArray,  q7_t *  buffIn,  const conv2d_relu_avgpool_opt opt)
{
  uint16_t inHeight , inWidth, inChannel, outHeight, outWidth, outChannel, kernelHeight, kernelWidth, stride,pad ;
  tExecutorRpcWork  * execRpcWork;
  uint16_t inArraySize, weightArraySize, biasArraySize, outArraySize;
  int index = 0;
   //uint64_t start_ms, stop_ms;
   //Make sure to change their types
   shMemBufPtr dspInArray = 0;
  shMemBufPtr dspWeight = 0;
   shMemBufPtr dspBias  = 0;
  shMemBufPtr  dspOutArray = 0;
  // find sizes of all of the arrays using the info present in opt
  stride = 1;
  pad = 0 ;
  kernelHeight = 2;
  kernelWidth = 2;
  inHeight = opt.in_rows;
  inWidth =  opt.in_cols;
  inChannel = opt.in_depth;
  outHeight = ((inHeight - kernelHeight) + 2*pad )/stride +1;
  outWidth = ((inWidth - kernelWidth) + 2*pad )/stride +1;
  // Adjust for average pool. take care of rounding  as per suggestion from NN experts. right now round up.
  outHeight = DIV_ROUND_UP(outHeight,2);
  outWidth =  DIV_ROUND_UP(outWidth,2);
  outChannel = opt.num_filt;
   // allocate memory from the shared memory
   inArraySize = inHeight*inWidth*inChannel;

#ifdef DYNAMIC_MAPPING
  dspInArray = (shMemBufPtr)pvPortMalloc( inArraySize* (sizeof ( dspInArray[0])));
#else
   dspInArray = (shMemBufPtr)SharedMemAlloc(inArraySize * (sizeof(dspInArray[0])));
#endif
  //ecm35xx_printf(" dspInArray [%d]\r\n", inArraySize);
  if ( ! dspInArray)
      ecm35xx_printf("No memory for  dspInArray...\r\n");
    weightArraySize = kernelHeight*kernelWidth*inChannel *outChannel;

#ifdef DYNAMIC_MAPPING
    dspWeight = (shMemBufPtr)pvPortMalloc(weightArraySize* (sizeof (dspWeight[0])));
#else
    dspWeight = (shMemBufPtr)SharedMemAlloc(weightArraySize * (sizeof(dspWeight[0])));
#endif
     //ecm35xx_printf(" dspWeight [%d]\r\n", weightArraySize);
  if ( ! dspWeight)
      ecm35xx_printf("No memory for  dspWeight...\r\n");
    biasArraySize = outChannel;
#ifdef DYNAMIC_MAPPING
    dspBias = (shMemBufPtr)pvPortMalloc(biasArraySize * (sizeof(dspBias[0])));
#else
    dspBias = (shMemBufPtr)SharedMemAlloc(biasArraySize * (sizeof(dspBias[0])));
#endif
   //ecm35xx_printf(" dspBias [%d]\r\n", biasArraySize);
  if ( ! dspBias)
      ecm35xx_printf("No memory for  dspBias...\r\n");
  outArraySize = outHeight * outWidth * outChannel;
#ifdef DYNAMIC_MAPPING
  dspOutArray = (  shMemBufPtr )pvPortMalloc(outArraySize*  (sizeof (dspOutArray[0]))); // Packing Dma not working now. So keep space for 16 bit data
#else
  dspOutArray = (shMemBufPtr)SharedMemAlloc(outArraySize * (sizeof(dspOutArray[0]))); // Packing Dma not working now. So keep space for 16 bit data
#endif
   //ecm35xx_printf(" dspOutArray [%d]\r\n",outArraySize);
  if ( ! dspOutArray)
      ecm35xx_printf("No memory for  dspOutArray...\r\n");
    // Convert all into DSP understandable form
   // start_ms = HalTmrRead(0);
     HWCq7_to_CHWq15((int8_t *) inArray, dspInArray, inHeight, inWidth, inChannel);
     //TBD:  this we can eliminate when compiler puts the kernel in the same format
     //stop_ms =  HalTmrRead(0);
    // ecm35xx_printf("input time= %d ms\r\n", (uint32_t) (stop_ms - start_ms));
     reorder_conv2d_kernel( ( int8_t* ) wt, dspWeight, kernelHeight,kernelWidth, inChannel, outChannel);

     // Bias  nothing to convert.. right now converting to int6_t. remember to remove it.
     for ( index =0; index<outChannel; index++){
         dspBias[index] = (int8_t) (bias[index]);
     }
         execRpcWork = SharedMemAlloc(sizeof(tExecutorRpcWork));
    if (!execRpcWork) {
        //TBD: Add trace message of error
        return -1;
    }
    // Fill in the shared data structure with DSP
    execRpcWork-> status = -1;
#ifdef DYNAMIC_MAPPING
    (execRpcWork->inbuf).ahbAddrHi = GET_HIGH_16(dspInArray);
    (execRpcWork->inbuf).ahbAddrLo = GET_LOW_16(dspInArray);
    (execRpcWork->outbuf).ahbAddrHi = GET_HIGH_16(dspOutArray);
    (execRpcWork->outbuf).ahbAddrLo = GET_LOW_16(dspOutArray);
    (execRpcWork->weight).ahbAddrHi = GET_HIGH_16(dspWeight);
    (execRpcWork->weight).ahbAddrLo = GET_LOW_16(dspWeight);
    (execRpcWork->bias).ahbAddrHi = GET_HIGH_16(dspBias);
    (execRpcWork->bias).ahbAddrLo = GET_LOW_16(dspBias);
    (execRpcWork->inbuf).mapped = 0;
    (execRpcWork->outbuf).mapped = 0;
    (execRpcWork->weight).mapped = 0;
    (execRpcWork->bias).mapped = 0;
#else
    (execRpcWork->inbuf).mapped = 1;
    (execRpcWork->outbuf).mapped = 1;
    (execRpcWork->weight).mapped = 1;
    (execRpcWork->bias).mapped = 1;
    (execRpcWork->inbuf).offset = SharedMemGetOffset(dspInArray);
    (execRpcWork->outbuf).offset = SharedMemGetOffset(dspOutArray);
    (execRpcWork->weight).offset = SharedMemGetOffset(dspWeight);
    (execRpcWork->bias).offset = SharedMemGetOffset(dspBias);
#endif
    (execRpcWork->inbuf).size = inArraySize;
    (execRpcWork->outbuf).size = outArraySize;
    (execRpcWork->weight).size = weightArraySize;
    (execRpcWork->bias).size = biasArraySize;
    memcpy (&((execRpcWork->params).convReluPoolParams),&opt,sizeof(conv2d_relu_avgpool_opt));
    // submit work
     rpcSubmitWork(RPC_MODULE_ID_EXECUTOR, EXEC_OP_DSP_CHW_2X2_CONV2D_RELU_AVGPOOL_Q7, (void*)execRpcWork);
    // work for wait to get over from DSP
    //ecm35xx_printf(" S \r\n");

     xSemaphoreTake(execDspRespSem, portMAX_DELAY);

    // PTR_DUMP16(dspOutArray,outArraySize);
    if (  execRpcWork->status == 0)
        CHWq15_to_HWCq7( dspOutArray, outArray, outHeight, outWidth, outChannel);
      // check status // convert back out buffer
      //PTR_DUMP8(outArray,outArraySize);
    //TBD remove it
     g_outHeight = outHeight;
     g_outWidth  = outWidth;
     g_outChannel = outChannel;
    // Free all shared memory pointers
#ifdef DYNAMIC_MAPPING
     vPortFree(dspInArray); vPortFree(dspWeight); vPortFree(dspBias); vPortFree(dspOutArray);
#else
     SharedMemFree(dspInArray); SharedMemFree(dspWeight); SharedMemFree(dspBias); SharedMemFree(dspOutArray);
#endif
     SharedMemFree(execRpcWork);
    // Get back  to caller
    return EXEC_STATUS_OK;
}
#endif

void getOutDimensions (uint16_t *  outHeight , uint16_t *  outWidth,  uint16_t *  outChannel )
{
    *outHeight = g_outHeight;
    *outWidth = g_outWidth;
     *outChannel = g_outChannel;
}

#ifdef  CONFIG_OP_DSP_CHW_3X3_CONV2D_RELU_AVGPOOL_Q7
static ExecStatus eta_conv2d_q7_CHW_ker3x3_stride1_pad0_relu_avgPool_2x2_stride2_pad0(const q7_t * inArray,  const q7_t *  wt, const q7_t * bias,  q7_t *  outArray,  q7_t *  buffIn,  const conv2d_relu_avgpool_opt opt)
{
    uint16_t inHeight , inWidth, inChannel, outHeight, outWidth, outChannel, kernelHeight, kernelWidth, stride,pad ;
    tExecutorRpcWork  * execRpcWork;
    uint16_t inArraySize, weightArraySize, biasArraySize, outArraySize;
    int index = 0;
    //uint64_t start_ms, stop_ms;
    //Make sure to change their types
    shMemBufPtr dspInArray = 0;
    shMemBufPtr dspWeight = 0;
    shMemBufPtr dspBias  = 0;
    shMemBufPtr  dspOutArray = 0;
    // find sizes of all of the arrays using the info present in opt
    stride = 1;
    pad = 0 ;
    kernelHeight = 3;
    kernelWidth = 3;
    inHeight = opt.in_rows;
    inWidth =  opt.in_cols;
    inChannel = opt.in_depth;
    outHeight = ((inHeight - kernelHeight) + 2*pad )/stride +1;
    outWidth = ((inWidth - kernelWidth )+ 2*pad )/stride+1;
    // Adjust for average pool. take care of rounding  as per suggestion from NN experts. right now round up.
    outHeight = DIV_ROUND_UP(outHeight,2);
    outWidth =  DIV_ROUND_UP(outWidth,2);
    outChannel = opt.num_filt;
    // allocate memory from the shared memory
    inArraySize = inHeight*inWidth*inChannel;

#ifdef DYNAMIC_MAPPING
    dspInArray = (shMemBufPtr)pvPortMalloc( inArraySize* (sizeof (dspInArray[0])));
#else
    dspInArray = (shMemBufPtr)SharedMemAlloc(inArraySize * (sizeof(dspInArray[0])));
#endif

    //ecm35xx_printf(" dspInArray [%d]\r\n", inArraySize);
    if ( ! dspInArray)
        ecm35xx_printf("No memory for  dspInArray...\r\n");
    weightArraySize = kernelHeight*kernelWidth*inChannel *outChannel;

#ifdef DYNAMIC_MAPPING
    dspWeight = (shMemBufPtr)pvPortMalloc(weightArraySize* (sizeof (dspWeight[0])));
#else
    dspWeight = (shMemBufPtr)SharedMemAlloc(weightArraySize * (sizeof(dspWeight[0])));
#endif
    // ecm35xx_printf(" dspWeight [%d]\r\n", weightArraySize);
    if ( ! dspWeight)
        ecm35xx_printf("No memory for  dspWeight...\r\n");
    biasArraySize = outChannel;
#ifdef DYNAMIC_MAPPING
    dspBias = (shMemBufPtr)pvPortMalloc(biasArraySize* (sizeof (dspBias[0])));
#else
    dspBias = (shMemBufPtr)SharedMemAlloc(biasArraySize * (sizeof(dspBias[0])));
#endif
    // ecm35xx_printf(" dspBias [%d]\r\n", biasArraySize);
    if ( ! dspBias)
        ecm35xx_printf("No memory for  dspBias...\r\n");
    outArraySize = outHeight * outWidth * outChannel;
#ifdef DYNAMIC_MAPPING
    dspOutArray = (shMemBufPtr)pvPortMalloc(outArraySize*  (sizeof (dspOutArray[0]))); // Packing Dma not working now. So keep space for 16 bit data
#else
    dspOutArray = (shMemBufPtr)SharedMemAlloc(outArraySize * (sizeof(dspOutArray[0]))); // Packing Dma not working now. So keep space for 16 bit data
#endif
    //  ecm35xx_printf(" dspOutArray [%d]\r\n",outArraySize);
    if ( ! dspOutArray)
        ecm35xx_printf("No memory for  dspOutArray...\r\n");
    // Convert all into DSP understandable form

    HWCq7_to_CHWq15((int8_t *) inArray, dspInArray, inHeight, inWidth, inChannel);
    //TBD:  this we can eliminate when compiler puts the kernel in the same format

    //  start_ms = HalTmrRead(0);
    reorder_conv2d_kernel( ( int8_t* ) wt, dspWeight, kernelHeight,kernelWidth, inChannel, outChannel);
    // stop_ms =  HalTmrRead(0);
    // ecm35xx_printf("weight time= %d ms\r\n", (uint32_t) (stop_ms - start_ms));
    // Bias  nothing to convert.. right now converting to int6_t. remember to remove it.
    for ( index =0; index<outChannel; index++){
        dspBias[index] = (int8_t) (bias[index]);
    }
    execRpcWork = SharedMemAlloc(sizeof(tExecutorRpcWork));
    if (!execRpcWork) {
        //TBD: Add trace message of error
        return -1;
    }
    // Fill in the shared data structure with DSP
    execRpcWork->status = -1;
#ifdef DYNAMIC_MAPPING
    (execRpcWork->inbuf).ahbAddrHi = GET_HIGH_16(dspInArray);
    (execRpcWork->inbuf).ahbAddrLo = GET_LOW_16(dspInArray);
    (execRpcWork->outbuf).ahbAddrHi = GET_HIGH_16(dspOutArray);
    (execRpcWork->outbuf).ahbAddrLo = GET_LOW_16(dspOutArray);
    (execRpcWork->weight).ahbAddrHi = GET_HIGH_16(dspWeight);
    (execRpcWork->weight).ahbAddrLo = GET_LOW_16(dspWeight);
    (execRpcWork->bias).ahbAddrHi = GET_HIGH_16(dspBias);
    (execRpcWork->bias).ahbAddrLo = GET_LOW_16(dspBias);
    (execRpcWork->inbuf).mapped = 0;
    (execRpcWork->outbuf).mapped = 0;
    (execRpcWork->weight).mapped = 0;
    (execRpcWork->bias).mapped = 0;
#else
    (execRpcWork->inbuf).mapped = 1;
    (execRpcWork->outbuf).mapped = 1;
    (execRpcWork->weight).mapped = 1;
    (execRpcWork->bias).mapped = 1;
    (execRpcWork->inbuf).offset = SharedMemGetOffset(dspInArray);
    (execRpcWork->outbuf).offset = SharedMemGetOffset(dspOutArray);
    (execRpcWork->weight).offset = SharedMemGetOffset(dspWeight);
    (execRpcWork->bias).offset = SharedMemGetOffset(dspBias);
#endif
    (execRpcWork->inbuf).size= inArraySize;
    (execRpcWork->outbuf).size= outArraySize;
    (execRpcWork->weight).size= weightArraySize;
    (execRpcWork->bias).size= biasArraySize;
    memcpy (&((execRpcWork->params).convReluPoolParams),&opt,sizeof(conv2d_relu_avgpool_opt));
    // submit work
        rpcSubmitWork(RPC_MODULE_ID_EXECUTOR, EXEC_OP_DSP_CHW_3X3_CONV2D_RELU_AVGPOOL_Q7, (void*)execRpcWork);
    // work for wait to get over from DSP
    //ecm35xx_printf(" Submitted to DSP \r\n");
    // start_ms = HalTmrRead(0);
    xSemaphoreTake(execDspRespSem, portMAX_DELAY);
    //stop_ms =  HalTmrRead(0);
    // ecm35xx_printf("DS time= %d ms\r\n", (uint32_t) (stop_ms - start_ms));

    if (  execRpcWork->status == 0)
        CHWq15_to_HWCq7( dspOutArray, outArray, outHeight, outWidth, outChannel);
    // check status // convert back out buffer
    //TBD remove it
    g_outHeight = outHeight;
    g_outWidth  = outWidth;
    g_outChannel = outChannel;
    // Free all shared memory pointers
#ifdef DYNAMIC_MAPPING
    vPortFree(dspInArray); vPortFree(dspWeight); vPortFree(dspBias); vPortFree(dspOutArray);
#else
    SharedMemFree(dspInArray); SharedMemFree(dspWeight); SharedMemFree(dspBias); SharedMemFree(dspOutArray);
#endif
    SharedMemFree(execRpcWork);

    // Get back  to caller
    return EXEC_STATUS_OK;
}
#endif
