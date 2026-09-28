/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A67F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A395C(s32 a0, s32 a1);
extern u16 D_8019FF8A;
extern s16 D_801F8714;
extern s32 func_8012BEE8(s32 a0);
extern void func_801A370C(s32 a0);
extern void func_801A85A8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_801AAA6C(s32 a0);
extern void func_801A36A8(s32 a0);
extern void func_801A36F0(void *a0);
extern void func_801A7C58();
extern void func_801A8C58(s32 a0);
extern void func_801A1984(s32 a0);
extern void func_801A2364();

void func_801A67F8(s32 a0) {
    if (((s32 (*)(s32, s32))func_801A395C)(a0, -0x250) != 0) {
        func_801A36A8(a0);
    }
    func_801AAA6C(a0);
    func_801A370C(a0);
    if (D_8019FF8A & 0x400) {
        func_801A36F0((void *)a0);
        {
            void *v0 = *(void **)(a0 + 0xD4);
            if (v0 != NULL) {
                func_801A7C58(v0);
            }
        }
        func_801A8C58(a0);
        func_801A85A8(a0, 0x1A040A0, 0, 0x200);
        if (D_801F8714 != 0) {
            func_801A1984(a0);
            *(s32 *)(a0 + 0x1C) = 0x30;
        } else {
            func_801A2364(a0);
        }
    } else if (func_8012BEE8(a0) != 0) {
        u16 v0 = D_8019FF8A;
        *(s16 *)(a0 + 0xAE) = -1;
        D_8019FF8A = v0 & 0xFFFE;
        func_801A1984(a0);
    }
}
