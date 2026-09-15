/* Overlay range [8016A08C,8016A1CC) from MAIN.CD member 0012.
 * SHA256(span)=52fd67dfe63353c8e5a918821f20d57d2a5fca15dde63ae49f09d340a9fafc8e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146A6C(s32, void *, s16, s16, s32, s32, s32); /* static */
void func_80146C3C(void *);                      /* static */
void func_80147324();                     /* static */
void func_80147364(s32, s32);            /* static */
void func_80148534(void *, void *);        /* static */
void func_8016A290(void *, void *, void *); /* static */
extern u8 D_80078EBF;

void func_8016A08C(void *arg0) {
    s32 sp28;
    s32 sp20;
    s16 var_v0;
    s32 temp_v0;
    s32 temp_v0_2;

    if (D_80078EBF != 0) {
        func_80148534(&sp20, &sp28);
        temp_v0 = D_80078EBF - 0x18;
        M2C_FIELD(arg0, s32 *, 0x30) = temp_v0;
        if (temp_v0 >= 0) {
            func_8016A290(arg0, &sp20, &sp28);
            temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x1C) + 1;
            M2C_FIELD(arg0, s32 *, 0x1C) = temp_v0_2;
            if (temp_v0_2 == 4) {
                func_80147324(0x44C);
            }
            if ((u8) D_80078EBF < 0x80U) {
                var_v0 = 1;
                do {
                    var_v0 += 1;
                } while (var_v0 < 2);
                func_80146A6C(0x17, arg0, M2C_FIELD(arg0, s16 *, 6), M2C_FIELD(arg0, s16 *, 0xA), (s32) M2C_FIELD(arg0, s16 *, 0xE), 0, 0);
                return;
            }
            if (M2C_FIELD(arg0, s16 *, 0x2A) == 0) {
                M2C_FIELD(arg0, s16 *, 0x2A) = 1;
                M2C_FIELD(arg0, s32 *, 0x1C) = 0x100;
            }
            if (!(M2C_FIELD(arg0, s32 *, 0x1C) & 0x1F)) {
                func_80147324(0x44D);
            }
        }
    } else {
        func_80147364(4, 0x44C);
        func_80146C3C(arg0);
    }
}
