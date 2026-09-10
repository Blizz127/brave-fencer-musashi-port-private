/* SC02.CD FILE_031 / ov_SC02_031 retail span [80130740,801307B0).
 * Offset 0x85E8 at overlay base 80128158. SHA256(span)=fd4f52484dd380823c2d3402c49351f0ad6de298ad64921d249fcb3017d69ff4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80130740.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_80130740 (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): calls
 * func_80146A6C(0x10, arg0, (s16)(arg0[3]+arg1[0]),
 * (s16)(arg0[5]+arg1[1]), (s16)(arg0[7]+arg1[2]), 0, 0) (u16
 * triplet sums with sll/sra half-sign-extend; the first stack word
 * is stored in the jal delay slot, the other two are pre-zeroed).
 * Returns void. */

extern void func_80146A6C(s32 arg0, void *arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6);

void func_80130740(u16 *arg0, u16 *arg1) {
    func_80146A6C(0x10, arg0, (s16)(arg0[3] + arg1[0]), (s16)(arg0[5] + arg1[1]), (s16)(arg0[7] + arg1[2]), 0, 0);
}
