#define W_IN 4 
#define H_IN 4 
#define CH_IN 2 
#define NUM_KER 1 
#define DIM_OUT 1


int chess_storage(XMEM) x[32] = {
-1,2,-3,4,5,-6,7,-8,9,10,-11,12,13,-14,15,-16,1,2,3,4,5,6,7,8,9,10,-11,12,13,-14,15,-16,
};

int chess_storage(YMEM) w[18] = {
1,2,3,4,5,6,7,8,9, 0,1,2,-3,4,-5,6,7,8
};

int chess_storage(YMEM) bias[1] = {
-5,
};

int bias_shift = 0;
int out_shift = 0;
int output_activation_min = 0;
int output_activation_max = 127;

int expected_output[DIM_OUT] = {
82
};

