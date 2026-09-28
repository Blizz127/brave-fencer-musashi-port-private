/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80132144 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
void func_8012CAE4(void *a0);
extern void func_8012C1B8(void);
extern void func_8001C214(int, int);

s32 func_80132144(s32 param_1)
{
    extern int D_80184A10;

    int v0;

    v0 = ((int (*)(void))func_8012C1B8)();
    *(int *)(((int)param_1) + 0x20) = v0;
    if (v0 == 0) {
        ((void (*)(int))func_8012CAE4)(((int)param_1));
    } else {
        ((void(*)(int, int))func_8001C214)(v0, 0);
        *(int *)(((int)param_1) + 0x58) = (int)&D_80184A10;
        *(short *)(((int)param_1) + 0x5c) = 0x80;
        *(unsigned short *)(((int)param_1) + 2) += 1;
    }
}
