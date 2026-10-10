/* sc03_0098: func_8012EECC from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8002A4FC(s32 a0);

s32 func_8012EECC(s32 a0) {
    s32 n = a0 * func_8002A4FC(a0);
    return a0 - (n * 100) / 7680;
}
