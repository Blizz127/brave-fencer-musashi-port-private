/* sc03_0001: func_80142978 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80140608.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
extern u16 D_801270C0;
extern u16 D_801270C0;
extern u16 D_801270C0;
extern u16 D_801270C0;
extern void (*D_8018EB40[])();

void func_80142978(int param_1)
{
    if (*(s16 *)&D_801270C0 != 3) {
        D_8018EB40[*(u16 *)(param_1 + 2)]();
    }
}
