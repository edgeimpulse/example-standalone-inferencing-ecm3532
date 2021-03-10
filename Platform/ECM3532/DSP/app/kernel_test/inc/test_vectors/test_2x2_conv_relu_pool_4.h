#define W_IN 11 
#define H_IN 15 
#define CH_IN 20 
#define NUM_KER 40 
#define DIM_OUT 1400

int chess_storage(XMEM) x[3300] = {
8, 9, 4, -8, -5, -12, 4, 4, -5, 6, -4, 10, 2, 4, -11, 3, 1, -1, -12, 7, -11, -7, 10, 5, -2, 11, -7, -3, 5, -5, 9, 0, -9, 3, -11, 11, 6, -8, 2, -8, -10, -8, -3, 10, 0, -6, -8, -4, 9, 7, 9, 10, 0, -7, -5, -10, 2, -6, -9, 6, -1, 6, -12, -5, 1, 3, -10, -10, -9, 6, 0, -9, 3, 1, -5, -7, 3, -9, -7, -7, -9, 6, 4, -10, -5, -10, -7, -6, -10, -5, -8, 5, 4, 10, -9, -6, 6, -4, -3, -10, 11, -6, -2, 7, -7, 8, 0, 0, 5, 9, 10, -8, -8, -2, 10, 0, 7, 11, 10, -12, 4, 11, -1, -7, 3, 6, 2, -4, 1, 8, -3, 2, -11, -12, -5, 0, 11, 7, -8, 0, -10, 0, -4, 5, -1, -4, 0, -7, -2, -2, 10, -5, -3, 7, -2, 6, -8, 8, -3, -3, 11, 7, 6, -6, -1, -8, -3, 11, 9, -7, -7, -1, 1, -10, 4, -10, 6, -10, 8, -1, 1, -8, -7, 5, -7, 5, -7, -7, -4, -12, 7, 3, 1, -5, 8, 10, 11, -9, 11, 10, 4, -6, 2, -10, -10, -12, -7, 7, 6, 1, 9, -6, -3, 11, 7, 9, 10, -12, 2, 8, 5, 8, -11, -2, -1, 0, -1, 11, 1, -9, 1, 1, -1, -1, -3, -6, 3, 1, -10, 0, 10, -7, 0, 10, -2, 9, -9, 8, -7, 4, 2, 1, -6, -8, -12, -4, 7, 6, 11, -5, -1, 5, -12, 0, 1, 0, -8, -5, 11, 5, 2, -2, -5, -9, -5, -12, -2, -6, 7, 11, -5, 6, -2, -8, -10, -7, 1, 10, 9, -12, -4, -6, 9, -3, 10, -3, -11, -7, 0, -6, 11, -2, 5, -11, -2, 6, -4, 7, -4, -9, -1, 0, 8, 5, -12, -12, -8, -5, -11, 8, -1, 9, -10, 10, -5, -6, -7, 7, -8, -8, -10, 2, -8, 6, 6, -11, -10, 5, -4, -6, -1, 5, 9, -9, 5, -1, -1, -4, -12, 3, -6, 1, 9, -8, -6, 1, -1, 4, 4, 3, -11, -2, 8, 4, 5, 11, -9, 11, -6, -3, -12, 9, 8, 6, 1, -8, -4, -9, -9, -9, 6, 7, -10, 9, -10, 5, 5, 1, -6, 6, -2, -5, -4, 1, 11, -11, -12, 3, -4, -6, -2, 3, 2, 3, -11, -9, -5, 3, 4, 4, 6, -10, 0, 4, -4, -6, -1, 8, -3, 7, 1, 9, -6, -5, -1, -5, -2, -11, -2, 10, -6, -11, 5, -4, 2, -5, -1, 7, -1, -1, -3, 10, -7, -11, -1, 2, 11, 0, 0, -10, 3, 7, 8, -3, 7, 1, -11, -7, 9, -9, 9, 5, 5, -12, -10, -9, 10, -1, -2, 4, -4, 11, -3, 8, -7, 4, -1, -9, 7, -11, -6, 4, 0, 6, 9, 11, 8, -3, 5, -10, 4, 10, 2, 6, 3, 7, 8, -6, -1, 2, 8, 5, -1, -8, 2, 11, -11, -11, 2, -3, -12, -10, 5, 4, -2, 8, -12, -10, 5, 6, 7, -10, -3, 2, -6, -1, 2, 8, -5, -1, 4, -1, -8, -4, 4, 2, -3, 10, 0, 2, 8, -11, 7, -11, -3, -6, -4, -1, 5, 5, 7, -3, -8, 4, -8, -11, 5, -4, 3, 8, -9, 0, -8, -8, 9, 0, -10, -1, -3, 9, 5, 11, -5, 4, -8, -7, 3, -2, 6, -6, 3, 9, -6, 6, 11, 9, 3, 4, 5, 6, 2, -12, -12, 5, 0, -2, -5, -8, -4, 6, 2, 0, 1, -2, -7, -4, 5, -11, 5, 6, 0, -12, -1, 3, 10, 5, -10, 7, -9, -5, 2, -7, -7, -9, 6, 8, -7, 6, -1, 5, 7, -7, 2, -7, 3, -5, 7, -1, 10, 9, 6, -10, -6, -2, -3, 5, -8, 10, -5, -3, 6, 1, 1, 9, -5, 2, 11, -11, -2, -1, 11, 11, -3, -1, 5, 6, -7, 9, -1, -8, 5, -8, 7, -7, -9, 11, -1, -11, 8, 8, -6, 4, 0, 6, -3, 9, -8, 2, -7, -8, -5, -2, 5, -3, -3, 5, 10, 1, 5, 10, 0, -1, -9, 2, 11, -5, 0, -1, 10, 9, -10, 9, 7, -2, -10, 0, 5, -7, 6, -6, -3, 0, 5, -2, -7, 6, -12, -10, -11, 4, -7, -11, -10, -9, 1, 8, 11, -8, -12, -10, -3, -12, -4, 8, 2, -2, -4, 8, 7, 11, 11, 7, 5, -3, -1, -1, -12, 2, 6, -3, -4, -5, -9, 2, 9, -6, -3, -8, -10, -5, 11, -6, -2, -8, -4, -8, 0, 8, 5, -5, 6, -10, 11, 4, -5, -5, 6, -4, 10, -8, 4, -3, -6, -3, -9, -6, 7, 6, -1, 3, -5, 8, -11, 3, -8, -10, -9, 11, 7, 8, -1, -3, -8, -10, 3, 8, 0, 10, 5, 3, -8, 11, -6, -5, -4, -4, 5, 4, -12, 6, -6, -10, 7, 5, 5, -8, 10, -2, 5, 11, 1, -2, -5, 11, -11, -12, 11, 10, -6, 9, 4, -1, 6, 8, -6, -9, 11, 8, 10, 9, -10, 3, -12, 4, -5, -11, -8, 2, -5, -8, 5, -10, -8, 2, -10, 9, 11, 0, 8, -12, -6, -10, -10, 5, 11, 3, 2, -5, 9, -12, -2, -2, 7, -11, 4, -2, 9, -12, 10, 0, -3, -9, -6, 7, -9, 6, -7, 8, 0, 9, 1, -12, 10, -12, 8, -3, 5, 8, -5, -1, -3, -3, -8, -10, -10, -8, 11, 3, 4, 3, -3, -7, -2, 10, 2, -10, -2, -2, 11, 1, -7, -3, 10, 8, 2, 8, 7, 9, 5, 10, -8, -3, 1, 0, -10, -10, 7, -6, 11, -11, 9, 8, 6, 6, -10, -1, 2, -8, -1, -12, 6, -7, 11, -5, -12, -5, -3, 9, 6, 6, -6, 5, -10, -11, -2, 0, -5, 7, -5, 0, -4, -11, -5, -5, -2, 6, 5, 2, -6, -6, 2, -3, -6, 2, -3, -10, -12, -5, -9, -2, 11, 11, 9, -5, 3, 10, -3, -12, -11, 2, 5, -11, 4, -7, 11, -4, -7, -6, 1, -8, 11, 0, -10, -5, 2, 3, -4, -8, -4, -10, 1, 1, 0, 6, 3, -11, 7, -9, 3, -1, -5, -12, 8, -7, -10, -2, 8, 4, 8, -11, 7, 9, -11, -7, -5, 5, -8, -12, -6, -8, 7, -3, -7, -4, -5, 8, 9, -5, 9, -6, -8, -7, -2, -9, -6, 10, 1, -1, 3, 5, -9, 11, 8, 4, 1, -1, -7, 5, -8, -7, -2, -12, -1, 9, -6, 3, -5, 9, -1, 11, 7, 0, -3, 8, 2, -9, -5, 6, 4, 6, 6, 5, 9, -9, 9, 1, 11, -2, -3, -9, 9, -12, -2, 7, 1, 6, -9, 11, 2, -2, 9, 8, 7, -3, 2, 5, -12, 3, 11, 9, 10, -12, -9, -6, 2, 2, 3, -8, 0, -5, 6, -10, -7, 0, 3, 5, 0, 11, -7, -6, -9, -2, -8, -3, 4, 11, -10, 4, -4, 8, -7, 1, -10, 5, -5, 6, 6, -10, 7, 8, 0, -11, 6, 9, 6, 4, -2, 5, -10, -4, 1, -1, 11, 11, -9, -1, 11, -8, 0, -8, -7, -6, 8, -9, -6, -9, 5, -9, -5, 8, -3, -10, -3, -10, 5, -9, 3, -11, 10, -1, 8, -9, -3, 2, 6, -1, 2, 10, -10, 11, -12, 3, -4, 9, -12, -9, -10, -8, -6, -3, 10, 1, 8, 0, -4, -7, -1, 1, -5, -11, 8, 6, -6, 5, -5, 6, 11, -12, -2, -12, 4, 1, 9, 11, -9, -4, 11, -2, -12, 2, -6, -4, -1, 0, -6, 11, 10, 2, 11, -10, 9, 11, 0, 1, -10, 11, -4, 7, 5, -2, 11, -3, -11, -4, 11, 1, 4, -6, 11, 8, -1, 2, -8, 7, 2, 5, -1, -3, -9, -12, -4, -2, -6, -8, 8, -2, -10, 6, 9, -3, -5, 10, -7, 5, 7, 6, -12, -12, -2, 5, -9, -1, 1, -10, 0, -4, -11, -11, -2, 7, -5, -9, -9, -12, -2, 2, 4, -5, 1, 9, 4, 9, -5, -6, 2, -4, 0, 3, -5, -9, -2, -1, 1, 7, -1, 2, -4, -11, -12, 11, 10, 5, -3, -8, -5, -4, 0, 0, 1, 9, -4, 6, -4, -11, 4, 1, -6, -2, -7, 4, -10, 8, -11, -10, 3, 8, -10, -2, -12, 4, 1, -11, -7, 1, -5, -7, -8, -6, -4, -4, 2, -1, -4, 8, -1, -10, -8, 4, -1, 8, 1, 6, 3, -6, -8, -6, -4, 1, -4, 5, 8, -1, -3, -12, 7, 5, -8, 11, 11, 2, -5, -12, 3, 9, 10, 0, -9, -11, 2, -5, 1, -10, 8, -7, -11, -3, -12, 10, 2, -5, 4, 2, 8, 5, 4, 9, -12, -2, -9, 7, 1, 5, -7, -5, 1, 2, -5, 5, -2, -1, -3, -7, -9, -6, 4, 5, -6, 10, -1, 8, -3, -9, 4, -6, -7, 6, -4, 7, 9, 7, 2, 0, 5, 7, 11, 9, 2, 2, 2, -3, 2, 2, -7, 2, -2, 8, -7, 3, -1, -9, 9, -8, -2, 2, -6, -10, -12, 1, -8, 1, -1, 3, -1, 10, 5, -1, 2, -7, 3, -10, 11, 3, -7, 7, 0, 10, 2, 1, -8, 9, -7, 11, 4, -9, 0, 11, 10, 1, 1, 7, 5, -2, -3, -8, 10, 9, -11, -3, -3, 0, 2, 3, -6, -7, -2, -6, 0, -8, 9, 3, -12, -1, -2, -7, 10, -3, -7, -1, 1, -10, 8, -6, -4, -10, -8, 4, -9, 1, -6, -12, -11, 8, 10, 2, -11, 5, -1, 7, -5, 11, -4, 5, -4, -6, -6, -5, -11, -5, -11, -6, -7, 10, -8, 0, 3, 9, -4, 5, -5, 0, -8, -9, -4, 10, 11, -12, -3, -6, 5, 6, -8, 1, 1, -9, 6, -8, -7, -4, 7, -7, -4, -7, 1, 7, 3, -5, -3, 11, 5, 5, -4, 0, -1, 2, -4, -6, -5, -4, 8, 6, 5, 10, -9, 4, -2, -5, -3, -12, 10, -8, 0, -4, -7, -9, -2, 1, 11, -9, -2, -1, 4, 3, -11, 3, -1, -6, 5, -10, -5, -2, -6, -5, 2, 2, 7, -9, 9, -4, -3, -7, 1, -9, 0, 1, -9, -5, 0, 1, 4, -10, -10, -5, -4, -10, 11, 10, -12, -9, 6, 9, -11, -11, -12, 2, -6, -1, -3, 2, 6, -1, 7, -11, -5, 8, -12, 9, 6, -11, -11, 1, -7, 1, 11, -7, -7, -9, -5, -2, 5, 9, -7, 0, 7, -7, -6, -9, -5, -2, 11, -12, 1, -3, 4, 1, 7, -1, -6, 1, -11, 11, 3, -3, -4, -3, -8, 1, 9, 11, -2, 3, -7, -1, -12, 5, -12, 4, -5, -8, -9, 11, -4, 5, 6, -12, 0, -5, 4, -2, -10, -7, 8, 3, 8, -6, 4, 7, 1, -8, -2, -5, 1, -5, -2, -12, -2, -12, 0, -2, 3, 5, -1, 3, 2, -4, 3, -1, -2, 11, 0, -6, -5, 4, 1, 9, 5, 3, -3, -1, -4, -12, -1, 9, 7, 6, -6, 0, 1, -11, 7, -2, 9, 10, 7, 8, 3, -3, -6, -6, -9, -3, -11, -8, -4, 10, 3, -9, 11, 10, -8, -6, -12, -8, -6, 1, 4, -11, -8, -6, -9, 7, -3, -9, -7, -10, -6, 3, 8, -9, 3, -11, 2, -7, -4, 4, 6, -1, -11, -11, -9, -5, 10, 8, 5, 3, -1, 11, -1, 5, 10, 6, -8, -1, -6, -6, 5, 5, -2, -6, 3, -1, -5, 6, 2, 2, -4, -2, -7, -1, -3, 9, 5, -7, 10, 0, -10, -9, 1, 2, 10, -10, -6, -9, -3, -1, 8, 1, 11, 1, -5, 10, 9, -8, 1, 0, 1, -9, 1, -10, -4, 0, 3, -12, -12, -2, 1, 1, -1, 5, -3, -9, 3, 6, 2, 8, -10, 7, 10, -4, -3, 5, -4, 8, 5, -2, 1, 2, -1, -12, 10, -4, -10, -5, -7, -8, -8, 5, -2, -4, 5, -10, 4, -12, 3, -10, 10, -6, 2, -9, -3, -7, 5, 10, 0, -6, 8, 0, 11, 5, 0, 1, -3, -4, 7, 0, -12, 2, 10, -8, 8, 6, -5, -8, 8, 10, 4, -2, 5, -10, -5, 1, 5, 8, 3, -10, -12, 0, -1, 6, -7, -10, -5, -4, -11, -4, -4, 7, 8, 0, 11, -2, 1, 5, -7, -2, -8, -5, -4, -4, -10, -3, 3, -3, -7, -7, 10, -8, -2, 1, 9, 10, -11, 9, 8, 1, 5, 1, 7, -2, 2, 8, 0, -11, -7, -12, 3, -12, 2, -12, -5, -12, 8, 6, -8, 8, -6, -10, 0, 6, 5, 8, 7, -5, -1, 3, 6, 7, 5, -1, -8, -11, -3, -3, 3, 3, -2, 2, 5, 5, 5, -9, 11, -8, -10, 8, -8, -8, 6, 1, -5, 3, 7, 3, -8, -11, -3, 11, 1, -11, -11, 4, -11, -10, -11, 0, 4, -12, 5, 1, -6, 7, -8, 11, -4, -2, -7, 9, 0, -10, -10, 9, 3, -7, -2, 9, 10, 5, 11, -4, -2, -12, 3, -3, -10, -12, -1, 9, -11, 5, 4, -8, -8, -11, -4, -3, -11, 11, -8, 4, -2, 0, -11, 10, 11, 6, 11, -6, 10, -1, 7, 11, 9, -9, -4, -2, -6, -1, -8, 8, -6, 3, -10, -1, -12, -11, -1, 2, 9, -3, -12, -9, 3, 3, 7, 9, 0, -7, -6, -11, -10, 6, 9, -2, -6, -1, -6, -6, -12, -7, -1, 1, 3, -7, -3, 11, 6, 3, 5, 1, -11, -7, -12, -3, -2, -9, 1, 5, -12, 11, -4, 4, -11, 2, -5, -1, 3, -3, 7, -2, 2, -2, 7, 1, 3, -10, -10, 10, 9, -11, -11, -12, 11, 1, 11, -12, 4, -2, 9, -5, -11, -10, -4, -5, 10, -1, 9, 3, 3, 11, -10, 10, 5, -4, -5, 5, -11, -7, 7, -2, 3, 1, 1, -12, 6, 11, 5, -12, -1, -5, -12, -7, -2, 2, 5, 4, -11, 2, 1, 10, 7, 0, -3, 5, 0, 10, -4, 9, 1, 9, -11, 3, -5, -4, 2, -6, 9, 8, -6, -4, 10, -5, -9, -12, -5, 5, -9, -11, 8, 8, 10, -4, -11, -3, -8, 1, -4, 4, 9, 3, -7, -7, -6, -2, 9, 5, -10, 5, -1, -1, 5, -6, 4, 10, 7, -3, -5, 0, 5, -12, 11, 2, 2, -1, 0, -9, -12, -6, 8, -10, 9, 9, 1, -2, 6, -1, -8, -5, 10, 7, 8, -4, -2, 10, -3, -8, -1, 8, -4, 2, 10, 3, -12, 0, -4, 6, -10, 9, -4, -3, 11, 1, -9, 7, 6, -11, -1, 1, -4, 6, -4, 8, -11, -11, -3, 11, -9, -10, 2, -8, -1, -1, 4, -10, -10, -2, 4, -10, 6, -4, 9, 3, -3, 1, -7, -11, 1, -1, 3, -1, -3, 1, -11, -4, 3, 11, -1, 1, -4, -11, -3, 4, -7, -12, 2, 6, 0, -6, -2, -6, 9, 7, -10, -11, -4, 11, 7, 6, -4, -4, -9, 1, 11, -11, -5, 11, -4, -9, -2, -11, -6, 5, 9, 10, -1, 7, 11, -8, -6, -2, -3, -11, -11, -1, -5, -12, 7, 8, -10, -9, 4, -12, -7, -8, -6, 3, 8, -2, 10, -12, -1, 5, 4, 3, 1, 3, -5, 7, -1, -1, 7, -9, 1, -9, -6, 0, -1, -4, 9, 4, -4, -7, 3, -12, 2, -9, 9, 10, 1, 9, -11, -7, 8, -1, -9, 11, -7, -11, -11, 3, -1, 8, 8, -3, 2, -2, -12, -11, 3, -1, -4, -6, 5, 11, 3, -10, 3, -5, -3, 4, 2, 6, -2, -7, 6, 5, 9, 3, 7, -3, 4, -1, -1, 0, 9, -2, -8, -12, 1, 1, -11, -12, 7, 7, -2, -8, -7, -12, -12, 3, -11, 8, 11, 9, -9, 8, 9, -5, 8, -4, -8, 3, 9, 11, -9, 5, -10, 10, -2, 5, 10, -6, 8, -10, 2, 5, 1, -10, 3, -8, 11, 11, -12, -10, 11, -7, -10, -3, -5, -8, 2, 3, 7, -1, 6, 11, 4, 7, 9, 0, -6, -3, 4, 4, -1, 3, 8, -8, 3, -5, -7, 7, 10, -3, 3, -11, 8, -7, 6, 1, 7, -12, 3, -7, -7, -10, -4, 10, 3, 5, -1, -2, 5, -12, -12, 6, -5, -3, -5, -8, -11, -4, -4, -10, -6, -5, -5, -11, 6, 5, 5, -10, -6, -3, 9, 1, -8, -11, 8, 8, 2, -5, -4, -2, 0, -2, -4, 0, 11, 8, 0, -8, 0, -11, 5, -11, 5, -6, -9, -9, 9, 8, -1, 9, -2, 6, 1, -6, 0, 11, 8, 5, -12, 7, -7, 7, -3, 6, -2, -7, -3, 8, -10, -4, -11, 2, 1, 10, 3, 2, -9, 1, -1, 6, 4, 4, 1, 5, -8, -6, 5, 5, -11, 3, -8, 4, 4, -7, 3, 11, 3, 5, -7, 11, 7, 1, -6, 11, 4, 9, -8, -4, 5, 1, -8, -6, -1, -6, 3, 11, -5, 11, 10, 8, 5, -3, 4, 1, 8, 7, 9, 2, -11, 1, -2, 1, 5, 3, -9, -4, 9, -5, 8, -10, 9, -9, 6, 0, 10, 9, 10, -10, -3, 1, -4, 10, 11, -6, 6, -10, 0, 2, 3, -4, 9, 6, 9, -6, -6, -6, 1, 0, 6, -8, -1, 0, 3, -4, 7, 0, -9, 3, 0, -12, -9, 3, 3, -9, 6, -12, -10, 6, -12, -1, 4, -7, -4, -3, -9, 5, -5, 11, 7, -10, 2, 6, -2, 1, -8, 5, 11, -4, 8, 11, 9, 5, -9, -3, 4, -2, -2, 9, -3, -2, -11, -6, 10, 8, -4, -6, -2, 3, -9, -1, 10, -8, -8, -12, 6, 5, 9, -8, -8, -6, 0, -3, 5, 1, 8, -6, 2, -11, 5, -4, -12, 8, -12, 5, 6, -7, 11, -7, 4, 6, 3, 1, -2, 7, -11, 0, -2, 7, 3, -8, 8, 10, -4, 5, 7, -12, -3, 2, 4, 10, -11, 1, 11, -5, -3, -6, -1, 11, 1, 5, -9, 7, 4, 7, -12, -12, -8, -12, 9, 8, -5, 2, -9, 5, -2, -8, -3, 10, -12, 10, -2, 10, -2, -10, -10, 5, -4, -9, 3, 6, 5, 7, 6, 1, -4, 1, 3, 4, -10, -5, 9, -10, -2, 1, 4, 4, 9, 4, -11, -1, 6, -5, 11, 5, 2, -7, -1, -10, -3, 6, -7, -5, 6, -7, -10, 9, 7, 7, -2, -1, -2, -3, 0, 3, 0, -4, 9, 7, 6, -12, 5, 7, -5, 8, -12, 7, -3, 2, -3, -1, 6, 3, 0, -9, 11, -4, 0, -12, 0, -11, -9, -10, 6, 4, -12, 6, -12, -6, 1, -3, 2, 4, -9, 3, -9, -7, 1, 5, -6, -2, 9, -7, 5, -5, 4, -1, 8, -8, -11, 2, 0, -6, -10, -4, -1, -7, 5, 1, 4, 4, 4, 6, -10, -6, 1, -8, -4, 3, 11, -4, 8, -8, -3, 6, 2, 5, 1, 0, 1, 9, 11, -8, -12, -12, 9, 6, -1, -2, 9, -8, 1, -11, -12, -2, 0, 11, 2, 9, 4, -1, -1, -5, 7, -6, -2, -6, -8, 6, 10, 6, 2, -12, -5, -6, -7, -11, 1, -4, 8, 1, -8, -9, 6, 5, 6, -1, -7, -4, -5, 8, -9, 11, 1, 11, -7, -3, -10, -6, 7, 5, -1, 8, -5, 2, 5, 9, -10, -9, -10, -6, 6, 2, 6, -10, -6, -7, -11, -8, 5, 10, -1, 9, -3, -12, 1, -6, -2, -2, 9, -2, -6, 10, 6, -1, -4, 5, -12, -10, -8, 5, 11, 7, -5, -12, -8, 1, -11, -12
};

