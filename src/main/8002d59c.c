/* Main-exec range [8002D59C,8002D678) from the SLUS executable.
 * SHA256(span)=14fa1d0b4f66cd9217c308975c794ba2459e336e078081a78791b47451181aba.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002D320();                                  /* static */
void func_8002D904(u32);                               /* static */
void func_8002DC68(s32, s32);                          /* static */
void func_8002E138(u32, s32, s32);                     /* static */
void func_80030F80();                                  /* static */
void func_80031BE0();                                  /* static */
extern s16 D_800A4EFC;
extern u8 D_800A4F17;
extern u8 D_800A4F18;

void func_8002D59C(s32 arg0, s32 arg1, s32 arg2) {
    u32 temp_v1;

    temp_v1 = arg0 & 0xFFFF;
    D_800A4F17 = 1;
    if (temp_v1 < 0x80U) {
        func_8002E138(temp_v1, arg1 & 0xFFFF, arg2 & 0xFFFF);
    } else if (temp_v1 >= 0x100U) {
        if (temp_v1 < 0x400U) {
            func_8002D904(temp_v1);
        } else {
            func_8002DC68(temp_v1 | (arg2 << 0x10), arg1 & 0xFFFF);
        }
    }
    D_800A4F17 = D_800A4F18;
    if (D_800A4F18 != 0) {
        if (D_800A4EFC != 0) {
            D_800A4EFC -= 1;
        }
        func_80030F80();
        func_8002D320();
        func_80031BE0();
        D_800A4F18 = 0;
        D_800A4F17 = 0;
    }
}
