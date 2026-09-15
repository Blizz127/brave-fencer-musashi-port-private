/* Overlay range [80168828,801689D8) from MAIN.CD member 0012.
 * SHA256(span)=871aae21999c78d67d19d2c41f0184c06fe5f08dbeef7f0a71cd20b3337d5c43.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800173BC(s16 *, void *);            /* extern */
void func_80017DC4(u16 *, void *);            /* extern */
void func_80017E68(u16 *, void *);            /* extern */
void func_80048EAC(void *, void *);        /* extern */
void func_80049A1C(u16 *, void *);            /* extern */
void func_80049CAC(u16 *, void *);            /* extern */
extern s32 D_80181364;

void func_80168828(void *arg0) {
    u16 sp7C;
    u16 sp7A;
    u16 sp78;
    s32 sp58;
    s32 sp38;
    s32 sp34;
    s8 sp32;
    s8 sp31;
    s8 sp30;
    s8 sp2E;
    s8 sp2D;
    s8 sp2C;
    s8 sp2A;
    s8 sp29;
    s8 sp28;
    s16 sp24;
    s16 sp22;
    s16 sp20;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    s16 sp14;
    s16 sp12;
    s16 sp10;
    s32 (*var_s3)();
    s16 temp_v0_2;
    s16 var_s5;
    u16 temp_v0;
    u16 temp_v0_3;

    sp14 = 2;
    sp1C = 0x24;
    sp24 = 0x28;
    sp18 = -3;
    sp20 = 3;
    sp2A = 0x10;
    sp30 = 0xFF;
    sp2C = 0xFF;
    sp31 = 0xC0;
    sp2D = 0xC0;
    sp12 = 0;
    sp10 = 0;
    sp22 = 0;
    sp1A = 0;
    sp28 = 0x40;
    sp29 = 0x40;
    sp32 = 0x40;
    sp2E = 0x40;
    sp34 = 0x50000000;
    sp78 = M2C_FIELD(arg0, u16 *, 6);
    var_s3 = D_80181364;
    sp7A = M2C_FIELD(arg0, u16 *, 0xA);
    var_s5 = 0;
    sp7C = M2C_FIELD(arg0, u16 *, 0xE);
    func_80017E68(&sp78, &sp38);
    temp_v0 = (M2C_FIELD(arg0, s32 *, 0x1C) << 0xB) + 0x1000;
    sp7C = temp_v0;
    sp7A = temp_v0;
    sp78 = temp_v0;
    func_80017DC4(&sp78, &sp38);
    sp78 = M2C_FIELD(arg0, u16 *, 0x12);
    sp7A = M2C_FIELD(arg0, u16 *, 0x16);
    sp7C = M2C_FIELD(arg0, u16 *, 0x1A);
    func_80049A1C(&sp78, &sp58);
    func_80048EAC(&sp38, &sp58);
    sp7A = 0;
    do {
        sp78 = M2C_FIELD(var_s3, u16 *, 0);
        temp_v0_3 = M2C_FIELD(var_s3, u16 *, 2);
        var_s3 = var_s3 + 2 + 2;
        sp7C = temp_v0_3;
        func_80049CAC(&sp78, &sp38);
        func_80048EAC(&sp58, &sp38);
        func_800173BC(&sp10, &sp38);
        temp_v0_2 = var_s5 + 1;
        var_s5 = temp_v0_2;
    } while (temp_v0_2 < 4);
}
