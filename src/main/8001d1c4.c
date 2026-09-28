/* Exact retail word export for [8001D1C4,8001D388); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001D1C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_800B9A11;
extern u8 D_800B5CB8;
extern u8 D_800B5D28;
extern u8 D_800B60A8;
extern u8 D_800B6968;
extern u8 D_800B7768;
void func_8001D388();

void func_8001D1C4(void) {
    u8 *base;
    u8 *p;
    s32 sp10;
    u8 flags;

    base = &D_800B9A11;
    sp10 = 0;
    flags = *base;
    p = base - 0x3E39;
    if (p < base - 0x3D59) {
        do {
            func_8001D388(p, &sp10);
            p += 0x38;
        } while (p < base - 0x3D59);
    }
    if (!(flags & 4)) {
        p = &D_800B5CB8;
        if (p < &D_800B5CB8 + 0x70) {
            do {
                func_8001D388(p, &sp10);
                p += 0x38;
            } while (p < &D_800B5CB8 + 0x70);
        }
    }
    if (!(flags & 0x10)) {
        p = &D_800B5D28;
        if (p < &D_800B5D28 + 0x380) {
            do {
                func_8001D388(p, &sp10);
                p += 0x38;
            } while (p < &D_800B5D28 + 0x380);
        }
    }
    if (!(flags & 0x20)) {
        p = &D_800B60A8;
        if (p < &D_800B60A8 + 0x8C0) {
            do {
                func_8001D388(p, &sp10);
                p += 0x38;
            } while (p < &D_800B60A8 + 0x8C0);
        }
    }
    if (!(flags & 0x40)) {
        p = &D_800B6968;
        if (p < &D_800B6968 + 0xE00) {
            do {
                func_8001D388(p, &sp10);
                p += 0x38;
            } while (p < &D_800B6968 + 0xE00);
        }
    }
    if (!(flags & 0x80)) {
        p = &D_800B7768;
        if (p < &D_800B7768 + 0x1C70) {
            do {
                func_8001D388(p, &sp10);
                p += 0x38;
            } while (p < &D_800B7768 + 0x1C70);
        }
    }
}
