/* Overlay range [8014562C,801457A4) from MAIN.CD member 0012.
 * SHA256(span)=4865d56d496f433a40d3baf1591ecdf60c30845aed4733ebe5e56c7440ee5105.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001C14C();                                  /* extern */
void func_8002D4C8(s32, s32);                              /* extern */
void func_8005C324(void *, void *, s32);                    /* extern */
s32 func_800CF854(s32);                             /* extern */
void func_8012A110();                                  /* static */
void func_8013D3D4(s32, s32);                          /* static */
extern s32 *D_80078E50;
extern s32 D_801151D8;
extern s32 D_8011DB28;
extern s32 D_801270B8;
extern s32 D_801274C8;
extern s32 D_801274CC;
extern s32 D_801274D0;
extern s32 D_801274D4;
extern s32 D_80127520;

void func_8014562C(s32 arg14, s32 arg15, s32 arg16, s32 arg17) {
    s32 temp_a0;

    D_801274C8 = saved_reg_fp->unk20->unkB4;
    D_801274CC = saved_reg_fp->unk20->unkB8;
    D_801274D0 = saved_reg_fp->unk20->unkBC;
    D_801274D4 = saved_reg_fp->unk20->unkC0;
    D_801270B8 = saved_reg_fp->unk20->unkC4;
    D_80127520 = saved_reg_fp->unk20->unkC4;
    D_801151D8 = 0;
    D_8011DB28 = 0;
    saved_reg_fp->unk30 = (s32 (*)()) saved_reg_fp->unk24->unk20;
    saved_reg_fp->unk30();
    func_8013D3D4(saved_reg_fp->unk20->unkA0, saved_reg_fp->unk20->unkA4);
    func_8002D4C8(0x1E, 0);
    if (saved_reg_fp->unk18->unk8 == 0) {
        func_8005C324(&D_80078E50, saved_reg_fp->unk24, 0x24);
    }
    saved_reg_fp->unk18->unk4 = &D_80078E50;
    temp_a0 = saved_reg_fp->unk18->unk8 & 0x7F000000;
    saved_reg_fp->unk18->unk8 = temp_a0;
    if (func_800CF854(temp_a0) != 0) {
        func_8001C14C();
        func_8012A110();
    }
}
