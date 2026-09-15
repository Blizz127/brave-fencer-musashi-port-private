/* Overlay range [8014B190,8014B2A8) from MAIN.CD member 0012.
 * SHA256(span)=7a9a8c7a180e57af96d32c22baa3b242e9282b540624bcb282d50f63c161fc9d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8016F1C4();                                /* static */
extern s32 *D_80078E78;
extern s16 D_80078E96;
extern s16 D_80078EA6;
extern u16 D_80078EB8;
extern u8 D_80078EC1;

void func_8014B190(void *arg0) {
    u16 temp_v1;

    M2C_FIELD(arg0, s16 *, 0x68) = 0x1000;
    M2C_FIELD(arg0, s16 *, 0x6A) = 0x1000;
    M2C_FIELD(arg0, s16 *, 0x6C) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) & ~0x200 & ~0x400);
    if (func_8016F1C4() == 0) {
        temp_v1 = M2C_FIELD(arg0, u16 *, 0);
        if ((temp_v1 != 0x1E) && (temp_v1 != 0x1A)) {
            if ((D_80078E96 & 0x8000) || ((u16) D_80078EB8 < 0xBU) || (D_80078EA6 < 0x10) || (D_80078EC1 == 1)) {
                M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 0x200);
            }
            if (M2C_FIELD(&D_80078E78, s16 *, 0x22) & 0x8000) {
                M2C_FIELD(arg0, s16 *, 0x68) = 0x555;
                M2C_FIELD(arg0, s16 *, 0x6A) = 0x555;
                M2C_FIELD(arg0, s16 *, 0x6C) = 0x555;
                M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 0x400);
            }
        }
    }
}
