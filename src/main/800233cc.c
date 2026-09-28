/* Exact retail [800233CC,800234E4).
 * Words from pinned SLUS_007.26.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800233CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 func_8004787C(s32 a0); /* rcos-like: angle (0..0xFFF) -> 1.12 fixed */
extern s32 func_80047948(s32 a0); /* rsin-like: angle (0..0xFFF) -> 1.12 fixed */

typedef struct {
    u16 x;
    u16 y;
} Poly12Pt;

typedef struct {
    u8 pad_00[0x10];
    Poly12Pt pts[12];
} Poly12Obj;

/* Builds a 12-gon of radius a1 into the u16{x,y} table at obj+0x10:
 * quarter arc (4 pts, angle step 0x155), mirrored in y, then in x. */
void func_800233CC(Poly12Obj *a0, u16 a1) {
    s32 i = 0;
    s32 radius = a1;

    /* `i * 0x155` must stay a DERIVED induction variable (no explicit `ang`
     * local): loop_strength_reduce then emits its preheader init alongside the
     * hoisted &pts[0] copy, giving the target's s2-before-s1 init order and the
     * s1-before-s0 increment order.  An explicit pre-loop `ang = 0` statement
     * sits ahead of the LSR-inserted init instead -> 6-instruction residual. */
    for (; i < 4; i++) {
        a0->pts[i].x = (func_8004787C(i * 0x155) * radius) >> 12;
        a0->pts[i].y = (func_80047948(i * 0x155) * radius) >> 12;
    }

    for (i = 4; i < 7; i++) {
        a0->pts[i].x = a0->pts[6 - i].x;
        a0->pts[i].y = -a0->pts[6 - i].y;
    }

    for (i = 7; i < 12; i++) {
        a0->pts[i].x = -a0->pts[12 - i].x;
        a0->pts[i].y = a0->pts[12 - i].y;
    }
}
