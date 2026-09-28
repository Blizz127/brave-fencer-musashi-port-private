/* Exact retail word export for [800316F8,80031988); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800316F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif
void func_800316F8(s32 arg0)
{
    s32 base;
    u16 *ptr;
    u16 speed;
    u16 delta;
    s32 tmp;
    s32 tmp1;

    base = arg0;
    delta = 0;
    ptr = *(u16 **)(base + 0x14);
    speed = 0;
    *(u8 *)(base + 0x37) = 0;
    *(u32 *)(base + 0x18) = 0;
    *(u32 *)(base + 0x20) = *(u32 *)(base + 0x24);
    if (ptr == NULL) {
        return;
    }
    switch (*ptr) {
    case 1:
        speed = ptr[1];
        delta = ptr[2];
        *(u16 *)(base + 0x30) = 0;
        *(u8 *)(base + 0x38) = 1;
        *(u16 *)(base + 0x3A) = ptr[3];
        *(u16 *)(base + 0x3C) = ptr[4];
        *(u16 *)(base + 0x12) = ptr[7];
        break;
    case 9:
        speed = ptr[1];
        tmp1 = ptr[2];
        *(u16 *)(base + 0x30) = 0;
        *(u8 *)(base + 0x38) = 1;
        *(u16 *)(base + 0x3A) = ptr[3];
        *(u16 *)(base + 0x3C) = ptr[4] + *(u32 *)(base + 0x20);
        delta = tmp1 + *(u32 *)(base + 0x20);
        *(u16 *)(base + 0x12) = ptr[7];
        break;
    case 6:
        speed = ptr[2];
        delta = ptr[3];
        *(u16 *)(base + 0x30) = 0;
        *(u8 *)(base + 0x38) = 1;
        *(u16 *)(base + 0x3A) = ptr[4];
        *(u16 *)(base + 0x3C) = ptr[5];
        *(u16 *)(base + 0x12) = ptr[8];
        goto L188c;
    case 10:
        speed = ptr[2];
        tmp = ptr[3];
        *(u16 *)(base + 0x30) = 0;
        *(u8 *)(base + 0x38) = 1;
        *(u16 *)(base + 0x3A) = ptr[4];
        *(u16 *)(base + 0x3C) = ptr[5] + *(u32 *)(base + 0x20);
        *(u16 *)(base + 0x12) = ptr[8];
        goto L18ac;
    case 0:
        *(u8 *)(base + 0x38) = 0;
        speed = ptr[1];
        delta = ptr[2];
        *(u16 *)(base + 0x12) = ptr[5];
        *(u16 *)(base + 0x30) = 0;
        break;
    case 7:
        *(u8 *)(base + 0x38) = 0;
        speed = ptr[1];
        delta = ptr[2] + *(u32 *)(base + 0x20);
        *(u16 *)(base + 0x12) = ptr[5];
        *(u16 *)(base + 0x30) = 0;
        break;
    case 5:
        *(u8 *)(base + 0x38) = 0;
        speed = ptr[2];
        delta = ptr[3];
        *(u16 *)(base + 0x12) = ptr[6];
    L188c:
        *(u16 *)(base + 0x30) = ptr[1];
        break;
    case 8:
        *(u8 *)(base + 0x38) = 0;
        speed = ptr[2];
        tmp = ptr[3];
        *(u16 *)(base + 0x12) = ptr[6];
    L18ac:
        delta = tmp + *(u32 *)(base + 0x20);
        *(u16 *)(base + 0x30) = ptr[1];
        break;
    case 2:
        *(u8 *)(base + 0x38) = 0;
        goto L18f4;
    case 3:
        *(u8 *)(base + 0x37) |= 2;
        *(u32 *)(base + 0x1C) = (s32)(s16)ptr[2] << 8;
        *(u16 *)(base + 0x32) = ptr[3];
        *(u8 *)(base + 0x38) = 0;
    L18f4:
        *(u16 *)(base + 0x12) = ptr[1];
        *(u16 *)(base + 0x30) = 0;
        return;
    case 4:
        *(u8 *)(base + 0x37) |= 2;
        *(u32 *)(base + 0x1C) = (s32)(s16)ptr[1] << 8;
        *(u16 *)(base + 0x32) = ptr[2];
        *(u8 *)(base + 0x38) = 0;
        *(u16 *)(base + 0x30) = 0;
        return;
    }
    if (speed == 0) {
        return;
    }
    if (*(s32 *)(base + 0x24) == delta) {
        return;
    }
    *(u32 *)(base + 0x28) = delta;
    *(u8 *)(base + 0x37) |= 1;
    if (delta < *(s32 *)(base + 0x24)) {
        *(u32 *)(base + 0x2C) = -speed;
    } else {
        *(u32 *)(base + 0x2C) = speed;
    }
}
