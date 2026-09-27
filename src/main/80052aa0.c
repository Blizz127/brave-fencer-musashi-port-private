/* Main-exec range [80052AA0,80052BDC) from the SLUS executable.
 * SHA256(span)=3bbb051466d1fcefa52923798b0a0d6c84260e32e93f9704a4faaf66dc449c5d.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80058C6C(s32, void *);                 /* static */
extern s32 *D_80078810;
extern s32 *D_80078814;
extern s32 *D_80078815;
extern s32 *D_80078816;
extern s32 *D_80078818;
extern s32 *D_8007881A;
extern s32 *D_8007881C;
extern s32 *D_8007881E;
extern s32 *D_800794E0;
extern s32 *D_800794E4;
extern u8 D_800A64A9;
extern s32 D_800AE618;
extern s32 D_800AE61C;
extern s16 D_800C7C74;

void func_80052AA0(s8 arg0, s8 arg1, s8 arg2, void *arg3) {
    s32 temp_a0;
    s32 temp_a1;

    *(&D_80078814 + (D_800C7C74 * 0x10)) = arg0;
    *(&D_80078815 + (D_800C7C74 * 0x10)) = arg1;
    *(&D_80078816 + (D_800C7C74 * 0x10)) = arg2;
    temp_a0 = D_800C7C74 * 2;
    temp_a1 = D_800C7C74 * 0x10;
    *(&D_80078818 + temp_a1) = *(&D_800794E0 + temp_a0);
    *(&D_8007881E + temp_a1) = (s16) D_800AE61C;
    *(&D_8007881A + temp_a1) = *(&D_800794E4 + temp_a0);
    if (D_800A64A9 != 0) {
        *(&D_8007881C + temp_a1) = (s16) ((s32) (D_800AE618 * 3) / 2);
    } else {
        *(&D_8007881C + temp_a1) = (s16) D_800AE618;
    }
    func_80058C6C(M2C_FIELD(arg3, s32 *, 0x10), (D_800C7C74 * 0x10) + &D_80078810);
}
