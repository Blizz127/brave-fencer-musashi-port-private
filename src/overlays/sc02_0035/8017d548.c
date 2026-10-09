/* SC02.CD member35: func_8017D548 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef int s32;
typedef void (*code_fn)(void);
extern void func_8012A568(void (*a0)(void));
extern code_fn D_801949F0[];
extern s32 func_8012DFD4(s32 a0);

void func_8017D548(int param_1)
{
    D_801949F0[*(unsigned short *)(param_1 + 2)]();
    ((void (*)(int))func_8012DFD4)(param_1);
    return;
}
