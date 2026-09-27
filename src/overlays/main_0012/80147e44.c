/* Overlay range [80147E44,80147F50) from MAIN.CD member 0012.
 * SHA256(span)=a2daf5a235735b7b4b729c4807d601b8ce292b44cc6a80aa304f7bbf58e976b3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80013F3C(void *);                               /* extern */
void func_800484EC(void *, void *, s32 *);                /* extern */
void func_80049F3C(s16, void *);                          /* extern */
void func_8004A0DC(s16, void *);                          /* extern */
void func_8004A27C(s16, void *);                          /* extern */
void func_80147928();                                  /* static */
void func_8014799C(void *, s32);                         /* static */
void func_80147A10(void *, s32);                         /* static */
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;

void func_80147E44(void *arg0, s32 arg2, s32 arg3) {
    s32 sp20;
    s32 sp10;
    void *temp_s2;

    temp_s2 = arg0->unk20;
    func_80147928();
    func_8014799C(arg0, arg2);
    func_80147A10(arg0, arg3);
    func_80013F3C(&sp20);
    func_8004A0DC(temp_s2->unk12, &sp20);
    func_80049F3C(temp_s2->unk10, &sp20);
    func_8004A27C(temp_s2->unk14, &sp20);
    func_800484EC(&sp20, arg0 + 0x24, &sp10);
    D_80127090 = sp10;
    D_80127098 = sp18;
    D_80127094 = sp14;
    arg0->unk10 = (s32) D_80127090;
    arg0->unk14 = (s32) D_80127094;
    arg0->unk18 = (s32) D_80127098;
    D_80127090 = 0;
    D_80127094 = 0;
    D_80127098 = 0;
}
