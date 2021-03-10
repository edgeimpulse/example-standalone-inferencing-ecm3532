#define W_IN 32 
#define H_IN 24 
#define CH_IN 3 
#define NUM_KER 1 
#define DIM_OUT 165

int chess_storage(XMEM) x[2304] = {
8, 7, -4, 2, 3, -10, -9, -3, 11, 3, 1, 5, 0, -12, -8, 4, -6, -2, 11, -7, -8, -1, -5, -2, -2, -1, -8, -7, 5, -5, 6, -9, -8, -6, -11, -6, -2, 8, -2, -10, 4, 5, 5, -7, -1, -10, 6, 1, 9, -7, -4, -10, 1, 2, -4, 5, 9, -6, -11, 2, 6, 2, -6, 4, -9, 4, -8, -10, 5, 5, -4, -8, 7, 3, 5, 10, 10, 1, -5, 3, 2, -11, -6, 10, 2, -4, 0, 8, -7, -7, 7, -5, -8, 1, 5, 11, 7, -5, 9, 1, 3, -12, -10, -3, 7, -3, 1, -8, -1, -2, -3, 3, -12, -2, -4, -5, -12, -2, 11, 4, -12, 4, -9, -6, -3, -11, 2, -7, 8, 4, 5, -3, 8, 5, -6, -12, -9, -12, 5, 5, -7, -12, 11, -4, 8, 3, -4, -7, 0, 4, -1, -11, -9, -1, -8, -6, -10, 3, 5, 5, -2, 6, 3, 7, 1, 1, -12, 7, 9, -7, -6, -11, -5, -11, -1, -1, -11, 3, 7, 3, -3, -3, -12, 5, -12, 3, -7, -5, -7, 5, 8, 0, -8, -6, 3, -6, 7, 3, 1, 4, 9, -1, 5, 9, -10, 1, 4, 11, -2, 6, 10, 5, 11, -1, 8, 8, -9, 11, 6, 11, 3, -5, -7, 2, -8, -3, 1, 10, -3, 8, -2, 7, -10, 1, 11, -10, 2, -5, -12, -7, 6, -1, -7, 2, -2, -12, -11, 2, 1, 6, -12, -4, 5, 4, -6, 4, 1, 9, -12, 1, -8, 4, -8, -2, -10, 0, 7, -12, 0, 4, 0, 9, 8, -6, 9, -8, 9, -3, 2, 4, -3, 10, -10, 3, 3, -6, 8, 6, 2, -10, -9, -10, 5, -4, 1, -8, 2, -12, -11, -4, -6, 8, 3, 9, -6, -10, 5, -6, 0, -1, 11, -7, 3, -4, -9, -8, 3, 7, 10, -8, 9, -11, -4, 2, -3, 11, -3, 7, 9, -9, -1, 10, 11, -3, 6, 9, -2, 0, -3, -6, 10, -4, 1, -12, 10, -4, 10, -12, 7, -8, -11, -4, 11, 5, 9, 8, 7, 7, 10, -5, -5, 5, 3, 1, 8, 1, 11, 5, 0, -7, -6, 3, -3, 1, 5, -10, -4, 10, 1, 8, -6, -8, -9, -1, 5, -5, -6, -2, 6, -9, -5, -12, 2, -8, 6, 11, 11, 3, 3, 4, -1, -11, -5, -1, -3, -9, 1, -1, 0, 5, -5, -11, -1, 9, -4, -5, -3, -6, 2, 7, -5, 3, -7, 3, 0, -6, 7, -9, -7, 8, 7, -8, 4, -2, -11, -2, -4, -11, 8, -11, -10, 0, 8, 3, 10, 10, -12, -1, -10, -3, -4, -4, 0, 1, -4, -11, 1, 10, 10, 1, 6, 9, -11, 0, 6, 11, -12, -6, -7, -9, 1, 11, 4, -2, 3, 9, 6, 11, -12, -9, 3, -1, -11, 1, 8, -2, -5, -10, -9, 10, 1, -2, 3, 2, -11, 0, 4, -6, -9, -5, -7, 5, 5, -7, -2, -11, 5, -7, 11, -9, 0, 10, 3, -1, 3, -6, -2, -6, 8, 9, -7, 4, -6, -9, -5, -12, -3, -2, -10, 6, -10, 11, 7, 7, 6, 6, -10, -11, -11, 0, 6, 3, -3, 10, 8, -10, 10, 8, -4, 10, -4, -1, 3, -6, 4, 0, -10, -9, 1, 10, -5, -6, -5, 7, -12, -12, -2, 2, -2, -12, 10, 9, -7, 10, -1, -12, -10, -9, 9, 1, -6, -6, -5, -3, 6, -6, 5, -8, 7, 9, 6, -2, 7, -12, 7, 8, 4, -6, -7, 11, -8, 9, -8, 9, -5, -2, 3, 7, 7, -10, -11, -8, -7, -7, -6, 8, -7, -9, 9, -10, 10, 5, -9, -3, -4, -1, 7, -5, -1, -3, -6, 3, -4, -4, -5, -3, -7, 2, 5, 3, 6, -12, 1, 3, 8, 3, -4, -12, 2, 8, 2, -12, 5, -8, -2, -10, -4, 4, 5, 6, -10, 0, 5, -2, -2, -5, 4, 0, -4, -7, 7, 2, 5, 5, -11, 11, -1, -11, 10, -6, -2, -8, 8, -8, -7, -1, 9, 11, 2, -5, 8, -12, 6, -7, 2, 3, -1, -5, -5, 0, 8, 2, -1, -12, -5, 1, 1, -2, -3, 6, 6, 3, -5, 8, 7, -2, 4, 5, -12, -1, 5, -2, -8, -7, -10, 0, 9, -5, -5, -5, 1, 0, -4, 1, -3, -10, 1, 11, 2, -4, -8, 5, -12, -7, -3, 9, -1, -6, -2, -12, 11, -11, -6, -3, -11, 11, -6, 10, -9, -9, 10, 6, -6, -10, 10, -7, 11, -5, -8, 11, 2, -8, 2, -1, 4, 2, 5, -2, 4, 1, -2, 4, -6, -5, 5, -12, -8, 10, 9, -1, 0, -9, 5, -2, -12, 6, 6, 8, -7, 4, 8, -12, 8, 6, -3, 1, 4, -12, -1, -7, -10, -7, -8, 1, -3, 5, 7, 6, 8, -5, -11, -5, -8, -6, -6, -3, -2, 9, 4, -8, 3, -7, -8, -12, -9, -1, -8, -5, 7, -4, 10, 10, -11, -3, -6, 6, 6, -6, -10, 7, 11, 1, 1, -2, -7, -9, 5, 5, -2, -1, -9, -11, -3, -3, 8, -10, 3, 5, 1, 11, -9, -5, 7, -12, -6, -1, -2, -12, -5, 3, 6, -1, 5, -5, 4, -4, -7, -6, 5, 8, -3, 5, -11, -11, -7, 3, -11, 5, -2, 10, 1, -11, 8, 11, 6, -4, -1, 5, -7, 4, -10, 0, 1, 9, 4, 9, 10, 1, -2, -5, -6, 5, 5, -5, 9, -2, -3, 8, -12, -3, 8, -4, 4, 9, -8, 1, 4, -4, -1, -7, -11, -7, -10, -3, 0, -1, -4, 6, 1, 2, -10, -4, -11, -4, 0, 4, 8, -2, -4, 3, 4, -5, -6, 2, 11, -4, -1, -7, 10, -5, 6, 5, -12, 9, -4, -2, 11, -9, -2, -12, 3, -9, 8, 4, 2, -7, -11, 3, 11, -3, 7, 4, -6, 5, 5, 5, 9, -2, -6, 5, 5, 11, 4, -4, 2, 5, -7, 7, -6, 10, -11, -3, 11, -2, 4, 11, -12, -5, 1, -5, 7, 2, -4, 1, 2, 5, 6, -2, -10, 10, 6, -8, -7, -6, -10, -12, -11, 4, 3, -2, 11, -8, -3, 0, -7, -12, -2, -8, 7, -9, 5, -7, -10, 2, -8, 6, -5, -6, -4, 4, -8, 0, 2, 2, -9, 10, 7, -4, 9, -5, 1, 1, 3, -10, 11, -4, -10, 0, 9, 1, 1, -4, 7, -8, -2, -9, -4, -12, 11, 10, 11, -2, 9, 11, -8, -9, -10, -9, -6, 0, -1, 9, -6, 1, -10, 5, 6, 4, 10, 9, 11, 3, 11, -10, 2, -10, 0, 1, -11, 0, 11, -7, 5, 6, -8, -6, -9, 1, 8, -10, -8, -1, -12, -10, 0, 5, -6, 2, 9, 9, 10, 2, -3, 7, 3, 11, -11, -3, -11, -7, 8, -10, -10, -8, 11, -6, 5, -12, 8, -11, -3, 6, -8, -1, 5, 1, -4, 11, 0, -3, -9, -6, 9, 7, -12, -5, 2, 5, -6, -4, 8, -12, -4, 8, -7, 7, -11, -9, 1, -2, -5, 2, 4, 11, -1, 11, -12, -5, -3, 9, 2, 3, -9, -2, 11, 2, 9, 7, 1, -12, -10, 9, -11, 9, -8, 3, 7, 0, -4, -4, -2, -9, -8, 8, 7, 8, 7, -8, -3, 4, 5, -7, -11, -3, -12, -2, -2, -4, -9, -9, 3, -9, -10, 9, 2, -8, -6, 8, 1, -10, -11, 0, 4, -1, 11, 3, 10, -11, -8, 5, 9, -5, 9, -5, 9, 4, -11, -9, 10, 8, 8, -5, -11, -8, 4, -5, -9, -6, -8, 8, -10, -9, -5, -12, 4, -10, -5, -8, 10, -12, 2, 4, 6, -7, -5, 4, -9, 4, 4, -4, 6, -9, -7, 7, 11, 5, 8, -12, -9, -12, 2, -5, 10, -3, -2, 0, 8, -11, -6, -8, 9, -10, 6, -4, 1, -10, 4, 10, 4, 2, 11, 11, 11, 8, 6, -6, 1, 8, -3, 4, -3, -7, 9, 9, -2, -1, -8, -10, -6, 8, -4, -9, -4, 1, 2, -3, -12, -12, -10, -7, 10, -5, 11, -6, 10, -10, 8, -9, -4, 11, -9, -11, -1, 3, -6, 9, 5, -11, 8, -2, 6, 4, 4, -2, -3, -11, -12, 5, 11, -3, -6, 2, -6, -10, 1, -1, -1, -5, -11, -10, 2, -6, 2, 10, 2, 7, 4, 1, 5, -12, 1, -3, -1, 3, 1, -11, -8, -6, -4, -1, 9, -3, 5, 3, -7, 11, 3, 3, 1, -3, -4, -1, -1, -2, 6, -6, -8, 2, -1, 4, -6, -6, -5, 11, 0, 5, -1, -5, -5, -9, 1, -5, -3, -12, -1, -4, 4, 8, -9, -3, 1, -7, 6, 1, 3, -8, -9, -2, 2, -6, 8, 9, 3, -3, -5, -1, -7, -8, 8, 5, -8, 0, 1, 5, -2, -4, -6, 4, -9, -10, 5, -11, 9, -11, 11, -1, 2, 8, -1, 2, 3, 10, -4, -2, -3, 3, -4, -11, -2, -6, 11, 1, -6, -10, -7, -7, -2, 3, 5, 0, 0, -2, 5, 9, 1, -7, -4, -5, 11, -4, -12, -7, 6, -5, -6, 2, -10, -4, -4, -5, 11, 6, 9, 8, -11, -5, -12, 2, -1, 11, -3, -8, 1, 5, 9, 6, 6, -12, -8, -10, -12, -3, -5, 2, -2, -1, 1, -1, -8, -7, 6, 6, -8, 11, -12, 1, -10, -10, -10, 3, 9, -4, 4, -1, 2, -9, 5, -10, 5, -10, -1, 0, 7, 8, -11, 4, -6, 5, -3, 4, -10, 1, -4, 11, 2, 5, 3, -10, -8, 6, -8, 0, -7, 6, 7, -9, 9, -2, -7, -8, 10, 2, 4, 2, 2, -1, 8, 9, -3, -1, -9, -6, 3, 3, -7, 5, -1, 1, 6, 1, 3, -1, 1, -10, -12, -9, 10, 1, 8, -7, -11, -8, 11, -8, 3, 9, -12, 11, -2, -12, -10, 4, 7, -2, -2, -7, 5, 1, -11, 5, -6, 11, -4, 11, 11, -5, 1, 11, -1, 0, -4, -8, 10, -10, 9, 7, 5, -1, -12, -4, 6, -4, 2, -11, 8, 8, -6, 9, 0, 5, -11, 5, 11, 7, 10, 2, 2, -11, 5, 3, -8, 1, -5, -10, 8, 2, 4, 6, -11, 2, -2, -8, 5, 2, -11, 7, 10, 11, 11, 8, -8, -5, 6, 4, 3, -10, -11, -9, -5, -1, 1, -7, 0, 2, -11, 2, -5, -4, 6, -9, 5, -10, -9, 1, -9, -7, 4, 10, -12, 0, 11, 3, -11, -1, 11, -3, -8, 4, -2, 4, 5, 0, -5, -8, 10, 4, -9, 3, 4, 4, -1, 11, -8, -8, -6, -7, -4, 2, 0, -10, 5, 9, 10, -2, 10, 6, -3, -5, 9, 5, -7, -6, -10, 2, 11, 8, 4, -6, 3, -7, -1, -2, -4, 0, -10, 1, 8, 2, -5, -1, 5, 9, 10, 0, -5, -1, -10, 9, 10, 1, 11, -4, -2, 9, 1, 3, -8, 5, -4, -1, 2, 5, -8, -11, -4, -8, 2, -11, 7, -3, -1, 11, -9, -2, -8, 8, -9, 2, -5, 6, 7, -6, 7, -3, -10, -6, -7, 7, 2, 9, -10, -1, 4, 5, -12, 6, 7, 11, -1, 1, 5, 3, 0, -1, 0, 1, 0, -4, -11, 2, -2, 0, 3, -2, -7, 1, -10, -12, -1, -2, -4, 11, -10, 7, -11, -1, 0, 11, -5, 8, 5, -6, 5, -3, -5, 9, 1, -10, -11, 7, 9, 5, -9, 4, 3, 10, 0, 11, -1, -1, -6, -6, -2, -1, 3, -12, -2, 3, 10, -3, -5, 1, 6, 5, -12, 2, -4, -2, 5, 11, 5, -9, 2, 5, 6, 6, 1, 9, -8, -9, -6, 9, 1, 8, -10, -10, -12, 5, 4, 1, 6, -3, -9, -8, 7, 9, -12, -2, 0, -8, -6, 1, -10, -8, 4, -7, -8, -1, -12, -1, -11, -10, -3, -3, -6, -11, -6, 4, 9, 3, -5, 5, 0, 0, 7, 10, -5, -8, 9, 3, -11, 3, -9, -8, 4, 0, 2, -12, -4, 10, -5, -4, 1, -3, -7, -8, 10, -3, 2, 0, 1, -1, -9, 0, 8, 9, -9, -3, 1, -12, -11, 8, 3, 11, -8, 11, 5, -1, -2, 0, -8, -3, 1, 11, -5, -1, 4, 7, -7, 1, 10, -9, -7, -8, -8, 0, 1, 7, 10, 9, -3, -1, -10, -6, 10, -6, -10, -7, 8, -8, -3, 10, 4, -2, -7, 1, 3, -9, -2, -7, 8, -10, -10, 7, -11, -8, -4, 9, 3, 7, -4, -10, -10, 3, 8, 5, 0, -7, -10, 1, -4, 3, -12, -9, 6, 6, 8, 10, -2, -7, 3, -4, -10, 6, 9, -8, -7, 3, -4, -12, 11, -12, 9, -6, -12, -5, 1, -3, 1, 3, -6, -6, 5, 3, -7, -11, -4, 10, 6, 6, 5, -8, -12, 8, -7, -11, -5, -5, 1, 3, 5, 0, -9, 6, -6, 0, -4, 5, 6, -1, -1, 10, -1, -10, 10, 8, -2, -3, -8, -7, -1, -4, -4, -12, -1, -6, 0, 1, 1, 0, 6, 0, 6, -11, -1, -9, 10, -10, -4, 6, -6, 9, 11, -2, -9, -6, 1, 7, -10, -8, -5, -1, -11, 9, -12, 6, 5, 3, -4, -11, 7, -6, 7, -4, 4, 9, -2, 7, -10, 5, 9, -11, -12, -9, -5, -4, -5, -3, -10, 10, 0, 6, 0, 0, -7, -1, -4, -9, 4, -5, -8, -6, -11, 7, -8, -9, -1, 10, -1, 3, 11, 0, 9, -7, -7, 10, -3, -1, 4, -12, 11, 6, -7, -7, -4, 11, 10, -2, 6, -1, -1, 7, -8, -11, -1, -1, -7, 4, 6, 7, -8, -2, -7, -10, -5, -10, -1, 1, -8, 6, -12, 3, 0, 0
};

