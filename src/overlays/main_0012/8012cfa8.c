/* Overlay range [8012CFA8,8012D098) from MAIN.CD member 0012.
 * SHA256(span)=f8f06bb2e73a72eebd4d58250840b3256059f037f726f9e6df91578437337328.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void *func_80010A08();                       /* extern */
void func_8004914C(void *);                   /* extern */
void func_800491AC(void *);                   /* extern */
s32 func_8004955C(s32, s32 *, void *, void *); /* extern */
void func_80058C6C(s32, void *, s32);            /* extern */
void func_80058D70(void *);                      /* extern */
extern s32 *D_800A651C;
extern s32 *D_800AF648;
extern u16 D_800B9A02;

void func_8012CFA8(s32 arg0) {
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 temp_a2;
    void *temp_v0;

    temp_v0 = func_80010A08(0x14);
    M2C_FIELD(temp_v0, s32 *, 4) = 0xFF;
    func_80058D70(temp_v0);
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    temp_a2 = (func_8004955C(arg0, &sp10, &sp14, &sp18) >> 2) - 0x20;
    if (temp_a2 > 0) {
        M2C_FIELD(temp_v0, s32 *, 8) = sp10;
        M2C_FIELD(temp_v0, s16 *, 0xC) = (s16) ((u16) M2C_FIELD(temp_v0, s32 *, 8) + 8);
        M2C_FIELD(temp_v0, u16 *, 0xE) = (u16) M2C_FIELD(temp_v0, u16 *, 0xA);
        M2C_FIELD(temp_v0, u16 *, 0x10) = (u16) M2C_FIELD(temp_v0, s32 *, 8);
        M2C_FIELD(temp_v0, s16 *, 0x12) = (s16) (M2C_FIELD(temp_v0, u16 *, 0xA) + 8);
        func_80058C6C(*(&D_800A651C + (D_800B9A02 * 0x14)) + (temp_a2 * 4), temp_v0, temp_a2);
    }
}
