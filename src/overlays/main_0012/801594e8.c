/* Overlay range [801594E8,80159698) from MAIN.CD member 0012.
 * SHA256(span)=2dd7108658b691a560ed104cdbda5b68d0b07ca4c7fee1603f68fa296c9847ac.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80029044();                            /* extern */
void func_8002906C();                            /* extern */
void func_80029094();                            /* extern */
void func_80029124(s32, u8);                 /* extern */
u8 func_80029178();                          /* extern */
void func_800291A0(s32, u8);                 /* extern */
u8 func_800291B4();                          /* extern */
void func_80029274();                            /* extern */
void func_8002941C();                            /* extern */
void func_80029514();                     /* extern */
void func_8002AB64();                            /* extern */
void func_800CF804();                            /* extern */
void func_800D185C(void *);                   /* extern */
void func_8014BEC0(s32);                         /* static */
void func_80175454();                            /* static */
extern s32 *D_80078E78;
extern s32 *D_800D3A44;

void func_801594E8(s32 arg0, s32 arg1) {
    u8 sp19;
    u8 sp18;
    u8 sp12;
    u8 sp11;
    u8 sp10;
    s32 temp_s0;

    func_80175454();
    if ((u32) (arg1 + 1) < 8U) {
        switch (arg1) {
        case 0:
            break;
        case -1:
            sp10 = func_80029178(0xB);
            sp11 = func_80029178(0xC);
            sp12 = func_80029178(0xD);
            sp18 = func_800291B4(0x2C);
            sp19 = func_800291B4(0x2D);
            temp_s0 = M2C_FIELD(&D_80078E78, s32 *, 4);
            func_80029274();
            func_80029044();
            func_8002906C();
            func_80029094();
            func_8002941C();
            func_80029124(0xB, sp10);
            func_80029124(0xC, sp11);
            func_80029124(0xD, sp12);
            func_800291A0(0x2C, sp18);
            func_800291A0(0x2D, sp19);
            M2C_FIELD(&D_80078E78, s32 *, 4) = temp_s0;
            func_8014BEC0(arg0);
            func_8002AB64();
            func_80029514(2);
            func_800D185C(&D_800D3A44);
            func_800CF804();
            break;
        }
    }
}
