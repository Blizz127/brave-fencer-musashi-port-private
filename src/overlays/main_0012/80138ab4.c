/* Overlay range [80138AB4,80138B88) from MAIN.CD member 0012.
 * SHA256(span)=b6a268a6655bb3690e380086932996198b3599ede4d815745825105602b09007.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80138DE0(void *, s32, s32);                  /* static */
void func_80139B18(void *);                            /* static */
s32 func_80139D04(void *, u16);                        /* static */
extern s32 *D_80127540;

void func_80138AB4(void *arg0) {
    s32 sp10;
    s32 temp_s1;
    s32 var_a0;
    u16 temp_v1;
    u16 temp_v1_2;

    temp_s1 = func_80139D04(&sp10, *(&D_80127540 + (arg0->unk48 * 2))) & 0xFFFF;
    do {
        temp_v1 = arg0->unk44;
        var_a0 = 0;
        if ((s32) temp_v1 < temp_s1) {
            var_a0 = func_80138DE0(arg0, ((sp + temp_v1)->unk10 + 0x30) & 0xFF, 0);
            if (!(arg0->unk8 & 0x80220)) {
                var_a0 = 0;
            }
        } else {
            temp_v1_2 = arg0->unk48;
            if (temp_v1_2 < 3U) {
                arg0->unk48 = (u16) (temp_v1_2 + 1);
            }
            arg0->unk4 = 2;
        }
    } while (var_a0 != 0);
    func_80139B18(arg0);
}
