/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801336E8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801BD608;
extern s32 D_801BD60C[];
extern int D_801BD610;
extern void func_80136BC4(s32 a0);

void func_801336E8(void *a0, int a1, int a2) {
    if (a0 != 0) {
        (*(void * *)&D_801BD608) = a0;
        ((void (*)(void))func_80136BC4)();
    }
    (*(int *)&D_801BD60C) = a1;
    D_801BD610 = a2;
}
