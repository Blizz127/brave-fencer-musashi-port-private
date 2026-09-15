/* Overlay range [80128DB4,80128EA8) from MAIN.CD member 0012.
 * SHA256(span)=2c87cf9648b559c0d31b06506e6fabdff950fbd802fbc4e717c03d3930462a1f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800183E0(s32, s32, s16);                     /* extern */
void func_80018450(s32, s32, s16);                     /* extern */

s32 func_80128DB4(s32 arg0, void *arg1) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v1;
    s32 temp_a2;
    s32 temp_t0;

    temp_v0 = arg1->unk6;
    temp_t0 = arg1->unk0;
    if (temp_v0 == 0) {
        return 1;
    }
    temp_v0_2 = temp_v0 - 1;
    arg1->unk6 = temp_v0_2;
    if ((temp_v0_2 << 0x10) <= 0) {
        temp_v1 = arg1->unk4;
        temp_a2 = ((temp_v1 * 8) + temp_t0)->unk4;
        if ((temp_a2 & 0xC0) == 0xC0) {
            arg1->unk6 = 0;
            return 1;
        }
        if (temp_a2 & 0x80) {
            arg1->unk4 = 0;
        } else {
            arg1->unk4 = (s16) (temp_v1 + 1);
        }
        arg1->unk6 = (s16) (((arg1->unk4 * 8) + temp_t0)->unk4 & 0x3F);
        if (arg0 != 0) {
            func_80018450(*((arg1->unk4 * 8) + temp_t0), temp_a2, temp_v1);
            return 0;
        }
        func_800183E0(*((arg1->unk4 * 8) + temp_t0), temp_a2, temp_v1);
        /* Duplicate return node #11. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
