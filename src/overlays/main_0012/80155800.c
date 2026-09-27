/* Overlay range [80155800,80155A44) from MAIN.CD member 0012.
 * SHA256(span)=4958e9a3123b66bf0da45374f2de256d4488a72c75c81cc2178467a8701a4069.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001382C(s16, void *, void *);                  /* extern */
void func_80146DB8(void *, void *);                       /* static */
s32 func_80146E98(void *);                          /* static */
void func_801473EC(void *);                            /* static */
void func_80147A84(void *);                            /* static */
s32 func_801487F4(void *);                          /* static */
s32 func_80148800(void *);                          /* static */
s32 func_801488A8(void *);                          /* static */
void func_80148AFC(void *);                            /* static */
s32 func_801496D4(void *);                          /* static */
void func_80149704(void *);                            /* static */
void func_80149AD4(void *);                            /* static */
void func_80149B14(void *);                            /* static */
void func_80154134(void *);                            /* static */
void func_80155A44(void *);                            /* static */
void func_80155F80(void *);                            /* static */
void func_80155FF8(void *, u8);                        /* static */
void func_801599A4(void *);                            /* static */
void func_80159B3C(void *);                            /* static */
void func_8015A230(void *);                            /* static */
s32 func_80161208(void *);                          /* static */
extern s32 D_8011F730;

void func_80155800(void *arg0) {
    s32 sp10;
    u8 temp_v0;
    u8 temp_v1;
    u8 var_v1;

    arg0->unk44 = (s32) (arg0->unk44 | 2);
    if (arg0->unkB8 == 0x8000) {
        func_801599A4();
        func_80159B3C(arg0);
        return;
    }
    func_80155A44(arg0);
    if (func_80148800(arg0) & 0x80) {
        temp_v1 = arg0->unk1A9;
        if (temp_v1 >= 4U) {
            if (arg0->unk1C0 != 0) {
                func_80148AFC(arg0);
                func_80155F80(arg0);
                func_80154134(arg0);
                temp_v0 = arg0->unk1AA;
                var_v1 = temp_v0 + 1;
                if (temp_v0 == 0) {
                    var_v1 = 2;
                } else if (var_v1 >= 5U) {
                    var_v1 = 1;
                }
                arg0->unk1AA = var_v1;
                func_80149B14(arg0);
                return;
            }
            if ((u8) arg0->unk1AA >= 2U) {
                if (arg0->unk1A8 == 0) {
                    if (temp_v1 != 0) {
                        goto block_13;
                    }
                    goto block_15;
                }
                goto block_22;
            }
block_13:
            func_80148AFC(arg0);
            func_80155F80(arg0);
            func_80154134(arg0);
            func_80149AD4(arg0);
            D_8011F730 |= 3;
            return;
        }
    }
block_15:
    if ((arg0->unk1A8 == 0) && (arg0->unk1A9 != 0)) {
        if (func_801496D4(arg0) != 0) {
            func_801599A4(arg0);
            func_80149704(arg0);
            return;
        }
        if (!(func_801487F4(arg0) & 8) && (func_801488A8(arg0) != 0)) {
            func_801599A4(arg0);
            func_8015A230(arg0);
            return;
        }
        goto block_22;
    }
block_22:
    if (func_80146E98(arg0) == 0) {
        func_8001382C((s16) ((s32) arg0->unk20->unk12 * -1), arg0 + 0x234, &sp10);
        func_80146DB8(arg0, &sp10);
        func_80147A84(arg0);
        func_801473EC(arg0);
    }
    if (func_80161208(arg0) == 0) {
        func_80155FF8(arg0, arg0->unk1AA);
    }
}
