/* Main-exec range [800190AC,80019198) from the SLUS executable.
 * SHA256(span)=b3e105ef1982420a7b1ac9f37048594e8b0ced61670698d614050b323c25b12a.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800747C0;
extern s32 D_800747C5;
extern u8 D_800747C4;
extern u8 D_80078DE2;
extern u8 D_80078DE3;

void func_800190AC(void) {
    u8 temp_v0;
    u8 temp_v0_2;
    void *temp_v0_3;
    void *temp_v1;

    if (D_800747C0 != 0) {
        if (D_800747C5 == 0) {
            temp_v0 = D_800747C4 + 1;
            D_800747C4 = temp_v0;
            temp_v1 = ((temp_v0 & 0xFF) * 3) + D_800747C0;
            D_80078DE2 = M2C_FIELD(temp_v1, u8 *, 1);
            D_80078DE3 = M2C_FIELD(temp_v1, u8 *, 0);
            temp_v0_2 = M2C_FIELD(temp_v1, u8 *, 2);
            D_800747C5 = temp_v0_2;
            if (temp_v0_2 == 0) {
                D_80078DE2 = 0;
                D_80078DE3 = 0;
                D_800747C4 = 0xFF;
                D_800747C0 = 0;
            }
        } else {
            temp_v0_3 = (D_800747C4 * 3) + D_800747C0;
            D_80078DE2 = M2C_FIELD(temp_v0_3, u8 *, 1);
            D_800747C5 = (u8) (D_800747C5 - 1);
            D_80078DE3 = M2C_FIELD(temp_v0_3, u8 *, 0);
        }
    }
}
