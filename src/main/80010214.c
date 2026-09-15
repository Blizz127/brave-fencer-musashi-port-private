/* Exact retail word export for [80010214,80010938); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800D25FC();                                  /* extern */
extern s32 D_80074778;
void func_80010938();                                  /* static */
void func_80010A98();                                  /* static */
void func_80010B40();                                  /* static */
void func_80014238();                                  /* static */
void func_80014390();                                  /* static */
void func_8001513C();                                  /* static */
void func_80015208();                                  /* static */
void func_80015498();                                  /* static */
void func_800184F0();                                  /* static */
void func_800189A8(u16, s32);                          /* static */
void func_800191A8();                                  /* static */
void func_8001AF34();                                  /* static */
void func_8001C00C();                                  /* static */
void func_8002D034();                                  /* static */
void func_8003500C();                                  /* static */
void func_8004239C(s32);                               /* static */
void func_80058CE4(s32, s32);                          /* static */
void func_800596F4();                                 /* static */
void func_80059BFC(s32, s32);                            /* static */
void func_80059CF4(s32);                               /* static */
void func_80059D68(void *);                            /* static */
void func_80059FC0(void *);                            /* static */
extern s32 *D_8007BA70;
extern s32 *D_800A4F48;
extern void *D_800A5E60;
extern s32 *D_800A651C;
extern s32 *D_800A6528;
extern s32 *D_800A6610;
extern s32 *D_800AA60C;
extern s32 *D_800AE7BC;
extern s32 *D_800AE7C8;
extern s32 *D_800BA0D8;
extern s32 *D_800BA0E4;
extern s32 D_800C7C70;
extern s16 D_800C7C74;

void func_80010214(void *arg0) {
    s32 var_v0;
    u16 temp_v0;
    u16 temp_v1;
    void *var_sp;

    var_sp = sp;
    func_80014238();
    func_80014390();
    func_800191A8();
    func_80010A98();
loop_1:
    if (saved_reg_s1->unkA3D4 == 0) {
        D_800C7C70 += 1;
        var_v0 = D_800C7C70;
        if (D_800C7C70 == 0) {
            var_v0 = 1;
        }
        D_800C7C70 = var_v0;
        D_800C7C74 = D_800C7C74 == 0;
        saved_reg_s1->unkA3D2 = (u16) D_800C7C74;
        D_800A5E60 = &D_8007BA70 + (saved_reg_s1->unkA3D2 * 0x13880);
        temp_v1 = saved_reg_s1->unkA3D2;
        (saved_reg_s1 + (saved_reg_s1->unkA3D2 * 0xC))->unk8 = (void *) (&D_800A4F48 + (temp_v1 * 0x640));
        *(saved_reg_s1 + (saved_reg_s1->unkA3D2 * 0xC)) = 0x640;
        temp_v0 = saved_reg_s1->unkA3D2;
        (saved_reg_s1 + (temp_v0 * 0xC))->unk4 = 0;
        func_800189A8(temp_v0, temp_v1 * 0x19);
        func_80015208();
        if (saved_reg_s1->unkA3E3 == 0) {
            saved_reg_s1->unkA3A8 = (u16) (saved_reg_s1->unkA3A8 + 1);
            saved_reg_s1->unkA3AC = (u16) (saved_reg_s1->unkA3AC + saved_reg_s1->unkA3A8);
            *(&D_800A651C + (saved_reg_s1->unkA3D2 * 0x14)) = &D_800A6610 + (saved_reg_s1->unkA3D2 << 0xE);
            *(&D_800A6528 + (saved_reg_s1->unkA3D2 * 0x14)) = (saved_reg_s1->unkA3D2 << 0xE) + &D_800AA60C;
            func_80059BFC(*(&D_800A651C + (saved_reg_s1->unkA3D2 * 0x14)), 0x1000);
            *(&D_800AE7BC + (saved_reg_s1->unkA3D2 * 0x14)) = &D_800BA0D8 + (saved_reg_s1->unkA3D2 * 0x10);
            *(&D_800AE7C8 + (saved_reg_s1->unkA3D2 * 0x14)) = (saved_reg_s1->unkA3D2 * 0x10) + &D_800BA0E4;
            func_80059BFC(*(&D_800AE7BC + (saved_reg_s1->unkA3D2 * 0x14)), 4);
            func_80010B40();
            *(void **)0x1F8003FC = var_sp;
            func_80015498();
            *(void *)0x1F8003FC = arg0;
            func_8001C00C();
            var_sp = arg0;
        } else {
            *(&D_800AE7BC + (saved_reg_s1->unkA3D2 * 0x14)) = &D_800BA0D8 + (saved_reg_s1->unkA3D2 * 0x10);
            *(&D_800AE7C8 + (saved_reg_s1->unkA3D2 * 0x14)) = (saved_reg_s1->unkA3D2 * 0x10) + &D_800BA0E4;
            func_80059BFC(*(&D_800AE7BC + (saved_reg_s1->unkA3D2 * 0x14)), 4);
            *(void *)0x1F8003FC = var_sp;
            func_800D25FC();
            var_sp = arg0;
        }
        func_800184F0();
        func_800596F4(0);
        func_8004239C(saved_reg_s1->unkA3E8);
        saved_reg_s1->unk188 = (u16) saved_reg_s1->unk18A;
        saved_reg_s1->unk18A = (u16) (saved_reg_s1->unk18A + 1);
        if ((u16) saved_reg_s1->unk18A >= 2U) {
            saved_reg_s1->unk18A = 0U;
        }
        func_80059FC0(saved_reg_s1 + ((saved_reg_s1->unk188 * 0x14) + 0x14C));
        func_80059D68(saved_reg_s1 + ((saved_reg_s1->unk18A * 0x5C) + 0x38));
        func_80058CE4(*(&D_800A651C + (saved_reg_s1->unkA3D2 * 0x14)) + 0x3FF0, (D_80074778 * 4) + *(&D_800A651C + (saved_reg_s1->unkA3D2 * 0x14)));
        func_80059CF4(*(&D_800A651C + (saved_reg_s1->unkA3D2 * 0x14)) + 0x3FFC);
        func_80059CF4(*(&D_800AE7BC + (saved_reg_s1->unkA3D2 * 0x14)) + 0xC);
        func_8003500C();
        func_8002D034();
        func_8001AF34();
        func_8001513C();
        goto loop_1;
    }
    func_80010938();
}
