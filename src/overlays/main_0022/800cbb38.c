/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBB38 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32  func_80017DC4(void *a0, void *a1);
extern void func_80048EAC(void *a0, void *a1);
extern s32  func_80017758(void *a0, void *a1);

void func_800CBB38(void *a0, void *a1) {
    u8 buf[0x60];
    u8 *p;
    u8 c, c2, c4;
    u16 ang;

    p = buf + 0x38;

    *(s16 *)(buf + 0x00) = 7;
    *(s16 *)(buf + 0x10) = 0;
    *(s16 *)(buf + 0x08) = 0;
    *(s16 *)(buf + 0x18) = -7;
    *(s16 *)(buf + 0x0A) = 3;
    *(s16 *)(buf + 0x1A) = 0;
    *(s16 *)(buf + 0x02) = 0;
    *(s16 *)(buf + 0x12) = -3;
    *(s16 *)(buf + 0x1C) = 0;
    *(s16 *)(buf + 0x14) = 0;
    *(s16 *)(buf + 0x0C) = 0;
    *(s16 *)(buf + 0x04) = 0;

    c  = *(u8 *)((s32)a0 + 0x30);
    c2 = c >> 2;
    c4 = c2 >> 2;

    *(u8 *)(buf + 0x2A) = c;
    *(u8 *)(buf + 0x26) = c;
    *(u8 *)(buf + 0x28) = c;
    *(u8 *)(buf + 0x24) = c;
    *(u8 *)(buf + 0x29) = c2;
    *(u8 *)(buf + 0x25) = c2;
    *(u8 *)(buf + 0x2C) = c4;
    *(u8 *)(buf + 0x20) = c4;
    *(u8 *)(buf + 0x2E) = c4;
    *(u8 *)(buf + 0x22) = c4;
    *(u8 *)(buf + 0x2D) = c4;
    *(u8 *)(buf + 0x21) = c4;

    *(s32 *)(buf + 0x30) = 0x50000000;

    ang = *(u16 *)((s32)a0 + 0x2C);
    *(s16 *)(buf + 0x5A) = ang;
    *(s16 *)(buf + 0x58) = ang;
    func_80017DC4((void *)(buf + 0x58), p);

    func_80048EAC(a1, p);

    *(s32 *)(buf + 0x4C) = *(s16 *)((s32)a0 + 0x6);
    *(s32 *)(buf + 0x50) = *(s16 *)((s32)a0 + 0xA);
    *(s32 *)(buf + 0x54) = *(s16 *)((s32)a0 + 0xE);

    func_80017758(buf, p);

    *(s16 *)(buf + 0x00) = 3;
    *(s16 *)(buf + 0x10) = 0;
    *(s16 *)(buf + 0x08) = 0;
    *(s16 *)(buf + 0x18) = -3;
    *(s16 *)(buf + 0x0A) = 7;
    *(s16 *)(buf + 0x1A) = 0;
    *(s16 *)(buf + 0x02) = 0;
    *(s16 *)(buf + 0x12) = -7;

    func_80017758(buf, p);
}
