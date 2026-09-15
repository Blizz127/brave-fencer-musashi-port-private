/* Exact retail [8001CF48,8001CFB8).
 * Words from pinned SLUS_007.26.
 */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001CF48(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0) = 2;
    M2C_FIELD(arg0, s16 *, 0x1C) = 0x1000;
    M2C_FIELD(arg0, s16 *, 0x1A) = 0x1000;
    M2C_FIELD(arg0, s16 *, 0x18) = 0x1000;
    M2C_FIELD(arg0, s16 *, 0x32) = 0;
    M2C_FIELD(arg0, s16 *, 0x30) = 0;
    M2C_FIELD(arg0, s16 *, 0x2E) = 0;
    M2C_FIELD(arg0, s16 *, 0x2C) = 0;
    M2C_FIELD(arg0, s8 *, 0x27) = 0;
    M2C_FIELD(arg0, s16 *, 0x1E) = 0;
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    M2C_FIELD(arg0, s16 *, 0x10) = 0;
    M2C_FIELD(arg0, s16 *, 0xE) = 0;
    M2C_FIELD(arg0, s16 *, 0xC) = 0;
    M2C_FIELD(arg0, s16 *, 0xA) = 0;
    M2C_FIELD(arg0, s16 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s8 *, 0x26) = 0x80;
    M2C_FIELD(arg0, s8 *, 0x25) = 0x80;
    M2C_FIELD(arg0, s8 *, 0x24) = 0x80;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x2C) = 0;
}
