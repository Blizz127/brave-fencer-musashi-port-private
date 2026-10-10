/* sc01_0077: func_80183C50 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183BAC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern s32 D_801270CC;
extern int func_8012BEE8(int a0);
extern void func_8012AD80(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C098(void);
extern void func_8012C218(void *a0);
extern s32 D_801270CC;
extern void func_8012AD80(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C098(void);
extern void func_8012C218(void *a0);
extern s32 D_801270CC;

void func_80183C50(s32 param_1) {
    ((s32 (*)(s32))func_8012AD80)(param_1);
    if (func_8012BEE8(param_1) == 0) {
        return;
    }
    switch ((s32)((u32)*(u16 *)(param_1 + 0x70) << 0x10) >> 0x18) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
        ((s32 (*)(s32))func_8012C098)(param_1);
        return;
    case 3:
    case 7:
        ((s32 (*)(s32))func_8012C218)(param_1);
        return;
    case 4:
        D_801270CC = D_801270CC + -1;
        ((s32 (*)(s32))func_8012C218)(param_1);
        return;
    default:
        return;
    }
}
