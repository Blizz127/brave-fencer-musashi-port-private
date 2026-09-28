/* Overlay range [80150EC4,80150F78) from MAIN.CD member 0012.
 * SHA256(span)=9e40e1c33fbb4f4dfff6aad0f3f3824c1a8df05d729259996e0e37289c38c520.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80150EC4 - byte-exact against retail at -O2 (tools/register_match.py). */
struct copy00;
struct copy00 { s32 w[41]; };
extern s32 D_800AE6B0;
s32 a1;
extern u8 D_800AE6C0;
extern s16 D_800AE6C8;
extern s16 D_800AE6CA;
extern u8 D_80126948[];
extern s16 D_800AE6CC;
extern s32 D_800AE6C4;
extern s16 D_800AE6CE;
extern u8 D_800AE6BE;
extern u8 D_801201F8[];

void func_80150EC4(s32 a0, s32 a1) {
    D_800AE6C0 = 1;
    D_800AE6C8 = *(u16 *)(a0 + 0x6);
    D_800AE6CA = *(u16 *)(a0 + 0xA);
    D_800AE6CC = *(u16 *)(a0 + 0xE);
    D_800AE6CE = *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12);
    D_800AE6B0 = *(s32 *)(((a1 << 2) + D_800AE6C4) + 4);
    D_800AE6BE = a1 + 1;
    *(struct copy00 *)D_801201F8 = *(struct copy00 *)D_80126948;
}
