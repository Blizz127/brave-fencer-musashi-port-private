/* Overlay range [8014AA28,8014AB5C) from MAIN.CD member 0012.
 * SHA256(span)=d967c4d44570c995b032868cb32e6cb862f1916fb7873f4d683f9c7c9285c479.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8014AB7C();                     /* static */
void func_8014AC10();                     /* static */
void func_801599A4(void *);                   /* static */
void func_80159B3C(void *);                   /* static */
void func_80165A20(void *);                   /* static */
extern u8 D_80078EC1;
extern s32 *D_80126B58;

void func_8014AA28(void) {
    u8 temp_s0;

    temp_s0 = D_80078EC1;
    if (((u32) (M2C_FIELD(&D_80126B58, u16 *, 0) - 0x19) >= 2U) && ((u32) (M2C_FIELD(&D_80126B58, u16 *, 0) - 0x1D) >= 2U)) {
        func_801599A4(&D_80126B58);
        func_80159B3C(&D_80126B58);
        if ((temp_s0 == 0xC) || (temp_s0 == 0x18) || (temp_s0 == 0xA)) {
            func_80165A20(&D_80126B58);
        }
    }
    M2C_FIELD(&D_80126B58, s16 *, 0x1C8) = 0;
    M2C_FIELD(&D_80126B58, s16 *, 0x1CA) = 0;
    M2C_FIELD(&D_80126B58, s16 *, 0x1CC) = 0;
    M2C_FIELD(&D_80126B58, s16 *, 0x1CE) = 0;
    M2C_FIELD(&D_80126B58, s16 *, 0x1D0) = 0;
    M2C_FIELD(&D_80126B58, s32 *, 0x1D4) = 0;
    M2C_FIELD(&D_80126B58, s32 *, 0x1D8) = 0;
    func_8014AB7C(5);
    func_8014AB7C(6);
    func_8014AB7C(7);
    func_8014AB7C(8);
    func_8014AB7C(9);
    func_8014AC10(0x26);
    func_8014AC10(0x27);
    func_8014AC10(0x39);
    func_8014AC10(0x3A);
    func_8014AB7C(0x10);
    func_8014AB7C(0x11);
    func_8014AB7C(0x12);
    func_8014AB7C(0x13);
    func_8014AB7C(0x14);
    func_8014AC10(0x3B);
    func_8014AC10(0x3C);
    M2C_FIELD(&D_80126B58, s8 *, 0x223) = 0x10;
}
