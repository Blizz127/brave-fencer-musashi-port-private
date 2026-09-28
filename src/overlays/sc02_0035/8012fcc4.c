/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012FCC4 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S80131E00;
struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
void func_8012B14C(s32 a0, s32 a1);
extern void func_80131B14();
extern void func_80131E00(struct S80131E00 *a0, s32 a1);
extern s32 func_80131A34(s32, s32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern s32 func_80131A34(s32 a0, s32 a1);
extern void func_80131CA8(s32 a0, s32 a1);

s32 func_8012FCC4(s32 param_1) {
    extern int D_80184858;

    int v1 = *(int *)(((int)param_1) + 0xC4);
    *(char *)(((int)param_1) + 0xC1) = 8;
    if (v1 & 2) {
        *(char *)(((int)param_1) + 0xC1) = 1;
        func_80131CA8(((int)param_1), 3);
        return;
    }
    if (v1 & 1) {
        ((void (*)(int, int))func_80131E00)(((int)param_1), 1);
        return;
    }
    if (*(int *)(((int)param_1) + 0xB4) & 0x100) {
        ((void (*)(int))func_80131B14)(((int)param_1));
        if (*(short *)(((int)param_1) + 0x76) <= 0) {
            ((void (*)(int, int))func_80131E00)(((int)param_1), 0xC);
            return;
        }
        if (((s32(*)(s32, s32))func_80131A34)(((int)param_1), 4) != 0) {
            *(char *)(((int)param_1) + 0xC2) = 0;
        } else {
            *(short *)(((int)param_1) + 0x98) = 0;
            *(char *)(((int)param_1) + 0xC2) = 1;
        }
        ((void (*)(int, void *))func_8012B14C)(((int)param_1), &D_80184858);
        *(int *)(((int)param_1) + 0x1C) = 0;
        func_80131CA8(((int)param_1), 0x1C);
        return;
    }
    func_80131CA8(((int)param_1), 0x1C);
}
