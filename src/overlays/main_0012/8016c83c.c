/* Overlay range [8016C83C,8016C998) from MAIN.CD member 0012.
 * SHA256(span)=3b2d09722548014b7c2bd4bd86dc9832f0a86aeb13967990429152fd350b6eda.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016C83C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define VectorNormalSS func_80047E98

/* func_8016C83C — shared body (overlay slot 0x80128158, h_exact 26450efe). ONE source: instantiated by #include at each
 * member's site in address order; the members are recorded in config/dedup.us.yaml (Phase 35). */
extern s32 VectorNormalSS(void *a0, void *a1);
extern void func_800D22E4(s32 a0);
extern short func_8016CF04();
void func_8016C83C(s32 a0) {
    s16 d[20];
    s32 a1 = *(s32 *)(a0 + 0x34);
    s32 v0 = *(s32 *)(a0 + 0x1C) - 1;
    s32 dist;
    *(s32 *)(a0 + 0x1C) = v0;
    if (v0 == 0) {
        *(s16 *)(a0 + 2) = 4;
        func_8016CF04(a0, 2);
        return;
    }
    d[0] = *(u16 *)(a1 + 6) - *(u16 *)(a0 + 6);
    d[1] = *(u16 *)(a1 + 0xA) - *(u16 *)(a0 + 0xA);
    d[2] = *(u16 *)(a1 + 0xE) - *(u16 *)(a0 + 0xE);
    dist = VectorNormalSS(d, d);
    if (dist < 0x790) {
        *(s16 *)(a0 + 2) = 4;
        func_8016CF04(a0, 2);
        return;
    }
    *(s32 *)(a0 + 0x10) = *(s32 *)(a0 + 0x10) + d[0] * 0x40;
    *(s32 *)(a0 + 0x14) = *(s32 *)(a0 + 0x14) + d[1] * 0x40;
    *(s32 *)(a0 + 0x18) = *(s32 *)(a0 + 0x18) + d[2] * 0x40;
    d[0] = *(u16 *)(a0 + 0x12);
    d[1] = *(u16 *)(a0 + 0x16);
    d[2] = *(u16 *)(a0 + 0x1A);
    dist = VectorNormalSS(d, d);
    {
        s32 lim = 0x1000;
        if (lim < dist) {
            *(s32 *)(a0 + 0x10) = (s32)d[0] << 10;
            *(s32 *)(a0 + 0x14) = (s32)d[1] << 10;
            *(s32 *)(a0 + 0x18) = (s32)d[2] << 10;
        }
    }
    func_800D22E4(a0);
    func_8016CF04(a0, 1);
}
