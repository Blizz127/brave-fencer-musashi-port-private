/* sc03_0001: func_801789AC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801789AC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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
extern short D_801EF464;
extern s32 D_801EE5E0;
extern s32 D_801EF2E0;
extern s32 D_801EE1CC;
extern s32 D_801EE60C;
extern s32 D_801EE1C8;
void func_80178CBC(s32 arg0, s32 arg1);

s32 func_801789AC(s32 arg0)
{
    s32 ret;
    func_8017BC38(arg0);
    func_8017A4AC();
    func_8017AE2C(arg0);
    switch ((s16)(D_801EF464 - 1)) {
    case 0:
        ret = func_801399F0(D_801EE5E0);
        D_801EF2E0 = ret;
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_801EE1C8);
        break;
    case 1:
        ret = func_801399F0(D_801EE5E0);
        D_801EF2E0 = ret;
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_801EE1C8);
        break;
    case 2:
        func_80178CBC(arg0, D_801EE1C8);
        break;
    case 3:
        if (--D_801EE1CC > 0) {
            break;
        }
        func_80178CBC(arg0, D_801EE1C8);
        break;
    case 4:
        ret = ((s32 (*)(s32))D_801EE60C)(arg0);
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_801EE1C8);
        break;
    case 5:
        switch (D_801EF2E0) {
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
