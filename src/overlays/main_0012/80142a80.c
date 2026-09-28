/* Overlay range [80142A80,80142B2C) from MAIN.CD member 0012.
 * SHA256(span)=b2ffe2dc87ad9af9706433101a654d1d6656bb9b0f978c97f81e062b9c0f7488.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80142A80 - byte-exact against retail at -O2 (tools/register_match.py). */
struct packed_word;
union word_bytes;
struct packed_word { int w; } __attribute__((packed, aligned(1)));
union word_bytes {
    struct packed_word pw;
    u8 b[4];
};
extern u16 D_800B99D8;

void func_80142A80(void)
{

    extern u16 D_800B99D8;
    extern struct packed_word D_801836AC;
    extern u8 D_80184200;
    extern u8 D_80184201;
    extern u8 D_80184202;
    u16 flags;
    union word_bytes local;
    s32 mul;

    flags = D_800B99D8;
    local.pw = D_801836AC;

    if (flags & 0x10) {
        mul = (s8)((flags & 0xf) >> 1) + 9;
    } else {
        mul = 0x10 - (s8)((flags & 0xf) >> 1);
    }

    D_80184200 = mul * (local.b[0] >> 4);
    D_80184201 = mul * (local.b[1] >> 4);
    D_80184202 = mul * (local.b[2] >> 4);
}
