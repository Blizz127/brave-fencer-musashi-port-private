/* Overlay range [80128ED8,80128FAC) from MAIN.CD member 0012.
 * SHA256(span)=c66504fc74987bd8b54f6b189f0c397c5077a8a6773a973be4c47c79bee895e6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80128ED8(void *arg0, void *arg1) {
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
        arg0->unk28 = (u16) *((arg1->unk4 * 8) + temp_t0);
        arg0->unk2A = (u16) ((arg1->unk4 * 8) + temp_t0)->unk2;
        /* Duplicate return node #9. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
