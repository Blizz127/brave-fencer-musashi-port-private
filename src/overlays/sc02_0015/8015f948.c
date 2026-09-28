/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015F948 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C98(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern s32 func_80161104(void);
extern void func_80154A74(int, int);
extern void func_80154150(int, int);
extern void func_80154A74(s32, s32);
extern void func_80154150(s32, s32);
extern void func_80147078(s32*, s16);
extern void func_80147078(s32 *, s16);

void func_8015F948(s32 *param_1) {
    extern void func_80146C98(s32 *a0, s16 a1);
    extern void func_80147078(s32 *a0, s16 a1);
    extern void func_80154150(s32 a0, s32 a1);
    extern void func_80154A74(s32 a0, s32 a1);
    extern s32 func_80161104(void);
    func_80147078(param_1, 0x15);
    if (((s32 (*)(s32 *))func_80161104)(param_1) != 0) {
        func_80154150((s32)param_1, 0x22);
        func_80154A74((s32)param_1, 0x1A);
        func_80146C98(param_1, 2);
    }
}
