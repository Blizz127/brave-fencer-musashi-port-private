/* SC02 resident retail span [8015879C,80158814). Offset 0x30644 at base 80128158.
 * SHA256(span)=36f897cafed81f796a86e59e792b4769d00e3ae9168956fce84500bc6f808461.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80184288->D_801B6440; D_80184294->D_801B644C; D_80184298->D_801B6450.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL from m2c draft of func_8015879C (main_0012.s): NOT verified
 * against retail. C89-gated only; promotion requires an oracle MATCH.
 * m2c shape: arg0->unkA8 on a void*. The disassembly stores it as a
 * BYTE (sb $zero, 0xA8), so the model declares one u8 at +0xA8 — a
 * word member would miscompile. The three globals are word stores
 * (sw %lo(...)); D_801B6440 was missing from the draft's declarations
 * and is added per the repo pipeline convention. Body is m2c's
 * verbatim. */

struct data_8015879C {
    u8 pad[0xA8];
    u8 unkA8;
};

extern s32 D_801B6440;
extern s32 D_801B644C;
extern s32 D_801B6450;
void func_80146C98(void *, s32);
void func_80147078(void *, s32);
void func_80147084();
void func_80147098(void *);
void func_801470AC(void *);
void func_80158880(void *);

void func_8015879C(struct data_8015879C *arg0) {
    D_801B6440 = 0;
    D_801B644C = 1;
    D_801B6450 = 0;
    arg0->unkA8 = 0;
    func_80147084();
    func_80147098(arg0);
    func_801470AC(arg0);
    func_80147078(arg0, 0x1A);
    func_80146C98(arg0, 1);
    func_80158880(arg0);
}
