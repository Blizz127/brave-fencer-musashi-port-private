/* Overlay range [8013A530,8013A860) from MAIN.CD member 0012.
 * SHA256(span)=64982c855bdbc4356a1ec38bcb7252180b76dab561ac8d6750cbd143754bfaf0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015D4C(s16, s16, s16, s16, s32, s32, s32, s32, s32); /* extern */
void func_80015F04(s16, s16, s16, s16, s32, s32, s32, s32, s32); /* extern */
void func_8013AA24(void *, void *, void *, s32);       /* static */

void func_8013A530(void *arg0) {
    s16 temp_a0;
    s16 temp_a1_2;
    s16 temp_s2;
    s16 temp_s3;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v1_2;
    s16 temp_v1_3;
    s16 temp_v1_4;
    s16 temp_v1_5;
    s32 temp_a3;
    s32 temp_s0;
    s32 temp_s1;
    s32 var_a0;
    u16 temp_a1;
    u16 temp_v1;
    u8 temp_t0;
    void *temp_fp;

    temp_fp = arg0->unk4;
    temp_v1 = temp_fp->unk18;
    temp_t0 = temp_fp->unk22;
    if ((temp_v1 != 0) && (temp_v1 < 7U)) {
        switch (temp_v1) {                          /* irregular */
        default:
            temp_a1 = temp_fp->unk34;
            var_a0 = temp_a1 + 0x10;
            temp_a3 = temp_fp->unk36 + 0x10;
            if (temp_fp->unk20 != 0) {
                var_a0 = temp_a1 + 0x38;
            }
            temp_v1_2 = (temp_fp->unk28 * (var_a0 & 0xFFFF)) / 154;
            arg0->unk8 = temp_v1_2;
            if (!(temp_t0 & 8)) {
                arg0->unk8 = (s16) -temp_v1_2;
            }
            if (!(temp_t0 & 0x60) || (temp_t0 & 0x80)) {
                arg0->unk8 = (s16) -(s16) (u16) arg0->unk8;
            }
            temp_v1_3 = (temp_fp->unk2A * (temp_a3 & 0xFFFF)) / 42;
            arg0->unkA = temp_v1_3;
            if (temp_t0 & 0x10) {
                arg0->unkA = (s16) -temp_v1_3;
            }
            temp_a1_2 = arg0->unkC;
            temp_a0 = arg0->unkE;
            if (temp_a1_2 < temp_a0) {
                temp_v0 = temp_a1_2 + 0x400;
                arg0->unkC = temp_v0;
                temp_v1_4 = arg0->unkE;
                if (temp_v1_4 < temp_v0) {
                    arg0->unkC = temp_v1_4;
                }
            } else {
                temp_v0_2 = temp_a1_2 - 0x400;
                if (temp_a0 < temp_a1_2) {
                    arg0->unkC = temp_v0_2;
                    temp_v1_5 = arg0->unkE;
                    if (temp_v0_2 < temp_v1_5) {
                        arg0->unkC = temp_v1_5;
                    }
                }
            }
            func_8013AA24(temp_fp, arg0, arg0, temp_a3);
            return;
        case 1:
            arg0->unkB = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            temp_s0 = (s32) (((s16) temp_fp->unk34 + 0x10) * arg0->unk8) >> 0xC;
            temp_s2 = temp_fp->unk24 - ((u32) (temp_s0 & 0xFFFF) >> 1);
            temp_s1 = (s32) (((s16) temp_fp->unk36 + 0x10) * arg0->unkA) >> 0xC;
            temp_s3 = temp_fp->unk26 - ((u32) (temp_s1 & 0xFFFF) >> 1);
            func_80015F04(temp_s2, temp_s3, (s16) temp_s0, (s16) temp_s1, 0xB3, 0x99, 0x4C, (s32) temp_fp->unk1A, 4);
            func_80015F04((s16) (temp_s2 + 1), (s16) (temp_s3 + 1), (s16) (temp_s0 - 2), (s16) (temp_s1 - 2), 0xE6, 0xCC, 0x73, (s32) temp_fp->unk1A, 4);
            func_80015D4C(temp_s2, temp_s3, (s16) temp_s0, (s16) temp_s1, 0xFF, 0xE6, 0x99, (s32) temp_fp->unk1A, 4);
            break;
        }
    } else {
    case 0:
    }
}
