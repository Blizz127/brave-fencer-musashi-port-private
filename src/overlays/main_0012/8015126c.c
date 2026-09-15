/* Overlay range [8015126C,80151664) from MAIN.CD member 0012.
 * SHA256(span)=a4e0109bb70d2b07b6d028b624dce54d42c80d6f03a575c572d16a15ec2b65e9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

u16 func_80029D3C(s16);                             /* extern */
void func_800CCF58(void *);                      /* extern */
void func_800CCF68(void *);                      /* extern */
void func_80146D80(void *);                      /* static */
void func_80147084(void *);                      /* static */
void func_801470A0(void *);                      /* static */
void func_80147324();                     /* static */
void func_801477E8(void *, s32);             /* static */
s32 func_8014A454(void *);                          /* static */
void func_8014ACE8(void *, s32, s32);    /* static */
void func_8014B310(void *);                      /* static */
void func_8014B4D4(void *);                      /* static */
void func_8014B944(void *, s32, s32);    /* static */
void func_8014BD24(void *, s32);             /* static */
s32 func_8014CB7C(u16);                             /* static */
void func_8015173C(void *);                      /* static */
s32 func_80151880(void *);                          /* static */
s32 func_801518D8(void *);                          /* static */
void func_80153C9C();                            /* static */
void func_801599A4(void *, u16);                 /* static */
void func_80160368(void *);                      /* static */
void func_801607B8(void *);                      /* static */
s32 func_801619D0(void *);                          /* static */
s32 func_80161A00(void *);                          /* static */
s32 func_80161A30(void *);                          /* static */
s32 func_80161A60(void *);                          /* static */
void func_801725CC(void *);                      /* static */
extern s32 *D_80078E78;
extern s32 *D_800AE6A8;
extern s32 D_801151FC;
extern s32 D_80126AE4;
extern s32 D_80127078;
extern s32 D_80127518;

