/* sc01_0077: func_8017E3EC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80139914(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_801399F0(s32);
extern void func_80139914(s32);
extern s32 func_801399F0(s32 a0);
extern void func_8012A568(void (*a0)(void));
void func_80154274(s32 *a0, s32 a1);
extern s32 D_8012695C;
extern s32 D_8012695C;
extern s32 D_8012695C;
extern s32 D_8012695C;
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_801399F0(s32 a0);
extern void func_80139914(s32 a0);
extern s32 D_8012695C;
extern void func_80154274(s32 *a0, s32 a1);
extern s32 D_8012695C;
extern s32 func_801399F0(s32 a0);
extern void func_80139914(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern s32 D_8018A5E4;
extern s32 D_8012695C;

void func_8017E3EC(s32 param_1)
{
    if (func_801399F0(*(s32 *)(param_1 + 0x198)) != 0) {
        ((s32 (*)(s32))func_80139914)(*(s32 *)(param_1 + 0x198));
        ((s32 (*)(s32, s32))func_80154274)(param_1, (s32)&D_8018A5E4);
        D_8012695C = *(s32 *)(param_1 + 0x208);
        *(s32 *)(param_1 + 0x204) = 0x20;
        *(unsigned char *)(param_1 + 0x214) = *(unsigned char *)(param_1 + 0x214) + 1;
    }
}
