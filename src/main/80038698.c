/* Exact retail word export for [80038698,800387C0); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80038698(void *arg0) {
    s16 temp_v1;
    s32 var_v0;
    void *temp_a3;

    temp_a3 = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(arg0, void **, 0) = (void *) (temp_a3 + 1);
    M2C_FIELD(arg0, void **, 0) = (void *) (temp_a3 + 2);
    M2C_FIELD(arg0, void **, 0) = (void *) (temp_a3 + 3);
    M2C_FIELD(arg0, void **, 0) = (void *) (temp_a3 + 4);
    var_v0 = -1;
    if ((M2C_FIELD(temp_a3, u8 *, 0) | (M2C_FIELD(temp_a3, u8 *, 1) << 8) | (M2C_FIELD(temp_a3, u8 *, 2) << 0x10) | (M2C_FIELD(temp_a3, u8 *, 3) << 0x18)) == 0x6468544D) {
        M2C_FIELD(arg0, void **, 0) = (void *) (temp_a3 + 5);
        M2C_FIELD(arg0, void **, 0) = (void *) (temp_a3 + 6);
        M2C_FIELD(arg0, void **, 0) = (void *) (temp_a3 + 7);
        M2C_FIELD(arg0, void **, 0) = (void *) (temp_a3 + 8);
        var_v0 = -1;
        if (((M2C_FIELD(temp_a3, u8 *, 8) << 8) | M2C_FIELD(temp_a3, u8 *, 9)) == 0) {
            var_v0 = -1;
            if ((s16) ((M2C_FIELD(temp_a3, u8 *, 0xA) << 8) | M2C_FIELD(temp_a3, u8 *, 0xB)) == 1) {
                temp_v1 = (M2C_FIELD(temp_a3, u8 *, 0xC) << 8) | M2C_FIELD(temp_a3, u8 *, 0xD);
                var_v0 = -1;
                if (!(temp_v1 & 0x8000)) {
                    var_v0 = 0;
                    M2C_FIELD(arg0, s16 *, 0x1E6) = (s16) (temp_v1 & 0x7FFF);
                    M2C_FIELD(arg0, void **, 0) = (void *) (M2C_FIELD(arg0, void **, 0) + ((((((M2C_FIELD(temp_a3, u8 *, 4) << 8) | M2C_FIELD(temp_a3, u8 *, 5)) << 8) | M2C_FIELD(temp_a3, u8 *, 6)) << 8) | M2C_FIELD(temp_a3, u8 *, 7)));
                }
            }
        }
    }
    return var_v0;
}
