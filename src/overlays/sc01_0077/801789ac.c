/* sc01_0077: func_801789AC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801789AC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 func_801399F0(s32);
extern s32 func_801399F0(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern void func_8017BC38(int a0);
extern void func_8017A4AC(void);
extern void func_8017AE2C(s32 a0);
extern s32 func_801399F0(s32 a0);
extern void func_80178CBC(s32 a0, s32 a1);
extern short D_801DAB2C;
extern s32 D_801DA720;
extern s32 D_801DA9B0;
extern s32 D_801DA30C;
extern s32 D_801DA74C;
extern s32 D_801DA308;
void func_80178CBC(s32 arg0, s32 arg1);

s32 func_801789AC(s32 arg0)
{
    s32 ret;
    func_8017BC38(arg0);
    func_8017A4AC();
    func_8017AE2C(arg0);
    switch ((s16)(D_801DAB2C - 1)) {
    case 0:
        ret = func_801399F0(D_801DA720);
        D_801DA9B0 = ret;
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_801DA308);
        break;
    case 1:
        ret = func_801399F0(D_801DA720);
        D_801DA9B0 = ret;
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_801DA308);
        break;
    case 2:
        func_80178CBC(arg0, D_801DA308);
        break;
    case 3:
        if (--D_801DA30C > 0) {
            break;
        }
        func_80178CBC(arg0, D_801DA308);
        break;
    case 4:
        ret = ((s32 (*)(s32))D_801DA74C)(arg0);
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_801DA308);
        break;
    case 5:
        switch (D_801DA9B0) {
        case -1:
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        }
        break;
    }
    return 0;
}
