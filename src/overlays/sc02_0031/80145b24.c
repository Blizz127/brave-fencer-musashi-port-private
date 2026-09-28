/* Complete SC02 retail span [80145B24,80145BF8).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80145B24 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029504(void);
extern s32 func_800291DC(s32);
extern void func_800291C8(s32, s32);
extern void func_80162120(void);
extern void func_80029124(s32, s32);
extern s32 func_80165A50(s32);
extern void func_80029514(s32);
extern u8 D_800AF630[];
extern u8 D_80078EC0;
extern s32 D_80126B58;

void func_80145B24(void)
{
    s32 iVar1;
    s32 uVar2;
    register u8 *p __asm__("$17");
    p = &D_800AF630;
    iVar1 = func_80029504();
    uVar2 = func_800291DC(8);
    if ((uVar2 & 0x8000) != 0) {
        func_800291C8(8, 0);
        func_80162120();
    }
    if (iVar1 >= 0x6A4) {
        func_80029124(0x1A, 0);
        func_80029124(0x8E, 0);
        func_80029124(0x143, 0);
        if ((D_80078EC0 & 0x7F) != 0) {
            D_80078EC0 = 1;
        }
        func_80165A50((s32)&D_80126B58);
        func_80029514(0x4B0);
    }
    *(s16 *)(p + 0xA3DA) = 0x3000;
}
