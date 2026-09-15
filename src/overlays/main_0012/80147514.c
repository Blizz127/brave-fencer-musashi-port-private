/* Overlay range [80147514,80147628) from MAIN.CD member 0012.
 * SHA256(span)=478ccbb0333aac6de5316ea64e3d6b3af5121f22afda55a18864057a0e36bd88.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800129CC(u16 *, void *);               /* extern */
s16 func_80012C6C(s16, s16, s32);               /* extern */

void func_80147514(void *arg0) {
    s32 sp17;
    u16 sp14;
    s32 sp13;
    s8 sp12;                                        /* compiler-managed */
    u16 sp10;

    sp13 = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    sp17 = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    if ((sp14 | (sp10 | (u16) sp12)) == 0) {
        sp12 = -0xFFF;
    }
    if (M2C_FIELD(arg0, s16 *, 0x12E) != 0) {
        sp10 += M2C_FIELD(arg0, u16 *, 0x128);
        sp12 = (u16) sp12 + M2C_FIELD(arg0, u16 *, 0x12A);
        sp14 += M2C_FIELD(arg0, u16 *, 0x12C);
    }
    M2C_FIELD(arg0, s16 *, 0x118) = func_80012C6C(M2C_FIELD(arg0, s16 *, 0x118), (s16) sp10, 8);
    M2C_FIELD(arg0, s16 *, 0x11A) = func_80012C6C(M2C_FIELD(arg0, s16 *, 0x11A), sp12, 8);
    M2C_FIELD(arg0, s16 *, 0x11C) = func_80012C6C(M2C_FIELD(arg0, s16 *, 0x11C), (s16) sp14, 8);
    sp10 = (u16) M2C_FIELD(arg0, s16 *, 0x118);
    sp12 = (u16) M2C_FIELD(arg0, s16 *, 0x11A);
    sp14 = (u16) M2C_FIELD(arg0, s16 *, 0x11C);
    func_800129CC(&sp10, arg0 + 0x100);
}
