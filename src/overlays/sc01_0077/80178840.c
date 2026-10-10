/* sc01_0077: func_80178840 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
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
extern int D_8018A360;
extern int D_8018A36C[];

void func_80178840(int param_1) {
    register int p __asm__("$16");
    int s1byte;
    p = param_1;
    if ((*(unsigned short *)(p + 0x5c) & 1) != 0) {
        s1byte = *(unsigned char *)(p + 0x5e);
        if (s1byte == 0xc) {
            ((void (*)(int))func_80019064)((int)&D_8018A360);
        }
        ((void (*)(int, int))func_80131E00)(p, D_8018A36C[s1byte]);
    }
}
