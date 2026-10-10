/* sc01_0077: func_8017DA44 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef signed char s8;
typedef short s16;
typedef int s32;
extern s32 *D_80126B78;
extern void func_8012A568(void (*a0)(void));
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_8017DAEC(s32);
extern s32 *D_80126B78;
s32 func_8017DAEC(s32 param_1);

void func_8017DA44(void *arg0) {
    s32 var_v0;
    s32 var_v0_2;
    var_v0 = -func_8004787C((*(s16 *)((s8 *)(D_80126B78) + (0x12))));
    if (var_v0 < 0) {
        var_v0 += 0x3F;
    }
    (*(s16 *)((s8 *)(arg0) + (0x2E))) = (s16) (var_v0 >> 6);
    var_v0_2 = -func_80047948((*(s16 *)((s8 *)(D_80126B78) + (0x12))));
    if (var_v0_2 < 0) {
        var_v0_2 += 0x1F;
    }
    (*(s16 *)((s8 *)(arg0) + (0x32))) = (s16) (var_v0_2 >> 5);
    func_8017DAEC(arg0);
}
