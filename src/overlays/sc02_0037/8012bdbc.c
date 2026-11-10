/* sc02_0037: func_8012BDBC from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 x, s32 y);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s16 D_80126CB8;
extern s16 D_80126CB4;
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s16 D_80126CB8;
extern s16 D_80126CB4;
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s16 D_80126CB4;
extern s16 D_80126CB8;
extern s16 D_80126CB4;
extern s32 func_8004CFEC(s32 a0, s32 a1);

s32 func_8012BDBC(s32 a0, s32 a1) {
    s32 s0 = a0;
    s32 v0;
    s32 angle;
    v0 = func_8004CFEC(*(s16 *)(s0 + 0xE) - D_80126CB8, D_80126CB4 - *(s16 *)(s0 + 0x6));
    v0 = (v0 - 0x400) & 0xFFF;
    v0 = v0 - *(s16 *)(*(s32 *)(s0 + 0x20) + 0x12);
    angle = v0 & 0xFFF;
    if (angle < 0x800) {
        return angle < (s16)a1;
    }
    return (0x1000 - angle) < (s16)a1;
}
