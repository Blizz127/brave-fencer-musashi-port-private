/* SC02.CD member35: func_80183E3C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_801B979C[];

s32 func_80183E3C(s32 arg0) {
        return ((s32 (*)(s32, void *, void *, s32))func_8012D5E4)(arg0, &D_801B979C[0], &D_801B979C[8], 5) != 0;
    }
