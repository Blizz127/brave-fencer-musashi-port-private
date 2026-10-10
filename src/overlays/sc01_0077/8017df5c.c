/* sc01_0077: func_8017DF5C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8014706C(void *arg0);
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_8013767C(s32 a0);
extern void func_8014706C(void *a0);
extern s32 func_80171B4C(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern u8 D_800D5A34[];
void func_8014706C(void *a0);
void func_80154274(s32 *a0, s32 a1);
extern s32 func_80171B4C(s32 a0, s32 a1);
extern s32 func_800CF854(void); /* main_0010: reads D_800AE6BF only */
extern s32 func_8013767C(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_8014706C(void *arg0);
extern u8 D_800D5A34[];

void func_8017DF5C(int param_1)
{
    char cVar1;
    if (func_80171B4C(param_1, 0x1E) != 0) {
        if (func_800CF854() != 0) {
            cVar1 = 4;
        } else {
            *(int *)(param_1 + 0x198) = func_8013767C(*(int *)(param_1 + 0x198));
            ((int (*)(int, int))func_80154274)(param_1, (int)&D_800D5A34);
            ((int (*)(int))func_8014706C)(param_1);
            cVar1 = *(char *)(param_1 + 0x214) + 1;
            *(short *)(param_1 + 0x20c) = 0;
        }
        *(char *)(param_1 + 0x214) = cVar1;
    }
}
