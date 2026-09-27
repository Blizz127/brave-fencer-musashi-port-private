/* Overlay range [8017B368,8017B490) from MAIN.CD member 0012.
 * SHA256(span)=e1492b6030cb4922e05af5c114df0ea60fed240e00a6c6d17eeae33be41994fb.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80181CC0;
extern s32 D_8018534C;
extern s32 D_8018536C;
void func_8012F214(s32, void *, void *);                  /* static */
void func_8017BA3C();                                  /* static */
extern s32 D_801853BC;
extern s32 D_801853C4;
extern s16 D_80185C08;

void func_8017B368(s32 arg0) {
    s32 sp1F;
    s32 sp1B;
    s32 sp18;
    s32 sp17;
    s32 sp13;
    s32 sp10;
    s32 temp_s0;

    func_8017BA3C();
    if ((u32) D_8018536C >= 0xBU) {
        sp13 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        sp17 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        sp1B = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        sp1F = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    } else {
        temp_s0 = (s32) D_8018536C * 0x10;
        func_8012F214(arg0, temp_s0 + D_80181CC0, &sp10);
        func_8012F214(arg0, temp_s0 + (D_80181CC0 + 8), &sp18);
    }
    D_801853C4.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_801853C4.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_801853BC.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_801853BC.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80185C08 = 1;
    D_8018534C = 0;
}
