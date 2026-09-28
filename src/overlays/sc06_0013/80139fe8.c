/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139FE8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8001B22C(void *a0);
extern void func_8001931C(void);
extern void func_80139788(void);
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);

void func_80139FE8(void *a0) {
    s32 v1;
    s32 a0v;
    v1 = func_8001B22C(a0);
    if (v1 == 2 || v1 == 4) {
        *(s16 *)((u8 *)a0 + 4) = 2;
    } else if (v1 == 0) {
        a0v = *(s32 *)((u8 *)a0 + 8);
        if (a0v & 1) {
            func_8001931C();
        } else {
            *(s32 *)((u8 *)a0 + 8) = (a0v & 0xFFFEFFFF) | 0x20020;
            func_80139788();
        }
        *(s16 *)((u8 *)a0 + 4) = 2;
    } else {
        func_80139A8C((s32)a0);
        if (*(s32 *)((u8 *)a0 + 8) & 0x20) {
            *(s16 *)((u8 *)a0 + 4) = 2;
        }
    }
    func_80139B18((s32)a0);
}
