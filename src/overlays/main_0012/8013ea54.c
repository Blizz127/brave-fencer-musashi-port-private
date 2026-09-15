/* Overlay range [8013EA54,8013EB7C) from MAIN.CD member 0012.
 * SHA256(span)=902848e250c9aacd584341b922f005a7da75dd6271a53347c5038a8aabce348e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002D4C8(s32, s32);                              /* extern */
void func_80137B80();                                  /* static */
void func_8013E958();                                  /* static */
void func_8013F244();                                  /* static */
void func_8013FAF8(s32, s32);                              /* static */
s32 func_80141C50();                                /* static */
extern u16 D_800B9A02;
extern s16 D_800B9A08;
extern u16 D_80115112;
extern u16 D_8011511A;
extern u16 D_8011511E;
extern s32 D_80115130;
extern s16 D_8011514C;
extern s32 *D_801151C8;
extern s32 D_801151D0;

void func_8013EA54(void) {
    if ((func_80141C50() << 0x10) == 0) {
        D_801151D0 = *(&D_801151C8 + (D_800B9A02 * 4));
        func_8013F244();
        func_8013FAF8(0, 5);
        func_80137B80();
        if (D_8011511E & 0x40) {
            if ((D_8011511A == 0) && (D_800B9A08 == 0x308F)) {
                func_8002D4C8(0x466, 0);
                return;
            }
            if ((D_8011511A & 0xFFFF) != 4) {
                D_80115130 = 0;
            }
            if ((u32) (D_8011511A - 1) < 2U) {
                D_8011514C = 0;
            }
            func_8002D4C8(0x45D, 0);
            D_80115112 += 1;
            return;
        }
        if (D_8011511E & 0x810) {
            func_8013E958();
        }
    }
}
