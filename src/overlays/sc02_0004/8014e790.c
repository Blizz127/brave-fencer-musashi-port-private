/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014E790 - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_80135888();
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);

s32 func_8014E790(s32 arg0, s16 * arg1, s16 * arg2)
{
    s32 temp_a1;
    void *temp_s0;
    temp_s0 = (*(  void ** )((s8 *)( arg0 ) + (  0x180 ))) ;
    if (((*(  u16 * )((s8 *)( temp_s0 ) + (  0 )))  == 0) || !((*(  u16 * )((s8 *)( temp_s0 ) + (  0x5C )))  & 0x20) || (temp_a1 = (*(  s32 * )((s8 *)( temp_s0 ) + (  0x58 ))) , (temp_a1 == 0)) || (func_80135888((*(  s32 * )((s8 *)( temp_s0 ) + (  0x20 ))) , temp_a1, arg1, arg2) == 0)) {
        (*(  void ** )((s8 *)( arg0 ) + (  0x180 )))  = ((void *)0) ;
        return 0;
    }
    (*(  u16 * )((s8 *)( arg0 ) + (  6 )))  = (u16) (*(  u16 * )((s8 *)( temp_s0 ) + (  6 ))) ;
    (*(  u16 * )((s8 *)( arg0 ) + (  0xA )))  = (u16) (*(  u16 * )((s8 *)( temp_s0 ) + (  0xA ))) ;
    (*(  u16 * )((s8 *)( arg0 ) + (  0xE )))  = (u16) (*(  u16 * )((s8 *)( temp_s0 ) + (  0xE ))) ;
    return 1;
}
