/* sc03_0001: func_8012B864 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 x, s32 y);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s16 D_80126CB8;
extern s16 D_80126CB4;
extern s32 func_8004CFEC(s32 a0, s32 a1);

s32 func_8012B864(s32 a0) {
    s32 dx = *(s16*)(a0 + 0xE) - D_80126CB8;
    s32 dy = D_80126CB4 - *(s16*)(a0 + 0x6);
    return (func_8004CFEC(dx, dy) - 0x400) & 0xFFF;
}
