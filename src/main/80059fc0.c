/* Retail word export [80059FC0,8005A468); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072784();
extern s32 D_80072788;
extern s32 D_80072780;
extern s32 D_800727F4;
extern s32 D_800727F8;
extern s32 D_800727FE;
extern s32 D_80072802;
extern s32 D_80072804;
extern s32 D_80074220;
u8 func_80043078();                                 /* static */
s32 func_8005ADB8(void *);                          /* static */
void func_8005C324(u16 *, void *, s32);                  /* static */
extern s32 func_800727FC;
extern u8 D_8007278A;
extern u8 D_8007278B;
extern u16 D_800727F6;
extern u16 D_800727FA;
extern u16 D_80072800;

void *func_80059FC0(void *arg0) {
    s16 temp_a0;
    s16 temp_a1;
    s16 temp_v0_2;
    s16 temp_v1_2;
    s16 temp_v1_3;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a2;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;
    u8 temp_v0;
    u8 temp_v0_3;

    var_s3 = 0x08000000;
    if ((u8) D_8007278A >= 2U) {
        D_80072784(D_80074220, arg0);
    }
    if ((u32) (D_80072788 - 1) < 2U) {
        var_v1 = ((arg0->unk2 & 0xFFF) << 0xC) | (func_8005ADB8(arg0) & 0xFFF);
        var_v0 = 0x05000000;
    } else {
        var_v0 = ((arg0->unk2 & 0x3FF) << 0xA) | (arg0->unk0 & 0x3FF);
        var_v1 = 0x05000000;
    }
    D_80072780->unk10(var_v0 | var_v1);
    if (((s16) func_800727FC != arg0->unk8) || ((s16) D_800727FE != arg0->unkA) || ((s16) D_80072800 != arg0->unkC) || ((s16) D_80072802 != arg0->unkE)) {
        temp_v0 = func_80043078();
        arg0->unk12 = temp_v0;
        temp_a0 = arg0->unkA;
        temp_v1 = (arg0->unk8 * 0xA) + 0x260;
        if (temp_v0 & 0xFF) {
            var_s1 = temp_a0 + 0x13;
        } else {
            var_s1 = temp_a0 + 0x10;
        }
        temp_a1 = arg0->unkC;
        if (temp_a1 != 0) {
            var_a2 = temp_v1 + (temp_a1 * 0xA);
        } else {
            var_a2 = temp_v1 + 0xA00;
        }
        temp_v0_2 = arg0->unkE;
        var_s2 = var_s1 + temp_v0_2;
        if (temp_v0_2 == 0) {
            var_s2 = var_s1 + 0xF0;
        }
        if (temp_v1 >= 0x1F4) {
            var_a1 = 0xCDA;
            if (temp_v1 < 0xCDB) {
                var_a1 = temp_v1;
            }
        } else {
            var_a1 = 0x1F4;
        }
        var_a1_2 = var_a1 + 0x50;
        var_v0_2 = var_s1 < 0x10;
        if (var_a2 >= var_a1_2) {
            var_a1_2 = 0xCDA;
            if (var_a2 < 0xCDB) {
                var_a1_2 = var_a2;
            }
            var_v0_2 = var_s1 < 0x10;
        }
        if (var_v0_2 == 0) {
            if (arg0->unk12 != 0) {
                if (var_s1 < 0x137) {
                    var_a0 = var_s1;
                } else {
                    goto block_30;
                }
            } else if (var_s1 >= 0x101) {
block_30:
                var_a0 = 0x100;
                if (arg0->unk12 != 0) {
                    var_a0 = 0x136;
                }
            } else {
                var_a0 = var_s1;
            }
        } else {
            var_a0 = 0x10;
        }
        var_a1_3 = var_a0 + 2;
        if (var_s2 >= var_a1_3) {
            if (arg0->unk12 != 0) {
                if (var_s2 < 0x139) {
                    var_a1_3 = var_s2;
                } else {
                    goto block_39;
                }
            } else if (var_s2 >= 0x103) {
block_39:
                var_a1_3 = 0x102;
                if (arg0->unk12 != 0) {
                    var_a1_3 = 0x138;
                }
            } else {
                var_a1_3 = var_s2;
            }
        }
        D_80072780->unk10(((var_a1_2 & 0xFFF) << 0xC) | ((var_a1 & 0xFFF) | 0x06000000), D_80072780, var_a1_2);
        D_80072780->unk10(((var_a1_3 & 0x3FF) << 0xA) | ((var_a0 & 0x3FF) | 0x07000000), D_80072780);
    }
    if ((D_80072804 != arg0->unk10) || ((s16) D_800727F4 != (s16) arg0->unk0) || ((s16) D_800727F6 != (s16) arg0->unk2) || ((s16) D_800727F8 != arg0->unk4) || ((s16) D_800727FA != arg0->unk6)) {
        temp_v0_3 = func_80043078();
        arg0->unk12 = temp_v0_3;
        if ((temp_v0_3 & 0xFF) == 1) {
            var_s3 = 0x08000008;
        }
        if (arg0->unk11 != 0) {
            var_s3 |= 0x10;
        }
        if ((u8) arg0->unk10 != 0) {
            var_s3 |= 0x20;
        }
        if (D_8007278B != 0) {
            var_s3 |= 0x80;
        }
        temp_v1_2 = arg0->unk4;
        if (temp_v1_2 >= 0x119) {
            if (temp_v1_2 < 0x161) {
                var_s3 |= 1;
            } else if (temp_v1_2 < 0x191) {
                var_s3 |= 0x40;
            } else if (temp_v1_2 < 0x231) {
                var_s3 |= 2;
            } else {
                var_s3 |= 3;
            }
        }
        temp_v1_3 = arg0->unk6;
        var_v0_3 = temp_v1_3 < 0x121;
        if (arg0->unk12 == 0) {
            var_v0_3 = temp_v1_3 < 0x101;
        }
        if (var_v0_3 == 0) {
            var_s3 |= 0x24;
        }
        D_80072780->unk10(var_s3);
    }
    func_8005C324(&D_800727F4, arg0, 0x14);
    return arg0;
}
