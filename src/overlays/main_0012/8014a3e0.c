/* Overlay range [8014A3E0,8014A454) from MAIN.CD member 0012.
 * SHA256(span)=11c9a9d89639c297e2a3d53f886d2dec33bc2c9e3703a2dfbc826b63c2c56119.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014A3E0 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S_8014A3E0;
struct S_8014A3E0 {
    char pad0[0x12];
    s16 h12;       
    char pad14[0x6];
    s16 h1A;       
    char pad1C[0x6C];
    u16 h88;       
    u16 h8A;       
    u16 h8C;       
};
extern s16 D_801152B0;
extern s16 D_801152B4;

s32 func_8014A3E0(struct S_8014A3E0 *a0) {
    s32 sp[4];
    sp[0] = a0->h12 * D_801152B0;
    sp[2] = a0->h1A * D_801152B4;
    if (sp[0] >= 0 && sp[2] >= 0) {
        return 1;
    }
    *(s16 *)((char *)a0 + 0x6) = a0->h88;
    *(s16 *)((char *)a0 + 0xA) = a0->h8A;
    *(s16 *)((char *)a0 + 0xE) = a0->h8C;
    return 0;
}
