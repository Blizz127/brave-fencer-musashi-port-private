/* Exact retail word export for [800459E8,80045C94); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CC90;
extern s32 D_8006CF94;
extern s32 D_800739D8;
extern s32 D_800739F8;
extern s32 D_80073A14;
extern s32 D_80073A1A;
extern s32 D_80073A1C;
extern s32 D_80073A38;
void func_80043A18(s32, void *, s32);                       /* static */
s32 func_80045C94(s32, s32, void *);                     /* static */
void func_8005C324(void *, void *, u8);                /* static */
void func_8005C604(s32 (*)(), u8, u8, u8, s32, void *);  /* static */
extern s16 D_80073A18;
extern s32 D_80076400;
extern s32 *D_80076401;
extern s32 *D_80076402;
extern s32 *D_80076404;
extern s32 *D_80076408;
extern s32 *D_800769DC;
extern s32 *D_80078000;
extern s32 *D_80078800;

s32 func_800459E8(s32 arg0) {
    s32 sp1B;
    void *var_s0;
    void *var_s4;
    s32 var_s1;
    s32 var_s2;
    s32 var_v0;
    void *temp_v0;
    void *var_s3;
    void *var_v0_2;

    if (arg0 != D_8006CF94) {
        var_s0 = &D_80078000;
        if (func_80045C94(1, *(&D_800769DC + (arg0 * 0x2C)), &D_80078000) != 1) {
            var_v0 = -1;
            if (D_8006CC90 > 0) {
                func_8005C604(D_800739D8);
                return -1;
            }
            /* Duplicate return node #24. Try simplifying control flow for better match */
            return var_v0;
        }
        var_v0_2 = &D_80078000 + 0x800;
        if (D_8006CC90 >= 2) {
            func_8005C604(D_800739F8);
            var_v0_2 = &D_80078000 + 0x800;
        }
        var_s2 = 0;
        if ((u32) &D_80078000 < (u32) var_v0_2) {
            var_s3 = &D_80076400 + 8;
            var_s1 = 0;
            var_s4 = &D_80076400;
loop_8:
            if (var_s0->unk0 != 0) {
                sp1B = (unaligned s32) (first 3 bytes) var_s0->unk0;
                func_80043A18((s32) sp18, var_s4, (first 3 bytes) var_s0->unk0);
                temp_v0 = var_s1 + (&D_80076400 + 4);
                temp_v0->unk3 = (unaligned s32) (first 3 bytes) var_s0->unk8;
                temp_v0->unk-2 = (first 3 bytes) var_s0->unk8;
                switch (var_s2) {                   /* irregular */
                case 0:
                    D_80076400.unk8 = (u16) D_80073A14;
                    break;
                case 1:
                    D_80076400.unk20 = (s16) D_80073A18;
                    D_80076400.unk22 = (s8) D_80073A1A;
                    break;
                default:
                    func_8005C324(var_s3, var_s0 + 0x21, var_s0->unk20);
                    *(var_s3 + var_s0->unk20) = 0;
                    break;
                }
                if (D_8006CC90 >= 2) {
                    func_8005C604(D_80073A1C, *(&D_80076400 + var_s1), *(&D_80076401 + var_s1), *(&D_80076402 + var_s1), *(&D_80076404 + var_s1), var_s3);
                }
                var_s3 += 0x18;
                var_s1 += 0x18;
                var_s2 += 1;
                var_s0 += var_s0->unk0;
                var_s4 += 0x18;
                if ((var_s2 < 0x40) && ((u32) var_s0 < (u32) &D_80078800)) {
                    goto loop_8;
                }
            }
        }
        D_8006CF94 = arg0;
        if (var_s2 < 0x40) {
            *(&D_80076408 + (var_s2 * 0x18)) = 0;
        }
        var_v0 = 1;
        if (D_8006CC90 >= 2) {
            func_8005C604(D_80073A38, (u8) var_s2);
            goto block_23;
        }
        /* Duplicate return node #24. Try simplifying control flow for better match */
        return var_v0;
    }
block_23:
    var_v0 = 1;
    return var_v0;
}
