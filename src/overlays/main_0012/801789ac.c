/* Overlay range [801789AC,80178B18) from MAIN.CD member 0012.
 * SHA256(span)=843a4b33199e922756a9fa34d060c0d0b6592e6dd3a6a827f86aeee91ca3720f.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801789AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern void func_8017BC38(int a0);
extern void func_8017A4AC(void);
extern void func_8017AE2C(s32 a0);
extern s32 func_801399F0(s32 a0);
extern void func_80178CBC(s32 a0, s32 a1);

extern short D_80185C7C;
extern s32 D_80185350;
extern s32 D_80185B24;
extern s32 D_80184F3C;
extern s32 D_8018537C;
extern s32 D_80184F38;

s32 func_801789AC(s32 arg0)
{
    s32 ret;

    func_8017BC38(arg0);
    func_8017A4AC();
    func_8017AE2C(arg0);

    switch ((s16)(D_80185C7C - 1)) {
    case 0:
        ret = func_801399F0(D_80185350);
        D_80185B24 = ret;
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_80184F38);
        break;
    case 1:
        ret = func_801399F0(D_80185350);
        D_80185B24 = ret;
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_80184F38);
        break;
    case 2:
        func_80178CBC(arg0, D_80184F38);
        break;
    case 3:
        if (--D_80184F3C > 0) {
            break;
        }
        func_80178CBC(arg0, D_80184F38);
        break;
    case 4:
        ret = ((s32 (*)(s32))D_8018537C)(arg0);
        if (ret == 0) {
            break;
        }
        func_80178CBC(arg0, D_80184F38);
        break;
    case 5:
        switch (D_80185B24) {
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
