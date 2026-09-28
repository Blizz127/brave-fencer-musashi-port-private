/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801609B8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 func_801487F4(s32 *a0);
extern int func_80161208();
extern s32 func_80161208();
extern void (*D_80180378[])(void *);
extern void (*D_80180378[])(void*);
extern u16 func_801487F4(s32*);
extern s32 func_80161208(void);
extern u16  func_801487F4(s32 *a0);
extern s32  func_80161208();
extern void func_80160A74(s32 *a0);

void func_801609B8(u16 *param_1) {
    if ((((u32 (*)(void))func_801487F4)() & 8) == 0) {
        ((void (**)(u16*))D_80180378)[*param_1](param_1);
        ((void (*)(u16 *))func_80160A74)(param_1);
    } else {
        ((void (*)(u16 *))func_80161208)(param_1);
    }
}
