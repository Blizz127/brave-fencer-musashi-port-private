/* Overlay range [800CF408,800CF6D0) from MAIN.CD member 0007.
 * SHA256(span)=5decf1ffd0193323d0c7efd3ffe43b7e2dcdb7a07277476b8fc36a122d286477.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_800CF408 - 178 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u16 D_800B99E4;
extern u8 D_800CFABF;
extern u8 D_800CFAC4[];
extern u8 D_800CFAD4[];
extern void (*D_800CFADC[])(void);
extern s32 D_800D1364;
extern u8 D_800AF630[];
extern void func_8001534C(int, void *, int, int, int, int);
extern void func_8001C044(void);
extern void func_80015310(void);
extern void func_800183E0(void *a0);
extern void func_800167B8(s32 a0);
extern void func_800118AC(void);
extern s8 D_800B9A11;
extern u16 D_800B99E8;
extern s32 D_800D130C;
extern s32 func_800167F0(s32 a0);
extern u16 D_800B99E6;
extern void (*D_800D133C[])(void);
extern void func_8001AA98(void *a0);
extern s32 D_800D1368;
extern s32 D_800D1370;
extern s32 D_800D1374;
extern void (*D_800D1344[])(void);
extern void func_800CF408(s32 a0, s32 a1);
extern void func_800CF6D0(s32 a0, u32 a1);
extern s32 D_800D136C;
extern s32 func_800CF3B0();
extern s32 func_800149E0(s32);
extern u8 *D_800A5E60;
extern u32 wD_800AA60C[] __asm__("D_800AA60C");
extern s16 D_800B9A02;
extern u8 D_800AA60C[];

void func_800CF408(s32 x, s32 y) {
    u8 *p;
    u32 m24;

    p = D_800A5E60;
    x -= 0xA0;
    y -= 0x78;

    *(u8 *)(p + 0x3) = 5;
    *(u32 *)(p + 0x4) = 0xE1000086;
    *(u8 *)(p + 0xB) = 0x64;
    *(u16 *)(p + 0x12) = 0x7980;
    *(u8 *)(p + 0x8) = *(u8 *)(p + 0x9) = *(u8 *)(p + 0xA) = 0x80;
    *(s16 *)(p + 0xC) = x;
    *(s16 *)(p + 0xE) = y;
    *(u8 *)(p + 0x10) = 0x20;
    *(u8 *)(p + 0x11) = 0;
    *(s16 *)(p + 0x14) = 0xA0;
    *(s16 *)(p + 0x16) = 0x100;
    m24 = 0x00FFFFFF;
    {
        u32 v = (wD_800AA60C[(u16)D_800B9A02 * 0x1000] & m24) & m24;
        u32 t = *(u32 *)p;
        t &= 0xFF000000;
        t |= v;
        *(u32 *)p = t;
    }
    {
        s32 oi = (u16)D_800B9A02 * 0x1000;
        wD_800AA60C[oi] = (wD_800AA60C[oi] & 0xFF000000) | ((u32)p & m24);
    }
    p += 0x18;

    *(u8 *)(p + 0x3) = 5;
    *(u32 *)(p + 0x4) = 0xE1000087;
    *(u8 *)(p + 0xB) = 0x64;
    *(u16 *)(p + 0x12) = 0x7980;
    *(u8 *)(p + 0x8) = *(u8 *)(p + 0x9) = *(u8 *)(p + 0xA) = 0x80;
    *(s16 *)(p + 0xC) = x + 0xA0;
    *(s16 *)(p + 0xE) = y;
    *(u8 *)(p + 0x10) = 0x40;
    *(u8 *)(p + 0x11) = 0;
    *(s16 *)(p + 0x14) = 0xA0;
    *(s16 *)(p + 0x16) = 0x100;
    {
        u32 v = (wD_800AA60C[(u16)D_800B9A02 * 0x1000] & m24) & m24;
        u32 t = *(u32 *)p;
        t &= 0xFF000000;
        t |= v;
        *(u32 *)p = t;
    }
    {
        s32 oi = (u16)D_800B9A02 * 0x1000;
        wD_800AA60C[oi] = (wD_800AA60C[oi] & 0xFF000000) | ((u32)p & m24);
    }
    p += 0x18;

    *(u8 *)(p + 0x3) = 5;
    *(u32 *)(p + 0x4) = 0xE1000096;
    *(u8 *)(p + 0xB) = 0x64;
    *(u16 *)(p + 0x12) = 0x7980;
    *(u8 *)(p + 0x8) = *(u8 *)(p + 0x9) = *(u8 *)(p + 0xA) = 0x80;
    *(s16 *)(p + 0xC) = x;
    *(s16 *)(p + 0xE) = y + 0x100;
    *(u8 *)(p + 0x10) = 0x20;
    *(u8 *)(p + 0x11) = 0;
    *(s16 *)(p + 0x14) = 0xA0;
    *(s16 *)(p + 0x16) = 0x100;
    {
        u32 v = (wD_800AA60C[(u16)D_800B9A02 * 0x1000] & m24) & m24;
        u32 t = *(u32 *)p;
        t &= 0xFF000000;
        t |= v;
        *(u32 *)p = t;
    }
    {
        s32 oi = (u16)D_800B9A02 * 0x1000;
        wD_800AA60C[oi] = (wD_800AA60C[oi] & 0xFF000000) | ((u32)p & m24);
    }
    p += 0x18;

    *(u8 *)(p + 0x3) = 5;
    *(u32 *)(p + 0x4) = 0xE1000097;
    *(u8 *)(p + 0xB) = 0x64;
    *(u16 *)(p + 0x12) = 0x7980;
    *(u8 *)(p + 0x8) = *(u8 *)(p + 0x9) = *(u8 *)(p + 0xA) = 0x80;
    *(s16 *)(p + 0xC) = x + 0xA0;
    *(s16 *)(p + 0xE) = y + 0x100;
    *(u8 *)(p + 0x10) = 0x40;
    *(u8 *)(p + 0x11) = 0;
    *(s16 *)(p + 0x14) = 0xA0;
    *(s16 *)(p + 0x16) = 0x100;
    {
        u32 v = (wD_800AA60C[(u16)D_800B9A02 * 0x1000] & m24) & m24;
        u32 t = *(u32 *)p;
        t &= 0xFF000000;
        t |= v;
        *(u32 *)p = t;
    }
    {
        s32 oi = (u16)D_800B9A02 * 0x1000;
        wD_800AA60C[oi] = (wD_800AA60C[oi] & 0xFF000000) | ((u32)p & m24);
    }
    p += 0x18;

    D_800A5E60 = p;
}
