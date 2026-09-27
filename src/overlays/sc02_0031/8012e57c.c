/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012E57C,8012E5CC).
 * Offset 0x6424 at overlay base 80128158. SHA256(span)=41513a26a5445cb70661f9b5804b66e3d450704121cf2122b5a302cadb9baf6c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012e57c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_8012E57C (main_0012.s), decoded manually from
 * raw asm (0x50 bytes; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): pool find-first like
 * func_8012E504 but keyed on two fields: first u16 == arg0 and
 * s16 at +0x70 == arg1 (a1 is sign-extended via sll/sra in the
 * entry-branch delay slot, hence s16). Byte stride 0x10C,
 * +0x6480 bound, else 0. */

extern u8 D_801202A0;

u8 *func_8012E57C(s32 arg0, s16 arg1) {
    u8 *v1;
    u8 *end;

    v1 = &D_801202A0;
    end = &D_801202A0 + 0x6480;
    while (v1 != end) {
        if (*(u16 *) v1 == arg0 && *(s16 *) (v1 + 0x70) == arg1) {
            return v1;
        }
        v1 += 0x10C;
    }
    return 0;
}
