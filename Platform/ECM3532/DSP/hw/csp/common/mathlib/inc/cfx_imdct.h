/*File::   cfx_imdct.h                                                             */
/*$Revision:: 55766                                                                    $*/
/*$Date:: 2015-06-19 18:45:02 +0300 (Fri, 19 Jun 2015)                                 $*/
/* -----------------------------------------------------------------------------------	*/
/* Copyright (c) 2006, 2007, 2008 NXP B.V.                                              */
/* All rights reserved.                                                                 */
/* This source code and any compilation or derivative thereof is the                    */
/* proprietary information of NXP B.V. and                                              */
/* is confidential in nature.                                                           */
/*                                                                                      */
/* Under no circumstances is this software to be combined with any Open                 */
/* Source Software in any way or placed under an Open Source License of                 */
/* any type without the express written permission of                                   */
/* NXP B.V.                                                                             */
/* -----------------------------------------------------------------------------------	*/

#ifndef IMDCT_H
#define IMDCT_H

#include "cf6_chess.h"
#include "mathlib.h"

//#include "cfx_fftcomplex.h"
#include "cfx_mdct_tables.h"
//#include "cfx_ffttables.h"

typedef struct imdct_window
{
    int quarter_size;
    const fix chess_storage(YMEM) * window_0;
    int window_limit_0;
    const fix chess_storage(YMEM) * window_1;
    int window_limit_1;
} CFX_IMDCT_WINDOW;


extern int cfx_imdct_PreTwiddle(fix* coeffs, 
                                fix* output, 
                                const CFX_MDCT_TABLE *table) property(loop_levels_1);

extern int cfx_imdct_PostTwiddle(fix* buffer, 
                                 const CFX_MDCT_TABLE *table) property(loop_levels_1);

extern fix* cfx_imdct_DeInterleave(fix* input, 
                                   fix* output, 
                                   CFX_IMDCT_WINDOW* window_struxt, 
                                   fix* buffer_start, 
                                   int buffer_limit) property(loop_levels_1);

extern fix* cfx_imdct_Process(fix* input_coeffs, 
                              fix* workspace, 
                              const CFX_MDCT_TABLE* imdct_table, 
                              CFX_IMDCT_WINDOW* imdct_window, 
                              fix* output, 
                              int outputLimit, 
                              fix* outputBase) property(loop_levels_3);

#endif // #ifdef IMDCT_H
