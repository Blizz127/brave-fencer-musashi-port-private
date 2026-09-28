/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A9674 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_8012AD80(s32 a0);
extern void func_801A9810();
extern void func_801A9908(void *a0, s32 a1);
extern void func_801A9954(void *a0);
extern u16 D_801B070C[];

void func_801A9674(void *a0) {
    void *s0 = a0;
    void *s1;
    void *s2;
    s32 s3;
    s32 sq0;
    s32 sq1;

    s1 = *(void **)((s32)s0 + 0xCC);
    s2 = *(void **)((s32)s0 + 0xD0);

    func_80128ED8((s32)s1, (s32 *)((s32)s0 + 0xF0));

    *(u8 *)((s32)s1 + 0x27) = (u8)D_801B070C[*(s16 *)((s32)s0 + 0xF4)];

    func_8012AD80((s32)s0);

    *(s16 *)((s32)s1 + 0x8) = *(u16 *)((s32)s0 + 0x6);
    *(s16 *)((s32)s1 + 0xA) = *(u16 *)((s32)s0 + 0xA);
    *(s16 *)((s32)s1 + 0xC) = *(u16 *)((s32)s0 + 0xE);

    if (*(s16 *)((s32)s0 + 0xFE) != 0) {
        s3 = 0x30;
        *(s16 *)((s32)s1 + 0x18) = (*(s16 *)((s32)s0 + 0xA) + 0x1400) * 2;
        *(s16 *)((s32)s1 + 0x1A) = (0x1000 - *(s16 *)((s32)s0 + 0xA)) * 6;
    } else {
        s3 = 0x18;
    }

    if (*(s16 *)((s32)s0 + 0xA) >= -0x200) {
        sq0 = *(s16 *)((s32)s0 + 0x6) * *(s16 *)((s32)s0 + 0x6);
        sq1 = *(s16 *)((s32)s0 + 0xE) * *(s16 *)((s32)s0 + 0xE);
        *(s16 *)((s32)s0 + 0xA) = -0x200;
        if (sq0 + sq1 > 0xFFFFF) {
            func_801A9954(s0);
            return;
        }
        func_801A9810(s0);
    } else {
        if (*(s16 *)((s32)s0 + 0xFE) != 0 && s2 != NULL) {
            s1 = *(void **)((s32)s2 + 0xCC);
            if (s1 != NULL) {
                s32 v = (*(s16 *)((s32)s0 + 0xA) + 0x500) * 40;
                *(s16 *)((s32)s1 + 0x1A) = v;
                *(s16 *)((s32)s1 + 0x18) = v;
            }
        }
    }
    func_801A9908(s0, s3);
}
