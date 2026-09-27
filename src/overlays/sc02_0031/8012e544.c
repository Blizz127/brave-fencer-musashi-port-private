/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012E544,8012E57C).
 * Offset 0x63EC at overlay base 80128158. SHA256(span)=7171c9cf5ec154308d603077d01d7d75519e1d3a9816f6accf933694c0af09b6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012e544.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_8012E544 (main_0012.s), decoded manually from
 * raw asm (0x38 bytes; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): same pool scan as
 * func_8012E504 but without the arg0 exclusion: returns the first
 * 0x10C-stride entry from &D_801202A0 (+0x6480 bound) whose first
 * u16 equals arg0, else 0. */

extern u8 D_801202A0;

u8 *func_8012E544(s32 arg0) {
    u8 *v1;
    u8 *end;

    v1 = &D_801202A0;
    end = &D_801202A0 + 0x6480;
    while (v1 != end) {
        if (*(u16 *) v1 == arg0) {
            return v1;
        }
        v1 += 0x10C;
    }
    return 0;
}
