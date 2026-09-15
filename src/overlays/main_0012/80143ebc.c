/* Overlay range [80143EBC,80144054) from MAIN.CD member 0012.
 * SHA256(span)=ead9f209d7f0e645b399d2416b794f792d89e79431be1213f9c542058e595e1d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016714(void *, s32);             /* extern */
s32 func_8004787C(s32);                             /* extern */
s16 func_8004CFEC(s16, s16);                        /* extern */
void func_8012C218(void *);                      /* static */
s32 func_80134510(u16 *);                           /* static */
extern s16 D_801152A8;
extern s16 D_801152AA;
extern s16 D_801152AC;

void func_80143EBC(void *arg0) {
    u16 sp14;
    u16 sp12;
    u16 sp10;
    void *temp_s0;
    void *temp_s1;

    temp_s1 = M2C_FIELD(arg0, void **, 0x64);
    temp_s0 = M2C_FIELD(arg0, void **, 0xCC);
    if (M2C_FIELD(temp_s1, s16 *, 0x36) != M2C_FIELD(arg0, s16 *, 0xFC)) {
        if (arg0 != 0) {
            func_80016714(temp_s0, 0x38);
            func_8012C218(arg0);
        }
    } else {
        sp10 = M2C_FIELD(temp_s1, u16 *, 6);
        sp12 = M2C_FIELD(temp_s1, u16 *, 0xA) - 0x10;
        sp14 = M2C_FIELD(temp_s1, u16 *, 0xE);
        if (func_80134510(&sp10) == 0) {
            M2C_FIELD(temp_s0, s32 *, 4) = (s32) (M2C_FIELD(temp_s0, s32 *, 4) | 0x80000000);
            return;
        }
        M2C_FIELD(temp_s0, u16 *, 8) = sp10;
        M2C_FIELD(temp_s0, u16 *, 0xA) = sp12;
        M2C_FIELD(temp_s0, s32 *, 4) = (s32) (M2C_FIELD(temp_s0, s32 *, 4) & 0x7FFFFFFF);
        M2C_FIELD(temp_s0, u16 *, 0xC) = sp14;
        if (M2C_FIELD(arg0, s16 *, 0x70) == 1) {
            M2C_FIELD(temp_s0, s16 *, 0x10) = 0x400;
            M2C_FIELD(temp_s0, s16 *, 0x12) = 0;
        } else {
            M2C_FIELD(temp_s0, s16 *, 0x10) = (s16) (func_8004CFEC(D_801152AC, D_801152AA) + 0x400);
            M2C_FIELD(temp_s0, s16 *, 0x12) = func_8004CFEC(D_801152A8, D_801152AA);
        }
        M2C_FIELD(temp_s0, s16 *, 0x14) = (s16) -(s16) M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x20), u16 *, 0x12);
        M2C_FIELD(temp_s0, s16 *, 0x18) = (s16) (func_8004787C((M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x20), u16 *, 0x14) & 0x3FF) * 2) + 0x4000);
        M2C_FIELD(temp_s0, s16 *, 0x1A) = (s16) (func_8004787C((M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x20), u16 *, 0x10) & 0x3FF) * 2) + 0x4000);
    }
}
