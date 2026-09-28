/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CF290 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CF290(void) {
    extern u16 D_800B9A02;
    extern u8 D_800D3AEC[];
    extern u8 D_800D3B1C[];
    extern u8 D_800D3C10_b __asm__("D_800D3C10");
    extern u8 D_800AA60C[];

    register s32 n __asm__("$7") = D_800B9A02;
    register u8 *p0 __asm__("$4");
    register u8 *p1 __asm__("$3");
    register u32 c5 __asm__("$6");
    register u32 c64 __asm__("$13");
    register u32 c7840 __asm__("$14");
    register u32 cm28 __asm__("$12");
    register u32 c38 __asm__("$11");
    register u32 c256 __asm__("$10");
    register u32 c60 __asm__("$9");
    u32 *q0;
    u32 *q1;
    u32 *ot;
    u8 c;
    s32 w;
    u32 t;

    {
        u32 e1a = 0xE100008A;

        w = n * 24;
        p0 = D_800D3AEC + w;
        q0 = (u32 *)(D_800D3AEC + w + 4);
        c5 = 5;
        p0[3] = c5;
        *q0 = e1a;
    }
    c64 = 0x64;
    p0[0xB] = c64;
    *(s16 *)(p0 + 0xC) = -0x100;
    c = D_800D3C10_b;
    n <<= 14;
    c7840 = 0x7840;
    cm28 = -28;
    *(s16 *)(p0 + 0x12) = c7840;
    *(s16 *)(p0 + 0xE) = cm28;
    c38 = 0x38;
    c256 = 0x100;
    p0[0x10] = 0;
    p0[0x11] = c38;
    *(s16 *)(p0 + 0x14) = c256;
    c60 = 0x60;
    *(s16 *)(p0 + 0x16) = c60;
    p0[0xA] = c;
    p0[9] = c;
    p0[8] = c;

    p1 = D_800D3B1C + w;
    q1 = (u32 *)(D_800D3B1C + w + 4);
    {
        register u32 e1b __asm__("$8") = 0xE100008C;
        p1[3] = c5;
        *q1 = e1b;
    }
    t = *(u32 *)p1;
    p1[0xB] = c64;
    c = D_800D3C10_b;
    *(s16 *)(p1 + 0x12) = c7840;
    *(s16 *)(p1 + 0xC) = 0;
    *(s16 *)(p1 + 0xE) = cm28;
    p1[0x10] = 0;
    p1[0x11] = c38;
    *(s16 *)(p1 + 0x14) = c256;
    *(s16 *)(p1 + 0x16) = c60;
    p1[0xA] = c;
    p1[9] = c;
    p1[8] = c;

    ot = (u32 *)(D_800AA60C + n);
    {
        register u32 m24 __asm__("$8");
        register u32 mFF __asm__("$5");

        m24 = 0xFFFFFF;
        mFF = 0xFF000000;
        *(u32 *)p1 = (t & mFF) | (*ot & m24);
        *ot = (*ot & mFF) | ((u32)p1 & m24);
        *(u32 *)p0 = (*(u32 *)p0 & mFF) | (*ot & m24);
        *ot = (*ot & mFF) | ((u32)p0 & m24);
    }
}
