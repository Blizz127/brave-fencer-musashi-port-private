/* sc01_0077: func_80182FD0 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80182E7C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
extern void func_8012A568(void (*a0)(void));
extern void func_80130740(void *a0, u16 *a1);
extern unsigned char D_8018AB8C[];

void func_80182FD0(int param)
{
    ((int (*)(int, void *))func_80130740)(param, &D_8018AB8C);
    *(int *)(param + 0x1c) = 0x1e;
    *(int *)(param + 0x18) = 0;
    *(int *)(param + 0x10) = 0;
    *(short *)(param + 0x2) = 0xf;
    *(short *)(param + 0x5c) = 0;
}
