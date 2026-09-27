/* Overlay range [80162438,801626B8) from MAIN.CD member 0012.
 * SHA256(span)=07c8064f5ce29bcc2f9a0fec9177ae01e124b8a991b8b002d6f2418c67291bb5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001CE28(void *, s32 (*)());                   /* extern */
void func_8001CE68(void *, s32 (*)());                   /* extern */
void func_80024054(s32 (*)(), s32 (*)());                  /* extern */
void func_800242D0(s16, s32 (*)(), s32);                   /* extern */
s32 func_800291DC();                               /* extern */
extern s32 D_80180EEC;
extern s32 D_80180F04;
extern s32 D_801842F8;
extern s32 D_801842FC;
extern s32 D_80184300;
extern s32 D_80184304;
extern s32 D_8018432C;
extern s32 D_80184348;
s16 func_801626B8();                                /* static */
void func_80162760();                                  /* static */
extern s16 D_80078EB0;
extern s32 *D_800AF630;
extern u16 D_800AF7BC;
extern u16 D_800AF7BE;
extern u16 D_800B5BD8;
extern s16 D_800B5BE0;
extern s16 D_800B5BE2;
extern s8 D_800B5BFF;
extern s16 D_800B5C04;
extern u16 D_800B5C10;
extern s16 D_800B5C18;
extern s16 D_800B5C1A;
extern s8 D_800B5C37;
extern s16 D_800B5C3C;
extern u16 D_800B5C48;
extern s16 D_800B5C50;
extern s16 D_800B5C52;
extern s16 D_800B5C74;

void func_80162438(void) {
    s32 temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;

    temp_v0 = func_800291DC(0x12);
    if (temp_v0 & 0x8000) {
        temp_v0_2 = &D_800AF630 + 0x65A8;
        if (D_800B5BD8 == 0) {
            D_801842F8 = temp_v0_2;
            func_80024054(D_80180EEC, D_80184304);
            func_8001CE28(temp_v0_2, D_80184304);
            D_800B5C04 = 1;
            D_800B5BFF = 1;
            D_800B5BE0 = ((s32) -(s32) D_800AF7BC / 2) + 0xD0;
            D_800B5BE2 = ((s32) -(s32) D_800AF7BE / 2) + 0x28;
        }
        temp_v0_3 = &D_800AF630 + 0x65E0;
        if (D_800B5C10 == 0) {
            D_801842FC = temp_v0_3;
            func_80024054(D_80180F04, D_8018432C);
            func_8001CE28(temp_v0_3, D_8018432C);
            D_800B5C3C = 1;
            D_800B5C37 = 1;
            D_800B5C18 = ((s32) -(s32) D_800AF7BC / 2) + 0xD0;
            D_800B5C1A = ((s32) -(s32) D_800AF7BE / 2) + 0x30;
        }
        temp_v0_4 = &D_800AF630 + 0x6618;
        if (D_800B5C48 == 0) {
            D_80184300 = temp_v0_4;
            func_800242D0(func_801626B8(), D_80184348, 0x84);
            func_8001CE68(temp_v0_4, D_80184348);
            D_800B5C74 = 1;
            D_800B5C50 = ((s32) -(s32) D_800AF7BC / 2) + 0xD0;
            D_800B5C52 = ((s32) -(s32) D_800AF7BE / 2) + 0x10;
        }
        func_800242D0(func_801626B8(), D_80184348, 0x84);
        if ((temp_v0 & 0x7FFF) == D_80078EB0) {
            func_80162760();
        }
    }
}
