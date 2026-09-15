/* Overlay range [80155A44,80155B20) from MAIN.CD member 0012.
 * SHA256(span)=f6563cd9958450829a3cf17b90e8091c08fc9396a8fc277ed77d3a1681c29c84.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029178();                         /* extern */
s32 func_80148800(void *);                          /* static */
void func_80149CB4(void *, s32);             /* static */
s32 func_8014BEF8(void *);                          /* static */

void func_80155A44(void *arg0) {
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 0x1AA);
    if ((s32) temp_v1 >= 0) {
        if ((s32) temp_v1 >= 2) {
            if (temp_v1 != 2) {
                return;
            }
            if ((func_80029178(0x86) & 0xFF) && (func_80148800(arg0) & 0x10)) {
                func_80149CB4(arg0, 3);
            }
        } else if ((func_80029178(0x85) & 0xFF) && (func_8014BEF8(arg0) != 0) && (M2C_FIELD(arg0, u8 *, 0x1C0) != 0) && (func_80148800(arg0) & 0x10)) {
            func_80149CB4(arg0, 2);
        }
    }
}
