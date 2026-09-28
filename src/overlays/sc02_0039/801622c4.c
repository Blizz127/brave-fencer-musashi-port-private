/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801622C4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800291C8(s32, s32);
extern void func_80029124(s32, s32);
extern void func_80016714(void *a0, s32 a1);
extern void func_80029124(s32 a0, s32 a1);
extern int D_8019FB38[];

void func_801622C4(void)
{
    int *p;
    int i;

    ((int (*)(int, int))func_80029124)(0x141, 1);
    ((int (*)(int, int))func_800291C8)(8, 0);
    i = 0;
    p = &D_8019FB38;
    do {
        ((int (*)(int, int))func_80016714)(*p, 0x38);
        p = p + 1;
        i = i + 1;
    } while (i < 3);
}
