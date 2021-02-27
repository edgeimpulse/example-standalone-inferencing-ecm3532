#include "executor_public.h"

DECL_CONST_INT_ROM(pbuf_1_1,72);
DECL_CONST_INT_ROM(pbuf_1_2,8);
DECL_CONST_INT_ROM(pbuf_3_1,1152);
DECL_CONST_INT_ROM(pbuf_3_2,16);
DECL_CONST_INT_ROM(pbuf_6_1,2496);
DECL_CONST_INT_ROM(pbuf_6_2,3);

DECL_BUF_M3_PERSISTENT(pbuff0,637);
DECL_BUF_M3_PERSISTENT(pbuff1,5096);
DECL_BUF_M3_PERSISTENT(pbuff2,1400);
DECL_BUF_M3_PERSISTENT(pbuff3,2800);
DECL_BUF_M3_PERSISTENT(pbuff4,832);
DECL_BUF_M3_PERSISTENT(pbuff5,832);
DECL_BUF_M3_PERSISTENT(pbuff6,3);
DECL_BUF_M3_PERSISTENT(out0,3);
DECL_BUF_M3_PERSISTENT(inp0,637);

DECL_BUF_M3_SCRATCH(pbuf_1_4,18);
DECL_BUF_M3_SCRATCH(pbuf_3_4,144);


void infer(q7_t *pIn0, q7_t *pOut0) { 

EXEC_ALLOC_MEM(inp0);
memcpy(GET_BUFF_ADDR(inp0), pIn0, NUM_BYTES(inp0));

EXEC_ALLOC_MEM(pbuff0);
WAIT_4_COMPLETION();
memcpy(GET_BUFF_ADDR(pbuff0), GET_BUFF_ADDR(inp0), NUM_BYTES(inp0));
EXEC_FREE_MEM(inp0);
EXEC_ALLOC_MEM(pbuff1);
conv2d_opt opt1 = { 
.in_rows = 49, .in_cols = 13, .in_depth = 1, .num_filt = 8, 
.filt_rows = 3, .filt_cols = 3, .row_pad = 1, .col_pad = 1, 
.row_stride = 1, .col_stride = 1, .bias_lshift = 4, .out_rshift = 6,
.out_rows = 49, .out_cols = 13,.act_min = 0, .act_max = 127 };

EXEC_ALLOC_MEM(pbuf_1_4);
EXEC_MAP_ROM(pbuf_1_1); EXEC_MAP_ROM(pbuf_1_2);
Exec_conv2d_q7(EXEC_HW_ID_M3, &pbuff0, &pbuf_1_1, &pbuf_1_2, &pbuff1, &pbuf_1_4, &opt1);
EXEC_UNMAP_ROM(pbuf_1_1); EXEC_UNMAP_ROM(pbuf_1_2);

EXEC_FREE_MEM(pbuff0);
EXEC_ALLOC_MEM(pbuff2);
pool2d_opt opt2 = { .in_rows = 49, .in_cols = 13, .in_depth = 8, .filt_rows = 2, .filt_cols = 2, .row_pad = 0, 
.col_pad = 0, .row_stride = 2, .col_stride = 2, 
.out_lshift = 0, .out_rows = 25, .out_cols = 7,.act_max = 117, .act_min = 0};

Exec_maxpool_q7(EXEC_HW_ID_M3, &pbuff1, &pbuff2, &opt2);

EXEC_FREE_MEM(pbuff1);
EXEC_ALLOC_MEM(pbuff3);
conv2d_opt opt3 = { 
.in_rows = 25, .in_cols = 7, .in_depth = 8, .num_filt = 16, 
.filt_rows = 3, .filt_cols = 3, .row_pad = 1, .col_pad = 1, 
.row_stride = 1, .col_stride = 1, .bias_lshift = 5, .out_rshift = 8,
.out_rows = 25, .out_cols = 7,.act_min = 0, .act_max = 127 };

EXEC_ALLOC_MEM(pbuf_3_4);
EXEC_MAP_ROM(pbuf_3_1); EXEC_MAP_ROM(pbuf_3_2);
Exec_conv2d_q7(EXEC_HW_ID_DSP, &pbuff2, &pbuf_3_1, &pbuf_3_2, &pbuff3, &pbuf_3_4, &opt3);
EXEC_UNMAP_ROM(pbuf_3_1); EXEC_UNMAP_ROM(pbuf_3_2);

EXEC_FREE_MEM(pbuff2);
EXEC_ALLOC_MEM(pbuff4);
pool2d_opt opt4 = { .in_rows = 25, .in_cols = 7, .in_depth = 16, .filt_rows = 2, .filt_cols = 2, .row_pad = 0, 
.col_pad = 0, .row_stride = 2, .col_stride = 2, 
.out_lshift = 0, .out_rows = 13, .out_cols = 4,.act_max = 101, .act_min = 0};

Exec_maxpool_q7(EXEC_HW_ID_M3, &pbuff3, &pbuff4, &opt4);

EXEC_FREE_MEM(pbuff3);
EXEC_ALLOC_MEM(pbuff5);
WAIT_4_COMPLETION();
memcpy(GET_BUFF_ADDR(pbuff5), GET_BUFF_ADDR(pbuff4), NUM_BYTES(pbuff4));
EXEC_FREE_MEM(pbuff4);
EXEC_ALLOC_MEM(pbuff6);
fc_opt opt6 = { 
.filt_rows = 3, .filt_cols = 832, .bias_shift = 4, .out_shift = 7, .input_length = 832,
.act_min = -99, .act_max= 81};

EXEC_MAP_ROM(pbuf_6_1); EXEC_MAP_ROM(pbuf_6_2);
Exec_fully_connected_q7(EXEC_HW_ID_M3, &pbuff5, &pbuf_6_1, &pbuf_6_2, &pbuff6, &opt6);
EXEC_UNMAP_ROM(pbuf_6_1); EXEC_UNMAP_ROM(pbuf_6_2);

EXEC_FREE_MEM(pbuff5);
EXEC_FREE_MEM(pbuff6);
WAIT_4_COMPLETION();
EXEC_ALLOC_MEM(out0);
memcpy(pOut0, GET_BUFF_ADDR(out0), NUM_BYTES(out0));
EXEC_FREE_MEM(out0);
}
