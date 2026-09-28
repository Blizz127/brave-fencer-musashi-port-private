/* Main-exec range [80028694,80028A30) from the SLUS executable.
 * SHA256(span)=de0479e6f3926950d785905250305293c9816e5e0631aeba7eef8bb535040ca5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80028694 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define SetDefDispEnv func_80058B04

extern u8 D_800B9A15;
extern s32 D_80075818;
extern s32 D_8007581C;
extern u16 D_80075820[];
extern u16 D_80075824[];
extern u16 D_80075828[];
extern u16 D_8007582C[];
extern u16 D_80075830[];
extern u16 D_80075834[];
extern u8 D_800AF737;
extern u8 D_800AF6DB;
extern u8 D_800AF67F;
extern u16 D_800AF77C[];
extern u16 D_800AF780[];
extern u16 D_800AF790[];
extern u16 D_800AF794[];
extern u16 D_800AF7A4[];
extern u16 D_800AF7A8[];
extern u8 D_800AF630[];

void func_80028694(void) {
    u8 *s0 = D_800AF630;
    u32 m;

    if (D_800B9A15 != 0) {
        return;
    }

    if ((s16)func_80014C54(1, 0, 2) != 0) {
        D_800AF737 = 1;
        D_800AF6DB = 1;
        D_800AF67F = 1;
        D_8007581C = 0;
        D_80075818 = 0;
        D_80075820[0] = D_800AF77C[0];
        D_80075820[1] = D_800AF77C[1];
        D_80075824[0] = D_800AF780[0];
        D_80075824[1] = D_800AF780[1];
        D_80075828[0] = D_800AF790[0];
        D_80075828[1] = D_800AF790[1];
        D_8007582C[0] = D_800AF794[0];
        D_8007582C[1] = D_800AF794[1];
        D_80075830[0] = D_800AF7A4[0];
        D_80075830[1] = D_800AF7A4[1];
        D_80075834[0] = D_800AF7A8[0];
        D_80075834[1] = D_800AF7A8[1];
    } else {
        if (((func_80014BFC(1) & 2) != 0) && ((func_80014B10(1) & 2) == 0)) {
            D_800AF737 = 0;
            D_800AF6DB = 0;
            D_800AF67F = 0;
            D_800AF77C[0] = D_80075820[0];
            D_800AF77C[1] = D_80075820[1];
            D_800AF780[0] = D_80075824[0];
            D_800AF780[1] = D_80075824[1];
            D_800AF790[0] = D_80075828[0];
            D_800AF790[1] = D_80075828[1];
            D_800AF794[0] = D_8007582C[0];
            D_800AF794[1] = D_8007582C[1];
            D_800AF7A4[0] = D_80075830[0];
            D_800AF7A4[1] = D_80075830[1];
            D_800AF7A8[0] = D_80075834[0];
            D_800AF7A8[1] = D_80075834[1];
        }
    }

    if ((s16)func_80014C54(1, 1, 2) == 0) {
        return;
    }

    m = func_80014B10(1) & 0x5000;
    if (m == 0x1000) goto minus1;
    if (m == 0x4000) goto plus1;
    goto skip1;
minus1:
    D_8007581C = D_8007581C - *(s32 *)(s0 + 0xA3E8) * 2;
    goto store1;
plus1:
    D_8007581C = D_8007581C + *(s32 *)(s0 + 0xA3E8) * 2;
store1:
skip1:
    m = func_80014B10(1) & 0xA000;
    if (m == 0x2000) goto plus2;
    if (m != 0x8000) goto skip2;
    D_80075818 = D_80075818 - *(s32 *)(s0 + 0xA3E8) * 2;
    goto store2;
plus2:
    D_80075818 = D_80075818 + *(s32 *)(s0 + 0xA3E8) * 2;
store2:
skip2:
    if ((s16)func_80014C54(1, 1, 8) != 0) {
        SetDefDispEnv(s0 + (*(u16 *)(s0 + 0x188) * 20 + 0x14C), D_80075818, D_8007581C, 0x140, 0xF0);
    } else {
        SetDefDispEnv(s0 + (*(u16 *)(s0 + 0x188) * 20 + 0x14C), D_80075818, D_8007581C, 0x280, 0x1E0);
    }
}
