/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D76C - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
extern void ApplyMatrixSV(void *a0, void *a1, void *a2);
extern void func_80013F3C(s32 a0);
extern void func_8017D7D0();

void func_8017D76C(s32 a0, void *a1, void *a2) {
    s32 m[8];

    ((void (*)(void *))func_80013F3C)((void *)m);
    ((void (*)(s32, void *))func_8017D7D0)((s16)a0, (void *)m);
    ApplyMatrixSV((void *)m, a1, a2);
}
