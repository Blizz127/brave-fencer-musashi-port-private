/* Overlay range [801630C4,80163194) from MAIN.CD member 0012.
 * SHA256(span)=be5701461925294257630535587dffdd89d96acca80d5e16b965baf6817dcc54.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800123F0(void *, s16);                          /* extern */
void func_80012558(void *, s16);                          /* extern */
void func_800126C4(void *, s16);                          /* extern */
void func_80013F3C(void *);                               /* extern */
void func_800484EC(void *, void *, s32 *);                /* extern */
void func_80146D30(void *, s32);                       /* static */
void func_80162F60();                                  /* static */
void func_80162F80(void *, s32);                         /* static */
void func_80162FA0(void *, s32);                         /* static */
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;

void func_801630C4(void *arg0, s32 arg2, s32 arg3) {
    s32 sp30;
    s32 sp20;
    void *temp_s1;

    temp_s1 = arg0->unk20;
    func_80162F60();
    func_80162F80(arg0, arg2);
    func_80162FA0(arg0, arg3);
    func_80013F3C(&sp30);
    func_80012558(&sp30, temp_s1->unk12);
    func_800126C4(&sp30, temp_s1->unk10);
    func_800123F0(&sp30, temp_s1->unk14);
    func_800484EC(&sp30, arg0 + 0x24, &sp20);
    D_80127090 = sp20;
    D_80127094 = sp24;
    D_80127098 = sp28;
    func_80146D30(arg0, sp28);
}
