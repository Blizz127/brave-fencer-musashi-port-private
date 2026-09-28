/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012FDA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80131C78(s32 a0);
extern void func_801319E0(s32 a0);

void func_8012FDA8(int param_1)
{
    extern void func_8012CBF4(s32 a0);
    extern void func_80131CA8(int a0, int a1);
    extern void func_80131E00(struct S80131E00 *a0, s32 a1);
    int iVar1;
    unsigned int uVar2;
    if ((*(unsigned int *)(param_1 + 0xb4) & 0x100) != 0) {
        iVar1 = *(int *)(param_1 + 0x1c) + 1;
        *(int *)(param_1 + 0x1c) = iVar1;
        if (0x14 < iVar1) {
            ((void (*)(int, int))func_80131E00)(param_1, 0xd);
            return;
        }
        uVar2 = ((int (*)(int))func_8012CBF4)(param_1);
        if ((uVar2 & 0x2000) != 0) {
            if ((uVar2 & 0xff) == 2) {
                ((void (*)(int, int))func_80131E00)(param_1, 0x12);
                return;
            }
            if ((uVar2 & 0xff) == 0x1a) {
                func_801319E0(param_1);
                return;
            }
            func_80131C78(param_1);
        }
    }
    func_80131CA8(param_1, 0x1d);
    return;
}
