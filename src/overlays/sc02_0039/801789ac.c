/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801789AC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801399F0(s32);
extern s32 func_801399F0(s32 a0);
extern void func_8017BC38(int a0);
extern void func_8017A4AC(void);
extern void func_8017AE2C(s32 a0);
extern void func_80178CBC(s32 a0, s32 a1);
extern short D_801A0DFC;
extern s32 D_801A0BE8;
extern s32 D_801A0CA4;
extern s32 D_801A07D4;
extern s32 D_801A0C14;
extern s32 D_801A07D0;

s32 func_801789AC(s32 arg0)
{
    s32 ret;

    func_8017BC38(arg0);
    func_8017A4AC();
    func_8017AE2C(arg0);

    switch ((s16)(D_801A0DFC - 1)) {
    case 0:
        ret = func_801399F0(D_801A0BE8);
        D_801A0CA4 = ret;
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_801A07D0);
        break;
    case 1:
        ret = func_801399F0(D_801A0BE8);
        D_801A0CA4 = ret;
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_801A07D0);
        break;
    case 2:
        func_80178CBC(arg0, D_801A07D0);
        break;
    case 3:
        if (--D_801A07D4 > 0) {
            break;
        }
        func_80178CBC(arg0, D_801A07D0);
        break;
    case 4:
        ret = ((s32 (*)(s32))D_801A0C14)(arg0);
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_801A07D0);
        break;
    case 5:
        switch (D_801A0CA4) {
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
