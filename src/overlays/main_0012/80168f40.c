/* Overlay range [80168F40,8016901C) from MAIN.CD member 0012.
 * SHA256(span)=3e1a122a103c2614c26c8512c84e405298203495a660bbe2fd0e87f8c9732c3f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80168F40 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { s32 w[8]; } Blk20;
typedef struct { s32 w0, w4, w8, wC; s16 h10, hpad; s32 t0, t1, t2; } Mat32;
extern Mat32 D_800AE620;
typedef struct {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 pad06;
    u16 f08;
    u16 f0A;
    u16 f0C;
    u16 pad0E;
    u8  f10;
    u8  f11;
    u8  f12;
    u8  pad13;
    u8  f14;
    u8  f15;
    u8  f16;
    u8  pad17;
    u32 f18;
} S1_80168F40;
extern s32 func_80016A5C();

void func_80168F40(void *a0)
{
     


    extern Mat32 D_800AE620;
    S1_80168F40 s1;
    Blk20 s2;
    s32 pad[2];

    s1.f00 = *(u16 *)((s32)a0 + 0x10);
    s1.f02 = *(u16 *)((s32)a0 + 0x14);
    s1.f04 = *(u16 *)((s32)a0 + 0x18);
    s1.f08 = *(u16 *)((s32)a0 + 0x6);
    s1.f0A = *(u16 *)((s32)a0 + 0xA);
    s1.f0C = *(u16 *)((s32)a0 + 0xE);
    s1.f10 = 8;
    s1.f14 = 0xC0;
    s1.f12 = 0;
    s1.f11 = 0;
    s1.f16 = 0x80;
    s1.f15 = 0x80;
    s2 = (*(Blk20 *)&D_800AE620);
    s1.f18 = 0x50000000;
    func_80016A5C(&s1, &s2);
}
