/* sc01_0077: func_80142A10 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
extern u16 D_801270C0;
extern u16 D_801270C0;
extern u16 D_801270C0;
extern u16 D_801270C0;
extern u16 D_801270C0;
extern void (*D_80188218[])(int);
extern void func_80142A80(void);
void func_80142A80(void);

void func_80142A10(int param_1)
{
    if (*(s16 *)&D_801270C0 != 3) {
        D_80188218[*(u16 *)(param_1 + 2)](param_1);
        if (*(s16 *)(param_1 + 0xFC) != 0) {
            ((void (*)(int))func_80142A80)(param_1);
        }
    }
}