int chess_storage(YMEM) w[3200] = {
1, -12, 6, 2, 5, -8, 7, -8, 6, 4, -1, -9, 8, -7, -4, 5, 7, 2, -12, -7, -3, 10, 9, 11, -11, 8, 0, -4, -10, -8, 3, -4, -6, 4, 4, 11, -10, 1, -7, 3, -6, -2, -5, -7, 7, 1, 7, 4, -6, 1, 7, -4, 10, 4, 2, 0, -12, -12, 0, -5, -6, -4, -9, 7, -9, 3, 6, -7, -6, -7, 1, -4, -1, -2, 9, 10, -8, 3, 0, -4, 11, 4, 0, 7, -6, -5, 5, 8, -5, -11, 7, -10, 10, -8, 4, -3, 3, -7, 7, 6, 6, 9, -12, -11, -12, -11, -6, 10, -10, -5, 9, -11, -4, 6, -5, 2, -7, 11, -11, -4, -11, 5, 1, 0, 9, -6, -5, 4, 9, 0, 5, 6, 10, -5, 6, 9, -9, 9, 3, -10, -5, -9, -8, 6, 11, 4, -4, 1, -5, -3, 9, -10, -1, -11, -7, -6, 8, 0, -9, 8, 8, -11, 9, 7, 9, -7, 6, -9, -2, 8, -5, 4, 0, -9, 2, 2, -2, 7, 10, -12, 9, -10, 5, 11, 1, 0, -3, -1, -9, 2, 0, 0, 8, -6, -6, 2, -1, -3, -4, -1, 11, -2, 0, -5, 4, 9, 0, -4, -8, -4, -5, -3, 11, -2, 6, -8, -4, 11, 3, -9, -11, -10, 9, 3, 8, 1, 3, 10, 7, 3, -12, 5, 5, 5, -2, 2, -5, -9, 8, -3, 8, 5, -8, 7, -6, -8, 3, 6, 10, 3, 5, -2, -4, -9, -7, 8, 4, -9, 8, -8, 9, 3, -9, -1, 8, 6, 3, 6, -9, -11, 1, -8, 7, 5, -9, -11, 9, -5, -6, 5, 9, -1, -3, 1, 10, -8, -10, 5, -6, -7, 11, -9, 8, 5, 4, 11, 0, 0, -8, 11, -7, -7, -3, 4, -7, 4, -12, 10, -3, 5, -9, 3, 1, -7, -9, 3, 0, 10, 7, 9, 7, -11, 7, 8, -12, -10, 4, 11, -2, 7, -11, 10, -12, -5, 5, -7, -7, -5, 9, 2, -11, -10, -10, 5, 4, -11, 10, 11, 3, -9, 9, 2, 8, 8, 0, -3, 6, -5, -9, 6, 5, 10, 5, -8, 9, 2, -9, 3, -6, -11, -11, -10, 5, 9, -2, -6, 6, -2, -4, -5, 2, 7, -3, 6, -5, -8, -5, -7, 8, -1, 8, 9, -11, 9, 1, 2, -6, 8, -3, -7, -11, -4, -12, 8, 4, 0, 6, -2, 3, -4, 7, -9, 6, -8, 5, 1, 10, -6, 6, -3, 8, 6, -5, -3, 0, 3, 4, -12, 9, 0, 5, 0, 11, -11, -7, 1, -3, -6, 3, -6, 10, -8, 1, -7, -3, 0, -8, -10, -7, -7, -12, -11, -3, 6, -11, -5, -1, 3, 6, 6, -9, 6, -4, 9, -2, 2, -7, -6, -6, -5, 7, 2, -10, -6, 0, -10, -2, -5, 4, 3, -10, 9, -3, 2, -9, -12, 4, 3, -8, 2, 6, -5, -2, -10, -9, -6, -12, 7, 9, -3, 0, 8, 7, -8, 8, -3, 6, -11, 1, -2, 5, -7, 5, 5, -12, -11, 11, -5, -2, 10, -12, 2, 11, 11, -8, 11, -9, -11, -6, -3, 10, 6, -12, 5, -4, 1, 9, -6, 0, -12, -10, 8, 11, -9, -9, 0, -7, 7, 9, -10, 7, 11, 2, -5, -5, -5, -3, 8, -5, 4, 0, -10, -8, 7, -11, 1, -8, 2, -1, 2, -5, -8, 3, -2, 3, 10, 3, 3, -1, 7, -1, 10, -12, 1, 9, -7, -10, 11, 3, -6, -3, -12, 11, -7, 7, 3, -1, 4, 11, 3, 8, -1, -1, 0, 9, 9, 7, 0, -12, -5, 7, 1, -7, 4, 7, 11, -3, 1, -7, -3, -5, -11, 3, 5, 10, 11, -3, -1, -5, 11, -7, 8, 4, 3, -11, 2, -6, -8, 1, 6, -5, 3, 2, -9, -7, -11, -11, -1, 5, 3, 3, 6, -4, -4, 10, 2, -11, -4, 6, 3, 1, 7, 10, 8, 9, 10, -2, -5, 1, -9, -9, -12, 5, 11, -6, 9, 4, -12, -11, 8, 11, -10, 4, 10, -4, 11, -6, -8, 10, -4, -5, 7, 9, -2, 9, -9, 10, -10, 8, 2, 9, -8, 4, 8, 4, -10, -12, 9, 7, 6, -7, -11, 7, 4, 10, -2, -11, 6, -10, -3, -7, 9, 6, -5, 4, -7, 3, 0, -5, 0, -7, -12, 3, 3, 10, -9, 9, -1, 10, 11, 8, 10, 10, -9, -10, 11, -9, -4, -2, -1, -12, 11, 6, 10, 11, 0, -6, 9, -5, 1, 6, -6, -1, -5, -5, 10, 2, 4, 7, -11, -5, -4, 11, 1, 0, -5, -9, -10, -6, -7, -9, 6, -3, 0, -7, -9, 10, -1, 6, 4, -10, 1, -2, 3, -2, 9, -8, 10, -8, 11, 9, 0, 6, 4, -5, -12, -5, 6, -11, -3, -10, 10, 7, 11, -6, 10, 1, 4, -2, 6, -6, -8, -8, -9, 10, 7, -6, 4, 9, -4, 11, 7, -12, 2, 4, 8, 3, 9, 3, 3, 2, 2, -10, 11, 0, 8, -7, -1, 1, -12, 10, -4, -9, 3, -5, -2, -3, -6, -1, -2, 1, -12, 5, -8, -1, 9, -10, -5, -1, -2, -6, 6, 8, -4, 5, -2, -10, -1, -9, 5, -2, 11, 0, 6, 11, 10, -9, 5, -7, -1, -11, -8, 0, -11, -2, 5, -2, -5, -11, -5, -1, 11, 8, -5, -8, -4, 5, 8, -8, -1, 1, 2, -1, -8, -1, -9, 0, -1, 9, -2, -1, 6, -10, 4, 3, -2, 7, 2, 7, 1, 9, 0, -2, 4, -10, -1, -1, -11, 11, -10, 6, 6, 1, 1, -7, -12, -2, -4, 6, -9, -5, -6, 5, 3, 4, 1, -3, -12, 11, -5, -2, -5, 4, 2, 5, 5, -11, 7, 8, 9, 3, 8, -3, 3, 3, 4, -12, -5, 4, 8, -10, -5, 7, -12, 8, -4, -6, -2, 5, -6, 11, -10, 8, 10, -1, -2, -6, -5, -1, -4, -11, 7, -7, -8, -5, -8, 7, -3, 10, 3, 2, -1, 10, 0, -9, -2, -4, -2, 7, -11, -3, -7, -11, 3, -12, 6, -11, 7, 10, -7, 10, -1, 10, -11, -5, 7, 8, -7, 0, -5, 1, -9, -10, 6, 0, 9, -2, -12, -1, 5, 2, 4, 10, -12, -10, 6, 8, 6, 3, 8, -11, 3, -12, -10, -3, 11, -9, 1, -1, 5, 0, -1, 2, 1, -2, 3, 2, 0, 4, -7, 10, -5, -3, -2, 3, 11, -6, -11, 2, -7, 1, 11, -2, 3, 0, 11, 10, 6, 9, -3, 8, 3, -4, 6, -9, -4, 7, -7, -10, -9, 4, 8, 4, -3, -7, -2, -12, 8, -2, 8, -1, 2, 1, -10, 1, -11, -5, -7, -5, 7, -6, -12, -8, -8, -10, -7, -7, -6, 8, -4, -11, -8, -8, -2, 3, 8, -7, -3, -3, -6, 3, 8, 2, 10, 0, -5, -9, -12, -10, 3, -11, -10, 10, -6, -9, -1, -11, -9, 2, 9, -11, 10, -2, -1, -4, -1, -10, 5, 2, -2, -7, -5, 7, -10, 8, -8, -12, -12, 3, -1, 10, -4, -10, 2, 11, 7, 7, 8, -8, 2, 4, -9, -3, -12, -5, -12, -10, -4, 11, 2, 7, -2, 5, 0, -9, -12, -4, -11, -1, 8, 3, 8, 6, -11, -6, -8, -5, 8, 7, 4, 4, 9, -8, -9, -7, 4, -7, -10, 5, -5, 0, -11, -8, -3, -2, -5, -5, -3, 2, -8, -4, -3, 8, 4, -11, -8, 4, 4, 0, -3, 10, -12, 5, 6, -5, 10, 4, 8, 11, 8, 0, 0, 0, -2, 10, 10, -7, 7, -8, -8, 11, -11, 11, -8, 2, 7, 3, 10, -11, 10, 4, -10, -6, 1, -12, 5, -3, -10, 2, -1, -6, -11, -7, 6, -12, 2, -4, -11, 9, -12, 11, 6, 7, 8, -5, -3, 3, 11, 7, -7, 8, -1, 8, 4, -4, -10, -4, -3, 5, 9, -8, 9, 11, 3, -3, 10, -6, -7, -9, -4, -12, -4, -2, -4, 9, 10, -11, -9, 3, -3, -12, 6, 5, -4, 10, -6, -12, 4, -5, -3, 1, -11, 1, -9, -7, 7, 1, -7, -9, 4, -8, -11, -8, 7, 9, -7, 7, 1, 9, -3, -12, -12, 6, 5, -12, 1, -7, -6, -8, -9, -6, -6, -9, 8, -1, 3, 4, -5, 2, 6, 1, 1, -3, 3, -1, -2, 9, 1, 7, -12, 11, 10, 2, 7, -6, 9, 2, -4, 8, 2, -4, 1, 11, -1, 6, -5, -7, 8, 11, 2, 11, -1, 0, -4, 9, 11, -3, 11, -3, -6, 1, -7, -9, 7, -11, -11, 3, -11, -2, -2, 4, 3, 8, 2, -2, 0, 7, -5, 5, 1, -11, 11, -7, 9, 5, -3, -1, 8, -1, 5, -7, -6, 0, -5, 8, 2, 11, 11, 2, 5, 8, -4, -5, -3, 6, 4, 2, -4, 4, -12, 3, -6, -11, -1, 0, -5, -3, 0, -4, 6, 2, 10, 7, 6, 11, 11, -7, 2, -12, -2, 3, -7, 5, 6, 2, -11, 7, 5, -9, 2, 0, 5, -9, 7, 9, 7, 2, -6, 5, 0, -10, -3, 10, -6, -8, -2, -7, -8, -10, -6, 4, -5, 10, 4, -10, 4, 3, 8, 10, -11, -11, -12, -5, 4, -11, -11, 10, 3, 11, 2, 5, 10, 11, -3, 5, -9, 0, 1, 2, -12, -12, -10, -9, -8, -2, -4, -4, -12, 8, 2, -5, 4, -8, -12, 6, 0, 5, -8, -6, -11, 8, 7, 0, 2, -1, 3, 1, -1, 11, 5, 4, 8, 6, 4, -2, -4, 0, -12, -10, 9, -7, -4, -3, 4, 9, 9, -9, -6, 10, 2, 11, -6, -11, -5, 1, 10, 2, 5, -8, -12, 6, -4, -2, 3, -9, -6, -10, -6, 8, -8, -11, -5, -4, -6, 3, 4, -12, -9, -5, 5, 11, -5, -9, -4, -7, -6, 9, -6, -7, 9, 7, 10, 1, 4, 9, 5, 6, 2, -4, 8, 7, -9, -5, 1, -9, -9, 0, -8, -5, 11, 7, -7, -1, -8, -4, 1, -2, 0, 0, 11, -11, 11, 2, -9, 5, -2, -10, 3, -2, -1, 2, -5, -12, 6, 1, -3, 10, -12, -12, 11, -3, 11, 11, -10, -7, -11, 8, 3, 7, 2, -7, 3, -8, -8, -8, -2, 4, -6, -3, 8, 11, -8, 9, 4, -3, 1, 0, 8, -6, 2, -7, 6, -2, 1, -4, 1, 0, 4, -6, -3, 10, -12, 1, -6, -6, 1, 11, 11, 4, -7, 9, 2, 7, -1, 10, -12, 2, -12, -1, 2, 5, -4, -6, 7, 7, -7, -8, -1, -6, -7, 0, 10, 6, -1, 4, -10, -8, 2, 3, 10, -8, 8, 9, 7, -12, -3, 10, 5, 5, -4, 5, 3, 7, -2, 5, 7, -1, 3, -7, -10, -8, 0, -12, -9, 10, 4, -12, -8, -3, 2, -5, -5, -11, 5, -7, 2, 9, -4, -9, 2, 6, -7, -11, 10, 7, -3, -4, 4, -1, -4, 8, -7, -3, 6, 6, -1, -12, -2, -8, -11, -9, -4, 0, 9, 11, -4, -5, -4, 8, 11, -2, -10, -1, -3, -2, -5, 7, -11, 9, -5, -12, 6, -6, -1, 3, -5, -3, -2, 6, -3, 8, -7, -9, -4, -1, -10, 0, -6, -10, 6, 8, -8, -5, -9, 11, -8, 9, 2, -4, 8, -7, -12, -5, -1, -6, 3, -9, -4, 4, -4, -9, 6, 2, -7, 1, 0, -12, 1, -12, -6, 9, -10, 5, -2, -9, -1, -10, 7, 7, 8, -5, 4, 10, -8, 1, 0, 7, 9, -6, 6, -4, 10, -8, -3, 6, 3, 8, -7, -5, 0, -2, 5, -9, 6, 11, 3, -7, -9, -12, 10, 1, 5, 5, -5, -10, -5, 2, -1, -2, -1, 9, 0, -4, 6, -1, -5, 3, 1, 4, 2, -2, -12, 7, 9, -3, -3, -10, 10, -7, 0, -4, 1, 4, -8, -6, -3, 1, -7, 11, 4, 6, 11, 1, -8, -3, 8, 5, 5, -1, 7, -10, 0, -3, 6, 7, -7, 6, 8, 1, -5, -6, -7, 2, -4, -9, -6, -6, 1, -11, -2, -2, -11, -4, 11, 6, -1, 11, -8, 7, -11, 1, 0, -4, -5, -10, -2, 1, 0, 0, 0, 5, 6, -6, -10, 7, 0, 2, 11, -10, 8, -4, -1, -1, -12, 1, -11, -6, 11, 2, 9, 4, -9, -7, 11, 11, -3, 10, -7, -9, -5, 4, 0, 6, 11, -9, 0, -12, -8, 2, 0, 0, 7, -3, 0, 9, -9, -12, 8, 7, -3, -2, -12, 0, 2, -3, -7, -7, 0, -8, 9, -2, -9, 1, 1, -7, 2, -12, 11, 0, 4, -11, -12, 1, -11, 1, -2, 0, -3, 7, 7, 3, -8, -9, -12, -11, -11, 3, -4, -6, 5, 2, -5, 3, -10, -12, 4, -2, 9, 4, -10, -10, 5, -4, 0, 3, 0, -11, -2, -2, 11, 3, -4, -6, 7, -10, 0, -3, 10, -5, -4, -4, 9, 7, -6, 2, -7, -7, 11, 9, -6, -4, -2, 3, 10, -11, -3, -12, -12, 9, 9, 10, 0, -11, 7, 8, 3, 2, 10, 2, -5, -10, -10, 7, 7, -6, -2, 6, 10, 0, 2, 11, -7, 11, 9, 6, -4, 10, -9, -10, -7, 9, -4, 11, 5, -9, -6, -7, -9, 4, 7, 1, 0, -2, -11, 8, 6, 9, 1, -2, 7, -10, -8, 6, 7, -2, 11, -1, 3, 10, -8, 5, -4, 10, 7, 9, -10, 4, 9, -12, -1, -3, -8, 7, -12, -6, -6, -6, 9, -12, -10, -11, 1, -6, 4, 1, 11, 3, -8, 8, -2, 7, -11, -1, 9, 11, 6, 7, -5, 7, 7, -9, 0, 9, 6, 5, 7, -1, -1, -7, 11, -10, -9, 9, -7, 3, 8, 8, 2, 2, 1, -5, -11, 0, 3, -5, 9, 8, 7, 6, -5, -6, -7, -8, -5, 10, 3, 8, 0, 0, -3, -1, 2, -3, 3, 6, 6, 1, 5, 8, -4, -1, 3, -9, -6, -9, 2, 1, -9, 1, 4, 9, -11, 1, 9, -4, -12, -1, -2, -9, 1, 1, 0, -4, 3, -1, -5, 7, -11, 8, -5, 11, -12, -5, -10, 1, 6, 6, 2, -3, 6, -2, 0, -5, -7, -4, -1, -12, 11, 5, -4, 11, -6, 7, 6, -7, -11, -2, 7, 7, 9, 3, 7, 6, -1, -1, 6, -6, -11, -2, 0, -4, 2, 9, 8, -3, -10, -7, -9, -11, -6, -4, 4, 8, -5, 10, -7, -11, -2, -8, -9, -3, 0, -2, 4, -7, 2, 8, 9, 6, -4, 5, 5, -12, 7, -7, 9, 10, -7, -12, 4, 6, 7, 9, -6, 5, 8, -8, -11, 11, 11, -2, 9, -7, -9, -5, -10, -3, -6, -4, 7, 6, 4, -5, -3, -10, 7, -9, -1, -11, 2, -6, -1, 2, -7, -1, 4, 8, 3, -8, -7, 3, 3, 11, -12, 7, 1, -1, 5, 5, 10, -9, -7, 2, 5, -7, 7, 5, 0, 6, 4, 4, 11, 11, 2, -6, 0, 6, 6, -2, 11, 1, -3, 8, 11, -5, 10, 6, -7, -8, 7, 7, -12, -3, 6, 0, 11, 0, 3, -4, -2, 2, 9, 2, -2, -6, 6, 0, -6, 1, 1, 2, 11, 0, -6, 6, 5, 1, 7, -12, 8, -9, -12, 10, 7, -12, 0, -6, -1, -7, -12, 0, 4, 2, -7, 0, -8, -1, 7, -7, -10, 9, -11, -3, 4, -12, -7, 1, -11, -9, 4, 5, 9, 10, 0, -2, -2, 5, 8, 0, -11, -1, -1, 1, 7, -12, 5, -5, 0, 5, -10, 0, 2, 4, -1, 11, -6, -6, -11, 11, 0, -7, 1, -12, -1, -3, 11, -4, 1, 11, 4, -10, 8, -4, -6, -7, -11, 10, -7, -6, 11, -4, -4, 6, 0, -10, -9, -2, 3, 0, 10, -5, -3, -8, -9, 10, -4, -7, 6, -9, -5, -12, -4, -1, 6, 9, 4, -3, 9, -9, -8, -9, -12, -8, -1, -1, 10, 8, -5, 1, -6, 7, 5, -10, 5, 7, -3, -1, 5, 2, 8, 10, -4, -5, 2, -1, -2, 1, -12, -12, 1, -3, -2, -9, 6, -6, -4, -3, -10, -12, 11, -8, 0, -9, 3, -5, -4, -1, 9, -6, -5, 8, -10, 11, -6, -7, -7, -4, -9, 11, -7, 5, 2, 10, 5, 3, -5, 2, -7, 6, 0, 2, 6, 3, 4, -4, 10, 10, 5, 10, -3, -7, 11, -6, -3, 7, 5, -4, 2, -5, -6, -3, -5, 8, -1, 5, 2, -12, 11, -8, 8, -11, -3, 6, -10, 4, -9, 9, -7, -1, -4, -11, 10, -5, 2, 0, -3, 7, -12, 8, -7, -10, 2, 8, -7, 0, 7, 10, 6, -7, 7, 5, -2, 11, -5, 8, -10, -1, -10, -12, -9, -7, 0, 9, -11, -9, -1, 9, -2, 5, 6, 3, -12, 3, -1, -7, -6, 5, -7, -7, 1, -1, 9, -12, 3, 7, -7, 5, 5, -11, -6, 7, 0, -12, 9, 6, 11, 11, 5, 10, -2, 5, -7, -4, 1, -6, 2, -3, 0, 10, 0, 6, 5, 4, -3, 0, 5, -4, 1, -11, -12, 2, 9, -6, -9, 5, -12, 7, 3, 6, 7, -7, -12, 3, 9, -3, 4, 10, 3, 11, -7, -5, -1, -3, -11, 10, 1, 2, 0, 8, -3, 11, -1, 2, -3, -9, -2, -3, 0, 0, 1, 11, -6, 8, -11, -12, -11, 10, -1, -9, -11, -10, 4, -1, -11, -3, -11, -2, -11, 2, -2, -12, 1, -4, -8, -10, 5, -3, 9, -2, -10, -9, 1, -6, -7, -6, 2, 8, 6, -10, 8, 7, 2, 6, -11, -12, 3, 6, 1, -12, 0, -2, -5, -3, -8, 10, 1, -2, -7, -12, 0, 4, -4, 9, -6, -7, 6, 7, -9, 10, 4, -10, 11, -4, -9, -4, -1, 11, -4, -1, -8, 3, 0, 5, -7, 0, -12, -1, -7, 5, 4, 11, 5, -1, 7, -7, -10, 5, -12, 5, -9, -10, 11, 1, 0, -6, 4, 8, 5, -3, 11, -12, -3, 5, -1, 8, -1, 1, -2, -10, 0, -3, 3, 1, -12, 11, 6, 1, 2, -3, 0, 1, 1, 9, -10, 9, 4, 7, 11, -8, 6, -6, 11, 11, -12, 8, 2, 7, -7, 1, 3, -4, -6, 8, 11, 11, 0, -11, -9, 5, 2, -5, -8, 4, 10, -7, 0, -3, -2, 6, 0, -4, -7, -10, -6, -10, -5, -11, -1, -8, -12, -6, -8, 4, -10, 10, 5, -9, -11, 1, -11, 0, -12, 2, 1, 2, -6, -12, 1, 0, 0, -5, 11, -10, 10, -5, -10, -2, 8, 2, 7, 0, -10, -1, 2, -6, -8, -9, 9, 10, -6, 11, 6, 11, 2, -8, 2, -9, 1, -6, -6, 2, 11, -4, -2, -4, 2, 5, -6, -6, -9, -6, -8, 5, 6, 8, -8, 11, 9, -11, 6, 5, 5, -8, -10, -10, 9, 9, 8, 5, -10, 8, 0, 0, 8, -9, -4, 3, -7, 1, 11, -5, 4, 3, -2, -8, 1, 9, -3, 7, -8, -9, 6, -8, -2, -10, 10, -7, -1, -6, 11
};

