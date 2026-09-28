/* Exact retail word export for [80034CF0,80034DFC); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80034CF0 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u8 D_8006AEF5;
extern s32 D_8006AEF8;
extern s32 D_8006AEFC;
extern u8 D_80076118[];

s32 func_80034CF0(u8 *p) {
    s32 idx = D_8006AEFC;
    u8 saved = D_8006AEF5;
    s32 limit = D_8006AEF8;
    u8 *self;
    s32 f28;
    s32 oldIdx;
    s32 ret;

    D_8006AEF5 = 1;
    idx = idx + 1;
    if (idx >= 4) {
        idx = 0;
    }

    if (idx == limit) {
        D_8006AEF5 = saved;
        return 0;
    }

    self = D_80076118 + D_8006AEFC * 0x30;

    *(s32 *)(self + 0x8) = *(s32 *)(p + 0x8);
    *(s32 *)(self + 0xC) = *(s32 *)(p + 0xC);
    *(s32 *)(self + 0x10) = *(s32 *)(p + 0x10);
    *(s32 *)(self + 0x14) = *(s32 *)(p + 0x14);
    *(s32 *)(self + 0x18) = *(s32 *)(p + 0x18);
    *(s32 *)(self + 0x1C) = *(s32 *)(p + 0x1C);
    *(s32 *)(self + 0x20) = *(s32 *)(p + 0x20);
    *(s32 *)(self + 0x24) = *(s32 *)(p + 0x24);
    f28 = *(s32 *)(p + 0x28);

    self[0] = 1;
    self[1] = 0;
    self[2] = 0;
    self[3] = 0;
    self[7] = 1;

    oldIdx = D_8006AEFC;
    D_8006AEFC = idx;
    D_8006AEF5 = saved;

    ret = oldIdx + 1;
    *(s32 *)(self + 0x28) = f28;
    *(s32 *)(self + 0x2C) = oldIdx;
    return ret;
}
