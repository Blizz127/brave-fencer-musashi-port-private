/* Complete SC02 retail span [80182674,80182848).
 * SC02 820xx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80182674 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
extern void func_8012A568(void (*a0)(void));
extern s32 func_8005C49C(void);
extern s32 func_80132EF4(s32 a0, s32 a1);
typedef struct { u16 x, y, z, w; } Vec8_80182674;

void func_80182674(s32 a0, s16 *vec, s32 count, s32 flag) {
    s32 i;
    Vec8_80182674 sp10;

    sp10 = *(Vec8_80182674 *)vec;
    for (i = 0; i < count; i++) {
        s32 tA, oldA, valA, tB, oldB, valB;
        s32 r1, r2;
        s32 ent;

        tA = func_8005C49C() % 320;
        oldA = vec[0];
        if (func_8005C49C() & 1) {
            valA = oldA + tA;
        } else {
            valA = oldA - tA;
        }
        sp10.x = valA;

        if (flag != 0) {
            tB = func_8005C49C() % 80;
            oldB = *(s16 *)((s8 *)vec + 4);
            if (func_8005C49C() & 1) {
                valB = oldB + tB;
            } else {
                valB = oldB - tB;
            }
            sp10.z = valB;
        }

        ent = func_80132EF4(a0, 0x22);
        if (ent != 0) {
            *(u16 *)(ent + 6) = sp10.x;
            *(u16 *)(ent + 0xA) = sp10.y;
            *(u16 *)(ent + 0xE) = sp10.z;
            r1 = func_8005C49C();
            r2 = func_8005C49C();
            *(u16 *)(ent + 0x34) = ((((r1 % 0x2000) + 0x3000) & ~0xF) | (r2 % 3));
        }
    }
}
