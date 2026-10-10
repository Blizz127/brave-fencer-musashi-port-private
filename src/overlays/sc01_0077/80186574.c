/* sc01_0077: func_80186574 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
void func_80185E68(s32 arg0);
extern void func_80185E68();
extern void (*D_801D5624[])(int);

void func_80186574(int param_1)
{
    if (((unsigned int)(*(unsigned short *)(param_1 + 2) - 1) < 2) &&
        ((*(unsigned short *)(param_1 + 0x5c) & 1) != 0)) {
        ((void (*)())func_80185E68)();
    } else {
        D_801D5624[*(unsigned short *)(param_1 + 2)](param_1);
    }
}
