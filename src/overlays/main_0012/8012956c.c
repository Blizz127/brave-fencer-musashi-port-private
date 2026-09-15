/* Overlay range [8012956C,801298F4) from MAIN.CD member 0012.
 * SHA256(span)=4a832986def3a9b9f1601aed72842ef19ba2a03b77d2b4decb399e3e8f24a557.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015B6C(s32, s16, s32, s16, s32, s32, s32, s32, s32, s32); /* extern */
void func_8005080C(s32, void *, u16, s32 *);             /* extern */
void func_80051044(s32, void *, u16, s32 *);             /* extern */
extern s32 D_801840B5;
extern s32 D_801840B6;
extern s32 D_801840B9;
extern s32 D_801840BA;
extern s32 D_80185BF0;
void func_801299C8(u8, s16, void *, u16);                 /* static */
extern s32 *D_800A6518;
extern s32 D_800AF630;
extern s32 *D_800B9A78;
extern s16 D_80114EE0;
extern s32 *D_801840B4;
extern s32 D_801840B8;

void func_8012956C(void) {
    void *var_s2;
    s16 var_a1;
    s32 *var_a2;
    s32 *var_a3;
    s32 var_s3;
    s32 var_s4;
    u16 temp_a3;
    u16 temp_v1;
    void *var_s0;

    if (D_80114EE0 != 0) {
        var_s2 = &D_800B9A78;
        var_s4 = 0;
        var_s3 = 4;
        var_s0 = &D_800B9A78 + 0x34;
        do {
            temp_v1 = var_s0->unk0;
            if (temp_v1 != 0x7FFE) {
                if ((s32) temp_v1 < 0x7FFF) {
                    var_a1 = var_s4 + 3;
                    if (temp_v1 != 0x7FFD) {
                        goto block_12;
                    }
                    if (var_s4 == 0) {
                        func_801299C8(D_80185BF0, 1, var_s2);
                    }
                    func_80015B6C(-0xA0, -0x74, 0x140, 0x8C, (s32) D_801840B8.unk0, (s32) D_801840B8.unk1, (s32) D_801840B8.unk2, (s32) D_801840B8.unk4, (s32) D_801840B8.unk5, (s32) D_801840B8.unk6);
                    func_80015B6C(-0xA0, 0x18, 0x140, 0x3C, (s32) D_801840B8.unk4, (s32) D_801840B8.unk5, (s32) D_801840B8.unk6, (s32) D_801840B8.unk8, (s32) D_801840B8.unk9, (s32) D_801840B8.unkA);
                    func_80015B6C(-0xA0, 0x54, 0x140, 0x28, (s32) D_801840B8.unk8, (s32) D_801840B8.unk9, (s32) D_801840B8.unkA, (s32) D_801840B8.unkC, (s32) D_801840B8.unkD, (s32) D_801840B8.unkE);
                    var_s0 += 0x54;
                } else {
                    var_a1 = var_s4 + 3;
                    if (temp_v1 == 0x7FFF) {
                        var_s0 += 0x54;
                    } else {
block_12:
                        temp_a3 = var_s0->unk4;
                        var_s0->unk-18 = (s16) (var_s0->unkC + temp_a3);
                        var_s0->unk-16 = (s16) (var_s0->unkE + var_s0->unk6);
                        func_801299C8(D_80185BF0, var_a1, var_s2, temp_a3);
                        *(s32 *)0x1F800000 = var_s2->unk0;
                        *(s32 *)0x1F800004 = var_s2->unk4;
                        *(s32 *)0x1F800008 = var_s2->unk8;
                        *(s32 *)0x1F80000C = var_s2->unkC;
                        var_a3 = (s32 *)0x1F800010;
                        var_a2 = var_s2 + 0x10;
                        do {
                            var_a3->unk0 = var_a2->unk0;
                            var_a3->unk4 = (s32) var_a2->unk4;
                            var_a3->unk8 = (s32) var_a2->unk8;
                            var_a3->unkC = (s32) var_a2->unkC;
                            var_a2 += 0x10;
                            var_a3 += 0x10;
                        } while (var_a2 != (var_s2 + 0x30));
                        *var_a3 = *var_a2;
                        (void *)0x1F800010->unk14 = 0x1F800000;
                        if (var_s0->unk2 == 0) {
                            func_80051044(0x1F800010, (D_800AF630.unkA3D2 * 0x14) + &D_800A6518, var_s0->unk0, var_a3);
                            var_s0 += 0x54;
                        } else {
                            func_8005080C(0x1F800010, (D_800AF630.unkA3D2 * 0x14) + &D_800A6518, var_s0->unk0, var_a3);
                            var_s0 += 0x54;
                        }
                    }
                }
            } else {
                func_801299C8(D_80185BF0, (s16) (var_s4 * 2), var_s2);
                func_80015B6C(-0xA0, (s16) var_s0->unk6, 0x140, var_s0->unkA, (s32) *(&D_801840B4 + var_s3), (s32) *(D_801840B5 + var_s3), (s32) *(D_801840B6 + var_s3), (s32) *(&D_801840B8 + var_s3), (s32) *(D_801840B9 + var_s3), (s32) *(D_801840BA + var_s3));
                var_s0 += 0x54;
            }
            var_s2 += 0x54;
            var_s4 += 1;
            var_s3 += 8;
        } while (var_s4 < 2);
    }
}
