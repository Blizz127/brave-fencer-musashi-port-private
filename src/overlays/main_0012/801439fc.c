/* Overlay range [801439FC,80143B30) from MAIN.CD member 0012.
 * SHA256(span)=ab9e2ee01d010e6ee5e9be27a8dbe5ab6215f3a71f3a277f0b3279f4f953be5e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016714(void *, s32);             /* extern */
s16 func_8004CFEC(s16, s16);                        /* extern */
void func_8012C218(void *);                      /* static */
s32 func_80134510(u16 *);                           /* static */
extern s16 D_801152A8;
extern s16 D_801152AA;
extern s16 D_801152AC;

void func_801439FC(void *arg0) {
    u16 sp14;
    u16 sp12;
    u16 sp10;
    void *temp_s1;
    void *temp_s2;

    temp_s2 = M2C_FIELD(arg0, void **, 0x64);
    temp_s1 = M2C_FIELD(arg0, void **, 0xCC);
    if (M2C_FIELD(temp_s2, s16 *, 0x36) != M2C_FIELD(arg0, s16 *, 0xFC)) {
        if (arg0 != 0) {
            func_80016714(temp_s1, 0x38);
            func_8012C218(arg0);
        }
    } else {
        sp10 = M2C_FIELD(temp_s2, u16 *, 6);
        sp12 = M2C_FIELD(temp_s2, u16 *, 0xA) - 0x10;
        sp14 = M2C_FIELD(temp_s2, u16 *, 0xE);
        if (func_80134510(&sp10) == 0) {
            M2C_FIELD(temp_s1, s32 *, 4) = (s32) (M2C_FIELD(temp_s1, s32 *, 4) | 0x80000000);
            return;
        }
        M2C_FIELD(temp_s1, u16 *, 8) = sp10;
        M2C_FIELD(temp_s1, u16 *, 0xA) = sp12;
        M2C_FIELD(temp_s1, s32 *, 4) = (s32) (M2C_FIELD(temp_s1, s32 *, 4) & 0x7FFFFFFF);
        M2C_FIELD(temp_s1, u16 *, 0xC) = sp14;
        M2C_FIELD(temp_s1, s16 *, 0x10) = (s16) (func_8004CFEC(D_801152AC, D_801152AA) + 0x400);
        M2C_FIELD(temp_s1, s16 *, 0x12) = func_8004CFEC(D_801152A8, D_801152AA);
        M2C_FIELD(temp_s1, s16 *, 0x14) = (s16) -(s16) M2C_FIELD(M2C_FIELD(temp_s2, void **, 0x20), u16 *, 0x12);
    }
}
