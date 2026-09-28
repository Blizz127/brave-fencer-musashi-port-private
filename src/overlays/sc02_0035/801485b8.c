/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801485B8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801485B8(s32 arg0, s32 arg1, s32 arg2)
{
    (*(  s16 * )((s8 *)( arg1 ) + (  0 )))  = (s16) (s8) (*(  u8 * )((s8 *)( arg0 ) + (  0 ))) ;
    (*(  s16 * )((s8 *)( arg1 ) + (  2 )))  = (s16) (s8) (*(  u8 * )((s8 *)( arg0 ) + (  1 ))) ;
    (*(  s16 * )((s8 *)( arg1 ) + (  4 )))  = (s16) (s8) (*(  u8 * )((s8 *)( arg0 ) + (  2 ))) ;
    (*(  s16 * )((s8 *)( arg2 ) + (  0 )))  = (s16) (s8) (*(  u8 * )((s8 *)( arg0 ) + (  3 ))) ;
    (*(  s16 * )((s8 *)( arg2 ) + (  2 )))  = (s16) (s8) (*(  u8 * )((s8 *)( arg0 ) + (  4 ))) ;
    (*(  s16 * )((s8 *)( arg2 ) + (  4 )))  = (s16) (s8) (*(  u8 * )((s8 *)( arg0 ) + (  5 ))) ;
}
