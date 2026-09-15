/* Overlay range [8017B0E4,8017B1D8) from MAIN.CD member 0012.
 * SHA256(span)=f6a0b4364f916394f6b42edbfb33012b8f27782d1e62ed110af0a01419b9c1ef.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012C6C(s16, s16, s16);                   /* extern */
extern s32 D_801853BE;
extern s32 D_801853C0;
extern s32 D_801853C6;
extern s32 D_801853C8;
extern s16 D_801853BC;
extern s16 D_801853C4;

void func_8017B0E4(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x48) = (s32) func_80012C6C(M2C_FIELD(arg0, s16 *, 0x48), D_801853C4, arg1);
    M2C_FIELD(arg0, s16 *, 0x4C) = (s32) func_80012C6C(M2C_FIELD(arg0, s16 *, 0x4C), D_801853C6, arg1);
    M2C_FIELD(arg0, s16 *, 0x50) = (s32) func_80012C6C(M2C_FIELD(arg0, s16 *, 0x50), D_801853C8, arg1);
    M2C_FIELD(arg0, s16 *, 0x3C) = (s32) func_80012C6C(M2C_FIELD(arg0, s16 *, 0x3C), D_801853BC, arg1);
    M2C_FIELD(arg0, s16 *, 0x40) = (s32) func_80012C6C(M2C_FIELD(arg0, s16 *, 0x40), D_801853BE, arg1);
    M2C_FIELD(arg0, s16 *, 0x44) = (s32) func_80012C6C(M2C_FIELD(arg0, s16 *, 0x44), D_801853C0, arg1);
}
