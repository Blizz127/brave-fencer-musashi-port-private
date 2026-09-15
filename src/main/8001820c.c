/* Main-exec range [8001820C,80018384) from the SLUS executable.
 * SHA256(span)=6ae840a8077af0c27d5d20e89459df1c9dda3548b051ad7aa4f141125275647f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void *func_80010A08();                       /* static */
s32 func_80058B40(s32, s32, s32, s32);  /* static */
void func_80058C6C(s32, void *);                 /* static */
void func_8005A600(void *, s32, s32, s32, s32); /* static */
extern s32 *D_800A651C;
extern u16 D_800B9A02;

void func_8001820C(void *arg0, u32 arg1, u32 arg2) {
    s32 temp_s0;
    s32 temp_s1;
    u32 var_s1;
    void *temp_s2;
    void *temp_s2_2;

    var_s1 = arg1;
    if (arg2 & 0x40000000) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x02000000);
    }
    if (var_s1 >= 0x1000U) {
        var_s1 = 0xFFF;
    }
    temp_s2 = func_80010A08(0xC);
    temp_s0 = (arg2 >> 0x1C) & 3;
    func_8005A600(temp_s2, 0, 0, func_80058B40(2, temp_s0, 0x280, 0) & 0xFFFF, 0);
    temp_s1 = var_s1 * 4;
    func_80058C6C(*(&D_800A651C + (D_800B9A02 * 0x14)) + temp_s1, temp_s2);
    func_80058C6C(*(&D_800A651C + (D_800B9A02 * 0x14)) + temp_s1, arg0);
    temp_s2_2 = func_80010A08(0xC);
    func_8005A600(temp_s2_2, 0, 1, func_80058B40(2, temp_s0, 0x280, 0) & 0xFFFF, 0);
    func_80058C6C(*(&D_800A651C + (D_800B9A02 * 0x14)) + temp_s1, temp_s2_2);
}
