/* sc03_0098: func_8012C044 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
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
