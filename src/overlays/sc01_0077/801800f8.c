/* sc01_0077: func_801800F8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern int func_8005C49C(void);
extern int func_8005C49C(void);
extern s32 func_8005C49C(void);
s32 func_8005C49C();
extern int func_8005C49C(void);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8005C49C(void);
extern u8 D_8018A940[];
extern u8 D_8018A942[];
extern u8 D_8018A944[];
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A828(s32, void *);
extern int func_8005C49C(void);
extern void *D_801D20B4;
extern u8 D_8018A800[];
extern u8 D_8018A940[];
extern u8 D_8018A942[];
extern u8 D_8018A944[];

void func_801800F8(int param_1) {
    int iVar3;
    int arg;
    u16 tmp;
    int sp10[4];
    iVar3 = ((s32 (*)(void))func_8012C1B8)();
    arg = iVar3;
    *(int *)(param_1 + 0x20) = iVar3;
    if (iVar3 == 0) {
        ((void (*)(s32))func_8012CAE4)(param_1);
    } else {
        ((void (*)(s32, void *))func_8001C214)(arg, &D_801D20B4);
        func_8012A828(param_1, D_8018A800);
        *(u8 *)(param_1 + 0x100) = *(u8 *)(param_1 + 0x70) & 1;
        *(u16 *)(param_1 + 0xfe) = func_8005C49C() & 0x3f;
        *(u16 *)(param_1 + 0xfc) = func_8005C49C() & 0x3f;
        *(u16 *)(param_1 + 6) = *(u16 *)(D_8018A940 +
            ((int)((u32)*(u16 *)(param_1 + 0x70) << 16) >> 24) * 0x10 +
            *(u8 *)(param_1 + 0x100) * 8);
        *(u16 *)(param_1 + 0xa) = *(u16 *)(D_8018A942 +
            ((int)((u32)*(u16 *)(param_1 + 0x70) << 16) >> 24) * 0x10 +
            *(u8 *)(param_1 + 0x100) * 8);
        tmp = *(u16 *)(D_8018A944 +
            ((int)((u32)*(u16 *)(param_1 + 0x70) << 16) >> 24) * 0x10 +
            *(u8 *)(param_1 + 0x100) * 8);
        *(u16 *)(param_1 + 2) = 1;
        *(int *)(param_1 + 0x1c) = 0x1e;
        *(u16 *)(param_1 + 0xe) = tmp;
    }
}
