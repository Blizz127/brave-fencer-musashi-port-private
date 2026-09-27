/* Overlay range [80130D48,80131170) from MAIN.CD member 0012.
 * SHA256(span)=6e7d43854cc07c74640d135aec8f0f3f5f28948210499a38faf749bf5ec9cf46.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8005C49C(u16, u16);                        /* extern */
extern s32 D_8017E760;
extern s32 D_8017E790;
extern s32 D_8017E7F0;
extern s32 D_8017E7F8;
extern s32 D_8017E818;
void *func_8012C658(s16, s16, void *);              /* static */
s32 func_80131CF4(s32, s32);                          /* static */
extern s32 D_80078E78;
extern u16 D_80078EB2;
extern u16 D_80078EB4;

void func_80130D48(void *arg0) {
    s32 (*var_s0)();
    s32 (*var_s0_2)();
    s16 *var_s0_3;
    s16 var_a0;
    s16 var_a1_2;
    s16 var_s1_3;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v0;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_4;
    s32 var_s1_5;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    u32 temp_v1;
    void *temp_v0_2;

    temp_v0 = func_80131CF4(arg0->unkBC, 0x15);
    if (temp_v0 != 0) {
        if (arg0->unk5E == 0xB) {
            var_a0 = 0x33;
            goto block_62;
        }
        temp_v1 = temp_v0 & 0xFFFF0000;
        if (temp_v1 != 0x40000) {
            if (temp_v1 <= 0x40000U) {
                switch (temp_v1) {                  /* switch 1; irregular */
                default:                            /* switch 1 */
                    var_a0 = 0x31;
                    if (temp_v1 != 0x30000) {
                        return;
                    }
                    goto block_62;
                case 0x10000:                       /* switch 1 */
                    var_s1 = 0;
                    if (D_80078EB4 == D_80078EB2) {
                        var_s1 = 0xC;
                    } else if ((u32) ((u16) D_80078EB2 >> 1) >= (u16) D_80078EB4) {
                        var_s1 = 3;
                    }
                    if (D_80078E78.unk40 == D_80078E78.unk3E) {
                        var_s1_2 = var_s1 + 0x18;
                        goto block_25;
                    }
                    var_v1 = var_s1 * 2;
                    if ((u32) ((u16) D_80078E78.unk3E >> 1) >= (u16) D_80078E78.unk40) {
                        var_s1_2 = var_s1 + 6;
block_25:
                        var_v1 = var_s1_2 * 2;
                    }
                    var_s0 = var_v1 + D_8017E790;
                    var_a1 = 0;
                    var_a0_2 = func_8005C49C() % 100;
loop_27:
                    if (var_a0_2 >= *var_s0) {
                        var_a1 += 1;
                        var_s0 += 2;
                        if (var_a1 >= 3) {

                        } else {
                            goto loop_27;
                        }
                    }
                    var_s1_3 = 0;
                    switch (var_a1) {               /* switch 2; irregular */
                    case 0:                         /* switch 2 */
                        var_s0 = D_8017E7F0;
                        var_s1_3 = 0x31;
                        break;
                    case 1:                         /* switch 2 */
                        var_a0_2 = (s32) D_80078E78.unk3A;
                        var_a1 = (s32) D_80078E78.unk3C;
                        var_v1_2 = 0 * 2;
                        if (((var_a0_2 * 7) / 10) >= var_a1) {
                            var_s1_4 = 4;
                            if (((s32) (var_a0_2 - (var_a0_2 >> 0x1F)) >> 1) >= var_a1) {
                                var_s1_4 = 8;
                                if ((D_80078E78.unk3A / 5) >= var_a1) {
                                    var_s1_4 = 0xC;
                                }
                            }
                            var_v1_2 = var_s1_4 * 2;
                        }
                        var_s0 = var_v1_2 + D_8017E7F8;
                        var_s1_3 = 0x32;
                        break;
                    case 2:                         /* switch 2 */
                        var_a0_2 = (s32) D_80078E78.unk3E;
                        var_a1 = (s32) D_80078E78.unk40;
                        var_v1_3 = 0 * 2;
                        if (((var_a0_2 * 7) / 10) >= var_a1) {
                            var_s1_5 = 4;
                            if (((s32) (var_a0_2 - (var_a0_2 >> 0x1F)) >> 1) >= var_a1) {
                                var_s1_5 = 8;
                                if ((D_80078E78.unk3E / 5) >= var_a1) {
                                    var_s1_5 = 0xC;
                                }
                            }
                            var_v1_3 = var_s1_5 * 2;
                        }
                        var_s0 = var_v1_3 + D_8017E818;
                        var_s1_3 = 0x33;
                        break;
                    }
                    var_a1_2 = 0;
                    temp_a0 = func_8005C49C((u16) var_a0_2, (u16) var_a1) % 100;
loop_50:
                    if (temp_a0 >= *var_s0) {
                        var_a1_2 += 1;
                        var_s0 += 2;
                        if (var_a1_2 < 4) {
                            goto loop_50;
                        }
                    }
                    var_a0 = var_s1_3;
                    goto block_63;
                case 0x20000:                       /* switch 1 */
                    var_a0 = 0x33;
                    goto block_62;
                }
            } else {
                if (temp_v1 != 0x60000) {
                    if (temp_v1 <= 0x60000U) {
                        var_a0 = 0x33;
                        if (temp_v1 != 0x50000) {
                            return;
                        }
                        goto block_62;
                    }
                    var_a0 = 0x27B;
                    if (temp_v1 != 0x70000) {
                        return;
                    }
                    goto block_62;
                }
                var_s0_2 = D_8017E760;
                temp_a0_2 = func_8005C49C() & 0xFF;
                if (temp_a0_2 >= D_8017E760) {
                    var_s0_3 = D_8017E760 + 6;
                    do {
                        var_s0_3 += 6;
                    } while (temp_a0_2 >= *var_s0_3);
                    var_s0_2 = var_s0_3 - 6;
                }
                var_a0 = var_s0_2->unk2;
                if ((u16) D_80078E78.unk40 < 4U) {
                    var_a0 = 0x33;
                }
                var_a1_2 = var_s0_2->unk4;
                goto block_63;
            }
        } else {
            var_a0 = 0x32;
block_62:
            var_a1_2 = 0;
block_63:
            temp_v0_2 = func_8012C658(var_a0, var_a1_2, arg0);
            if (temp_v0_2 != 0) {
                temp_v0_2->unkA = (u16) (temp_v0_2->unkA - 0x20);
            }
        }
    }
}
