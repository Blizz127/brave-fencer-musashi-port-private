/* Overlay range [8016CF04,8016D19C) from MAIN.CD member 0012.
 * SHA256(span)=0f53250c44d9e8f60f156ea1af634d8c03711bc60f702ae1134f42048c42ad7f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80048FBC(void *, u16 *, u16 *, u16);            /* extern */
void func_80049A1C(u16 *, void *);                        /* extern */
void func_800D23D0(u16 *, s16);                        /* extern */
extern s32 D_801848D0;

s32 func_8016CF04(void *arg0, s16 arg1) {
    s32 sp20;
    u16 sp18;
    s16 sp14;
    u16 sp12;                                       /* compiler-managed */
    u16 sp10;                                       /* compiler-managed */
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v1;
    void *temp_s2;

    temp_s2 = (arg0->unk2A * 0xC4) + D_801848D0;
    switch (arg1) {                                 /* irregular */
    case 0:
        temp_s2->unk2 = 0U;
        temp_s2->unk1 = 0U;
        temp_s2->unk3 = 0xF0U;
    default:
block_14:
        sp10 = (u16) ((s32) arg0->unk10 >> 0xC);
        sp12 = (u16) ((s32) arg0->unk14 >> 0xC);
        sp14 = (s16) ((s32) arg0->unk18 >> 0xC);
        func_800D23D0(&sp10, arg1);
        func_80049A1C(&sp10, &sp20);
        sp10 = 9;
        sp12 = 0;
        sp14 = 0;
        func_80048FBC(&sp20, &sp10, &sp18);
        (temp_s2 + (temp_s2->unk1 * 0xC))->unk4 = (s16) (arg0->unk6 + sp18);
        (temp_s2 + (temp_s2->unk1 * 0xC))->unk6 = (s16) (arg0->unkA + sp1A);
        (temp_s2 + (temp_s2->unk1 * 0xC))->unk8 = (s16) (arg0->unkE + sp1C);
        sp10 = -(s16) sp10;
        sp12 = -(s16) sp12;
        func_80048FBC(&sp20, &sp10, &sp18, sp1C);
        (temp_s2 + (temp_s2->unk1 * 0xC))->unkA = (s16) (arg0->unk6 + sp18);
        (temp_s2 + (temp_s2->unk1 * 0xC))->unkC = (s16) (arg0->unkA + sp1A);
        (temp_s2 + (temp_s2->unk1 * 0xC))->unkE = (s16) (arg0->unkE + sp1C);
        return 0;
    case 1:
        temp_v0 = temp_s2->unk1 + 1;
        temp_s2->unk1 = temp_v0;
        if ((u32) (temp_v0 & 0xFF) >= 0x10U) {
            temp_s2->unk1 = 0U;
        }
        temp_v1 = temp_s2->unk2;
        if (temp_v1 < 0xFU) {
            temp_s2->unk2 = (u8) (temp_v1 + 1);
        }
        goto block_14;
    case 2:
        temp_v0_2 = temp_s2->unk2 - 1;
        temp_s2->unk2 = temp_v0_2;
        if (!(temp_v0_2 & 0xFF)) {
            temp_s2->unk0 = 0;
            return 1;
        }
        temp_s2->unk3 = (u8) (temp_s2->unk3 - 0xF);
        return 0;
    }
}
