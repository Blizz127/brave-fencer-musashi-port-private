/* Overlay range [8017C268,8017C348) from MAIN.CD member 0012.
 * SHA256(span)=e102c7960af5822f9b5df698461341f733f7455492bb2f84a923fd460a7655e5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8002B0B4(s32, s32, void *);                   /* extern */
extern s32 D_801857E8;
extern s32 D_801857EC;
extern s32 D_80185AD4;
extern s32 D_80185AD8;
extern s32 D_80185AEC;
s16 func_8017C3BC();                                /* static */
void func_8017CA18();                                  /* static */
void func_8017CF3C();                                  /* static */
void func_8017D2A4();                                  /* static */
extern u16 D_800B9A02;
extern s8 D_800B9A15;
extern u16 D_80115112;
extern s16 D_80115126;
extern s32 *D_801151C8;
extern s32 D_801151D0;
extern s32 *D_80185ADC;

void func_8017C268(void) {
    s16 temp_s0;

    D_801151D0 = *(&D_801151C8 + (D_800B9A02 * 4));
    if (D_801857EC == 0) {
        D_80185AEC = func_8002B0B4(D_80185AD4, D_80185AD8, &D_80185ADC);
        if (D_80115126 == 0) {
            func_8017CF3C();
        } else {
            func_8017D2A4();
        }
    }
    temp_s0 = func_8017C3BC();
    func_8017CA18();
    if ((temp_s0 << 0x10) != 0) {
        D_801857E8 = temp_s0;
        D_800B9A15 = 0;
        D_80115112 += 1;
    }
}
