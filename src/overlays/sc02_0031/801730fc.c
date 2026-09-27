/* SC02.CD FILE_031 / ov_SC02_031 retail span [801730FC,8017316C).
 * Offset 0x4AFA4 at overlay base 80128158. SHA256(span)=10f79cb2188cd64b4afdcf4fc0ca5cc580529a33316fd873a4cc2aaf5dfa3fe1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801730fc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL from m2c draft of func_801730FC (main_0012.s): NOT verified
 * against retail. C89-gated only; promotion requires an oracle MATCH.
 * m2c shape: arg0->unkB8 & 0x8000 on a void*. The disassembly loads
 * it as a halfword (lhu +0xB8), so the model declares one u16 at
 * +0xB8 — same flags member as the other 0xB8-family functions. The
 * global is an s16 per the draft (kept; the branch only tests
 * nonzero). func_80147060 was missing from the draft's declarations
 * and is added per the repo pipeline convention. Body is m2c's
 * verbatim. */

struct data_801730FC {
    u8 pad[0xB8];
    u16 unkB8;
};

void func_80154150(void *, s32);
void func_80171A1C();
void func_80174650(void *);
extern s16 D_80126B30;
void func_80147060();

void func_801730FC(struct data_801730FC *arg0) {
    if (arg0->unkB8 & 0x8000) {
        func_80171A1C();
        if (D_80126B30 != 0) {
            func_80147060(arg0);
            func_80154150(arg0, 0);
        }
        func_80174650(arg0);
    }
}
