/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161374 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015954(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8015BDD0(s32 *a0);
extern void func_8015BF48(s32 *a0);
extern s32 D_801152BC;
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
extern void func_80015954(s32, s32);

int func_80161374(int param_1, unsigned int param_2) {
    extern int D_801152BC;
    if ((param_2 == 0) || (param_2 == 0x8000)) {
        ((void (*)(int))func_801599A4)(param_1);
        ((void (*)(int))func_8015BDD0)(param_1);
        return 1;
    }
    if ((param_2 & 0x4000) != 0) {
        if ((D_801152BC != 0) ||
            (*(short *)(param_1 + 10) >= *(short *)(param_1 + 0x8a))) {
            ((void (*)(int))func_801599A4)(param_1);
            ((void (*)(int))func_8015BF48)(param_1);
            return 1;
        }
        ((int (*)(int, int))func_80015954)(param_1 + 0x88, param_1 + 4);
        return 0;
    }
    return 0;
}
