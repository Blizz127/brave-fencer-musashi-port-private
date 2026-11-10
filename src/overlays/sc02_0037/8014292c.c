/* sc02_0037: func_8014292C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8013F350.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
extern u16 D_801270C0;

void func_8014292C(int param_1)
{
    extern u16 D_801270C0;
    extern void (*D_80185070[])();
    if (*(s16 *)&D_801270C0 != 3) {
        D_80185070[*(u16 *)(param_1 + 2)]();
    }
}
