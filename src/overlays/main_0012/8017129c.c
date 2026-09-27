/* Overlay range [8017129C,80171384) from MAIN.CD member 0012.
 * SHA256(span)=bad3e3f04e71314c6a9e1b5d336999c4036e542334f8fd7d79bdd257cf501883.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80171384(void *);                      /* static */
void func_80171990(void *, s32, void *);      /* static */
void func_801719A4();                     /* static */
extern s32 *D_800A5E88;
extern s32 *D_800A5E98;
extern s32 *D_800A5EA8;
extern void *D_8011F738;

void func_8017129C(void *arg0) {
    void *temp_a0;

    func_801719A4(1);
    M2C_FIELD(D_8011F738, s32 *, 0) = (s32) M2C_FIELD(&D_800A5E88, s32 *, 0);
    M2C_FIELD(D_8011F738, s32 *, 4) = (s32) M2C_FIELD(&D_800A5E88, s32 *, 4);
    M2C_FIELD(D_8011F738, s32 *, 8) = (s32) M2C_FIELD(&D_800A5E88, s32 *, 8);
    M2C_FIELD(D_8011F738, s32 *, 0xC) = (s32) M2C_FIELD(&D_800A5E88, s32 *, 0xC);
    M2C_FIELD(D_8011F738, s32 *, 0x10) = (s32) M2C_FIELD(&D_800A5E98, s32 *, 0);
    M2C_FIELD(D_8011F738, s32 *, 0x14) = (s32) M2C_FIELD(&D_800A5E98, s32 *, 4);
    M2C_FIELD(D_8011F738, s32 *, 0x18) = (s32) M2C_FIELD(&D_800A5E98, s32 *, 8);
    M2C_FIELD(D_8011F738, s32 *, 0x1C) = (s32) M2C_FIELD(&D_800A5E98, s32 *, 0xC);
    M2C_FIELD(D_8011F738, s32 *, 0x20) = (s32) M2C_FIELD(&D_800A5EA8, s32 *, 0);
    M2C_FIELD(D_8011F738, s32 *, 0x24) = (s32) M2C_FIELD(&D_800A5EA8, s32 *, 4);
    M2C_FIELD(D_8011F738, s32 *, 0x28) = (s32) M2C_FIELD(&D_800A5EA8, s32 *, 8);
    M2C_FIELD(D_8011F738, s32 *, 0x2C) = (s32) M2C_FIELD(&D_800A5EA8, s32 *, 0xC);
    temp_a0 = M2C_FIELD(arg0, void **, 0x20);
    M2C_FIELD(temp_a0, u16 *, 0x2C) = (u16) (M2C_FIELD(temp_a0, u16 *, 0x2C) | 0x20);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0x80) = (void *) D_8011F738;
    func_80171990(arg0, M2C_FIELD(&D_800A5EA8, s32 *, 8), &D_800A5EA8);
    func_80171384(arg0);
}
