/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017DA30 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern s32 rand(void);
extern int rand(void);
extern u8 D_800D387C[];
extern u8 D_800D3888[];
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80128EA8();
extern u8 D_801817A4[];
extern u8 D_801817B0[];

void func_8017DA30(s32 a0) {
    register s32 ent __asm__("$16");
    s32 sub;
    s32 hw;
    u32 r;

    ent = a0;
    sub = *(s32 *)((u8 *)ent + 0x20);
    if (*(s16 *)((u8 *)ent + 0x2E) != 0) {
        func_8001CC3C(sub, (s32)D_800D387C, 0, 0);
        *(u8 *)((u8 *)sub + 0x27) = 0x9C;
        *(u16 *)((u8 *)sub + 0x1A) = 0x4000;
        *(u16 *)((u8 *)sub + 0x18) = 0x4000;
        *(s32 *)((u8 *)sub + 4) |= 0x50000040;
        func_80128EA8(sub, (s32)((u8 *)ent + 0x24), (s32)D_800D3888);
        hw = 0x2C;
    } else {
        register s32 q __asm__("$4");
        register s32 p __asm__("$5");
        register s32 e __asm__("$6");
        func_8001CC3C(sub, (s32)D_801817A4, 0, 0);
        q = sub;
        p = (s32)((u8 *)ent + 0x24);
        e = (s32)D_801817B0;
        __asm__ __volatile__("" : "=r"(q), "=r"(p), "=r"(e) : "0"(q), "1"(p), "2"(e));
        *(u8 *)((u8 *)q + 0x27) = 0x33;
        func_80128EA8(q, p, e);
        hw = 0x1C;
    }
    *(u16 *)((u8 *)ent + 0x1A) = hw;
    r = rand();
    *(s16 *)((u8 *)ent + 0x12) = (r & 0x3F) - 0x20;
    *(u16 *)((u8 *)ent + 0x16) = 0x20 - ((r >> 4) & 0x3F);
    *(u16 *)((u8 *)ent + 2) += 1;
}
