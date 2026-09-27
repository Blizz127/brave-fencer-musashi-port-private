/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012E504,8012E544).
 * Offset 0x63AC at overlay base 80128158. SHA256(span)=3efa63ebd656a4f0113df552f32341ff0456675e4b4937f54b8b326df5886635.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012e504.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_8012E504 (main_0012.s), decoded manually from
 * raw asm (0x40 bytes; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): scans the 96-entry
 * 0x10C-stride pool from &D_801202A0 to +0x6480, skipping arg0,
 * returning the first entry whose first u16 equals arg1 (lhu/beq;
 * arg1 kept s32 so the comparison is bit-exact), else 0 (NULL is
 * spelled 0: no hosted headers under the Psy-Q chain). */

extern u8 D_801202A0;

u8 *func_8012E504(void *arg0, s32 arg1) {
    u8 *v1;
    u8 *end;

    v1 = &D_801202A0;
    end = &D_801202A0 + 0x6480;
    while (v1 != end) {
        if (v1 != arg0 && *(u16 *) v1 == arg1) {
            return v1;
        }
        v1 += 0x10C;
    }
    return 0;
}
