/* sc03_0001: func_80188618 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 func_80029504(void);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_80029504(void);
s32 aF801877C0(void) __asm__("func_801877C0");
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_8012E57C(s32 a0, s32 a1);
extern void func_80188AEC(s32 a0, s32 a1);
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_8012E57C(s32 a0, s32 a1);
extern void func_80188AEC(s32 a0, s32 a1);

void func_80188618(s32 a0) {
    s32 v1;
    v1 = func_8012E57C(0x61, (s32)(s16)a0);
    if (v1 != 0) {
        *(s16 *)((char *)v1 + 0x108) = 1;
        func_80188AEC(a0, 0x3C);
    }
}
