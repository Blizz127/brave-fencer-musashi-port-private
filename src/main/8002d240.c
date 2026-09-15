/* Exact retail word export for [8002D240,8002D29C); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006ADD8[];
void func_8003B45C(s32 *, s32 *);                /* static */
extern s16 D_800A4E74;
extern s32 D_800A4ECC;
extern u16 D_800A4ED4;
extern u16 D_800A4ED6;

void func_8002D240(s16 arg0) {
    u16 temp_v1;

    temp_v1 = *(D_8006ADD8 + ((s32) (arg0 << 0x10) >> 0xF));
    D_800A4ECC = 6;
    D_800A4E74 = arg0;
    D_800A4ED4 = temp_v1;
    D_800A4ED6 = temp_v1;
    func_8003B45C(&D_800A4ECC, &D_800A4ECC);
}
