/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80173648 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80171CC4(void *a0, void *a1);
extern s32 func_80172664(s32 *a0);
extern void func_80171A1C(u8 *a0);
extern s32 func_80171CC4(void * a0, void * a1);
extern s32 func_80174650(s32);
extern s16 D_80126B3E;

void func_80173648(u8 *a0) {
    u8 *s0 = a0;
    s16 *p = &D_80126B3E;
    if (*p != 0) {
        func_80171CC4(s0, (u8 *)p - 6);
    }
    if (func_80172664((s32 *)s0) == 0) {
        func_80171A1C(s0);
        func_80174650((s32)s0);
    }
}