int chess_storage(YMEM) w[27] = {
-5, 2, -4, -1, 4, -2, -5, 1, 3, 5, 1, -6, 3, -5, 5, -6, 3, 0, 2, -5, 1, 4, 5, -5, -2, 2, -2
};

int chess_storage(YMEM) bias[1] = {
-2
};

int bias_shift = 0;
int out_shift = 0;

int output_activation_min = 0;
int output_activation_max = 32767;

int expected_output[165] = {
14, 68, 59, 74, 40, 30, 82, 60, 14, 52, 32, 32, 58, 25, 83, 76, 32, 50, 29, 118, 46, 18, 88, 67, 3, 54, 37, 96, 123, 24, 32, 86, 36, 135, 44, 55, 53, 67, 53, 43, 78, 62, 48, 82, 42, 17, 48, 64, 24, 18, 86, 56, 50, 82, 28, 40, 38, 36, 20, 31, 9, 57, 8, 108, 74, 85, 41, 5, 88, 69, 14, 19, 36, 56, 54, 83, 20, 66, 46, 22, 0, 46, 14, 26, 68, 103, 58, 67, 68, 70, 36, 79, 56, 34, 65, 42, 0, 71, 3, 66, 82, 32, 114, 18, 15, 66, 57, 19, 35, 104, 24, 56, 74, 26, 64, 112, 52, 20, 44, 22, 91, 20, 48, 0, 34, 98, 57, 71, 43, 41, 67, 61, 60, 107, 22, 2, 36, 70, 34, 99, 57, 53, 86, 31, 32, 35, 49, 82, 66, 12, 30, 34, 117, 29, 55, 8, 36, 68, 78, 10, 64, 88, 0, 78, 23
};

