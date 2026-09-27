/* SC02.CD FILE_031 / ov_SC02_031 retail span [80134A28,80134A74).
 * Offset 0xC8D0 at overlay base 80128158. SHA256(span)=23d26b15e4a40ad8a6bd4edd16f82767d7854a7954402a041c2430c534e2a952.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80134a28.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_80134A28 (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): frameless 3-arg s32
 * leaf, instruction-identical to func_80134310 (verified register
 * for register from raw asm): arg0[0]*arg1[0] + arg0[1]*arg1[1] +
 * arg0[2]*arg1[2] + arg2 via three mult/mflo lows summed with the
 * bias in the jr delay slot. */

s32 func_80134A28(s16 *arg0, s16 *arg1, s32 arg2) {
    return arg0[0] * arg1[0] + arg0[1] * arg1[1] + arg0[2] * arg1[2] + arg2;
}
