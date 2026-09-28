/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80130974 - byte-exact against retail at -O2 (tools/register_match.py). */
s32 func_8012BEE8(s32 a0);
extern void func_80131CA8(int a0, int a1);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_801319E0(s32 a0);
extern void func_801319E0(int);
extern int func_8012BEE8(int);
extern void func_80131CA8(int, int);
extern void func_80166244();

void func_80130974(int param_1) {
    short sVar1;
    if ((*(unsigned int *)(param_1 + 0xb4) & 0x8000) != 0) {
        sVar1 = *(short *)(*(int *)(param_1 + 0x20) + 0x18);
        if (sVar1 < 0x1000) {
            *(short *)(*(int *)(param_1 + 0x20) + 0x18) = sVar1 + 0x400;
            *(short *)(*(int *)(param_1 + 0x20) + 0x1c) =
                *(unsigned short *)(*(int *)(param_1 + 0x20) + 0x1c) + 0x400;
        }
        if (func_8012BEE8(param_1) != 0) {
            ((void (*)(int))func_80166244)(param_1);
            func_801319E0(param_1);
            return;
        }
    }
    func_80131CA8(param_1, 0x2b);
}
