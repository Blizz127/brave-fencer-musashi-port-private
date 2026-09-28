/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801288E8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801BC3F0;
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern int D_800C7C60;
extern int *D_800C7C64;
extern int D_800A2E20;
extern int D_800AF558;
extern int D_801BC3F0;

int func_801288E8(int arg0)
{
    int *p = &D_800C7C60;
    *p = 0x60;
    D_800C7C64 = &D_800A2E20;
    ((void (*)(int, int, int *, int, int *))func_8001ABBC)(0, 0, &D_800AF558, D_801BC3F0, p);
}
