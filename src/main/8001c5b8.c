/* Main-exec range [8001C5B8,8001C6E4) from the SLUS executable.
 * SHA256(span)=e48b4b053a337d548bef9405bd1df5bd32923f77c78e7dda90e720d82483423f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80063548;
void func_8001C9D0();                                  /* static */
void func_80052D90(s32, s32);                            /* static */
void func_80053290(s32);                               /* static */
void func_80054514(s32, void *);                          /* static */
void func_800553D8(s32, void *, s32);                    /* static */
s32 func_800553F4(void *, s32);                     /* static */
extern s32 *D_800A5BD0;
extern s32 D_800AF630;
extern s32 D_800AF7C8;
extern u16 D_800AF7CC;

void func_8001C5B8(void *arg0, s32 *arg1) {
    s32 sp10;
    s32 *var_s2;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 var_s3;
    void *temp_a1;
    void *temp_s0_4;

    var_s2 = arg1;
    func_8001C9D0();
    temp_s0 = arg0 + 0x30;
    arg0->unk0 = 1;
    arg0->unk2 = 8;
    func_80052D90(0, temp_s0);
    func_80054514(temp_s0, &sp10);
    arg0->unk24 = var_s2;
    if (var_s2 != 0) {
        arg0->unk20 = D_80063548;
        var_s3 = D_800AF7C8;
        arg0->unk2E = (u16) D_800AF7CC;
        if (*var_s2 != 0) {
            do {
                temp_s0_2 = *var_s2;
                var_s2 += 4;
                temp_s0_3 = (temp_s0_2 & 0x80FFFFFF) + 4;
                func_80053290(temp_s0_3);
                temp_s0_4 = (D_800AF630.unk19C * 0x14) + &D_800A5BD0;
                temp_a1 = temp_s0_4;
                D_800AF630.unk19C = (u16) (D_800AF630.unk19C + 1);
                func_800553D8(temp_s0_3 + 8, temp_a1, 0);
                var_s3 = func_800553F4(temp_s0_4, var_s3);
            } while (*var_s2 != 0);
        }
        D_800AF630.unk198 = var_s3;
    }
}
