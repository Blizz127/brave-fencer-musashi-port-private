/* sc02_0037: func_8012C044 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 func_80013478(s32 a0, s32 a1);
extern s32 func_80013478(s32 a0, s32 a1);
extern s32 func_80013478(s32 a0, s32 a1);
extern s16 D_80126CAC;
extern s32 D_801274D4;
extern s16 D_80126CAC;
extern s32 D_801274E0;
extern s32 func_80013478(s32 a0, s32 a1);

s32 func_8012C044(s32 a0) {
    s32 (*fp)(void) = (s32 (*)(void))D_801274D4;
    if (fp != 0) {
        return fp();
    }
    return func_80013478(a0 + 4, (s32)&D_80126CAC) >= D_801274E0;
}
