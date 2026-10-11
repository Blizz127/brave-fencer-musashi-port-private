/* sc03_0001: func_80156A1C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern void func_80147324(s32 a0);
extern unsigned char D_8011520C[];
extern unsigned short D_8018F7E0[];
extern void func_80147324(s32 arg0);

void func_80156A1C(s32 param_1, s32 param_2)
{
    if (*(unsigned char *)(param_1 + 0xDA) == 0) {
        func_80147324(D_8018F7E0[D_8011520C[param_2]]);
        *(unsigned char *)(param_1 + 0xDA) = *(unsigned char *)(param_1 + 0xDA) + 1;
    }
}
