/* sc01_0077: func_8017F460 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern u16 D_80126B66;
extern void func_8012A568(void (*a0)(void));
extern u16 D_80126B66;
extern u16 D_80126B66;
extern u16 D_80126B66;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 D_801270D4;
extern u16 D_80126B66;
extern void func_8002D4C8(int, int);
extern int D_801270CC;
extern int D_801270D4;
extern u16 D_80126B66;
extern s32 D_801270CC;
extern s32 D_801270D4;
extern short D_8018A8FC[];
extern int D_8018A8F8;
extern u16 D_80126B66;
extern void func_8017F5BC(int param_1);
extern void func_8002D4C8(s32 a0, s32 a1);
void func_8017F5BC(int param_1);

void func_8017F460(int param_1)
{
    int iVar1;
    if (*(unsigned char *)(param_1 + 0x70) == 4) {
        s32 *pCC = &D_801270CC;
        if (*pCC == 0 && (*(unsigned short *)(param_1 + 0x5c) & 1) != 0) {
            if (D_801270D4 == 0) {
                D_801270D4 = 1;
            }
            *pCC = 3;
            *(unsigned short *)(param_1 + 0x5c) = 0;
        }
        if (1 < D_801270CC) {
            if ((*(unsigned short *)(param_1 + 0x5c) & 1) != 0 && D_801270D4 == 0) {
                D_801270D4 = 1;
            }
            if (D_8018A8FC[(int)((unsigned int)*(unsigned short *)(param_1 + 0x70) << 0x10) >> 0x18] <= D_801270D4) {
                func_8017F5BC(param_1);
                func_8002D4C8(0x495, 0);
            }
        }
    } else {
        iVar1 = (int)(s16)D_80126B66 - (int)*(short *)(param_1 + 0xe);
        if (iVar1 < 0) {
            iVar1 = -iVar1;
        }
        if (iVar1 < D_8018A8F8) {
            func_8017F5BC(param_1);
        }
    }
}
