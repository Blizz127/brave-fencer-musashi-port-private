/* sc01_0077: func_8014680C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
typedef struct Rec801466F0 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Rec801466F0;
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 D_8011F9D0;
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3,
                          s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern u16 *func_80146750(u16 *param_1);
extern u16 *func_8014680C(short *param_1);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8)
    __asm__("func_801466F0");
void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern int D_8011FA1C;
extern unsigned short D_8011F9D6;
extern unsigned short D_8011F9DA;
extern unsigned short D_8011F9DE;
extern int D_8011FA20;
extern int D_8011FA24;
unsigned short *func_80146750(unsigned short *a0);
extern s32 D_8011F9D0;
extern unsigned short D_8011F9D6;
extern unsigned short D_8011F9DA;
extern unsigned short D_8011F9DE;
extern int D_8011FA1C;
extern int D_8011FA20;
extern int D_8011FA24;

unsigned short *func_8014680C(short *param_1)
{
    int iVar1, iVar2;
    unsigned short *psVar3;
    register unsigned short *psVar4 __asm__("$7");
    iVar2 = 0;
    psVar4 = (unsigned short *)&(*(unsigned short *)&D_8011F9D0);
    psVar3 = psVar4;
    iVar1 = 0;
    for (; iVar2 < 8;
         psVar4 = psVar4 + 0x34, psVar3 = psVar3 + 0x34, iVar2 = iVar2 + 1, iVar1 = iVar1 + 0x68) {
        if (*psVar3 == 0) {
            *(int *)((char *)&D_8011FA1C + iVar1) = *(int *)(param_1 + 4);
            *psVar3 = *param_1;
            *(short *)((char *)&D_8011F9D6 + iVar1) = param_1[1];
            *(short *)((char *)&D_8011F9DA + iVar1) = param_1[2];
            *(short *)((char *)&D_8011F9DE + iVar1) = param_1[3];
            *(int *)((char *)&D_8011FA20 + iVar1) = *(int *)(param_1 + 6);
            *(int *)((char *)&D_8011FA24 + iVar1) = *(int *)(param_1 + 8);
            return psVar4;
        }
    }
    return (unsigned short *)0;
}
