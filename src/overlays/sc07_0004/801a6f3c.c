/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6F3C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012AD80(s32 a0);
extern void func_8012B178(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern void func_801439C0(u8 *a0);
extern void func_801A54AC(s32 a0);
extern s32 D_801F8844[];

void func_801A6F3C(s32 param_1) {
    func_8012AD80(param_1);
    *(s32 *)(param_1 + 0xF0) = *(s32 *)(param_1 + 0xF0) - 0x20000;
    func_8012B178(param_1, *(s32 *)(param_1 + 0xF0));
    if (func_8012BEE8(param_1) != 0) {
        D_801F8844[*(s16 *)(param_1 + 0x70)] = 0;
        func_8012C218((void *)param_1);
        if (*(u8 **)(param_1 + 0xD0) != NULL) {
            func_801439C0(*(u8 **)(param_1 + 0xD0));
        }
    } else {
        func_801A54AC(param_1);
    }
}
