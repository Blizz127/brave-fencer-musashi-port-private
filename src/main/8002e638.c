/* Exact retail word export for [8002E638,8002E700); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006A99C;
extern s32 D_8006AEEC;
void func_8002E700(s32);                               /* static */
s32 func_8003836C(s16);                             /* static */
extern s32 D_80078F10;
extern s32 D_800A46B4;
extern u16 D_800A46B8;
extern s8 D_800A46BA;
extern s16 D_800A4E86;
extern u16 D_800A4E8E;
extern s16 D_800A4EF4;

void func_8002E638(s32 arg0) {
    u16 var_v1;
    u32 temp_a0;

    if ((D_800A4E8E & 4) && ((func_8003836C(D_800A4E86) << 0x10) != 0)) {
        func_8002E700(arg0 & 0xFFFF);
        return;
    }
    temp_a0 = arg0 & 0xFFFF;
    if (D_80078F10 != 0) {
        if (temp_a0 < 5U) {
            var_v1 = *(D_8006A99C + (temp_a0 * 4));
        } else {
            var_v1 = 0x1F;
        }
        D_800A46B8 = var_v1;
        D_800A46B4 = 0xFFFF;
        D_800A46BA = 1;
        D_800A4EF4 = (s16) D_8006AEEC;
    }
}
