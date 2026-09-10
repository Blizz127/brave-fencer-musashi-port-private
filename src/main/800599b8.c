/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

/* Exact retail word export for [800599B8,80059A80); EXE and assembly verified. */
#include "psx_types.h"

/* HAND MODEL from m2c draft of func_800599B8 (main.s): NOT verified
 * against retail. C89-gated only; promotion requires an oracle MATCH.
 * D_80072780 is a LOADED struct pointer (lw, then member loads and
 * jalr): callback at +0x8 taking four words, data member at +0x20
 * passed as the first call argument (both lw). D_80074184 is
 * address-taken (lui+addiu, likely a function passed as a callback
 * context — the address passes identically either way). The
 * ?-prototype and ? parameter follow the repo pipeline convention.
 * NOTE: a second, UNNAMED sibling function follows at 0x80059A24
 * (same shape, D_80074190, member +0x1C); it is a separate function
 * and is not modeled here. Body is m2c's verbatim. */

struct tbl_800599B8 {
    u8 pad[8];
    void (*unk8)(s32, s32, s32, s32);
    u8 pad2[0x14];
    s32 unk20;
};

extern struct tbl_800599B8 *D_80072780;
extern u8 D_80074184[];
void func_80059760();

void func_800599B8(s32 arg0, s32 arg1) {
    func_80059760(D_80074184, arg0);
    D_80072780->unk8(D_80072780->unk20, arg0, 8, arg1);
}
