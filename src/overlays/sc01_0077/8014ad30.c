/* Overlay range [8014AD30,8014AD7C) from MAIN.CD member 0012.
 * SHA256(span)=0352d9a38854b257162f8d9d5d95a719be6ffeb2631de3fc64c1efe1284a3bb4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014AD30 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S_8014AD30;
struct S_8014AD30 {
    s16 h0;
    s16 h1;
    s16 h2;
    s16 h3;
    s32 w0;
    s32 w1;
    s32 w2;
};
extern void func_80146AFC(void*);
extern void func_80146AFC(void *a0);

void func_8014AD30(s32 a0, u16 *a1, s32 a2, s32 a3) {
    struct S_8014AD30 sp;
    s16 b = a1[0];
    s16 c = a1[1];
    s16 d = a1[2];
    sp.h0 = 0x1D;
    sp.w0 = a0;
    sp.w1 = a2;
    sp.w2 = a3;
    sp.h1 = b;
    sp.h2 = c;
    sp.h3 = d;
    func_80146AFC(&sp);
}
