/* sc03_0001: func_80187890 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_80029504(void);
extern s32 func_80029504(void);
s32 aF801877C0(void) __asm__("func_801877C0");
extern s32 func_80029504(void);
extern s32 func_80029504(void);

s32 func_80187890(void) {
    s32 v0 = func_80029504();
    if (v0 < 0xC8) return 5;
    if (v0 < 0x12C) return 0;
    if (v0 < 0x258) return 1;
    if (v0 < 0x2B2) return 2;
    if (v0 < 0x2E4) return 3;
    if (v0 < 0x384) return 4;
    return 6;
}