int chess_storage(YMEM) bias[40] = {
4, -3, 4, 5, 9, 9, 2, -12, -3, 9, 2, -3, -4, 9, 10, -12, 1, -5, -8, -11, -7, -11, -9, 10, 0, 0, 0, 3, -11, -9, -9, 4, -7, -9, -9, -9, 11, 5, -7, -6
};

int bias_shift = 0;
int out_shift = 0;
int output_activation_min = 0;
int output_activation_max = 32767;

int expected_output[DIM_OUT] = {
112, 127, 127, 116, 127, 0, 127, 127, 127, 127, 0, 127, 127, 127, 0, 83, 127, 127, 110, 0, 127, 127, 127, 127, 127, 127, 127, 127, 127, 115, 93, 0, 55, 127, 127, 127, 77, 54, 127, 127, 127, 127, 127, 98, 70, 127, 127, 52, 127, 127, 43, 18, 103, 127, 26, 127, 106, 0, 127, 127, 90, 14, 127, 127, 127, 127, 127, 127, 127, 0, 127, 127, 111, 4, 127, 32, 127, 127, 127, 127, 127, 22, 127, 127, 127, 127, 0, 127, 82, 127, 96, 73, 126, 127, 127, 61, 127, 127, 20, 115, 48, 23, 127, 127, 121, 127, 127, 127, 127, 127, 127, 127, 0, 127, 0, 127, 50, 127, 127, 66, 74, 93, 119, 127, 96, 45, 42, 127, 86, 127, 0, 41, 127, 127, 127, 16, 127, 127, 59, 127, 66, 127, 85, 84, 127, 120, 127, 127, 127, 122, 37, 72, 127, 0, 82, 127, 88, 127, 102, 25, 127, 127, 127, 127, 127, 127, 127, 49, 127, 127, 127, 127, 127, 127, 80, 127, 68, 127, 127, 104, 127, 127, 17, 120, 127, 120, 127, 0, 88, 127, 127, 116, 127, 127, 127, 127, 127, 127, 10, 31, 127, 127, 40, 63, 127, 127, 127, 127, 15, 127, 127, 127, 127, 127, 127, 127, 20, 127, 127, 115, 127, 127, 28, 127, 127, 127, 127, 127, 127, 127, 90, 127, 127, 68, 79, 127, 105, 127, 127, 127, 127, 127, 127, 127, 127, 127, 95, 0, 39, 64, 60, 127, 114, 127, 127, 84, 127, 62, 96, 63, 47, 127, 127, 89, 4, 127, 24, 70, 0, 48, 118, 118, 22, 122, 76, 88, 127, 87, 127, 44, 5, 127, 127, 127, 79, 27, 0, 78, 127, 127, 0, 6, 127, 29, 127, 127, 127, 127, 127, 0, 127, 127, 23, 61, 127, 126, 127, 88, 127, 127, 118, 127, 4, 127, 127, 98, 127, 127, 127, 127, 67, 127, 127, 127, 127, 127, 90, 127, 67, 127, 127, 93, 127, 127, 48, 127, 0, 127, 127, 21, 90, 127, 127, 28, 127, 127, 127, 127, 69, 0, 127, 0, 127, 127, 127, 127, 127, 93, 127, 127, 47, 127, 0, 0, 96, 0, 127, 127, 127, 127, 127, 88, 99, 127, 100, 50, 39, 116, 25, 127, 127, 82, 112, 127, 0, 127, 127, 127, 127, 127, 28, 28, 127, 60, 127, 50, 127, 127, 127, 34, 12, 127, 127, 50, 0, 62, 127, 127, 127, 127, 127, 127, 127, 127, 0, 112, 127, 0, 127, 127, 127, 127, 65, 49, 127, 127, 127, 95, 127, 127, 73, 127, 0, 127, 96, 127, 127, 127, 0, 127, 127, 127, 0, 98, 108, 127, 127, 127, 127, 127, 127, 127, 0, 127, 127, 127, 40, 127, 127, 44, 27, 127, 110, 127, 0, 127, 127, 127, 106, 127, 127, 127, 26, 115, 127, 127, 38, 4, 127, 45, 114, 127, 73, 127, 127, 39, 127, 127, 28, 14, 2, 127, 127, 127, 109, 48, 127, 88, 127, 4, 127, 90, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 64, 127, 127, 44, 127, 127, 127, 127, 127, 73, 127, 127, 127, 127, 72, 127, 98, 127, 127, 106, 127, 127, 127, 127, 110, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 52, 127, 127, 127, 62, 127, 107, 127, 127, 127, 127, 85, 127, 127, 127, 127, 68, 127, 24, 127, 38, 127, 87, 0, 0, 127, 127, 47, 127, 127, 127, 127, 66, 20, 67, 127, 127, 0, 116, 0, 127, 127, 127, 92, 50, 22, 127, 47, 127, 127, 127, 127, 92, 16, 127, 86, 127, 36, 127, 127, 127, 127, 93, 80, 127, 127, 127, 0, 127, 0, 109, 0, 127, 64, 9, 127, 72, 0, 127, 49, 52, 127, 127, 107, 99, 26, 122, 10, 127, 122, 127, 127, 127, 127, 127, 0, 0, 127, 80, 127, 43, 127, 9, 127, 68, 33, 4, 127, 127, 79, 127, 8, 127, 127, 127, 127, 127, 127, 127, 127, 42, 127, 127, 127, 126, 29, 127, 127, 127, 52, 127, 111, 127, 127, 127, 127, 127, 127, 30, 127, 127, 127, 57, 127, 127, 127, 127, 0, 127, 127, 127, 19, 127, 85, 127, 122, 127, 127, 72, 127, 127, 67, 127, 127, 127, 10, 54, 127, 127, 127, 127, 0, 127, 70, 96, 127, 127, 127, 84, 127, 127, 0, 127, 127, 127, 127, 127, 127, 114, 127, 127, 58, 127, 0, 127, 111, 122, 127, 127, 127, 54, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 118, 127, 127, 53, 127, 127, 127, 127, 0, 127, 127, 92, 43, 127, 0, 127, 127, 127, 127, 127, 116, 127, 127, 0, 127, 0, 127, 127, 127, 127, 127, 32, 127, 0, 127, 100, 127, 36, 127, 106, 114, 126, 127, 127, 127, 107, 81, 46, 127, 127, 127, 101, 127, 127, 0, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 62, 127, 67, 127, 127, 127, 127, 127, 127, 127, 6, 127, 127, 54, 89, 127, 33, 127, 127, 0, 127, 48, 127, 127, 2, 91, 100, 86, 86, 6, 127, 14, 0, 0, 72, 127, 127, 127, 127, 23, 27, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 96, 127, 127, 69, 127, 52, 116, 127, 127, 127, 127, 127, 127, 127, 127, 127, 5, 127, 127, 110, 127, 91, 127, 127, 0, 110, 127, 93, 127, 127, 127, 127, 75, 127, 127, 50, 127, 127, 127, 127, 122, 95, 127, 16, 127, 127, 107, 127, 127, 33, 127, 127, 127, 78, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 0, 127, 127, 101, 83, 127, 127, 92, 127, 127, 127, 127, 127, 98, 127, 127, 0, 127, 127, 6, 92, 0, 114, 127, 127, 127, 25, 127, 127, 34, 127, 127, 78, 6, 115, 0, 127, 127, 127, 0, 127, 75, 78, 127, 30, 127, 0, 93, 127, 63, 91, 84, 127, 115, 127, 127, 127, 101, 42, 0, 127, 127, 127, 125, 100, 104, 4, 104, 21, 127, 127, 0, 102, 4, 127, 127, 127, 0, 10, 127, 127, 96, 127, 118, 127, 127, 126, 127, 127, 77, 127, 127, 127, 124, 74, 127, 127, 127, 0, 127, 127, 2, 127, 0, 77, 127, 127, 127, 127, 127, 36, 74, 127, 127, 127, 127, 127, 127, 113, 14, 127, 127, 127, 127, 127, 41, 54, 127, 127, 127, 5, 79, 127, 127, 127, 126, 127, 0, 127, 127, 30, 122, 127, 118, 0, 90, 127, 40, 127, 64, 100, 127, 127, 7, 98, 127, 0, 127, 127, 0, 90, 127, 127, 58, 127, 95, 5, 27, 0, 100, 127, 0, 8, 0, 127, 59, 118, 127, 127, 127, 127, 0, 127, 127, 127, 127, 127, 121, 127, 127, 127, 0, 127, 127, 127, 127, 127, 127, 45, 127, 127, 127, 127, 87, 127, 127, 127, 0, 108, 127, 0, 127, 127, 75, 90, 127, 122, 0, 127, 48, 127, 113, 32, 64, 44, 16, 76, 127, 127, 61, 36, 0, 102, 127, 127, 80, 113, 127, 127, 127, 93, 127, 80, 127, 95, 0, 97, 88, 127, 43, 127, 127, 113, 98, 127, 26, 127, 127, 26, 127, 58, 127, 127, 127, 127, 66, 110, 127, 127, 78, 127, 29, 127, 34, 127, 127, 127, 127, 127, 50, 127, 127, 127, 34, 127, 127, 111, 127, 42, 127, 49, 0, 58, 127, 127, 127, 0, 127, 127, 126, 24, 0, 0, 8, 0, 59, 100, 127, 0, 65, 127, 98, 127, 0, 127, 127, 124, 119, 22, 127, 127, 127, 119, 127, 127, 127, 127, 127, 127, 127, 122, 127, 63, 127, 36, 127, 127, 127, 127, 127, 127, 127, 0, 127, 127, 127, 61, 127, 127, 127, 51, 127, 127, 127, 127, 127, 40, 127, 127, 127, 127, 127, 127, 110, 84, 127, 127, 127, 47, 127, 127, 127, 127, 68, 56, 127, 127, 127, 0, 127, 124, 0, 127, 0, 44, 127, 127, 127, 114, 127, 77, 106, 23, 127, 118, 127, 127, 127, 127, 127, 127, 127, 127, 96, 127, 127, 127, 127, 127, 127, 68, 127, 6, 127, 127, 53, 0, 95, 28, 127, 26, 127, 127, 127, 0, 127, 38, 127, 127, 127, 19, 127, 104, 127, 0, 125, 127, 127, 127, 127, 36, 28, 127, 127, 92, 127, 70, 127, 114, 80, 29, 127, 127, 86, 127, 63, 127, 127, 127, 0, 127, 127
};

