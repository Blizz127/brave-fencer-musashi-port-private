/* Overlay range [8016EBA8,8016EC0C) from MAIN.CD member 0012.
 * SHA256(span)=e3de14ee3bd25e256ef7a1fba01ca72daca7d85f8d9d0a942e149d652dd21078.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80181740[];
void func_8016EC0C();                     /* static */

void func_8016EBA8(void *arg0) {
    u8 temp_v1;

    M2C_FIELD(arg0, u16 *, 4) = (u16) (M2C_FIELD(arg0, u16 *, 4) - *(D_80181740 + (M2C_FIELD(arg0, u8 *, 2) * 2)));
    func_8016EC0C(0x80);
    temp_v1 = M2C_FIELD(arg0, u8 *, 2);
    M2C_FIELD(arg0, u8 *, 2) = (u8) (temp_v1 + 0xFF);
    if (temp_v1 == 0) {
        M2C_FIELD(arg0, s8 *, 0) = 0;
    }
}
