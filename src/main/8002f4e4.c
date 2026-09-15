/* Exact retail word export for [8002F4E4,8002F5C8); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800A4640;
extern void *D_800A4EE8;
extern s16 D_800A4EF0;

u16 func_8002F4E4(void *arg0) {
    s16 temp_a1;
    s16 temp_a1_3;
    s16 temp_v1;
    s32 temp_a1_2;
    u16 temp_a0_2;
    u16 var_v0;
    u8 temp_a0;

    if ((D_800A4EF0 == 0) || ((var_v0 = 0, (D_800A4EE8 != 0)) && (temp_a1 = *(&D_800A4640 + (arg0->unk2 * 0x18)), temp_v1 = D_800A4EE8->unk4, var_v0 = 0, ((temp_a1 < temp_v1) == 0)) && ((temp_a1_2 = temp_a1 - temp_v1, ((temp_a1_2 < D_800A4EE8->unk2) == 0)) || ((temp_a1_3 = *((temp_a1_2 * 2) + D_800A4EE8->unk8), var_v0 = 0, (temp_a1_3 != 0)) && ((temp_a0 = arg0->unk3, (((s32) temp_a0 < D_800A4EE8->unkC) == 0)) || (temp_a0_2 = *(((temp_a1_3 - 1) * 2) + (D_800A4EE8->unk10 + (temp_a0 * (D_800A4EE8->unkE * 2)))), var_v0 = temp_a0_2, (temp_a0_2 == 0x7F))))))) {
        var_v0 = 0;
    }
    return var_v0;
}
