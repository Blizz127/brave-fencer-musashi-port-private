/* sc01_0077: func_8012B0B4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern int func_80047948(int a0);
extern int func_8004787C(int a0);

void func_8012B0B4(unsigned int *param_1, int param_2, int param_3)
{
    int iVar1, iVar2;
    int prod;
    unsigned int *p;
    int sh1;
    register int sh2 __asm__("$3");
    unsigned int uVar3, result;
    uVar3 = (param_2 - 0x400U) & 0xfff;
    iVar1 = func_80047948(uVar3);
    result &= 0xFFFF0000;
    prod = iVar1 * param_3;
    sh1 = prod >> 0xc;
    result |= sh1 & 0xFFFF;
    iVar2 = func_8004787C(uVar3);
    prod = iVar2 * -param_3;
    result &= 0xFFFF;
    __asm__ ("addu %0,%1,$zero" : "=r"(p) : "r"(param_1));
    sh2 = prod >> 0xc;
    result |= sh2 << 0x10;
    *p = result;
}
