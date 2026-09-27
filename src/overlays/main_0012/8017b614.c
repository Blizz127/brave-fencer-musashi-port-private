/* Overlay range [8017B614,8017B7A8) from MAIN.CD member 0012.
 * SHA256(span)=c6574a19818e972ff3ee5a795b834afbff49930e77c16d42bc7d0cbf96fa5a3a.
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
extern s32 D_801853BE;
extern s32 D_801853C0;
extern s32 D_801853C6;
extern s32 D_801853C8;
void func_80129CF8(s16, s16, s16, s16);                /* static */
void func_8012A018(s32 (*)(), s32);                        /* static */
void func_8012F214(s32, void *, void *);                  /* static */
extern s32 func_8017BE60;
extern s8 D_8012694C;
extern s32 D_80126984;
extern s32 D_80126988;
extern s32 D_8012698C;
extern s32 D_80126990;
extern s32 D_80126994;
extern s32 D_80126998;
extern s32 D_801853BC;
extern s32 D_801853C4;
extern s16 D_80185C08;

void func_8017B614(s32 arg0, u32 arg1) {
    s32 sp1F;
    s32 sp1B;
    s32 sp18;
    s32 sp17;
    s32 sp13;
    s32 sp10;
    s32 temp_s0;

    if (arg1 >= 0xBU) {
        sp13 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        sp17 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        sp1B = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        sp1F = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    } else {
        temp_s0 = arg1 * 0x10;
        func_8012F214(arg0, temp_s0 + D_80181CC0, &sp10);
        func_8012F214(arg0, temp_s0 + (D_80181CC0 + 8), &sp18);
    }
    D_801853C4.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_801853C4.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_801853BC.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_801853BC.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    func_8012A018(func_8017BE60, 0);
    D_8012694C = 0;
    D_80185C08 = 1;
    D_8018534C = 0x1E;
    D_80126990 = (s32) D_801853C4.unk0;
    D_80126994 = (s32) D_801853C6;
    D_80126998 = (s32) D_801853C8;
    D_80126984 = (s32) D_801853BC.unk0;
    D_80126988 = (s32) D_801853BE;
    D_8012698C = (s32) D_801853C0;
    func_80129CF8(D_801853C6, D_801853C8, D_801853BC.unk0, D_801853BE);
}