void func_8015126C(void *arg0) {
    s16 temp_a0_2;
    s32 temp_v0;
    s32 temp_v1_2;
    s32 var_v0_2;
    s32 var_v0_3;
    u16 temp_a0;
    u16 temp_a1;
    u16 temp_v0_3;
    u16 temp_v0_4;
    u16 temp_v0_5;
    u16 temp_v1;
    u16 var_v0;
    u8 temp_v0_2;

    temp_v0 = D_80127078;
    D_80127078 = 0;
    D_801151FC = 0;
    D_80126AE4 = temp_v0;
    if (M2C_FIELD(arg0, u8 *, 0xA8) != 0) {
        temp_v1 = M2C_FIELD(arg0, u16 *, 0x3C);
        var_v0 = temp_v1 & 0xFFFE;
        if (!(temp_v1 & 1) || (var_v0 = temp_v1 & 0xFFFE, ((M2C_FIELD(arg0, u16 *, 0x3E) & 0x8000) == 0))) {
            M2C_FIELD(arg0, u16 *, 0x3C) = var_v0;
            M2C_FIELD(arg0, u16 *, 0x3E) = 0U;
            M2C_FIELD(arg0, u16 *, 0x40) = 0U;
            M2C_FIELD(arg0, u16 *, 0x42) = 0U;
        }
        temp_v0_2 = M2C_FIELD(arg0, u8 *, 0xA8) - 1;
        M2C_FIELD(arg0, u8 *, 0xA8) = temp_v0_2;
        if (temp_v0_2 & 1) {
            func_801470A0(arg0);
        }
    }
    temp_a0 = M2C_FIELD(arg0, u16 *, 0x3C);
    if (temp_a0 & 1) {
        if (!((s32) M2C_FIELD(arg0, u16 *, 0x3C) & 0x80008000) || (M2C_FIELD(&D_800AE6A8, s32 *, 8) & 0x80FFFFFF)) {
            M2C_FIELD(arg0, u16 *, 0x3C) = (u16) (temp_a0 & 0xFFFE);
            M2C_FIELD(arg0, u16 *, 0x3E) = 0U;
            M2C_FIELD(arg0, u16 *, 0x40) = 0U;
            M2C_FIELD(arg0, u16 *, 0x42) = 0U;
            goto block_47;
        }
        temp_v0_3 = M2C_FIELD(arg0, u16 *, 0x3E);
        M2C_FIELD(arg0, u16 *, 0x3C) = (u16) (temp_a0 & 0xFFFE);
        M2C_FIELD(arg0, u16 *, 0x3E) = (u16) (temp_v0_3 & 0x7FFF);
        if (!(temp_v0_3 & 0x4000) && (M2C_FIELD(arg0, s32 *, 0x44) & 1) && (func_8014A454(arg0) != 0)) {
            func_80160368(arg0);
            M2C_FIELD(arg0, u16 *, 0x3E) = 0U;
            M2C_FIELD(arg0, u16 *, 0x40) = 0U;
            M2C_FIELD(arg0, u16 *, 0x42) = 0U;
            M2C_FIELD(arg0, u16 *, 0x3C) = (u16) (M2C_FIELD(arg0, u16 *, 0x3C) & 0xFFFE);
            return;
        }
        if ((func_801619D0(arg0) != 0) && (func_80151880(arg0) != 0)) {
            M2C_FIELD(arg0, u16 *, 0x40) = 0U;
            M2C_FIELD(arg0, u16 *, 0xF2) = 0U;
            func_800CCF68(arg0);
        }
        if ((func_80161A00(arg0) != 0) && (func_801518D8(arg0) != 0)) {
            func_800CCF58(arg0);
        }
        if (func_80161A30(arg0) != 0) {
            M2C_FIELD(arg0, s16 *, 0x1C8) = 0;
        }
        if (func_80161A60(arg0) != 0) {
            M2C_FIELD(arg0, s16 *, 0x1C8) = 0;
        }
        if (((u32) (M2C_FIELD(arg0, u16 *, 0) - 0x19) >= 2U) && ((temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x1F8), (temp_v1_2 == 0)) || (temp_v1_2 & 0x02000000))) {
            temp_a1 = M2C_FIELD(arg0, u16 *, 0x42);
            M2C_FIELD(arg0, u16 *, 0xF0) = (u16) M2C_FIELD(arg0, u16 *, 0x3E);
            M2C_FIELD(arg0, u16 *, 0xF2) = (u16) M2C_FIELD(arg0, u16 *, 0x40);
            M2C_FIELD(arg0, u16 *, 0xF4) = temp_a1;
            func_801599A4(arg0, temp_a1);
            func_801607B8(arg0);
            func_80147084(arg0);
            temp_v0_4 = M2C_FIELD(arg0, u16 *, 0x3E);
            M2C_FIELD(arg0, u8 *, 0xA8) = 0U;
            M2C_FIELD(arg0, s8 *, 0xDD) = (s8) temp_v0_4;
            if ((temp_v0_4 & 0xFF) != 0x11) {
                temp_a0_2 = (s16) M2C_FIELD(arg0, u16 *, 0xF2);
                if (temp_a0_2 != 0x3E8) {
                    temp_v0_5 = func_80029D3C(temp_a0_2);
                    M2C_FIELD(arg0, u16 *, 0xF2) = temp_v0_5;
                    var_v0_2 = temp_v0_5 << 0x10;
                    if (M2C_FIELD(&D_80078E78, u8 *, 0x49) != 5) {
                        if (func_8014CB7C(temp_v0_5) != 0) {
                            var_v0_2 = M2C_FIELD(arg0, u16 *, 0xF2) << 0x10;
                            goto block_32;
                        }
                    } else {
block_32:
                        M2C_FIELD(arg0, u16 *, 0xF2) = (u16) ((s32) ((var_v0_2 >> 0x10) + ((u32) var_v0_2 >> 0x1F)) >> 1);
                    }
                }
            }
            func_80153C9C();
            func_8015173C(arg0);
            func_801725CC(arg0);
            if (M2C_FIELD(arg0, u16 *, 0x3E) & 0x2000) {
                func_8014B310(arg0);
            }
            if (M2C_FIELD(arg0, u16 *, 0x3E) & 0x1000) {
                func_8014B4D4(arg0);
            }
            if (M2C_FIELD(arg0, u16 *, 0x3E) & 0x800) {
                func_8014B944(arg0, 0x50000, 1);
            }
            if (M2C_FIELD(arg0, u16 *, 0x3E) & 0x400) {
                func_80146D80(arg0);
                func_801477E8(arg0, 0);
            }
            if (func_80151880(arg0) == 2) {
                func_80147324(0x676);
            }
            if (M2C_FIELD(&D_80078E78, u8 *, 0x49) == 0x14) {
                func_8014BD24(arg0, 0xA);
                func_8014ACE8(arg0, 4, 0xA);
            }
            var_v0_3 = D_80126AE4;
            D_80127518 = var_v0_3;
        } else {
            M2C_FIELD(arg0, u16 *, 0x3E) = 0U;
            M2C_FIELD(arg0, u16 *, 0x40) = 0U;
            M2C_FIELD(arg0, u16 *, 0x42) = 0U;
            M2C_FIELD(arg0, u16 *, 0x3C) = (u16) (M2C_FIELD(arg0, u16 *, 0x3C) & 0xFFFE);
            goto block_47;
        }
        goto block_48;
    }
block_47:
    var_v0_3 = D_80127518;
block_48:
    D_801151FC = var_v0_3;
}
