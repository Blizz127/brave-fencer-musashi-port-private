/* Main-exec range [8003602C,80036130) from the SLUS executable.
 * SHA256(span)=f0cb22c2f006b8cf007fff763341a46fc2748aa94e25bf8eeec75ed9fb85132e.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003621C();                            /* static */
void func_800434BC();                            /* static */
s32 func_8004355C(s32, u8 *);                   /* static */
void func_80043704(s32, s32);            /* static */
extern s8 D_80076214;

void func_8003602C(void *arg0) {
    u8 sp10;
    s32 temp_v0;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 3);
    switch (temp_v1) {
    case 2:
        M2C_FIELD(arg0, s8 *, 2) = 1;
        func_800434BC();
        M2C_FIELD(arg0, u8 *, 3) = (u8) (M2C_FIELD(arg0, u8 *, 3) + 2);
        return;
    case 3:
        M2C_FIELD(arg0, s8 *, 2) = 1;
        func_800434BC();
        M2C_FIELD(arg0, u8 *, 3) = (u8) (M2C_FIELD(arg0, u8 *, 3) + 1);
        /* fallthrough */
    case 4:
        func_80043704(9, 0);
        func_8003621C();
        M2C_FIELD(arg0, s8 *, 2) = 1;
        M2C_FIELD(arg0, u8 *, 3) = (u8) (M2C_FIELD(arg0, u8 *, 3) + 1);
        return;
    case 5:
        temp_v0 = func_8004355C(1, &sp10);
        if (temp_v0 == 0) {
            M2C_FIELD(arg0, s8 *, 2) = 1;
            return;
        }
        if ((temp_v0 == 5) && (sp10 & 0x10)) {
            D_80076214 = 1;
        }
    default:
        M2C_FIELD(arg0, s8 *, 2) = 0;
        return;
    }
}
