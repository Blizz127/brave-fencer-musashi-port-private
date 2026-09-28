/* Main-exec range [80029774,800298BC) from the SLUS executable.
 * SHA256(span)=60178c0ae6b305a7b3bd4f14702cdb013db141e42123b892a0ca531573294a95.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80029774 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

typedef struct {
    s32 words[38];
} Blk98_80029274;

typedef struct {
    char c[4];
} Blk4_80029774;

extern Blk98_80029274 D_80078E78;
extern u8 D_80078F28[];
extern u16 D_800A6588[];
extern u8 D_800AE648[];
extern u8 D_800BA1B8[];
extern u8 D_800BA2B8[];
extern s32 D_800A5E58[];

void func_80029774(s32 a0) {
    u8 *dst;
    s32 i;

    dst = D_80078F28 + a0 * 0x2DC;
    *(Blk98_80029274 *)(dst + 0x24) = D_80078E78;

    for (i = 0; i < 0x40; i++) {
        *(u16 *)(dst + 0xBC + i * 2) = D_800A6588[i];
    }

    for (i = 0; i < 0x40; i++) {
        *(u8 *)(i + dst + 0x13C) = D_800AE648[i];
    }

    for (i = 0; i < 0x100; i++) {
        *(u8 *)(i + dst + 0x17C) = D_800BA1B8[i];
    }

    for (i = 0; i < 0x18; i++) {
        *(Blk4_80029774 *)(dst + 0x27C + i * 4) = *(Blk4_80029774 *)(D_800BA2B8 + i * 4);
    }

    D_800A5E58[a0] = 1;
}
