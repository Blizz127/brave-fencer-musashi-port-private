/* sc03_0098: func_8014292C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80140608.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
extern u16 D_801270C0;
extern u16 D_801270C0;
extern u16 D_801270C0;
extern void (*D_80186784[])();

void func_8014292C(int param_1)
{
    if (*(s16 *)&D_801270C0 != 3) {
        D_80186784[*(u16 *)(param_1 + 2)]();
    }
}
