/* sc03_0001: func_80187904 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_80029504(void);
extern s32 func_80029504(void);
s32 aF801877C0(void) __asm__("func_801877C0");
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);

s32 func_80187904(void) {
    s32 v1 = func_80029504();
    if (v1 < 0x3b6) {
        return 0;
    }
    if (v1 < 0x3e8) {
        return 1;
    }
    if (v1 < 0x44c) {
        return 2;
    }
    if (v1 < 0x4b0) {
        return 3;
    }
    return 4;
}
