/* Exact retail word export for [8002EC10,8002ED90); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80068B66;
s32 func_8003836C(s16);                             /* static */
void func_800383A4(s16);                               /* static */
void func_800384A8(s16);                               /* static */
void func_800385C0(s16);                               /* static */
extern s16 D_800A4E86;
extern s16 D_800A4E8A;
extern u16 D_800A4E8C;
extern u16 D_800A4E8E;
extern s16 D_800A4E9A;
extern u16 D_800A4EA0;
extern u16 D_800A4EA2;
extern s16 D_800A4F20;
extern s16 D_800A4F22;

void func_8002EC10(void) {
    u16 temp_v0;
    u16 temp_v1;

    D_800A4F20 = 0;
    D_800A4F22 = 0;
    D_800A4E8A = 0;
    if (D_800A4E8E & 4) {
        if (((func_8003836C(D_800A4E86) << 0x10) != 0) && (*(D_80068B66 + (D_800A4E8C * 0x10)) & 1)) {
            if (D_800A4EA2 & 4) {
                func_800385C0(D_800A4E9A);
                D_800A4EA2 &= 0xFEE8;
            }
            func_800383A4(D_800A4E86);
            temp_v0 = D_800A4E8E & 0xFFFD;
            temp_v1 = D_800A4E8E & 0xFEF9;
            D_800A4E8E = temp_v0;
            D_800A4EA2 = temp_v0;
            D_800A4E9A = (s16) (u16) D_800A4E86;
            D_800A4EA0 = D_800A4E8C;
            D_800A4E8E = temp_v1;
            return;
        }
        if ((func_8003836C(D_800A4E86) << 0x10) != 0) {
            func_800384A8(D_800A4E86);
        }
        D_800A4E8E &= 0xFEE8;
        func_800385C0(D_800A4E86);
    }
}
