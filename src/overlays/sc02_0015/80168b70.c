/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80168B70 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80168BDC(s32 a0, s32 a1, s32 a2, s32 a3);

void func_80168B70(s32 a0) {
    s32 *p = (s32 *)a0;
    if (--p[0x1C / 4] != -1) {
        func_80168BDC(a0, 9, 3, 1);
    } else {
        func_80168BDC(a0, 9, 2, 1);
        ((void (*)(s32))func_80146C3C)(a0);
    }
}
