/* Overlay range [80148AFC,80148C18) from MAIN.CD member 0012.
 * SHA256(span)=8c22a26364ace265c0b6cbba89c9e763cb0be990cf80ae5875b5f8835069e13c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80148AFC - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
typedef s32 (*ActorFn)(void *);
extern s32 ratan2(s32 a0, s32 a1);
extern s32 ratan2(s32 x, s32 y);

/* Fallthrough (no case) returns the dispatch constant gcc leaves in $v0
 * (0x41 below 0x54, else 0x73); callers test the result, so it is spelled
 * out with $v0 pinned (byte-identical to the switch form). */
int func_80148AFC(void *a0) {

    extern s32 D_801151D4;
    extern ActorFn D_80188614[];
    register s32 s0 __asm__("$16") = (s32)a0;
    register s32 s2 __asm__("$18");
    register s32 s1 __asm__("$17");
    register s32 v0 __asm__("$2");
    register s32 v1 __asm__("$3");
    register s32 a0_ __asm__("$4");
    register s32 a1 __asm__("$5");
    s2 = *(s32 *)(s0 + 0x20);
    v0 = D_801151D4;
    a0_ = *(s32 *)(v0 + 0x44) - *(s32 *)(v0 + 0x50);
    a1 = *(s32 *)(v0 + 0x48) - *(s32 *)(v0 + 0x3C);
    v0 = ratan2(a0_, a1);
    v0 = v0 - 0x400;
    a1 = v0 & 0xFFF;
    __asm__("" : "=r"(a1) : "0"(a1));
    s1 = a1;
    v1 = *(u8 *)(s0 + 0xA9);
    if (v1 == 0x53) goto LAB_S;
    v0 = v1 < 0x54;
    if (v0 == 0) goto LAB_GE;
    v0 = 0x41;
    if (v1 == v0) goto LAB_41;
    goto LAB_RET;
LAB_GE:
    v0 = 0x73;
    if (v1 == v0) goto LAB_S;
    goto LAB_RET;
LAB_41:
    v0 = D_80188614[*(u16 *)(s0 + 0xAA) >> 12]((void *)s0) & 0xFF;
    goto LAB_RET;
LAB_S:
    v1 = *(u16 *)(s0 + 0xAE);
    v0 = 0x80;
    a0_ = v1 & 0xFF;
    if (a0_ != v0) goto LAB_ATAN;
    v0 = v1 >> 8;
    if (v0 == a0_) { v0 = 0; goto LAB_RET; }
LAB_ATAN:
    a1 = *(u16 *)(s0 + 0xAE);
    v0 = 0x80;
    a0_ = a1 & 0xFF;
    a0_ = a0_ - 0x80;
    a1 = a1 >> 8;
    a1 = v0 - a1;
    v0 = ratan2(a0_, a1);
    v1 = s1 + v0;
    v0 = 1;
    v1 = v1 & 0xFFF;
    *(u16 *)(s2 + 0x12) = v1;
LAB_RET:
    return v0;
}
