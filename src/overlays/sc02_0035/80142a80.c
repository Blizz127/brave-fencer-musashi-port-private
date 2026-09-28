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
extern struct packed_word D_801BCD80;
extern u8 D_801BD6E8;
extern u8 D_801BD6E9;
extern u8 D_801BD6EA;

void func_80142A80(void)
{
    u16 flags;
    union word_bytes local;
    s32 mul;

    flags = D_800B99D8;
    local.pw = D_801BCD80;

    if (flags & 0x10) {
        mul = (s8)((flags & 0xf) >> 1) + 9;
    } else {
        mul = 0x10 - (s8)((flags & 0xf) >> 1);
    }

    D_801BD6E8 = mul * (local.b[0] >> 4);
    D_801BD6E9 = mul * (local.b[1] >> 4);
    D_801BD6EA = mul * (local.b[2] >> 4);
}
