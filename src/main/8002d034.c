/* Exact retail word export for [8002D034,8002D1F0); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002D240(s16, s16, s16, s16);                /* static */
void func_8002D29C();                                  /* static */
void func_8002DF80();                                  /* static */
extern u8 D_8006A980;
extern u8 D_800A46BA;
extern s32 D_800A4E68;
extern s16 D_800A4E6C;
extern u8 D_800A4E70;
extern s16 D_800A4E74;
extern s16 D_800A4E76;
extern s16 D_800A4E78;
extern u8 D_800A4E7A;
extern s32 (*D_800A4F24)();
extern s32 *D_800A64B0;

void func_8002D034(void) {
    void *var_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_s1;

    if (D_800A46BA != 0) {
        func_8002D29C();
    }
    var_s0 = &D_800A64B0;
    var_s1 = 0;
    do {
        temp_v0 = var_s0->unk0;
        temp_v0_2 = temp_v0 - 1;
        if (temp_v0 != 0) {
            var_s0->unk0 = temp_v0_2;
            if (temp_v0_2 == 0) {
                var_s0->unk8(var_s0);
            }
        }
        var_s1 += 1;
        var_s0 += 0xC;
    } while (var_s1 < 8);
    if (D_8006A980 & 0xEF) {
        func_8002DF80();
    }
    if (D_800A4F24 != 0) {
        D_800A4F24();
    }
    if (D_800A4E70 != 0) {
        temp_v0_3 = D_800A4E68 - 1;
        D_800A4E68 = temp_v0_3;
        if (temp_v0_3 == 0) {
            D_800A4E70 = 0;
            func_8002D240(D_800A4E6C);
        }
    }
    if (D_800A4E7A != 0) {
        if (D_800A4E74 < D_800A4E76) {
            if (D_800A4E74 < (D_800A4E76 - D_800A4E78)) {
                D_800A4E74 += D_800A4E78;
            } else {
                goto block_20;
            }
        } else if ((D_800A4E76 + D_800A4E78) < D_800A4E74) {
            D_800A4E74 -= D_800A4E78;
        } else {
block_20:
            D_800A4E74 = D_800A4E76;
            D_800A4E7A = 0;
        }
        func_8002D240(D_800A4E74, D_800A4E74, D_800A4E74, D_800A4E76);
    }
}
