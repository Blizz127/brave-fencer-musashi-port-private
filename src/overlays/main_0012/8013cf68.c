/* Overlay range [8013CF68,8013D064) from MAIN.CD member 0012.
 * SHA256(span)=02604d37404b415b90fef7df7b91404a218b57e4126a84f7e090cb23792f71bd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013CF68 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8013CF68()
{
    extern void func_80028620();
    extern u8 D_800A5E94[];
    extern s32 D_800A5E8C;
    extern s32 D_800A5E90;
    extern u8 D_800A5E95;
    extern u8 D_800A5E96;
    extern u8 D_80185B28;
    extern u8 D_80185B29;
    extern u8 D_80185B2A;
    extern u8 D_80185B2B;
    extern u8 D_80185B2C;
    extern u8 D_80185B2D;
    extern u8 D_80185B2E;
    extern u8 D_80185B2F;
    extern u8 D_80185B30;

    u8 t0, t1, t2;
    u8 *base;
    __asm__("la %0, D_800A5E94" : "=r"(base));

    *(s32 *)(base - 0xC) = 0;
    t0 = D_80185B28; t1 = D_80185B29; t2 = D_80185B2A;
    D_800A5E8C = 0x1E;
    D_800A5E90 = 0;
    base[0] = t0; D_800A5E95 = t1; D_800A5E96 = t2;
    func_80028620(0, base - 0xC);

    *(s32 *)(base + 4) = 0; *(s32 *)(base + 8) = 7;
    t0 = D_80185B2B; t1 = D_80185B2C; t2 = D_80185B2D;
    *(s32 *)(base + 0xC) = 0x14;
    base[0x10] = t0; base[0x11] = t1; base[0x12] = t2;
    func_80028620(1, base + 4);

    *(s32 *)(base + 0x14) = 0;
    t0 = D_80185B2E; t1 = D_80185B2F; t2 = D_80185B30;
    *(s32 *)(base + 0x18) = -0x12;
    *(s32 *)(base + 0x1C) = 0;
    base[0x20] = t0; base[0x21] = t1; base[0x22] = t2;
    func_80028620(2, base + 0x14);
}
