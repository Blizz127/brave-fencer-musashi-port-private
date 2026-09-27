/* Exact retail word export for [80036D58,80036EB4); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006AEE8;
s32 func_80034CF0(void *);                             /* static */
void func_80034DFC(s16);                               /* static */
extern s32 func_80035C4C;
extern s32 func_8003602C;
extern s32 func_80036F98;
extern s32 func_80036FB0;
void func_8003EDE8(s32, s32, s32);                       /* static */
extern s16 D_80078F10;
extern s8 D_800A46BA;
extern s16 D_800A4EF8;
extern s8 D_800A4F1A;
extern s32 D_800C6D28;

void func_80036D58(s16 arg0) {
    s32 (*sp38)();
    s32 (*sp34)();
    s32 sp30;
    s32 (*sp2C)();
    s32 sp1C;
    s32 (*sp18)();
    s32 sp10;
    s16 *var_s0;
    s32 temp_a1;
    s32 temp_v0;
    s32 var_s1;

    if (((arg0 << 0x10) != 0) || (D_800C6D28 != 0)) {
        D_800A46BA = 0;
        if (D_8006AEE8 != 0) {
            var_s1 = 0;
            if (D_8006AEE8 > 0) {
                var_s0 = &D_80078F10;
                do {
                    var_s1 += 1;
                    func_80034DFC(*var_s0);
                    *var_s0 = 0;
                    var_s0 += 4;
                } while (var_s1 < D_8006AEE8);
            }
            D_8006AEE8 = 0;
        }
        sp18 = func_80035C4C;
        sp2C = func_80036F98;
        sp34 = func_8003602C;
        sp1C = (s32) arg0;
        sp30 = 0;
        sp38 = func_80036FB0;
        temp_v0 = func_80034CF0(&sp10);
        *(&D_80078F10 + (D_8006AEE8 * 4)) = temp_v0;
        if (temp_v0 != 0) {
            D_8006AEE8 = (s32) (D_8006AEE8 + 1);
        }
        D_800A4F1A = 0;
        if (arg0 != 0) {
            D_800C6D28 = 0;
        }
        temp_a1 = ((u32) (D_800A4EF8 * 0x61) >> 7) & 0xFF;
        func_8003EDE8(0, temp_a1, temp_a1);
    }
}
