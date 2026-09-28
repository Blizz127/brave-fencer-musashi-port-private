/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB190 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB190(void *arg0) {
    extern void func_80147324(s32);
    extern void func_80146CA0(s32 *);
    extern s32 func_80146E98(s32);
    extern void func_8001382C(s32, void *, void *);
    extern s32 func_80012ABC(s32, s32, s32);
    extern void func_80162FC0(s32 *);
    extern u8 D_800CB8CC;

    void *p;
    void *ptr;
    s32 color;
    u16 w;
    s32 out[3];
    s32 i;
    s32 acc;

    ptr = *(void **)((u8 *)arg0 + 0x4C);
    p = *(void **)((u8 *)arg0 + 0x20);
    color = (*(s32 *)((u8 *)arg0 + 0x1C) & 1) ? 0x80 : 0x40;

    w = (*(u16 *)((u8 *)p + 0x1A) += 0x100);

    *(u8 *)((u8 *)p + 0x26) = color;
    *(u8 *)((u8 *)p + 0x25) = color;
    *(u8 *)((u8 *)p + 0x24) = color;

    *(u16 *)((u8 *)p + 0x18) = w;
    if (*(s16 *)((u8 *)p + 0x1A) >= 0x2001) {
        w = 0x2000;
        *(u16 *)((u8 *)p + 0x1A) = w;
        *(u16 *)((u8 *)p + 0x18) = w;
    }

    {
        s32 r = func_80012ABC(*(s16 *)((u8 *)p + 0x12),
                              *(s16 *)(*(void **)((u8 *)ptr + 0x20) + 0x12), 0x10);
        *(s16 *)((u8 *)p + 0x12) = r;
        func_8001382C((s16)r, (u8 *)arg0 + 0x24, out);
    }

    *(s32 *)((u8 *)arg0 + 0x10) = out[0];
    *(s32 *)((u8 *)arg0 + 0x14) = out[1];
    *(s32 *)((u8 *)arg0 + 0x18) = out[2];

    func_80162FC0((s32 *)arg0);
    if (func_80146E98((s32)arg0) == 0) {
        acc = 0;
        for (i = 0; i < 3; i++) {
            acc |= func_800CB3D8((s32)arg0, (s32)&D_800CB8CC + i * 8);
        }
        if (acc != 0) {
            func_80147324(0x8F0);
            func_80146CA0((s32 *)arg0);
        }
    } else {
        func_80146CA0((s32 *)arg0);
    }
}
