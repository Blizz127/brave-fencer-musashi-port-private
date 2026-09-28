/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015E698 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern int func_80161208();
extern s32 func_80161208();
extern void func_80159BE4(s32);
extern void func_80159BE4(s32 arg0);
extern void func_80159BE4(s32 a0);
extern void (*D_80180378[])(void *);
extern void (*D_80180378[])(void*);
extern void func_80147078(s32*, s16);

void func_8015E698(u16 *param_1)
{
    if (func_80161208() == 0 && (param_1[0x5c] & 0x8000) != 0) {
        ((void (**)(u16*))D_80180378)[param_1[0]](param_1);
        ((void (*)(u16 *, s32))func_80147078)(param_1, 0);
        ((void (*)(u16 *))func_80159BE4)(param_1);
    }
}
