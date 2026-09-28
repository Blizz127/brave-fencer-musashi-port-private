/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD674 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 *D_800A71D0;
extern u32 D_800ABA24[];
extern u16 D_800BAE22;

void func_800CD674(s32 x, s32 y, s32 c) {
    u8 *p;
    register u32 tp0 __asm__("$3") = 0xE1000086;
    register u32 *ot __asm__("$7");
    register u32 m24 __asm__("$9") = 0x00FFFFFF;
    register u32 mff __asm__("$11") = 0xFF000000;
    register u32 tpr __asm__("$17");
    register u32 pm __asm__("$8");
    u32 pm2;
    u32 pm3;
    register u32 otv __asm__("$3");

    p = (u8 *)D_800A71D0;
    tpr = 0xE1000087;
    x -= 0xA0;
    y -= 0x78;

    *(u8  *)(p + 0x3) = 5;
    *(u32 *)(p + 0x4) = tp0;
    *(u8  *)(p + 0xB) = 0x64;
    *(u16 *)(p + 0x12) = 0x7800;
    *(u8 *)(p + 0x8) = *(u8 *)(p + 0x9) = *(u8 *)(p + 0xA) = c;
    *(s16 *)(p + 0xC) = x;
    *(s16 *)(p + 0xE) = y;
    *(u8  *)(p + 0x10) = 0;
    *(u8  *)(p + 0x11) = 0;
    *(s16 *)(p + 0x14) = 0xA0;
    *(s16 *)(p + 0x16) = 0x100;
    ot = (u32 *)((u8 *)D_800ABA24 + (D_800BAE22 << 14));
    *(u32 *)p = (*(u32 *)p & mff) | (*ot & m24);
    ot = (u32 *)((u8 *)D_800ABA24 + (D_800BAE22 << 14));
    pm = (u32)p & m24;
    otv = *ot;
    p += 0x18;
    *ot = (otv & mff) | pm;

    *(u8  *)(p + 0x3) = 5;
    *(u32 *)(p + 0x4) = tpr;
    tpr = 0xE1000097;
    *(u8  *)(p + 0xB) = 0x64;
    *(u16 *)(p + 0x12) = 0x7800;
    *(u8 *)(p + 0x8) = *(u8 *)(p + 0x9) = *(u8 *)(p + 0xA) = c;
    *(s16 *)(p + 0xC) = x + 0xA0;
    *(s16 *)(p + 0xE) = y;
    *(u8  *)(p + 0x10) = 0x20;
    *(u8  *)(p + 0x11) = 0;
    *(s16 *)(p + 0x14) = 0xA0;
    *(s16 *)(p + 0x16) = 0x100;
    ot = (u32 *)((u8 *)D_800ABA24 + (D_800BAE22 << 14));
    *(u32 *)p = (*(u32 *)p & mff) | (*ot & m24);
    ot = (u32 *)((u8 *)D_800ABA24 + (D_800BAE22 << 14));
    pm = (u32)p & m24;
    otv = *ot;
    p += 0x18;
    *ot = (otv & mff) | pm;

    *(u8  *)(p + 0x3) = 5;
    *(u32 *)(p + 0x4) = 0xE1000096;
    *(u8  *)(p + 0xB) = 0x64;
    *(u16 *)(p + 0x12) = 0x7800;
    *(u8 *)(p + 0x8) = *(u8 *)(p + 0x9) = *(u8 *)(p + 0xA) = c;
    *(s16 *)(p + 0xC) = x;
    *(s16 *)(p + 0xE) = y + 0x100;
    *(u8  *)(p + 0x10) = 0;
    *(u8  *)(p + 0x11) = 0;
    *(s16 *)(p + 0x14) = 0xA0;
    *(s16 *)(p + 0x16) = 0x100;
    ot = (u32 *)((u8 *)D_800ABA24 + (D_800BAE22 << 14));
    *(u32 *)p = (*(u32 *)p & mff) | (*ot & m24);
    ot = (u32 *)((u8 *)D_800ABA24 + (D_800BAE22 << 14));
    pm3 = (u32)p & m24;
    otv = *ot;
    p += 0x18;
    *ot = (otv & mff) | pm3;

    *(u8  *)(p + 0x3) = 5;
    *(u32 *)(p + 0x4) = tpr;
    *(u8  *)(p + 0xB) = 0x64;
    *(u16 *)(p + 0x12) = 0x7800;
    *(u8 *)(p + 0x8) = *(u8 *)(p + 0x9) = *(u8 *)(p + 0xA) = c;
    *(s16 *)(p + 0xC) = x + 0xA0;
    *(s16 *)(p + 0xE) = y + 0x100;
    *(u8  *)(p + 0x10) = 0x20;
    *(u8  *)(p + 0x11) = 0;
    *(s16 *)(p + 0x14) = 0xA0;
    *(s16 *)(p + 0x16) = 0x100;
    ot = (u32 *)((u8 *)D_800ABA24 + (D_800BAE22 << 14));
    *(u32 *)p = (*(u32 *)p & mff) | (*ot & m24);
    ot = (u32 *)((u8 *)D_800ABA24 + (D_800BAE22 << 14));
    pm2 = (u32)p & m24;
    otv = *ot;
    p += 0x18;
    D_800A71D0 = p;
    *ot = (otv & mff) | pm2;
    __asm__ volatile("" : "=r"(pm3));
}
