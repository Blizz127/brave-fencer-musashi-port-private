/* Overlay range [8017BD50,8017BE60) from MAIN.CD member 0012.
 * SHA256(span)=db033eb94c298c42c48730c33c5dbb7f62a5c799810fdffe666fb961b3aa9ba3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8018534C;
void D_80185390();                                     /* static */
extern s32 D_801853D6;
extern s32 D_801853D8;
void func_8012A4BC(s16, s16, s16);                     /* static */
void func_8017B0E4();                                 /* static */
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s16 D_801853D4;
extern s16 D_80185C08;

void func_8017BD50(void) {
    u16 temp_v0;

    func_8017B0E4(6);
    temp_v0 = D_8018534C + 1;
    D_8018534C = temp_v0;
    if ((s16) temp_v0 >= 0x19) {
        if (D_80185390 != 0) {
            D_80185390();
        } else {
            D_80114F30 += D_801853D4;
            D_80114F34 += D_801853D6;
            D_80114F38 += D_801853D8;
            D_80114F24 += D_801853D4;
            D_80114F28 += D_801853D6;
            D_80114F2C += D_801853D8;
            func_8012A4BC(D_801853D8, D_801853D4, D_801853D6);
        }
        D_80185C08 = 0;
    }
}
