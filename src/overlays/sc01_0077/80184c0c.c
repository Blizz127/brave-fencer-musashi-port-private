/* sc01_0077: func_80184C0C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012CAE4(void *a0);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012A828(int a0, void *a1);
extern void func_8012CAE4(void *a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern u8 D_8019731C;
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012CAE4(void *a0);
typedef struct { unsigned char b[0x34]; } S_8018AEB8;
extern S_8018AEB8 D_8018AEB8[];
extern unsigned char D_8018AF20[];
extern u8 D_8019731C;
extern s32 func_8012C354(s32 a0, s32 a1);
extern int func_8012C658(int, int, int);
extern void func_8012CAE4(void *a0);
extern void func_8012A828(int, void *);

void func_80184C0C(int param_1) {
    int iVar1;
    iVar1 = ((int (*)(int, void *))func_8012C354)(param_1, &D_8018AEB8[*(unsigned short *)(param_1 + 0x70) & 1]);
    if (iVar1 != 0) {
        *(unsigned char *)(param_1 + 0xc0) = 1;
        *(int *)(param_1 + 0xb4) = -1;
        *(void **)(param_1 + 0xbc) = D_8018AF20;
        *(int *)(param_1 + 0xc4) = 1;
        iVar1 = func_8012C658(0x79, *(unsigned short *)(param_1 + 0x70) & 1, param_1);
        *(int *)(param_1 + 0x6c) = iVar1;
        if (iVar1 == 0) {
            ((void (*)(int))func_8012CAE4)(param_1);
        } else {
            *(unsigned short *)(param_1 + 2) = 1;
            func_8012A828(param_1, ((unsigned char *)&D_8019731C));
        }
    }
    return;
}
