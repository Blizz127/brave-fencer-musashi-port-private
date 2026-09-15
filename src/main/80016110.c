/* Main-exec range [80016110,80016224) from the SLUS executable.
 * SHA256(span)=e988dd4bc46b414166e20ec88b715e71e3e4a35bceb462d756c253e6f96e948d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void *func_80010A08();                       /* static */
void func_80016638(void *, s32, s32);    /* static */
extern s32 *D_800A6518;
extern s32 *D_800A651C;
extern u16 D_800B9A02;

void func_80016110(void) {
    s32 *temp_a0;
    void *temp_v0;

    temp_v0 = func_80010A08(0x18);
    M2C_FIELD(temp_v0, s8 *, 3) = 5;
    M2C_FIELD(temp_v0, s8 *, 7) = 0x2A;
    M2C_FIELD(temp_v0, s16 *, 0x10) = -0xA0;
    M2C_FIELD(temp_v0, s16 *, 8) = -0xA0;
    M2C_FIELD(temp_v0, s16 *, 0x14) = 0xA0;
    M2C_FIELD(temp_v0, s16 *, 0xC) = 0xA0;
    M2C_FIELD(temp_v0, s16 *, 0xE) = -0x78;
    M2C_FIELD(temp_v0, s16 *, 0xA) = -0x78;
    M2C_FIELD(temp_v0, s8 *, 6) = 0;
    M2C_FIELD(temp_v0, s8 *, 5) = 0;
    M2C_FIELD(temp_v0, s8 *, 4) = 0;
    M2C_FIELD(temp_v0, s16 *, 0x16) = 0x78;
    M2C_FIELD(temp_v0, s16 *, 0x12) = 0x78;
    M2C_FIELD(temp_v0, s32 *, 0) = (s32) ((M2C_FIELD(temp_v0, s32 *, 0) & 0xFF000000) | (**(&D_800A651C + (D_800B9A02 * 0x14)) & 0xFFFFFF));
    temp_a0 = *(&D_800A651C + (D_800B9A02 * 0x14));
    *temp_a0 = (*temp_a0 & 0xFF000000) | ((s32) temp_v0 & 0xFFFFFF);
    func_80016638((D_800B9A02 * 0x14) + &D_800A6518, 0, 0);
}
