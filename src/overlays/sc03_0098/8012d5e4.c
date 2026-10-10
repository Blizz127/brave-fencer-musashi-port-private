/* sc03_0098: func_8012D5E4 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_80126B98;
extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);
s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);

s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3) {
    if (func_8012DEB8(a0, a1, a2) != 0) {
        D_80126B98 = a3;
        return 1;
    }
    return 0;
}
