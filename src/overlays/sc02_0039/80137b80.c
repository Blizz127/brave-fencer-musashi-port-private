/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80137B80 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80127548[];
extern s32 D_801269F0;
extern void func_80138BE0(s32 a0);
extern int D_8017F6FC;
extern int D_801269F0;
extern void func_80138BE0(int p);

void func_80137B80(void) {
    int *p = &D_801269F0;
    (*(int *)&D_80127548) = 0x24;
    if (*p != 0) {
        ((void (*)(int *))func_80138BE0)(p);
    }
    D_8017F6FC += 1;
}
