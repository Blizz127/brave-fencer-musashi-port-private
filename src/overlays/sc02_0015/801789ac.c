/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801789AC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801399F0(s32);
extern s32 func_801399F0(s32 a0);
extern void func_8017BC38(int a0);
extern void func_8017A4AC(void);
extern void func_8017AE2C(s32 a0);
extern void func_80178CBC(s32 a0, s32 a1);
extern short D_8019069C;
extern s32 D_80190290;
extern s32 D_80190544;
extern s32 D_8018FE7C;
extern s32 D_801902BC;
extern s32 D_8018FE78;

s32 func_801789AC(s32 arg0)
{
    s32 ret;

    func_8017BC38(arg0);
    func_8017A4AC();
    func_8017AE2C(arg0);

    switch ((s16)(D_8019069C - 1)) {
    case 0:
        ret = func_801399F0(D_80190290);
        D_80190544 = ret;
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_8018FE78);
        break;
    case 1:
        ret = func_801399F0(D_80190290);
        D_80190544 = ret;
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_8018FE78);
        break;
    case 2:
        func_80178CBC(arg0, D_8018FE78);
        break;
    case 3:
        if (--D_8018FE7C > 0) {
            break;
        }
        func_80178CBC(arg0, D_8018FE78);
        break;
    case 4:
        ret = ((s32 (*)(s32))D_801902BC)(arg0);
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_8018FE78);
        break;
    case 5:
        switch (D_80190544) {
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
