/* Main-exec range [8003E65C,8003EA04) from the SLUS executable.
 * SHA256(span)=d4be7f49a8f29cfb1d36ecdf7b62ea893efa9625d360a7b37a5ee12c9350dd3e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003E418(s16, s16, u8, void *);              /* static */
s32 func_8003EA04(s16, s16, s32, s8);               /* static */
extern s32 (*D_800794E8)();
extern s32 (*D_800794EC)();
extern s32 (*D_800794F0)();
extern s32 (*D_800794F4)();
extern s32 (*D_800794F8)();
extern s32 *D_800C73D8;

s32 func_8003E65C(s16 arg0, s16 arg1) {
    s32 (*var_v0_2)();
    s16 var_a0;
    s16 var_a1_3;
    s32 *var_a2;
    s32 temp_v0;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_v0;
    s8 temp_a3_2;
    u8 temp_s2;
    u8 temp_s2_2;
    u8 temp_v1_6;
    u8 var_a2_2;
    u8 var_a2_3;
    u8 var_s4;
    void *temp_a3;
    void *temp_s3;
    void *temp_t1;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_7;

    var_a2 = (arg0 * 4) + &D_800C73D8;
    temp_v0 = arg1 * 0xB0;
    temp_s3 = *var_a2 + temp_v0;
    temp_a3 = temp_s3->unk0;
    temp_t1 = temp_a3 + 1;
    temp_s3->unk0 = temp_t1;
    temp_s2 = temp_a3->unk0;
    if (((temp_v0 + *var_a2)->unk98 & 0x401) == 0x401) {
        temp_v1 = temp_s3->unk10;
        var_v0 = temp_s2 & 0x80;
        if (temp_t1 == (temp_v1 + 1)) {
            func_8003E418(arg0, arg1, temp_v1->unk1, temp_a3);
            return -1;
        }
        goto block_4;
    }
    var_v0 = temp_s2 & 0x80;
block_4:
    temp_a3_2 = temp_s2 & 0xF;
    if (var_v0 != 0) {
        var_a2 = (s32 *) (temp_s2 & 0xF0);
        temp_s3->unk17 = temp_a3_2;
        if (var_a2 != (s32 *)0xC0) {
            if ((s32) var_a2 < 0xC1) {
                switch (var_a2) {                   /* switch 1; irregular */
                case 0x90:                          /* switch 1 */
                    temp_v1_2 = temp_s3->unk0;
                    temp_s3->unk16 = 0x90U;
                    temp_s3->unk0 = (void *) (temp_v1_2 + 1);
                    temp_s2_2 = temp_v1_2->unk0;
                    temp_s3->unk0 = (void *) (temp_v1_2 + 2);
                    var_s4 = temp_v1_2->unk1;
                    temp_s3->unk90 = func_8003EA04(arg0, arg1, (s32) var_a2, temp_a3_2);
                    var_a2_2 = temp_s2_2;
                    goto block_28;
                case 0xB0:                          /* switch 1 */
                    var_a0 = arg0;
                    temp_v1_3 = temp_s3->unk0;
                    temp_s3->unk16 = 0xB0U;
                    temp_s3->unk0 = (void *) (temp_v1_3 + 1);
                    var_a2_3 = temp_v1_3->unk0;
                    var_v0_2 = D_800794F8;
                    var_a1 = arg1 << 0x10;
                    goto block_37;
                default:                            /* switch 1 */
                    return 0;
                }
            } else {
                switch (var_a2) {                   /* switch 2; irregular */
                case 0xE0:                          /* switch 2 */
                    var_a1_2 = arg1 << 0x10;
                    temp_s3->unk16 = 0xE0U;
                    temp_s3->unk0 = (void *) (temp_s3->unk0 + 1);
                    goto block_32;
                case 0xF0:                          /* switch 2 */
                    temp_v1_4 = temp_s3->unk0;
                    temp_s3->unk16 = 0xFFU;
                    temp_s3->unk17 = temp_a3_2;
                    temp_s3->unk0 = (void *) (temp_v1_4 + 1);
                    var_a2_3 = temp_v1_4->unk0;
                    if (var_a2_3 != 0x2F) {
                        var_a0_2 = arg0 << 0x10;
                        goto block_36;
                    }
                    goto block_34;
                default:                            /* switch 2 */
                    return 0;
                }
            }
        } else {
            var_a0 = arg0;
            temp_v1_5 = temp_s3->unk0;
            temp_s3->unk16 = 0xC0U;
            temp_s3->unk0 = (void *) (temp_v1_5 + 1);
            var_a2_3 = temp_v1_5->unk0;
            var_v0_2 = D_800794EC;
            var_a1 = arg1 << 0x10;
            goto block_37;
        }
    } else {
        temp_v1_6 = temp_s3->unk16;
        if (temp_v1_6 != 0xC0) {
            if ((s32) temp_v1_6 < 0xC1) {
                switch (temp_v1_6) {                /* switch 3; irregular */
                case 0x90:                          /* switch 3 */
                    temp_v1_7 = temp_s3->unk0;
                    temp_s3->unk0 = (void *) (temp_v1_7 + 1);
                    var_s4 = temp_v1_7->unk0;
                    var_a2_2 = temp_s2;
                    temp_s3->unk90 = func_8003EA04(arg0, arg1, (s32) var_a2, temp_a3_2);
block_28:
                    D_800794E8(arg0, arg1, var_a2_2, var_s4);
                    return 0;
                case 0xB0:                          /* switch 3 */
                    var_a0 = arg0;
                    var_a1_3 = arg1;
                    var_v0_2 = D_800794F8;
                    var_a2_3 = temp_s2;
                    goto block_38;
                default:                            /* switch 3 */
                    return 0;
                }
            } else {
                if (temp_v1_6 != 0xE0) {
                    var_a2_3 = temp_s2 & 0xFF;
                    if (temp_v1_6 != 0xFF) {
                        return 0;
                    }
                    if (var_a2_3 == 0x2F) {
block_34:
                        func_8003E418(arg0, arg1, 0x2FU, (void *) temp_a3_2);
                        return 1;
                    }
                    var_a0_2 = arg0 << 0x10;
block_36:
                    var_a0 = (s16) (var_a0_2 >> 0x10);
                    var_a1 = arg1 << 0x10;
                    var_v0_2 = D_800794F4;
block_37:
                    var_a1_3 = (s16) (var_a1 >> 0x10);
                    goto block_38;
                }
                var_a1_2 = arg1 << 0x10;
block_32:
                D_800794F0(arg0, var_a1_2 >> 0x10, (s32) var_a2, temp_a3_2);
                return 0;
            }
        } else {
            var_a0 = arg0;
            var_a1_3 = arg1;
            var_v0_2 = D_800794EC;
            var_a2_3 = temp_s2;
block_38:
            var_v0_2((s32) var_a0, (s32) var_a1_3, var_a2_3, temp_a3_2);
            return 0;
        }
    }
}
