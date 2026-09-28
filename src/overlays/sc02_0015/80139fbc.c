/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80139FBC - byte-exact against retail at -O2 (tools/register_match.py). */
struct obj;
struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};

void func_80139FBC(struct obj *a0) {
    if (a0->unk8 & 0x800) {
        a0->unk8 &= ~0x800;
        a0->unk4 = 2;
    }
}
