/* Exact retail word export for [8003D3B4,8003D3F8); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B54C;
void func_8003B0E4(void *);                      /* static */

void func_8003D3B4(s32 arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = (arg0 * 0x10) + D_8006B54C;
    M2C_FIELD(temp_a0, u16 *, 0xA) = (u16) ((M2C_FIELD(temp_a0, u16 *, 0xA) & 0xFFC0) | arg1);
    func_8003B0E4(temp_a0);
}
