/* sc01_0077: func_801807B8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012B030(u8 *a0);
extern void func_8012A828(s32 a0, void *a1);
extern M2C_UNK D_80186E48;
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32, void *);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8001D0E8(int, int, int);
extern void func_8012A828(int, void *);
extern M2C_UNK D_80186E48;
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8001D0E8(s32 a0, s32 a1, s32 a2);
extern void func_8012A828(s32 a0, void *a1);
extern M2C_UNK D_80186E48;
extern s32 D_801270C8;
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8001D0E8(s32 a0, s32 a1, s32 a2);
extern s32 func_8012B030(u8 *a0);
extern void func_8012A828(s32 a0, void *a1);
extern int D_801D100C;
extern unsigned char D_8018A914[];
extern M2C_UNK D_80186E48;
extern s32 D_801270C8;

void func_801807B8(int param_1) {
    int iVar1;
    iVar1 = ((int (*)(void))func_8012C1B8)();
    *(int *)(param_1 + 0x20) = iVar1;
    if (iVar1 == 0) {
        ((void (*)(int))func_8012CAE4)(param_1);
    } else {
        ((int (*)(int, void *))func_8001C214)(iVar1, &D_801D100C);
        func_8001D0E8(*(int *)(param_1 + 0x20), 0x140, 0xF0);
        *(int *)(param_1 + 0x58) = (int)&D_8018A914 | 0x40000000;
        *(short *)(param_1 + 0x5C) = 0x800;
        ((int (*)(int))func_8012B030)(param_1);
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) - 0x200000;
        *(int *)(param_1 + 0xC) = *(int *)(param_1 + 0xC) - 0x200000;
        func_8012A828(param_1, &D_80186E48);
        *(short *)(param_1 + 2) = 1;
        *(short *)(*(int *)(param_1 + 0x20) + 0x10) = 0;
        *(short *)(*(int *)(param_1 + 0x20) + 0x12) = 0;
        *(short *)(*(int *)(param_1 + 0x20) + 0x14) = 0;
        D_801270C8 = 0;
    }
}
