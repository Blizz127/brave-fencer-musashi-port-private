/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172E20,80172E8C).
 * Offset 0x4ACC8 at overlay base 80128158. SHA256(span)=cff09b337e305685cdd4962700d5140659af68a902920672885ab52ca8505658.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172e20.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172E20 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct Src80172E20 {
    u8 pad0[6];
    u16 _6;
    u8 pad8[0xA - 8];
    u16 _A;
    u8 padC[0xE - 0xC];
    u16 _E;
};
extern void func_8012A568(void (*a0)(void));
extern s32 D_80127508;
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);

void func_80172E20(u8 * a0)
{
    struct Src80172E20 *p = (struct Src80172E20 *)D_80127508;
    u16 sp10[3];
    sp10[0] = p->_6;
    sp10[1] = p->_A;
    sp10[2] = p->_E;
    if (func_80171AB0(a0, sp10) == 0) {
        func_80171A1C((u8 *)a0);
        func_80174650(a0);
    }
}
