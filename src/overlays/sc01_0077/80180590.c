/* sc01_0077: func_80180590 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern M2C_UNK D_80186E48;
void func_8017F714_impl(int param_1) __asm__("func_8017F714");
void func_8017F714_impl(int param_1);
extern void func_8012B2CC(s32 a0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32, void *);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8001D0E8(int, int, int);
extern void func_8012B2CC(int);
extern void func_8012A828(int, void *);
extern M2C_UNK D_80186E48;
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8001D0E8(s32 a0, s32 a1, s32 a2);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B2CC(s32 a0);
extern int D_801D15C4;
extern int D_801D1CBC;
extern int D_8018A8A4;
extern int D_8018A8B4;
extern int D_8018A8C4;
extern M2C_UNK D_80186E48;

void func_80180590(int param_1)
{
    int iVar2;
    register unsigned int uVar3 __asm__("$2");
    int uVar5;
    int uVar6;
    unsigned short uVar1;
    iVar2 = ((int (*)(void))func_8012C1B8)();
    *(int *)(param_1 + 0x20) = iVar2;
    if (iVar2 == 0) {
        ((void (*)(int))func_8012CAE4)(param_1);
    } else {
        int ppuVar4;
        ppuVar4 = (int)&D_801D15C4;
        if (*(char *)(param_1 + 0x70) == 4) {
            ppuVar4 = (int)&D_801D1CBC;
        }
        ((void (*)(int, int))func_8001C214)(iVar2, ppuVar4);
        if (*(char *)(param_1 + 0x70) != 4) {
            uVar5 = 0x168;
            uVar3 = (int)&D_8018A8A4;
            uVar6 = 0x140;
        } else {
            uVar5 = 0x7fff;
            uVar6 = 0x7fff;
            uVar3 = (int)&D_8018A8B4;
        }
        *(unsigned int *)(param_1 + 0x58) = uVar3 | 0x40000000;
        func_8001D0E8(*(int *)(param_1 + 0x20), uVar5, uVar6);
        *(int *)(param_1 + 0x78) = (int)&D_8018A8C4;
        *(char *)(param_1 + 0x75) = 4;
        func_8012A828(param_1, &D_80186E48);
        *(short *)(param_1 + 2) = 1;
        if (*(char *)(param_1 + 0x70) == 4) {
            uVar1 = *(unsigned short *)(param_1 + 0x5c) | 0x8000;
        } else {
            uVar1 = 0xc800;
        }
        *(unsigned short *)(param_1 + 0x5c) = uVar1;
        __asm__ __volatile__("" ::: "memory");
        *(short *)(*(int *)(param_1 + 0x20) + 0x10) = 0;
        func_8012B2CC(param_1);
    }
}
