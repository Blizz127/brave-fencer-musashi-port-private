/* sc01_0077: func_801803B0 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern M2C_UNK D_80186E48;
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
extern void func_8012B200(u8 *a0);
extern void func_8012A828(int, void *);
extern unsigned char D_801D0B94[];
extern M2C_UNK D_80186E48;
extern unsigned char D_8018A884[];

void func_801803B0(int param_1)
{
    int iVar1;
    iVar1 = ((int (*)(void))func_8012C1B8)();
    *(int *)(param_1 + 0x20) = iVar1;
    if (iVar1 == 0) {
        ((void (*)(int))func_8012CAE4)(param_1);
    } else {
        ((int (*)(int, void *))func_8001C214)(iVar1, D_801D0B94);
        func_8001D0E8(*(int *)(param_1 + 0x20), 0xDC, 0xB8);
        func_8012B2CC(param_1);
        *(int *)(param_1 + 0x58) = (int)D_8018A884 | 0x40000000;
        *(unsigned char *)(param_1 + 0x75) = 0;
        *(int *)(param_1 + 0x1c) = 0x80;
        *(unsigned short *)(param_1 + 0x5c) = *(unsigned short *)(param_1 + 0x5c) | 0xD010;
        ((void (*)(int))func_8012B200)(param_1);
        func_8012A828(param_1, ((unsigned char *)&D_80186E48));
        *(short *)(param_1 + 2) = 1;
        *(short *)(param_1 + 0x84) = 0x10;
        *(short *)(param_1 + 0xDC) = *(short *)(param_1 + 6);
        *(short *)(param_1 + 0xDE) = *(short *)(param_1 + 0xE);
    }
}
