/* Overlay range [8015E4B0,8015E588) from MAIN.CD member 0012.
 * SHA256(span)=f374b6bcfeacb87ce0c59f16a0d0c78e9677a90e4bdcce17fca935ecca6770b2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80013E94(s32 (*)(), s32 *);        /* extern */
extern s32 D_80180CE6;
extern s32 D_80180CE8;
extern s32 D_80180CEC;
void func_80146A6C(s32, void *, s16, s16, s32, s32, s32); /* static */
void func_80149350(s16 *, s16 *);                /* static */
extern u16 D_80180CE4;

void func_8015E4B0(void *arg0) {
    s32 sp28;
    s16 sp24;
    s16 sp22;
    s16 sp20;
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg0, void **, 0x18C);
    if ((temp_a2 != 0) && (M2C_FIELD(temp_a2, u16 *, 0) != 0)) {
        sp20 = D_80180CE4 + M2C_FIELD(M2C_FIELD(temp_a2, void **, 0x78), u16 *, 0xC);
        sp22 = D_80180CE6 + (M2C_FIELD(M2C_FIELD(temp_a2, void **, 0x78), s16 *, 0xE) * 2);
        sp24 = D_80180CE8 + M2C_FIELD(M2C_FIELD(temp_a2, void **, 0x78), u16 *, 0x10);
        func_80149350(&sp20, &sp20);
        func_80013E94(D_80180CEC, &sp28);
        func_80146A6C(0x1F, arg0, sp20, sp22, (s32) sp24, sp28, 0);
    }
}
