/* sc03_0001: func_80178840 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
struct S80131E00;
struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
extern void func_80019064(void *a0);
extern void func_8012A568(void (*a0)(void));
extern void func_80019064(void *a0);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);

void func_80178840(int param_1)
{
    extern int D_80190D50;
    extern int D_80190D5C[];
    int p;
    int s1byte;
    p = param_1;
    if (((*((unsigned short *) (p + 0x5c))) & 1) != 0)
    {
        s1byte = *((unsigned char *) (p + 0x5e));
        if (s1byte == 0xc)
        {
            ((void (*)(int)) func_80019064)((int) (&D_80190D50));
        }
        ((void (*)(int, int)) func_80131E00)(p, D_80190D5C[s1byte]);
        p = param_1;
    }
}
