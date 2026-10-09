/* SC02.CD member35 [80150B28,80150B9C): twin of main_0012 80150B28 (src/overlays/main_0012/80150b28.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [80150B28,80150B9C) from MAIN.CD member 0012.
 * SHA256(span)=4cac5a2b426da23c617530203eb52104ff2165e0845ea1968fc18bbe52f43569.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80150B28 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_800AE6B0;

void func_80150B28(int param_1) {

    extern s32 D_800AE6B0;
    extern void (*D_8018614C[])(void);
    u32 idx;
    register u32 sub __asm__("$2");

    if ((D_800AE6B0 & 0x80FFFFFF) == 0) {
        idx = *(u16 *)(param_1 + 0x16C);
        if (idx != 0 && idx < 0x26) {
            sub = idx - 1;
            D_8018614C[sub]();
        }
    }
    *(u16 *)(param_1 + 0x16C) = 0;
}
