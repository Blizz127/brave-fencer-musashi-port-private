/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80137DD4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { u32 addr : 24; u32 len : 8; u8 r0, g0, b0, code; } P_TAG_80137DD4;
typedef void (*code)(unsigned short *);
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void *func_80010A08(s32);
extern void func_80137FD8(s32 a0, s32 a1, s32 a2, s32 a3);

void func_80137DD4(s32 ent, u8 *arg, u8 *work) {
    register s32 t __asm__("$4");
    s32 d, c, c1, sub, y;
    u32 b;
    P_TAG_80137DD4 *q, *r;
    {
        register u32 h12 __asm__("$2"), h16 __asm__("$3");
        h12 = *(u16 *)(ent + 0x12);
        h16 = *(u16 *)(ent + 0x16);
        t = h12 - h16;
    }
    d = t;
    if ((s16)t < 0) {
        register s32 e __asm__("$2");
        e = t + 1;
        d = (u32)*(u16 *)(ent + 0x2e) + e;
    }
    b = *(volatile u8 *)(ent + 0x1f);
    c = (s8)b;
    sub = d - (u32)*(u8 *)(ent + 0x21);
    c1 = c + 1;
    y = (u32)*(u16 *)(ent + 0x32) + (s16)(sub + c1) * 0xe;
    q = (P_TAG_80137DD4 *)func_80010A08(0x48);
    *(u8 *)(arg + 3) = 0;
    func_80137FD8(ent, (s32)arg, (s32)q, (s16)y);
    q->addr = ((P_TAG_80137DD4 *)((u32)*(u16 *)(ent + 0x1a) * 4 + *(s32 *)(work + 4)))->addr;
    ((P_TAG_80137DD4 *)((u32)*(u16 *)(ent + 0x1a) * 4 + *(s32 *)(work + 4)))->addr = (u32)q;
    q = (P_TAG_80137DD4 *)((u8 *)q + 0x24);
    *(u8 *)(arg + 3) = 1;
    func_80137FD8(ent, (s32)arg, (s32)q, (s16)y);
    q->addr = ((P_TAG_80137DD4 *)((u32)*(u16 *)(ent + 0x1a) * 4 + *(s32 *)(work + 4)))->addr;
    ((P_TAG_80137DD4 *)((u32)*(u16 *)(ent + 0x1a) * 4 + *(s32 *)(work + 4)))->addr = (u32)q;
    r = (P_TAG_80137DD4 *)func_80010A08(8);
    r->len = 1;
    *(u32 *)((u8 *)r + 4) = 0xe100000a;
    r->addr = ((P_TAG_80137DD4 *)((u32)*(u16 *)(ent + 0x1a) * 4 + *(s32 *)(work + 4)))->addr;
    ((P_TAG_80137DD4 *)((u32)*(u16 *)(ent + 0x1a) * 4 + *(s32 *)(work + 4)))->addr = (u32)r;
}
