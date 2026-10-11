/* sc03_0001: func_8016DA30 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
extern void func_8016DBD8(u8 *a0);
extern void (*D_80190808[])(int);
void func_8016DBD8(u8 *a0);

void func_8016DA30(int param_1)
{
    ((void (*)(void))func_8016DBD8)();
    D_80190808[*(unsigned short *)(param_1 + 2)](param_1);
}
