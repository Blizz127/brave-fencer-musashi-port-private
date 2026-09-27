/* Overlay range [8015D738,8015DA5C) from MAIN.CD member 0012.
 * SHA256(span)=6fd4448bd686158502642d825572b87be33a3b36f20ee29dbe2cc581a664a95b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800CAF14(void *);                            /* extern */
extern s32 D_801809E0;
extern s32 D_801809F0;
extern s32 D_80180A1C;
extern s32 D_80180C61;
extern s32 D_80180C62;
void func_80146DB8(void *, s32 (*)());                   /* static */
void func_80147078(void *, s32);                         /* static */
void func_801473EC(void *);                            /* static */
void func_80147A84(void *);                            /* static */
void func_801483E8(void *);                            /* static */
s32 func_80148800(void *);                          /* static */
s32 func_801488A8(void *);                          /* static */
void func_80148AFC();                                  /* static */
void func_80149374(void *, void *);                    /* static */
s32 func_8014BEF8(void *);                          /* static */
s32 func_8014D738(void *);                          /* static */
void func_80154150(void *, s32);                         /* static */
void func_80154A74(void *, s32);                         /* static */
void func_80159B70(void *);                            /* static */
void func_8015C714(void *);                            /* static */
void func_8015DA5C(void *);                            /* static */
void func_8015DAC4(void *);                            /* static */
void func_8015DE24(void *);                            /* static */
void func_8015F948(void *);                            /* static */
s32 func_80161208(void *);                          /* static */
s32 func_80161B18(void *);                          /* static */
s32 func_80161B84(void *);                          /* static */
s32 func_80165624(void *);                          /* static */
extern s32 D_80078E78;
extern s32 *D_80180C60;

void func_8015D738(void *arg0) {
    s32 (*var_a1)();
    void *temp_s1;
    void *temp_s1_2;

    func_80148AFC();
    if ((func_80161B18(arg0) == 0) && (func_80161B84(arg0) == 0)) {
        temp_s1 = arg0->unk178;
        if ((temp_s1 == 0) || (temp_s1->unk0 != 0x360)) {
            if ((temp_s1 == 0) || (temp_s1->unk0 == 0)) {
                *(D_80180A1C + (arg0->unk0 * 4))(arg0);
                func_80147078(arg0, 0);
                func_80159B70(arg0);
                return;
            }
            if (func_80148800(arg0) & 0x80) {
                goto block_8;
            }
            if ((func_80148800(arg0) & 0x10) && (func_8014BEF8(arg0) != 0)) {
                func_80154A74(arg0, 0x11);
                func_8015DE24(arg0);
                return;
            }
            if ((func_80148800(arg0) & 0x20) && (D_80078E78.unk49 == 0xA)) {
                if (func_80165624(arg0) != 0) {
                    func_8015DA5C(arg0);
                    func_8015F948(arg0);
                    return;
                }
                func_80154A74(arg0, 0x11);
                func_800CAF14(arg0);
                return;
            }
            if ((func_801488A8(arg0) != 0) && (arg0->unk178->unk0 != 0x82)) {
                func_80154150(arg0, 0x1B);
                var_a1 = D_801809E0;
            } else {
                func_80154150(arg0, 0x1A);
                var_a1 = D_801809F0;
            }
            func_80146DB8(arg0, var_a1);
            func_80147A84(arg0);
            func_801473EC(arg0);
            temp_s1_2 = arg0->unk178;
            temp_s1_2->unk6 = (s16) ((s8) *(&D_80180C60 + arg0->unk234) + temp_s1_2->unk78->unkC);
            temp_s1_2->unkA = (s16) ((s8) *(D_80180C61 + arg0->unk234) + temp_s1_2->unk78->unkE);
            temp_s1_2->unkE = (s16) ((s8) *(D_80180C62 + arg0->unk234) + temp_s1_2->unk78->unk10);
            func_80149374(arg0, temp_s1_2 + 4);
            temp_s1_2->unk20->unk12 = (s16) ((arg0->unk20->unk12 + 0x800) & 0xFFF);
            if (func_8014D738(arg0) != 0) {
                *(D_80180A1C + (arg0->unk0 * 4))(arg0);
                func_80147078(arg0, 9);
                func_8015C714(arg0);
                return;
            }
            if (func_80161208(arg0) == 0) {
                func_801483E8(arg0);
            }
        } else {
block_8:
            func_80154A74(arg0, 0x11);
            func_8015DAC4(arg0);
        }
    }
}
