/* sc03_0098: func_801789AC from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801789AC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
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
extern short D_801C58B4;
extern s32 D_801C5428;
extern s32 D_801C575C;
extern s32 D_801C5014;
extern s32 D_801C5454;
extern s32 D_801C5010;
void func_80178CBC(s32 arg0, s32 arg1);

s32 func_801789AC(s32 arg0)
{
    s32 ret;
    func_8017BC38(arg0);
    func_8017A4AC();
    func_8017AE2C(arg0);
    switch ((s16)(D_801C58B4 - 1)) {
    case 0:
        ret = func_801399F0(D_801C5428);
        D_801C575C = ret;
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_801C5010);
        break;
    case 1:
        ret = func_801399F0(D_801C5428);
        D_801C575C = ret;
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_801C5010);
        break;
    case 2:
        func_80178CBC(arg0, D_801C5010);
        break;
    case 3:
        if (--D_801C5014 > 0) {
            break;
        }
        func_80178CBC(arg0, D_801C5010);
        break;
    case 4:
        ret = ((s32 (*)(s32))D_801C5454)(arg0);
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_801C5010);
        break;
    case 5:
        switch (D_801C575C) {
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
