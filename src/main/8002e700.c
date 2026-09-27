/* Exact retail word export for [8002E700,8002E79C); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006A9B0[];
extern s32 D_8006A9BC[];
void func_8003819C(s16, s32, s32, s16);  /* static */
s32 func_8003836C(s16);                             /* static */
extern s16 D_800A4E86;
extern u16 D_800A4E8A;
extern u16 D_800A4E8E;

void func_8002E700(s32 arg0) {
    s32 temp_s0;
    s32 var_s0;

    if ((D_800A4E8E & 4) && ((func_8003836C(D_800A4E86) << 0x10) != 0)) {
        var_s0 = arg0 & 0xFFFF;
        if ((u32) (arg0 & 0xFFFF) >= 5U) {
            var_s0 = 4 & 0xFFFF;
        }
        temp_s0 = var_s0 * 2;
        func_8003819C(D_800A4E86, 0, 0, *(D_8006A9BC + temp_s0));
        D_800A4E8A = *(D_8006A9B0 + temp_s0);
    }
}
