/* Overlay range [801407F4,80140958) from MAIN.CD member 0012.
 * SHA256(span)=90beba0ea7bad140bcb48f3caa2d749d6bb55a2ae72ff24e0f388fae4af6ee7a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80028D58();                                /* extern */
s32 func_80028D9C();                                /* extern */
s32 func_80028DE0();                                /* extern */
s32 func_80028FBC();                                /* extern */
s32 func_80029000();                                /* extern */
extern s32 D_8017F3D8;
extern s32 D_8017F3DC;
extern s32 D_8017F3E0;
extern s32 D_8017F3E4;
extern s32 D_8017F3E8;
extern s32 D_8017F3EC;
extern s32 D_8017F3F4;
extern s32 D_8017F414;

void func_801407F4(void) {
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;

    temp_s0 = D_8017F3D8;
    temp_v1 = *(D_8017F3EC + (func_80028D58() * 4));
    temp_s0->unk16 = (u16) temp_v1->unk0;
    temp_s0->unk18 = (u16) temp_v1->unk2;
    temp_s0->unk1A = (u16) (temp_v1 + 2)->unk2;
    temp_s0_2 = D_8017F3DC;
    temp_v1_2 = *(D_8017F3EC + (func_80028DE0() * 4));
    temp_s0_2->unk16 = (u16) temp_v1_2->unk0;
    temp_s0_2->unk18 = (u16) temp_v1_2->unk2;
    temp_s0_2->unk1A = (u16) (temp_v1_2 + 2)->unk2;
    D_8017F3E0->unk18 = (u16) **(D_8017F3F4 + (func_80028FBC() * 4));
    D_8017F3E4->unk18 = (u16) **(D_8017F3F4 + (func_80029000() * 4));
    temp_s0_3 = D_8017F3E8;
    temp_v1_3 = *(D_8017F414 + (func_80028D9C() * 4));
    temp_v1_4 = temp_v1_3 + 2;
    temp_s0_3->unk12 = (u16) temp_v1_3->unk0;
    temp_v1_5 = temp_v1_4 + 2;
    temp_s0_3->unk14 = (u16) temp_v1_3->unk2;
    temp_v1_6 = temp_v1_5 + 2;
    temp_s0_3->unk16 = (u16) temp_v1_4->unk2;
    temp_s0_3->unk18 = (u16) temp_v1_5->unk2;
    temp_s0_3->unk1A = (u16) temp_v1_6->unk2;
    temp_s0_3->unk1C = (u16) (temp_v1_6 + 2)->unk2;
}
