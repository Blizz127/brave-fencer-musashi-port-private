/* sc01_0077: func_8017F7E8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_80047948(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_80047948(s32 a0);

s32 func_8017F7E8(s32 a0) {
    extern s16 D_8018A9D0;
    extern s16 D_8018A9D2;
    s32 m = D_8018A9D0;
    s32 i = *(s16 *)(a0 + 0xFC) & (D_8018A9D2 - 1);
    return (((func_80047948((0x2000 / D_8018A9D2) * i) / 2
              + func_80047948((0x4000 / D_8018A9D2) * i) * 3 / 8 - 0x800) < 0
               ? -(func_80047948((0x2000 / D_8018A9D2) * i) / 2
                   + func_80047948((0x4000 / D_8018A9D2) * i) * 3 / 8 - 0x800)
               : (func_80047948((0x2000 / D_8018A9D2) * i) / 2
                  + func_80047948((0x4000 / D_8018A9D2) * i) * 3 / 8 - 0x800))
            * m >> 12) + 8;
}
