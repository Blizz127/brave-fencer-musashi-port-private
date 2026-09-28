/* MAIN10 resident retail span [800D1658,800D1714), offset 0x22860 at base 800AEDF8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D1658 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_800291B4();
extern void func_800291A0(s32 arg0, s32 arg1);
extern s16 D_8010EDEC;
extern void func_8002D4C8(s32, s32);

s16 func_800D1658(s32 arg0) {
    extern int func_800291B4(int);
    extern void func_800291A0(int, int);
    extern void func_8002D4C8(int, int);
    extern s16 D_8010EDEC;
    register int v __asm__("$2");
    register int t __asm__("$3");
    int id;
    register short ret __asm__("$16");
    int slot;

    slot = (arg0 & 0xFF) + 0x2F;
    id = func_800291B4(slot) & 0xFF;
    if (id == 0) {
        return 0;
    }
    v = *(s16 *)((u8 *)&D_8010EDEC + id * 0xC);
    if (v > 0) {
        goto ok;
    }
    ret = v;
    t = ret & 0xFFFF;
    if (t != 0x8000) {
        goto bad;
    }
    if (id == 0x27) {
        goto bad;
    }
ok:
    func_800291A0(slot, 0);
    func_8002D4C8(0x462, 0);
    ret = 1;
    goto out;
bad:
    ret = 0;
    func_8002D4C8(0x45F, 0);
out:
    return ret;
}
