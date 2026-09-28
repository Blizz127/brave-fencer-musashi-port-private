/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AC59C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern void func_8017E5D4(void *a0);
extern void func_8017E1E8(void *a0, void *a1, void *a2);
extern void func_8012AD80(s32 a0);
extern void func_801AA004(void *a0, void *a1);
extern void func_801AA210(void *a0, void *a1, void *a2);
extern void func_801AA4A8(void *a0, void *a1);

void func_801AC59C(void *arg0) {
    void *s2;
    s8 sp10[0x20];
    s8 sp30[0x18];

    s2 = *(void **)((u8 *)arg0 + 0x20);
    if (func_8012BEE8((s32)arg0) != 0) {
        if (*(void **)((u8 *)arg0 + 0xCC) != NULL) {
            func_8017E5D4(*(void **)((u8 *)arg0 + 0xCC));
        }
        if (*(void **)((u8 *)arg0 + 0xD0) != NULL) {
            func_8017E5D4(*(void **)((u8 *)arg0 + 0xD0));
        }
        func_8012C218(arg0);
    } else {
        s16 v0;
        s16 v1;

        v0 = *(s16 *)((u8 *)s2 + 0x18);
        v1 = v0;
        if (v0 < 0x1800) {
            v1 += 0x100;
            *(s16 *)((u8 *)s2 + 0x18) = v1;
            *(u16 *)((u8 *)s2 + 0x1A) += 0x40;
        }
        func_801AA004(arg0, sp10);
        func_801AA210(arg0, sp10, sp30);
        if (*(void **)((u8 *)arg0 + 0xCC) != NULL) {
            func_8017E1E8(*(void **)((u8 *)arg0 + 0xCC), sp30, sp30 + 8);
        }
        if (*(void **)((u8 *)arg0 + 0xD0) != NULL) {
            func_8017E1E8(*(void **)((u8 *)arg0 + 0xD0), sp30, sp30 + 0x10);
        }
        *(u16 *)((u8 *)s2 + 0x14) += *(u16 *)((u8 *)arg0 + 0xFE);
        func_8012AD80((s32)arg0);
        func_801AA4A8(arg0, sp30);
    }
}
