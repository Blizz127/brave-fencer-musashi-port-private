/* Exact retail word export for [8005EB28,8005EC00); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072988();                               /* static */
void D_8007298C();                               /* static */
extern s32 D_80072998;
extern s32 D_8007299C;
extern s32 D_800729AC;
extern s32 D_800729DC;
void func_8005DE78(void *, u8);                  /* static */
void func_80072974();                            /* static */

void func_8005EB28(void *arg0) {
    u8 var_a1;

    if ((D_8007299C == D_800729AC) && (D_80072998 != 0)) {
        D_8007298C();
        D_80072988();
    }
    if (D_800729DC != 0) {
        func_80072974(M2C_FIELD(arg0, s32 *, 0xC));
        func_80072974(M2C_FIELD(arg0, s32 *, 0xC) + 0xF0);
    }
    if (M2C_FIELD(arg0, u8 *, 0x36) == 0) {
        var_a1 = 0x42;
    } else {
        var_a1 = M2C_FIELD(arg0, u8 *, 0x36);
    }
    func_8005DE78(arg0, var_a1);
}
