/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016D5EC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C();
extern void func_80146C3C(void);
extern short func_8016CF04();
short func_8016CF04(s32 param_1, s32 param_2);

void func_8016D5EC(s32 *a0) {
    u16 *rec = (u16 *)a0[8];    
    rec[0xC] -= 0x60;           
    rec[0xD] -= 0x60;           
    if ((s16)((s32 (*)(s32, s32))func_8016CF04)((s32)a0, 2) != 0) {
        ((void (*)(s32 *))func_80146C3C)(a0);
    }
}
