/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD57C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146E98(s32 arg0);
extern void func_800CD6D4(void);
extern s32 func_80012FC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8004787C(s32 a0);
extern s32 func_80146E98(s32 a0);
extern void func_80146CA0(void *a0);
extern u8 D_800CD764[];

void func_800CD57C(void *arg0) {
    s32 s0;
    s32 v0;
    s32 t;

    s0 = *(s32 *)((s32)arg0 + 0x20);
    ((void (*)(void *, void *))func_800CD6D4)(
        arg0,
        (void *)(D_800CD764 + (*(s32 *)((s32)arg0 + 0x50) << 6)));
    v0 = func_80012FC8(*(s16 *)(s0 + 0x1A), 0x5000, 0xA, 1);
    t = *(u16 *)(s0 + 0x1A) + v0;
    *(u16 *)(s0 + 0x1A) = t;
    *(u16 *)(s0 + 0x18) = t;
    {
        s32 x;
        x = (s16)t;
        v0 = func_8004787C(x / 10);
    }
    {
        s32 adj;
        s32 v1;
        v1 = *(s16 *)((s32)arg0 + 0x62);
        v0 = v0 * 2;
        v1 = v1 * v0;
        adj = v1 / 0x1000;
        {
            register s32 fld __asm__("$2");
            fld = *(u16 *)((s32)arg0 + 0x60);
            v0 = fld - adj;
        }
    }
    *(u16 *)((s32)arg0 + 0xA) = v0;
    v0 = func_80146E98((s32)arg0);
    if (v0 != 0) {
        func_80146CA0(arg0);
    }
}
