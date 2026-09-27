/* Exact retail word export for [8002CDD8,8002CFE4); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006A990;
void func_8002CFE4();                                  /* static */
void func_8002D904(s32, u16);                          /* static */
void func_8002EC10();                                  /* static */
void func_80037FC4();                                  /* static */
s32 func_8003836C(s16);                             /* static */
s32 func_8003C4F0();                               /* static */
void func_8003D25C(s32, s32, void *);                         /* static */
extern u8 D_8006AEF4;
extern s32 D_800A4638;
extern s16 D_800A4E86;
extern s16 D_800A4E8A;
extern u16 D_800A4E8E;
extern u16 D_800A4EE0;
extern u16 D_800A4EE2;
extern u16 D_800A4EE4;
extern u8 D_800A4EE6;
extern s32 *D_800A4EFE;
extern s8 D_800A4F16;
extern u8 D_800A4F17;
extern s8 D_800A4F18;
extern u16 D_800A4F22;

void func_8002CDD8(void) {
    s16 temp_v0_3;
    s32 temp_a0;
    s32 var_v0;
    u16 temp_v0;
    u16 temp_v0_2;
    u32 temp_a0_2;

    temp_a0 = D_800A4F22 & 0xFFFF;
    D_800A4638 += 1;
    if (temp_a0 != 0) {
        D_8006A990 = (u16) D_800A4F22;
        func_8002D904(temp_a0, D_800A4F22);
        D_800A4F22 = 0;
    }
    if (D_800A4EE6 & 1) {
        D_800A4F16 = 1;
        temp_a0_2 = D_800A4EE4 & 0xFFFF;
        if (temp_a0_2 < (u16) D_800A4EE0) {
            temp_v0 = D_800A4EE0 - D_800A4EE2;
            D_800A4EE0 = temp_v0;
            var_v0 = temp_a0_2 < (u32) (temp_v0 & 0xFFFF);
        } else {
            temp_v0_2 = D_800A4EE0 + D_800A4EE2;
            D_800A4EE0 = temp_v0_2;
            var_v0 = (u32) (temp_v0_2 & 0xFFFF) < temp_a0_2;
        }
        if (var_v0 == 0) {
            D_800A4EE0 = D_800A4EE4;
            D_800A4EE6 &= 0xFE;
        }
    }
    func_8003D25C(0, 0x17, &D_800A4EFE);
    if (D_800A4E8E & 8) {
        func_80037FC4();
        if (D_800A4E8A != 0) {
            temp_v0_3 = D_800A4E8A - 1;
            D_800A4E8A = temp_v0_3;
            if ((temp_v0_3 << 0x10) == 0) {
                func_8002EC10();
            }
        }
        if ((func_8003836C(D_800A4E86) << 0x10) == 0) {
            D_800A4E8E &= 0xFFF7;
        }
    }
    if (D_800A4F17 == 0) {
        D_800A4F18 = 0;
        func_8002CFE4();
    } else {
        D_800A4F18 = 1;
    }
    if ((D_8006AEF4 & 1) && !(D_8006AEF4 & 2) && (func_8003C4F0(0) != 0)) {
        D_8006AEF4 &= 0xFE;
    }
}
