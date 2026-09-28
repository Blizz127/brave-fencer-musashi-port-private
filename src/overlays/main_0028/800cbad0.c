/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBAD0 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_800CB8A0(void *a0);
typedef struct { s32 w[4]; } Blk_800CBAD0;

void func_800CBAD0(s32 a0) {
    extern void func_800CB8A0();

    s32 s;
    s32 v;

    s = *(s32 *)(a0 + 0x34);
    if (*(s32 *)(a0 + 0x2C) & 0x8000) {
        goto L_inc;
    }
    if ((*(s32 *)(a0 + 0x1C))++ < 8) {
        *(u16 *)(a0 + 0x28) += 0x120;
    } else {
        *(s32 *)(a0 + 0x1C) = 0;
        *(u16 *)(a0 + 2) = 4;
    }
    v = *(s32 *)(s + 0x20);
    *(Blk_800CBAD0 *)(a0 + 0x38) = *(Blk_800CBAD0 *)(v + 0x34);
    *(Blk_800CBAD0 *)(a0 + 0x48) = *(Blk_800CBAD0 *)(v + 0x44);
    func_800CB8A0(a0);
    return;

L_inc:
    *(u16 *)(a0 + 2) += 1;
}
