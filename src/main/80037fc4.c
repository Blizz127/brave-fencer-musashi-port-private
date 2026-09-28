/* Exact retail word export for [80037FC4,8003819C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80037FC4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 D_800A2B98;
extern s32 D_800A2BA0;
extern s32 D_800C7D20;
extern s32 D_800C7D2C;
extern u8  D_800A4F1D;
extern u8 D_800C6E2E[];
extern void func_8003BE74(s32, s32);
extern void func_80037FC4(void);

void func_80037FC4(void)
{

    extern u8 D_800C6DD0[];
    extern void func_80038A58(void);
    extern void func_8003D3B4(s32, s32);
    extern void func_8003C23C(s32, s32);
    extern void func_8003B250(s32, void *);

    register u8 *p __asm__("$16");
    register s32 i __asm__("$17");
    register u32 mask __asm__("$18");
    u8 *base;

    if (D_800A4F1D == 0) {
        func_80038A58();
    }

    i = 0;
    mask = 0xFFF9FFFF;
    p = D_800C6E2E;
    do {
        if (p[-4] != 0 && p[-1] == 0 && p[0] != 0) {
            func_8003D3B4(i, 8);
            *(u32 *)(p - 0x4A) &= mask;
            p[0] = 0;
        }
        i++;
        p += 0x60;
    } while (i < 0x10);

    if ((D_800A2B98 & 0xFFFF) != 0) {
        func_8003C23C(0, D_800A2B98 & 0xFFFF);
        D_800A2B98 &= 0xFF0000;
    }

    if ((D_800A2BA0 & 0xFFFF) != 0) {
        func_8003BE74(0, D_800A2BA0 & 0xFFFF);
        D_800A2BA0 &= 0xFF0000;
    }

    base = D_800C6DD0;
    i = 0;
    p = base + 0x5E;
    do {
        if (p[-4] != 0 && p[-1] != 0) {
            func_8003B250(i, base + 0x10);
            *(u32 *)(p - 0x4A) = 0;
            p[-1] = 0;
            p[0] = 0;
        }
        i++;
        p += 0x60;
        base += 0x60;
    } while (i < 0x10);

    if ((D_800C7D20 & 0xFFFF) != 0) {
        func_8003C23C(1, D_800C7D20 & 0xFFFF);
        D_800C7D20 &= 0xFF0000;
    }

    if ((D_800C7D2C & 0xFFFF) != 0) {
        func_8003BE74(1, D_800C7D2C & 0xFFFF);
        D_800C7D2C &= 0xFF0000;
    }
}
