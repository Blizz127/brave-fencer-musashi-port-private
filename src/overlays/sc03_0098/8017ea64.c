/* sc03_0098: func_8017EA64 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8016EE40(s32 a0, s32 a1, s32 a2);
extern void func_8016EE40(s32 _arg0, s32 _arg1, s32 _arg2);
extern void func_8012A568(void (*a0)(void));
extern void func_8016EE40(s32 a0, s32 a1, s32 a2);

void func_8017EA64(void) {
    extern s32 D_80188F64(void *a0);
    ((void (*)(void *, s32))func_8016EE40)((void *)D_80188F64, 0x1000000);
}
