/* Main-exec range [8003AAD8,8003AB84) from the SLUS executable.
 * SHA256(span)=dc1a73e617197db28fdccefc26869e740aa04f693b15952455d2c8574dc1af14.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B54C;
extern s32 *D_8006B550;
extern s32 *D_8006B554;
extern s32 *D_8006B558;
extern s32 D_8006B59C;
void func_8003B0B8();                            /* static */
void func_8003B0E4();                            /* static */

void func_8003AAD8(s32 arg0, s16 arg1, s32 arg2) {
    M2C_FIELD(D_8006B54C, s16 *, 0x1A6) = arg1;
    func_8003B0E4();
    M2C_FIELD(D_8006B54C, u16 *, 0x1AA) = (u16) (M2C_FIELD(D_8006B54C, u16 *, 0x1AA) | 0x30);
    func_8003B0E4();
    func_8003B0B8();
    *D_8006B550 = arg0;
    *D_8006B554 = (arg2 << 0x10) | 0x10;
    D_8006B59C = 1;
    *D_8006B558 = 0x01000200;
}
