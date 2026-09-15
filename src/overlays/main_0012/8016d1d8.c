/* Overlay range [8016D1D8,8016D428) from MAIN.CD member 0012.
 * SHA256(span)=247ab08d966bd22dec4c47555f7d2a0bd9aff48da71926a3be5e0fccbf39e2b4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001CD9C(void *, void *);              /* extern */
void func_800233CC(void *, s32);             /* extern */
void func_80048FBC(void *, s16 *, s16 *);     /* extern */
void func_80049A1C(s16 *, void *);            /* extern */
s32 func_8005C49C();                                /* extern */
extern s32 D_80184851;
extern s32 D_80184852;
extern s32 D_80184855;
extern s32 D_80184856;
extern s32 D_80184891;
extern s32 D_80184892;
extern s32 D_80184895;
extern s32 D_80184896;
void *func_801465C0();                              /* static */
void func_80147324();                     /* static */
extern s8 D_80184854;
extern s8 D_80184894;

void func_8016D1D8(void *arg0) {
    s32 sp18;
    s16 sp14;
    s16 sp12;
    s16 sp10;
    s16 temp_s0_2;
    s32 temp_v0_3;
    void *temp_s0;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;

    temp_s0 = M2C_FIELD(arg0, void **, 0x34);
    if (M2C_FIELD(arg0, s32 *, 0x2C) == 0) {
        M2C_FIELD(D_80184851, s8 *, 0) = 0xE0;
        D_80184852 = 0xE0;
        M2C_FIELD(D_80184851, s8 *, -1) = 0xE0;
        D_80184856 = 0;
        D_80184855 = 0;
        D_80184854 = 0;
        temp_s1 = D_80184851 - 1;
        temp_v0 = func_801465C0();
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, void **, 0x20) = temp_v0;
            func_800233CC(temp_s1, 0x28);
            func_8001CD9C(temp_v0, temp_s1);
            M2C_FIELD(temp_v0, s16 *, 0x1A) = 0x1400;
            M2C_FIELD(temp_v0, s32 *, 4) = (s32) (M2C_FIELD(temp_v0, s32 *, 4) | 0x50000000);
            temp_v1 = M2C_FIELD(arg0, void **, 0x30);
            M2C_FIELD(arg0, u16 *, 0x28) = (u16) M2C_FIELD(temp_v1, u16 *, 0x36);
            M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(temp_v1, u16 *, 6);
            M2C_FIELD(arg0, s16 *, 0x16) = (s16) (M2C_FIELD(temp_v1, u16 *, 0xA) - 0x28);
            M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
            M2C_FIELD(arg0, u16 *, 0x1A) = (u16) M2C_FIELD(temp_v1, u16 *, 0xE);
        }
        M2C_FIELD(arg0, s32 *, 0x1C) = 8;
        func_80147324(0x647);
        return;
    }
    M2C_FIELD(D_80184891, s8 *, 0) = 0xE0;
    D_80184892 = 0x20;
    M2C_FIELD(D_80184891, s8 *, -1) = 0x20;
    D_80184895 = 0;
    D_80184896 = 0;
    D_80184894 = 0;
    temp_s1_2 = D_80184891 - 1;
    temp_v0_2 = func_801465C0();
    if (temp_v0_2 != 0) {
        M2C_FIELD(arg0, void **, 0x20) = temp_v0_2;
        func_800233CC(temp_s1_2, 0x18);
        func_8001CD9C(temp_v0_2, temp_s1_2);
        M2C_FIELD(temp_v0_2, s32 *, 4) = (s32) (M2C_FIELD(temp_v0_2, s32 *, 4) | 0x50000000);
        M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(temp_s0, u16 *, 6);
        M2C_FIELD(arg0, u16 *, 0xA) = (u16) M2C_FIELD(temp_s0, u16 *, 0xA);
        M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(temp_s0, u16 *, 0xE);
        temp_v0_3 = func_8005C49C();
        sp10 = ((temp_v0_3 & 0x7F) * 8) - 0x80;
        sp12 = (s16) ((u32) (temp_v0_3 & 0x7F00) >> 3);
        sp14 = 0;
        func_80049A1C(&sp10, &sp18);
        sp12 = 0;
        sp10 = 0;
        sp14 = 0x240;
        func_80048FBC(&sp18, &sp10, &sp10);
        M2C_FIELD(arg0, s32 *, 0x10) = (s32) (sp10 << 0xC);
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) (sp12 << 0xC);
        temp_s0_2 = (temp_v0_3 & 0x3F0) + 0x200;
        M2C_FIELD(arg0, s32 *, 0x18) = (s32) (sp14 << 0xC);
        M2C_FIELD(temp_v0_2, s16 *, 0x1A) = temp_s0_2;
        M2C_FIELD(temp_v0_2, s16 *, 0x18) = temp_s0_2;
        M2C_FIELD(arg0, s32 *, 0x1C) = 0x10;
        M2C_FIELD(arg0, u16 *, 2) = 2U;
    }
}
