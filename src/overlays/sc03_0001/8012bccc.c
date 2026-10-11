/* sc03_0001: func_8012BCCC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 D_80126B58;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_80126B58;
extern s32 func_80013478(s32 a0, s32 a1);
extern s32 func_80013478(s32 a0, s32 a1);
extern s16 D_80126CBA;
extern s32 D_80126B58;

s32 func_8012BCCC(s32 a0) {
    s32 *p = &D_80126B58;
    if (D_80126CBA != 0) {
        return 0x7FFFFFFF;
    }
    return func_80013478(a0 + 4, (s32)p + 0x15C);
}
