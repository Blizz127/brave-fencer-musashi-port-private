/* Overlay range [80148E54,80148F60) from MAIN.CD member 0012.
 * SHA256(span)=4d04462e5a1aabfc2d23f9efb915fced1d3926a5a33dac2edf43af258d09a1dc.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80148E54 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);
extern s32 ratan2(s32 x, s32 y);
extern s32 ratan2(s32, s32);

/* Same dispatch as 80148AFC: a fallthrough (no case) returns the constant
 * gcc's dispatch leaves in $v0 (0x41 below 0x54, else 0x73), and a0 still
 * holds the angle at the handler jalr. Both are spelled out with pinned
 * registers (byte-identical to the switch form). */
s32 func_80148E54(s32 arg0) {

    extern s32 D_801151D4;
    extern s16 (*D_80186E98[])(s32);
    register s32 s0 __asm__("$16") = arg0;
    register s32 s1 __asm__("$17");
    register s32 v0 __asm__("$2");
    register s32 v1 __asm__("$3");
    register s32 a0_ __asm__("$4");
    register s32 a1 __asm__("$5");
    v0 = D_801151D4;
    a0_ = *(s32 *)(v0 + 0x44) - *(s32 *)(v0 + 0x50);
    a1 = *(s32 *)(v0 + 0x48) - *(s32 *)(v0 + 0x3C);
    v0 = ratan2(a0_, a1);
    v0 = v0 - 0x400;
    a0_ = v0 & 0xFFF;
    __asm__("" : "=r"(a0_) : "0"(a0_));
    s1 = a0_;
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
    v0 = D_80186E98[*(u16 *)(s0 + 0xAA) >> 12](a0_);
    goto LAB_RET;
LAB_S:
    v1 = *(u16 *)(s0 + 0xAE);
    v0 = 0x80;
    a0_ = v1 & 0xFF;
    if (a0_ != v0) goto LAB_ATAN;
    v0 = v1 >> 8;
    if (v0 == a0_) { v0 = -1; goto LAB_RET; }
LAB_ATAN:
    a1 = *(u16 *)(s0 + 0xAE);
    v0 = 0x80;
    a0_ = a1 & 0xFF;
    a0_ = a0_ - 0x80;
    a1 = a1 >> 8;
    a1 = v0 - a1;
    v0 = ratan2(a0_, a1);
    v0 = s1 + v0;
    v0 = v0 & 0xFFF;
LAB_RET:
    return v0;
}
