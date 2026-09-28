/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801430F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80142DB8(s32 *a0);
extern s32 func_8012C0EC(s32 a0);
extern void func_80142BB4(s32 *a0, s32 a1, s32 a2);
extern void func_80142C9C(s32 *a0);
extern s32 func_8012BF10(s32 a0, s32 a1);
extern void func_8012AD44(s32 *a0, s16 a1);

void func_801430F4(s32 *a0) {
    if (func_80142DB8(a0) == 1) {
        func_80142BB4(a0, 1, 3);
        return;
    }
    if (*(s16 *)((u8 *)a0 + 0x100) != 0) {
        if (func_8012C0EC(a0) == 0) {
            return;
        }
        func_80142BB4(a0, 0, 3);
        return;
    }
    func_80142C9C(a0);
    if (func_8012BF10((s32)a0, 0x30) != 0) {
        func_8012AD44(a0, 2);
    }
}
