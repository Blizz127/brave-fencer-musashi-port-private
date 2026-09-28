/* Exact retail word export for [8002823C,80028304); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8002823C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_800A5E88;
extern s32 D_800A5E8C;
extern s32 D_800A5E90;
extern u8 D_800A5E94;
extern u8 D_800A5E95;
extern u8 D_800A5E96;
extern void func_80028620(s32 a0, void *a1);

void func_8002823C(void) {
    s32 i;
    s32 a;
    s32 b;
    u8 *p;
    s32 off;

    i = 0;
    a = 0x800;
    b = 0x20;
    p = &D_800A5E88;
    off = 0;
    do {
        *(s32 *)((s32)&D_800A5E88 + off) = a;
        *(s32 *)((s32)&D_800A5E8C + off) = a;
        *(s32 *)((s32)&D_800A5E90 + off) = 0;
        *(u8 *)((s32)&D_800A5E94 + off) = b;
        *(u8 *)((s32)&D_800A5E95 + off) = b;
        *(u8 *)((s32)&D_800A5E96 + off) = b;
        func_80028620(i, p);
        p += 0x10;
        i++;
        off += 0x10;
    } while (i < 3);
}
