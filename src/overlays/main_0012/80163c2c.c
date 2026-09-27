/* Overlay range [80163C2C,80163EC8) from MAIN.CD member 0012.
 * SHA256(span)=7e0c923dda8da50595dfb3acb5dc545fbd1a59311ed49076c7dc3b64d52126a1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800123F0(s32 *, s16);                        /* extern */
void func_80012558(s32 *, s16);                        /* extern */
void func_800126C4(s32 *, s16);                        /* extern */
void func_80013F3C(s32 *);                             /* extern */
void func_80015954(void *, void *);                    /* extern */
void func_80015978(void *, void *);                    /* extern */
void func_80146AB4(s32, void *, s32, s32, s32, s32, void *); /* static */
void func_80146CA0(void *);                            /* static */
void func_80146DE8(void *, s32, s32, s32);                   /* static */
void func_80146E90(void *, s32);                         /* static */
void func_80147364(s32, s32);                              /* static */
s32 func_80156370(s32, s32);                            /* static */
void func_80162FC0(void *);                            /* static */
void func_80163194(void *, s32, s32, s32, s32 *);            /* static */
void *func_801632E0(void *);                        /* static */
s32 func_801632F0(void *);                          /* static */
void func_801634D8(void *, s32, s32, s32, s32);            /* static */
void func_80163764(void *);                            /* static */
void func_80164530();                                  /* static */
extern s32 (*D_8011DB10)();

void func_80163C2C(void *arg0) {
    s32 sp40;
    s32 temp_v0;
    void *temp_s0;
    void *temp_s1;
    void *temp_s3;
    void *temp_v0_2;

    temp_s3 = arg0->unk4C;
    temp_s1 = arg0->unk20;
    func_80164530();
    temp_s1->unk14 = (s16) ((arg0->unk20->unk14 + 0x71) & 0xFFF);
    func_80013F3C(&sp40);
    func_800126C4(&sp40, arg0->unk60);
    func_800123F0(&sp40, arg0->unk64);
    func_80012558(&sp40, arg0->unk62);
    func_80012558(&sp40, temp_s1->unk12);
    func_800126C4(&sp40, temp_s1->unk10);
    func_800123F0(&sp40, temp_s1->unk14);
    func_80163194(arg0, 0, 0, 0x18000, &sp40);
    func_80162FC0(arg0);
    temp_s1->unk34 = sp40;
    temp_s1->unk38 = sp44;
    temp_s1->unk3C = sp48;
    temp_s1->unk40 = sp4C;
    temp_s1->unk44 = sp50;
    temp_s1->unk48 = sp54;
    temp_s1->unk4C = sp58;
    temp_s1->unk50 = sp5C;
    if (arg0->unk2C >= 0) {
        func_80146DE8(arg0, 0, 0, 0xC0000);
        func_80146E90(arg0, 0x20);
        func_80147364(4, 0x448);
        func_80146CA0(arg0);
        func_80146CA0(arg0);
        return;
    }
    func_801634D8(arg0, 0xD, func_80156370(0xD, 0) & 0xFFFF, 1, 0);
    temp_v0 = func_801632F0(arg0);
    if (temp_v0 & 1) {
        temp_v0_2 = func_801632E0(arg0);
        temp_s3->unk184 = temp_v0_2;
        temp_s3->unk44 = (s32) (temp_s3->unk44 | 0x20);
        temp_s3->unk18A = 0;
        temp_s3->unk188 = 0;
        temp_s3->unk194 = (u16) temp_v0_2->unk36;
        func_80146DE8(arg0, 0, 0, 0xC0000);
        temp_s0 = arg0 + 0x58;
        if (D_8011DB10 == 0) {
            func_80015978(arg0 + 4, arg0 + 0x58);
        } else {
            D_8011DB10(temp_s0);
            func_80015954(temp_s0, arg0 + 4);
        }
        arg0->unk66 = 0;
        func_80147364(4, 0x448);
        func_80146AB4(0x30, arg0, 0, 0, 0, 0, temp_s3->unk184);
        goto block_9;
    }
    if (temp_v0 & 6) {
        func_80146DE8(arg0, 0, 0, 0xC0000);
        func_80146E90(arg0, 0x20);
        func_80147364(4, 0x448);
        func_80146CA0(arg0);
block_9:
        func_80146CA0(arg0);
    }
    func_80163764(arg0);
}
