/* Overlay range [801564B0,801565C0) from MAIN.CD member 0012.
 * SHA256(span)=7f0b616df091759e1971eb40158e3fbe9403fcfe932d59d6d0f1448155796b63.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8002A1B4();                                /* extern */
s32 func_8002A400();                                /* extern */
s32 func_8002A670();                                /* extern */
s32 func_8002A8E0();                                /* extern */
s32 func_8005C49C();                                /* extern */
extern s32 *D_80078E78;

s32 func_801564B0(void *arg0) {
    s32 var_v0;
    u32 temp_v1;

    if ((!(M2C_FIELD(arg0, s32 *, 0x44) & 0x200) || (var_v0 = 0x8000, ((func_8005C49C() & 1) == 0))) && (((func_8002A1B4() == 0) && (func_8002A400() == 0) && (func_8002A670() == 0) && (func_8002A8E0() == 0)) || (var_v0 = 0x8000, ((func_8005C49C() & 3) != 0)))) {
        var_v0 = 0;
        if (!(func_8005C49C() & 3)) {
            temp_v1 = (func_8005C49C() % 160) & 0xFFFF;
            var_v0 = 0;
            if (temp_v1 >= 0x51U) {
                var_v0 = 0x8000;
                if ((s32) temp_v1 >= M2C_FIELD(&D_80078E78, s16 *, 0x2E)) {
                    var_v0 = 0;
                }
            }
        }
    }
    return var_v0;
}
