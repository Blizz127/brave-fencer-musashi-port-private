/* Overlay range [800CF6D0,800CFAB4) from MAIN.CD member 0007.
 * SHA256(span)=abf48c3ddfc7a59903cfa9026795774daa7a10efaaa81adaeaac73b810d18d5e.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_800CF6D0 - 249 words. Promoted from vendor/bfm-decomp
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

void func_800CF6D0(s32 arg0, u32 arg1) {
    u8 *p;
    typedef struct { u32 addr:24; u32 len:8; } P_TAG;
    u8 *ob;
    u32 m24;

    p = D_800A5E60;
    arg0 -= 0xA0;
    arg1 -= 0x78;
    ob = D_800AA60C;

    *(u8 *)(p + 0x3) = 5;
    *(u32 *)(p + 0x4) = 0xE1000089;
    *(u8 *)(p + 0xB) = 0x64;
    *(u16 *)(p + 0x12) = 0x7940;
    *(u8 *)(p + 0x8) = *(u8 *)(p + 0x9) = *(u8 *)(p + 0xA) = 0x80;
    *(s16 *)(p + 0xC) = arg0;
    *(s16 *)(p + 0xE) = arg1;
    *(u8 *)(p + 0x10) = 0;
    *(u8 *)(p + 0x11) = 0;
    *(s16 *)(p + 0x14) = 0x100;
    *(s16 *)(p + 0x16) = 0x100;
    m24 = 0xFFFFFF;
    {
        u32 v = (*(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)) & m24) & m24;
        u32 t = *(u32 *)p;
        t &= 0xFF000000;
        t |= v;
        *(u32 *)p = t;
    }
    ((P_TAG *)(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)))->addr = (u32)p;
    p += 0x18;

    *(u8 *)(p + 0x3) = 5;
    *(u32 *)(p + 0x4) = 0xE100008B;
    *(u8 *)(p + 0xB) = 0x64;
    *(u16 *)(p + 0x12) = 0x7940;
    *(u8 *)(p + 0x8) = *(u8 *)(p + 0x9) = *(u8 *)(p + 0xA) = 0x80;
    *(s16 *)(p + 0xC) = arg0 + 0x100;
    *(s16 *)(p + 0xE) = arg1;
    *(u8 *)(p + 0x10) = 0;
    *(u8 *)(p + 0x11) = 0;
    *(s16 *)(p + 0x14) = 0x100;
    *(s16 *)(p + 0x16) = 0x100;
    {
        u32 v = (*(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)) & m24) & m24;
        u32 t = *(u32 *)p;
        t &= 0xFF000000;
        t |= v;
        *(u32 *)p = t;
    }
    ((P_TAG *)(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)))->addr = (u32)p;
    p += 0x18;

    *(u8 *)(p + 0x3) = 5;
    *(u32 *)(p + 0x4) = 0xE100008D;
    *(u8 *)(p + 0xB) = 0x64;
    *(u16 *)(p + 0x12) = 0x7940;
    *(u8 *)(p + 0x8) = *(u8 *)(p + 0x9) = *(u8 *)(p + 0xA) = 0x80;
    *(s16 *)(p + 0xC) = arg0 + 0x200;
    *(s16 *)(p + 0xE) = arg1;
    *(u8 *)(p + 0x10) = 0;
    *(u8 *)(p + 0x11) = 0;
    *(s16 *)(p + 0x14) = 0x100;
    *(s16 *)(p + 0x16) = 0x100;
    {
        u32 v = (*(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)) & m24) & m24;
        u32 t = *(u32 *)p;
        t &= 0xFF000000;
        t |= v;
        *(u32 *)p = t;
    }
    ((P_TAG *)(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)))->addr = (u32)p;
    p += 0x18;

    *(u8 *)(p + 0x3) = 5;
    *(u32 *)(p + 0x4) = 0xE100008F;
    *(u8 *)(p + 0xB) = 0x64;
    *(u16 *)(p + 0x12) = 0x7940;
    *(u8 *)(p + 0x8) = *(u8 *)(p + 0x9) = *(u8 *)(p + 0xA) = 0x80;
    *(s16 *)(p + 0xC) = arg0 + 0x300;
    *(s16 *)(p + 0xE) = arg1;
    *(u8 *)(p + 0x10) = 0;
    *(u8 *)(p + 0x11) = 0;
    *(s16 *)(p + 0x14) = 0x40;
    *(s16 *)(p + 0x16) = 0x100;
    {
        u32 v = (*(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)) & m24) & m24;
        u32 t = *(u32 *)p;
        t &= 0xFF000000;
        t |= v;
        *(u32 *)p = t;
    }
    ((P_TAG *)(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)))->addr = (u32)p;
    p += 0x18;

    *(u8 *)(p + 0x3) = 5;
    *(u32 *)(p + 0x4) = 0xE1000086;
    *(u8 *)(p + 0xB) = 0x64;
    *(u16 *)(p + 0x12) = 0x7880;
    *(u8 *)(p + 0x8) = *(u8 *)(p + 0x9) = *(u8 *)(p + 0xA) = 0x80;
    *(s16 *)(p + 0xC) = -0xA0;
    *(s16 *)(p + 0xE) = -0x78;
    *(u8 *)(p + 0x10) = 0x20;
    *(u8 *)(p + 0x11) = 0;
    *(s16 *)(p + 0x14) = 0xA0;
    *(s16 *)(p + 0x16) = 0x100;
    {
        u32 v = (*(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)) & m24) & m24;
        u32 t = *(u32 *)p;
        t &= 0xFF000000;
        t |= v;
        *(u32 *)p = t;
    }
    ((P_TAG *)(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)))->addr = (u32)p;
    p += 0x18;

    *(u8 *)(p + 0x3) = 5;
    *(u32 *)(p + 0x4) = 0xE1000087;
    *(u8 *)(p + 0xB) = 0x64;
    *(u16 *)(p + 0x12) = 0x7880;
    *(u8 *)(p + 0x8) = *(u8 *)(p + 0x9) = *(u8 *)(p + 0xA) = 0x80;
    *(s16 *)(p + 0xC) = 0;
    *(s16 *)(p + 0xE) = -0x78;
    *(u8 *)(p + 0x10) = 0x40;
    *(u8 *)(p + 0x11) = 0;
    *(s16 *)(p + 0x14) = 0xA0;
    *(s16 *)(p + 0x16) = 0x100;
    {
        u32 v = (*(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)) & m24) & m24;
        u32 t = *(u32 *)p;
        t &= 0xFF000000;
        t |= v;
        *(u32 *)p = t;
    }
    ((P_TAG *)(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)))->addr = (u32)p;
    p += 0x18;

    D_800A5E60 = p;
}
