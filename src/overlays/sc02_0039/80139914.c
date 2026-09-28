/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80139914 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8013A8B0(s32 *a0);

void func_80139914(s32 arg0)
{
    s32 temp_a0;
    (*(  s16 * )((s8 *)( arg0 ) + (  4 )))  = 0;
    (*(  s32 * )((s8 *)( arg0 ) + (  0 )))  = 0;
    if ((*(  u16 * )((s8 *)( arg0 ) + (  0x18 )))  != 0) {
        temp_a0 = (*(  s32 * )((s8 *)( arg0 ) + (  0x40 ))) ;
        if (temp_a0 != 0) {
            func_8013A8B0(temp_a0);
        }
    }
}
