/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCE80 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixY func_8004A0DC
extern void func_80013F3C(void *a0);
extern void RotMatrixY(s32 a0, void *a1);
extern void func_80048D9C(void *a0, void *a1);
extern void func_80020F34(s32 a0, s32 a1);

void func_800CCE80(void *arg0) {
    void *s2;
    void *s1;
    void *s0;
    void *p;

    s2 = *(void **)((u8 *)arg0 + 0x4C);
    p = *(void **)((u8 *)s2 + 0x20);
    s1 = *(void **)((u8 *)arg0 + 0x20);
    *(s16 *)((u8 *)arg0 + 0x06) = *(s32 *)((u8 *)p + 0x48);
    *(s16 *)((u8 *)arg0 + 0x0A) = *(s32 *)((u8 *)p + 0x4C) - 0x20;
    s0 = (void *)((u8 *)s1 + 0x34);
    *(s16 *)((u8 *)arg0 + 0x0E) = *(s32 *)((u8 *)p + 0x50);
    func_80013F3C(s0);
    RotMatrixY(*(s16 *)((u8 *)s1 + 0x12), s0);
    func_80048D9C(s0, (void *)((u8 *)*(void **)((u8 *)s2 + 0x20) + 0x34));
    func_80020F34((s32)s0, (s32)((u8 *)s1 + 0x18));
    *(u16 *)((u8 *)s1 + 0x2C) |= 1;
}
