/* sc03_0001: func_80187C2C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8014B12C(void);
extern s32 func_8016F1C4(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8014B12C(void);
extern void func_8014B12C(void);
extern s32 func_8016F1C4(void);

s32 func_80187C2C(s32 a0) {
    if (func_8016F1C4() != 0) {
        return 0;
    }
    if (((s32 (*)(void))func_8014B12C)() != 0) {
        return 2;
    }
    return 1;
}
