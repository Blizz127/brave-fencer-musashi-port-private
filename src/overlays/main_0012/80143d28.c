/* Overlay range [80143D28,80143E68) from MAIN.CD member 0012.
 * SHA256(span)=f5062271bece294d2764798b74cf10951b828c25b654116aeacff019ff0ea852.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80048FBC(void *, void *, void *);      /* extern */
extern s32 D_8017FCDC;
s32 func_8012BEE8(void *);                          /* static */
void func_8012C218(void *);                      /* static */

void func_80143D28(void *arg0) {
    s16 var_s3;
    s32 temp_v1;
    void *temp_a1;
    void *temp_s1;
    void *temp_s2;

    temp_s2 = M2C_FIELD(arg0, void **, 0x20);
    temp_s1 = M2C_FIELD(arg0, void **, 0x64);
    temp_a1 = (M2C_FIELD(arg0, s16 *, 0x70) * 0xC) + D_8017FCDC;
    M2C_FIELD(temp_s2, u16 *, 0x14) = (u16) M2C_FIELD(temp_a1, u16 *, 8);
    M2C_FIELD(temp_s2, u16 *, 0x12) = (u16) (M2C_FIELD(temp_s2, u16 *, 0x12) + M2C_FIELD(temp_a1, u16 *, 0xA));
    func_80048FBC(M2C_FIELD(arg0, void **, 0x20) + 0x34, temp_a1, arg0 + 0x50);
    var_s3 = 0x1000;
    if ((M2C_FIELD(arg0, s16 *, 0xFE) == 0) && ((temp_s1 == 0) || (M2C_FIELD(temp_s1, s16 *, 0x36) != M2C_FIELD(arg0, s16 *, 0xFC)) || (M2C_FIELD(temp_s1, u8 *, 0xC1) != 6))) {
        if (M2C_FIELD(arg0, s32 *, 0x1C) >= 0x11) {
            M2C_FIELD(arg0, s32 *, 0x1C) = 0x10;
        }
        M2C_FIELD(arg0, s16 *, 0xFE) = 1;
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x1C);
    if (temp_v1 < 0x11) {
        var_s3 = temp_v1 << 8;
    }
    if (temp_v1 >= 0x74) {
        var_s3 = (0x78 - temp_v1) << 0xA;
    }
    M2C_FIELD(temp_s2, s16 *, 0x1C) = var_s3;
    M2C_FIELD(temp_s2, s16 *, 0x1A) = var_s3;
    M2C_FIELD(temp_s2, s16 *, 0x18) = var_s3;
    if (func_8012BEE8(arg0) != 0) {
        func_8012C218(arg0);
    }
}
