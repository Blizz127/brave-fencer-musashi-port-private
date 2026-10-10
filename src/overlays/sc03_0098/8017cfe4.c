/* sc03_0098: func_8017CFE4 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_8017D030(int);
extern void func_8017D030(int);
extern void func_8017D030(int);
extern void func_8017D030(int);
extern void func_80146C3C(void);
void func_8017D030(int param_1);

void func_8017CFE4(int param_1)
{
    unsigned short uVar1;
    uVar1 = *(unsigned short *)(param_1 + 0x12) - 0x100;
    *(unsigned short *)(param_1 + 0x12) = uVar1;
    if ((short)uVar1 > 0) {
        func_8017D030(param_1);
    } else {
        ((void (*)(int))func_80146C3C)(param_1);
    }
}
