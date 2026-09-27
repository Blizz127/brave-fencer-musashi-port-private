/* Overlay range [80162968,80162AC0) from MAIN.CD member 0012.
 * SHA256(span)=d2e0c33c693da4e8a2b877b03abb4dc903f772d76f08068285df8f7d6ada6239.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800123F0(void *, s16);                 /* extern */
void func_80012558(void *, s16);                 /* extern */
void func_800126C4(void *, s16);                 /* extern */
void func_80013F3C(void *);                      /* extern */
s16 func_80047D3C(s32);                             /* extern */
s16 func_8004CFEC(s16, s16);                        /* extern */

void func_80162968(void *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 var_a0;
    s32 temp_v0_3;
    void *temp_s0;
    void *temp_s1;
    void *temp_s3;

    temp_s1 = M2C_FIELD(arg0, void **, 4);
    temp_s3 = M2C_FIELD(arg0, void **, 8);
    temp_s0 = arg0 + 0xC;
    M2C_FIELD(temp_s3, s16 *, 0x10) = func_8004CFEC(M2C_FIELD(temp_s1, s16 *, 0x84), M2C_FIELD(temp_s1, s16 *, 0x82));
    temp_v0 = M2C_FIELD(temp_s1, s16 *, 0x84);
    temp_v0_2 = M2C_FIELD(temp_s1, s16 *, 0x82);
    M2C_FIELD(temp_s3, s16 *, 0x14) = func_8004CFEC(M2C_FIELD(temp_s1, s16 *, 0x80), -func_80047D3C((temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2)));
    func_80013F3C(temp_s0);
    func_800126C4(temp_s0, M2C_FIELD(temp_s3, s16 *, 0x10));
    func_800123F0(temp_s0, M2C_FIELD(temp_s3, s16 *, 0x14));
    func_80012558(temp_s0, M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x20), s16 *, 0x12));
    func_800126C4(temp_s0, 0x400);
    temp_v0_3 = 0x300 - (s16) (M2C_FIELD(arg0, s32 *, 0x24) - M2C_FIELD(temp_s1, u16 *, 0xA));
    var_a0 = (temp_v0_3 << 0xD) / 768;
    if (M2C_FIELD(temp_s1, s32 *, 0x44) & 0x400) {
        var_a0 = ((temp_v0_3 << 0xD) / 768) / 3;
    }
    M2C_FIELD(temp_s3, s16 *, 0x1C) = var_a0;
    M2C_FIELD(temp_s3, s16 *, 0x1A) = var_a0;
    M2C_FIELD(temp_s3, s16 *, 0x18) = var_a0;
}
