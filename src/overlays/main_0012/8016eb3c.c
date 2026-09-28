/* Overlay range [8016EB3C,8016EBA8) from MAIN.CD member 0012.
 * SHA256(span)=305a0f4482d5bcf13308fc9b81d55a98526ef4e42abcae5715b6972ac282560d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016EB3C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8016EC0C(s32 a0, s32 a1);

void func_8016EB3C(s32 p) {

    extern u8 D_80181730[];
    u8 v;

    ((void (*)(s32, s32))func_8016EC0C)(p, D_80181730[*(u8 *)(p + 2) & 3]);

    v = *(u8 *)(p + 2);
    *(u8 *)(p + 2) = v + 0xFF;
    if (v == 0) {
        *(u8 *)(p + 2) = 5;
        *(u8 *)(p + 1) = *(u8 *)(p + 1) + 1;
    }
}
