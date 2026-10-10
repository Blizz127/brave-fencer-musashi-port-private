/* sc03_0098: func_8017F0D8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef int s32;
typedef void (*code_fn)(void);
extern void func_8012A568(void (*a0)(void));
extern code_fn D_80199DE4[];
extern s32 func_8012DFD4(s32 a0);

void func_8017F0D8(int param_1)
{
    D_80199DE4[*(unsigned short *)(param_1 + 2)]();
    ((void (*)(int))func_8012DFD4)(param_1);
    return;
}
