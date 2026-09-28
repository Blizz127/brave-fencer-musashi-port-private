/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801554B8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801659DC();

s32 func_801554B8(void *arg0) {
    s32 var_v0;
    u8 temp_a0;
    temp_a0 = (*(  u8 * )((s8 *)( arg0 ) + (  0x1A0 ))) ;
    var_v0 = 0;
    if (temp_a0 != (*(  u8 * )((s8 *)( arg0 ) + (  0x196 ))) ) {
        if (func_800D02D0(temp_a0) != 0) {
            (*(  u8 * )((s8 *)( arg0 ) + (  0x196 )))  = (u8) (*(  u8 * )((s8 *)( arg0 ) + (  0x1A0 ))) ;
            func_801659DC(arg0);
            return 0;
        }
        var_v0 = 1;
         
        return var_v0;
    }
    return var_v0;
}
