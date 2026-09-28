/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB2CC - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB2CC(void *a0) {
    extern u8 D_80078EC1;
    extern void func_801493D0(s32, s32, s32);
    extern void func_80146C3C();

    s32 *s2 = *(s32 **)((s32)a0 + 0x34);
    if (D_80078EC1 == 0x11) {
        func_801493D0((s32)s2, (s32)a0 + 0x10, (s32)a0 + 4);
    } else {
        func_80146C3C(a0);
    }
}
