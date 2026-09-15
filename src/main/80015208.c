/* Exact retail word export for [80015208,800152F4); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801281D8(u8, void *);               /* extern */
extern u16 D_80078DD2;
extern s32 D_800A5E78;
extern s32 *D_800AF630;
extern u8 D_800B9A10;
extern u8 D_800B9A13;
extern u8 D_800B9A15;
extern u8 D_800B9A16;
extern u8 D_800B9A17;
extern u8 D_800B9A64;

void func_80015208(void) {
    s32 var_v0;

    if ((D_800B9A64 == 0) && (D_800B9A10 == 1) && (D_800B9A17 == D_800B9A10) && (D_800B9A15 != D_800B9A17)) {
        if (D_800B9A16 != 0) {
            D_800B9A15 = 1;
            return;
        }
        if (D_800B9A13 == 0) {
            var_v0 = 0;
            if ((D_80078DD2 & 0x800) == 0x800) {
                var_v0 = 1;
            }
            if ((var_v0 != 0) || (D_800A5E78 == 0)) {
                M2C_FIELD(&D_800AF630, s8 *, 0xA3E5) = 1;
                func_801281D8(D_800B9A10, &D_800AF630);
            }
        }
    }
}
