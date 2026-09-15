/* Exact retail word export for [8002FB08,8002FC64); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80064D49;
extern s32 D_80064D4D;
void func_8002EC10();                                  /* static */
extern s32 func_800301A4;
void func_80031A98();                                  /* static */
s32 func_80037CD8(s32 (*)());                         /* static */
void func_800415A8(s16);                               /* static */
extern u8 D_8006AEF4;
extern s32 *D_800A463C;
extern s32 *D_800A4640;
extern s32 *D_800A4642;
extern s32 *D_800A4650;
extern s32 D_800A46C8;
extern s16 D_800A46CC;
extern s32 *D_800C5328;

s32 func_8002FB08(s32 arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v1;
    u8 temp_v1_2;

    if (func_80037CD8(func_800301A4) == 0) {
        return 0;
    }
    temp_s0 = arg0 * 0xC;
    temp_v1 = *(D_80064D49 + temp_s0) * 0x18;
    D_800A46C8 = *(&D_800A463C + temp_v1);
    if (*(&D_800A4650 + temp_v1) == 0) {
        *(&D_800C5328 + (*(&D_800A4640 + temp_v1) * 4)) = -1;
    }
    func_80031A98();
    temp_v1_2 = *(D_80064D4D + temp_s0);
    if (temp_v1_2 != 0) {
        temp_s0_2 = temp_v1_2 * 0x18;
        if (*(&D_800A4642 + temp_s0_2) >= 0) {
            func_8002EC10();
            func_800415A8(*(&D_800A4642 + temp_s0_2));
            *(&D_800A4642 + temp_s0_2) = -1;
            *(&D_800A4640 + temp_s0_2) = -1;
        }
        *(&D_800A4650 + temp_s0_2) = 1;
    }
    D_800A46CC = 0;
    D_8006AEF4 |= 2;
    return 1;
}
