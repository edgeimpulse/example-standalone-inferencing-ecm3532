#include "executor_public.h"

DECL_CONST_INT_ROM(pbuf_0_1,35);
DECL_CONST_INT_ROM(pbuf_0_2,5);
DECL_CONST_INT_ROM(pbuf_1_1,20);
DECL_CONST_INT_ROM(pbuf_1_2,4);

DECL_BUF_M3_PERSISTENT(pbuff0,5);
DECL_BUF_M3_PERSISTENT(pbuff1,4);
DECL_BUF_M3_PERSISTENT(out0,4);
DECL_BUF_M3_PERSISTENT(inp0,7);



void infer(q7_t *pIn0, q7_t *pOut0) { 

EXEC_ALLOC_MEM(inp0);
memcpy(GET_BUFF_ADDR(inp0), pIn0, NUM_BYTES(inp0));

EXEC_ALLOC_MEM(pbuff0);
fc_opt opt0 = { 
.filt_rows = 5, .filt_cols = 7, .bias_shift = 2, .out_shift = 7, .input_length = 7,
.act_min = 0, .act_max= 127};

EXEC_MAP_ROM(pbuf_0_1); EXEC_MAP_ROM(pbuf_0_2);
Exec_fully_connected_q7(EXEC_HW_ID_M3, &inp0, &pbuf_0_1, &pbuf_0_2, &pbuff0, &opt0);
EXEC_UNMAP_ROM(pbuf_0_1); EXEC_UNMAP_ROM(pbuf_0_2);

EXEC_FREE_MEM(inp0);
EXEC_ALLOC_MEM(pbuff1);
fc_opt opt1 = { 
.filt_rows = 4, .filt_cols = 5, .bias_shift = 0, .out_shift = 6, .input_length = 5,
.act_min = -109, .act_max= 18};

EXEC_MAP_ROM(pbuf_1_1); EXEC_MAP_ROM(pbuf_1_2);
Exec_fully_connected_q7(EXEC_HW_ID_M3, &pbuff0, &pbuf_1_1, &pbuf_1_2, &pbuff1, &opt1);
EXEC_UNMAP_ROM(pbuf_1_1); EXEC_UNMAP_ROM(pbuf_1_2);

EXEC_FREE_MEM(pbuff0);
EXEC_FREE_MEM(pbuff1);
WAIT_4_COMPLETION();
EXEC_ALLOC_MEM(out0);
memcpy(pOut0, GET_BUFF_ADDR(out0), NUM_BYTES(out0));
EXEC_FREE_MEM(out0);
}
