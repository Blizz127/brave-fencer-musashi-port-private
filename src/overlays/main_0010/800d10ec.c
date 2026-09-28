/* MAIN10 resident retail span [800D10EC,800D11F0), offset 0x222F4 at base 800AEDF8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D10EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_800291B4();
extern s32 func_800291DC(s32);
extern void func_800291A0(s32, s32);
extern void func_800291C8(s32, s32);
typedef struct {
    u8 pad00[0x34];
    s16 field_0x34;    /* 0x34 */
} Struct80078E78;
extern Struct80078E78 D_80078E78;
extern u8 D_8010EDF0;
extern u8 D_8010EDF1;
extern s16 D_80078EAC;

void func_800D10EC(void) {
    s16 i;
    Struct80078E78 *p = &D_80078E78;

    for (i = 0; i < 0xC; i++) {
        s32 v1;
        s32 idx;
        s32 s0;
        s32 j;

        v1 = func_800291B4(i + 0x2F) & 0xFF;
        if (v1 == 0) {
            continue;
        }
        idx = v1 * 0xC;
        s0 = (&D_8010EDF0)[idx];
        if (s0 == 0) {
            continue;
        }
        j = i * 2 + 0x14;
        {
            s32 r = (s16)func_800291DC(j);   /* sign-extend FIRST (sll/sra scheduled early) */
            s32 f = p->field_0x34;            /* then load the field (lh between sll and sra) */
            if (f - r < s0) {
                continue;
            }
        }
        func_800291A0(i + 0x2F, (&D_8010EDF1)[idx]);
        func_800291C8(j, D_80078EAC);
    }
}
