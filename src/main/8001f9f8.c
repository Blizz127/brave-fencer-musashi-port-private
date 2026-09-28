/* Exact retail word export for [8001F9F8,8001FB8C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001F9F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_800AF8D8[];
extern u8 D_800AFB6C[];
extern u8 D_800AFBF0[];
extern u8 D_800B0430[];
extern u8 D_800B0C70[];
extern u8 D_800B3DF0[];
extern u8 D_800B9A11;
extern void func_8001FB8C(s32* a0, s32* a1);

void func_8001F9F8(void) {
    u8* p;
    u8 bits;
    s32 x;

    bits = D_800B9A11;
    {
        s32 i;
        i = 0;
        p = D_800AF8D8;
        x = 0;
        for (; i < 4; i++) {
            func_8001FB8C(p, &x);
            p += 0x84;
        }
    }
    if (!(bits & 2)) {
        s32 i;
        i = 0;
        p = D_800AF8D8 + 0x210;
        for (; i < 1; i++) {
            func_8001FB8C(p, &x);
            p += 0x84;
        }
    }
    if (!(bits & 8)) {
        s32 i;
        i = 0;
        p = D_800AFB6C;
        for (; i < 1; i++) {
            func_8001FB8C(p, &x);
            p += 0x84;
        }
    }
    if (!(bits & 0x10)) {
        s32 i;
        i = 0;
        p = D_800AFBF0;
        for (; i < 0x10; i++) {
            func_8001FB8C(p, &x);
            p += 0x84;
        }
    }
    if (!(bits & 0x20)) {
        s32 i;
        i = 0;
        p = D_800B0430;
        for (; i < 0x10; i++) {
            func_8001FB8C(p, &x);
            p += 0x84;
        }
    }
    if (!(bits & 0x40)) {
        s32 i;
        i = 0;
        p = D_800B0C70;
        for (; i < 0x60; i++) {
            func_8001FB8C(p, &x);
            p += 0x84;
        }
    }
    if (!(bits & 0x80)) {
        s32 i;
        i = 0;
        p = D_800B3DF0;
        for (; i < 0x3A; i++) {
            func_8001FB8C(p, &x);
            p += 0x84;
        }
    }
}
