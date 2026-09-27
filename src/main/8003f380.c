/* Exact retail word export for [8003F380,8003F434); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800414E4(s16, s32);                    /* static */
extern s32 D_800A6578;

s32 func_8003F380(s16 arg0, s16 arg1) {
    if (func_800414E4(arg0, 0) != -1) {
        if ((arg1 & 1) > 0) {
            return M2C_FIELD(((((s32) (arg1 - 1) / 2) * 0x10) + D_800A6578), u16 *, 0xC) * 8;
        }
        return M2C_FIELD(((((s32) (arg1 - 1) / 2) * 0x10) + D_800A6578), u16 *, 0xE) * 8;
    }
    return -1;
}
