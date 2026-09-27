/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A908,8012A988).
 * Offset 0x27B0 at overlay base 80128158. SHA256(span)=692ec3771ef15c43d8aa87dfbc58bebb616b147beeea33e6d1ac0e57a3a2231e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a908.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL from m2c draft of func_8012A908 (main_0012.s): NOT
 * verified against retail. C89-gated only; promotion requires an
 * oracle MATCH. Loop shape from m2c; widths grounded from raw asm (lh D_801270C0, lh+andi 0x1000 on unk72, +0x10C step, 0x60 iterations). */

struct entry_8012A908 {
    u8 pad[0x72];
    u16 unk72;
    u8 pad2[0x98];
};

extern struct entry_8012A908 D_801202A0[0x60];
extern s16 D_801270C0;

void func_8012A988(struct entry_8012A908 *arg0);

void func_8012A908(void) {
    struct entry_8012A908 *var_s0;
    s32 var_s1;

    var_s0 = D_801202A0;
    var_s1 = 0;
    do {
        if ((D_801270C0 == 1) || (var_s0->unk72 & 0x1000)) {
            func_8012A988(var_s0);
        }
        var_s1 += 1;
        var_s0 += 1;
    } while (var_s1 < 0x60);
}
