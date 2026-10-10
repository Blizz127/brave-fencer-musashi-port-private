/* sc01_0077: func_8017DFD8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_80147060(u8 * a0);
extern void func_80139914(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_801399F0(s32);
extern void func_80139914(s32);
extern s32 func_801399F0(s32 a0);
extern s32 func_8016F410(s32 a0);
extern void func_80147060(u8 *a0);
extern void func_8012A568(void (*a0)(void));
void func_80154274(s32 *a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_8016F410(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_801399F0(s32 a0);
extern void func_80139914(s32 a0);
extern void func_80147060(u8 *a0);
extern unsigned char D_8018A62C[];
extern unsigned char D_8018A69C[];
extern unsigned char D_8018A6E4[];

void func_8017DFD8(int param_1) {
    if (func_8016F410(0) != 0) {
        ((void (*)(int, void *))func_80154274)(param_1, &D_8018A62C);
    }
    if (func_8016F410(1) != 0) {
        ((void (*)(int, void *))func_80154274)(param_1, &D_8018A69C);
        *(short *)(param_1 + 0x20c) = 1;
    }
    if (*(short *)(param_1 + 0x20c) == 1 && (*(unsigned short *)(param_1 + 0xb8) & 0x8000) != 0) {
        *(short *)(param_1 + 0x20c) = 2;
        ((void (*)(int, void *))func_80154274)(param_1, &D_8018A6E4);
    }
    if (func_801399F0(*(int *)(param_1 + 0x198)) != 0) {
        func_80139914(*(int *)(param_1 + 0x198));
        ((void (*)(int))func_80147060)(param_1);
        *(char *)(param_1 + 0x214) = *(char *)(param_1 + 0x214) + 1;
    }
}
