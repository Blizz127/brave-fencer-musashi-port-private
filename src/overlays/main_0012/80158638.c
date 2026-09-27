/* Overlay range [80158638,80158794) from MAIN.CD member 0012.
 * SHA256(span)=37828f1f88a9096575f44aad0e0bb5e7a1cdc4d6d5717de6838a773cd7a3bc38.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800D0F4C();                     /* extern */
s32 func_800D0F8C();                         /* extern */
s32 func_8013767C(void *);                       /* static */
void func_8014B2A8();                            /* static */
void func_8014BB0C();                            /* static */
void func_8014BDC8();                            /* static */
s32 func_8014C98C();                                /* static */
void func_80158814(void *);                      /* static */
s16 func_80159464(void *);                          /* static */
void func_801599A4(void *);                      /* static */
void func_80159B3C(void *);                      /* static */
void func_80165718(void *);                      /* static */
void func_8016F0E4(void *);                      /* static */
extern u16 D_80078EB4;
extern s8 D_800B9A17;
extern u8 D_800B9A64;
extern s32 *D_80110EC0;

void func_80158638(void *arg0) {
    s32 temp_v1_2;
    u16 temp_v1;

    if ((D_800B9A64 == 0) && !(M2C_FIELD(arg0, s32 *, 0x44) & 0x10) && (temp_v1 = M2C_FIELD(arg0, u16 *, 0), (temp_v1 != 0x1A)) && (temp_v1 != 0x1E) && ((temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x1F8), (temp_v1_2 == 0)) || (temp_v1_2 & 0x08000000)) && (D_80078EB4 == 0)) {
        if ((((func_80159464(arg0) << 0x10) <= 0) || (func_80159464(arg0) >= 6)) && (func_8014C98C() == 0) && (func_800D0F8C(0xA) != 0)) {
            func_801599A4(arg0);
            func_8016F0E4(arg0);
            func_80159B3C(arg0);
            func_80165718(arg0);
            func_800D0F4C(0xA);
            func_8014BB0C();
            func_8014BDC8();
            func_8014B2A8();
            M2C_FIELD(arg0, s32 *, 0x198) = func_8013767C(&D_80110EC0);
            D_800B9A17 = 1;
            return;
        }
        func_801599A4(arg0);
        func_8016F0E4(arg0);
        func_80158814(arg0);
    }
}
