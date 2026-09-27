/* Overlay range [8017DF40,8017E22C) from MAIN.CD member 0012.
 * SHA256(span)=2f588bba7bca73975724ec4c768f57db23ca1b91150f1a87acfd59cfcaaa0f9f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8018581C;
extern s32 D_801858B4;
extern s32 D_80185934;
extern s32 D_80185974;
extern s32 D_80185A74;
extern s32 *D_80078E78;
extern s32 *D_800A6588;
extern s32 *D_800AE648;
extern s32 *D_800BA1B8;
extern s32 *D_800BA2B8;

void func_8017DF40(s32 arg0) {
    s32 (*var_a2)();
    s32 (*var_a3_2)();
    void *var_a2_2;
    void *var_a3;
    s16 temp_v0_3;
    s16 temp_v0_6;
    s16 temp_v1;
    s16 temp_v1_2;
    s16 temp_v1_3;
    s16 temp_v1_4;
    s16 temp_v1_5;
    s16 temp_v1_6;
    s16 var_t0;
    s16 var_t0_2;
    s16 var_t0_3;
    s16 var_t0_4;
    s16 var_t0_5;
    s16 var_t0_6;
    s16 var_t0_7;
    s16 var_t0_8;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;

    if ((arg0 << 0x10) == 0) {
        var_a3 = &D_80078E78;
        var_a2 = D_8018581C;
        do {
            var_a3->unk0 = (s32) var_a2->unk0;
            var_a3->unk4 = (s32) var_a2->unk4;
            var_a3->unk8 = (s32) var_a2->unk8;
            var_a3->unkC = (s32) var_a2->unkC;
            var_a2 += 0x10;
            var_a3 += 0x10;
        } while (var_a2 != (D_8018581C + 0x90));
        var_a3->unk0 = (s32) var_a2->unk0;
        var_a3->unk4 = (s32) var_a2->unk4;
        var_t0 = 0;
        do {
            temp_a0 = var_t0 << 0x10;
            temp_v1 = var_t0 + 1;
            var_t0 = temp_v1;
            temp_a0_2 = temp_a0 >> 0xF;
            *(temp_a0_2 + &D_800A6588) = *(temp_a0_2 + D_801858B4);
        } while (temp_v1 < 0x40);
        var_t0_2 = 0;
        var_v0 = 0 << 0x10;
        do {
            temp_v0 = var_v0 >> 0x10;
            temp_v1_2 = var_t0_2 + 1;
            var_t0_2 = temp_v1_2;
            *(&D_800AE648 + temp_v0) = *(D_80185934 + temp_v0);
            var_v0 = var_t0_2 << 0x10;
        } while (temp_v1_2 < 0x40);
        var_t0_3 = 0;
        var_v0_2 = 0 << 0x10;
        do {
            temp_v0_2 = var_v0_2 >> 0x10;
            temp_v1_3 = var_t0_3 + 1;
            var_t0_3 = temp_v1_3;
            *(&D_800BA1B8 + temp_v0_2) = *(D_80185974 + temp_v0_2);
            var_v0_2 = var_t0_3 << 0x10;
        } while (temp_v1_3 < 0x100);
        var_t0_4 = 0;
        var_v0_3 = 0 << 0x10;
        do {
            ((var_v0_3 >> 0xE) + &D_800BA2B8)->unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            temp_v0_3 = var_t0_4 + 1;
            var_t0_4 = temp_v0_3;
            var_v0_3 = var_t0_4 << 0x10;
        } while (temp_v0_3 < 0x18);
        return;
    }
    var_a3_2 = D_8018581C;
    var_a2_2 = &D_80078E78;
    do {
        var_a3_2->unk0 = (s32) var_a2_2->unk0;
        var_a3_2->unk4 = (s32) var_a2_2->unk4;
        var_a3_2->unk8 = (s32) var_a2_2->unk8;
        var_a3_2->unkC = (s32) var_a2_2->unkC;
        var_a2_2 += 0x10;
        var_a3_2 += 0x10;
    } while (var_a2_2 != (&D_80078E78 + 0x90));
    var_a3_2->unk0 = (s32) var_a2_2->unk0;
    var_a3_2->unk4 = (s32) var_a2_2->unk4;
    var_t0_5 = 0;
    do {
        temp_a0_3 = var_t0_5 << 0x10;
        temp_v1_4 = var_t0_5 + 1;
        var_t0_5 = temp_v1_4;
        temp_a0_4 = temp_a0_3 >> 0xF;
        *(temp_a0_4 + D_801858B4) = *(temp_a0_4 + &D_800A6588);
    } while (temp_v1_4 < 0x40);
    var_t0_6 = 0;
    var_v0_4 = 0 << 0x10;
    do {
        temp_v0_4 = var_v0_4 >> 0x10;
        temp_v1_5 = var_t0_6 + 1;
        var_t0_6 = temp_v1_5;
        *(D_80185934 + temp_v0_4) = *(&D_800AE648 + temp_v0_4);
        var_v0_4 = var_t0_6 << 0x10;
    } while (temp_v1_5 < 0x40);
    var_t0_7 = 0;
    var_v0_5 = 0 << 0x10;
    do {
        temp_v0_5 = var_v0_5 >> 0x10;
        temp_v1_6 = var_t0_7 + 1;
        var_t0_7 = temp_v1_6;
        *(D_80185974 + temp_v0_5) = *(&D_800BA1B8 + temp_v0_5);
        var_v0_5 = var_t0_7 << 0x10;
    } while (temp_v1_6 < 0x100);
    var_t0_8 = 0;
    var_v0_6 = 0 << 0x10;
    do {
        ((var_v0_6 >> 0xE) + D_80185A74)->unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        temp_v0_6 = var_t0_8 + 1;
        var_t0_8 = temp_v0_6;
        var_v0_6 = var_t0_8 << 0x10;
    } while (temp_v0_6 < 0x18);
}
