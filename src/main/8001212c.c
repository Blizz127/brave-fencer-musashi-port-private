/* Main-exec range [8001212C,800123F0) from the SLUS executable.
 * SHA256(span)=b3b625587df6529b69d0a5c1aa21e8811ea6549af8158d6385360bcf9c97d4ae.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern void *D_800A5E60;
extern s32 *D_800A6610;
extern s32 *D_800AF630;

void func_8001212C(void) {
    void *sp4;
    void *sp0;
    void *temp_v1;

    sp0 = D_800A5E60;
    sp4 = &D_800A6610 + (M2C_FIELD(&D_800AF630, u16 *, 0xA3D2) << 0xE);
    M2C_FIELD(D_800A5E60, s8 *, 3) = 5;
    M2C_FIELD(sp0, s32 *, 4) = 0xE1000018;
    M2C_FIELD(D_800A5E60, s8 *, 0xB) = 0x66;
    M2C_FIELD(D_800A5E60, s16 *, 0x12) = 0x77D6;
    M2C_FIELD(D_800A5E60, s8 *, 8) = 0x80;
    M2C_FIELD(D_800A5E60, s8 *, 9) = 0x80;
    M2C_FIELD(D_800A5E60, s8 *, 0xA) = 0x80;
    M2C_FIELD(D_800A5E60, s16 *, 0xC) = 0x30;
    M2C_FIELD(D_800A5E60, s16 *, 0xE) = 0x2E;
    M2C_FIELD(D_800A5E60, s8 *, 0x10) = 0x40;
    M2C_FIELD(D_800A5E60, s8 *, 0x11) = 0xE0;
    M2C_FIELD(D_800A5E60, s16 *, 0x14) = 0x60;
    M2C_FIELD(D_800A5E60, s16 *, 0x16) = 0x18;
    M2C_FIELD(D_800A5E60, s32 *, 0) = (s32) ((M2C_FIELD(D_800A5E60, s32 *, 0) & 0xFF000000) | (M2C_FIELD(sp4, s32 *, 4) & 0xFFFFFF & 0xFFFFFF));
    M2C_FIELD(sp4, s32 *, 4) = (s32) ((M2C_FIELD(sp4, s32 *, 4) & 0xFF000000) | ((s32) sp0 & 0xFFFFFF));
    temp_v1 = sp0 + 0x18;
    sp0 = temp_v1;
    M2C_FIELD(sp0, s8 *, 3) = 5;
    M2C_FIELD(temp_v1, s32 *, 4) = 0xE1000018;
    M2C_FIELD(sp0, s8 *, 0xB) = 0x66;
    M2C_FIELD(sp0, s16 *, 0x12) = 0x77D6;
    M2C_FIELD(sp0, s8 *, 8) = 0x80;
    M2C_FIELD(sp0, s8 *, 9) = 0x80;
    M2C_FIELD(sp0, s8 *, 0xA) = 0x80;
    M2C_FIELD(sp0, s16 *, 0xC) = 0x30;
    M2C_FIELD(sp0, s16 *, 0xE) = 0x46;
    M2C_FIELD(sp0, s8 *, 0x10) = 0xA0;
    M2C_FIELD(sp0, s8 *, 0x11) = 0xE0;
    M2C_FIELD(sp0, s16 *, 0x14) = 0x60;
    M2C_FIELD(sp0, s16 *, 0x16) = 0x18;
    M2C_FIELD(sp0, s32 *, 0) = (s32) ((M2C_FIELD(sp0, s32 *, 0) & 0xFF000000) | (M2C_FIELD(sp4, s32 *, 4) & 0xFFFFFF & 0xFFFFFF));
    M2C_FIELD(sp4, s32 *, 4) = (s32) ((M2C_FIELD(sp4, s32 *, 4) & 0xFF000000) | ((s32) temp_v1 & 0xFFFFFF));
    sp0 = temp_v1 + 0x18;
    D_800A5E60 = sp0;
}
