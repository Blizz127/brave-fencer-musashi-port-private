/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80160920 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef void (*code)(unsigned short *);
extern void func_80146CA0(void *a0);
extern u16 func_801487F4(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern int func_80161208();
extern s32 func_80161208();
extern void (*D_80181798[])(void *);
extern void (*D_80181798[])(void*);
extern void func_80154150(int, int);
extern void func_80154150(s32, s32);
extern u16 func_801487F4(s32*);
extern s32 func_80161208(void);
extern u16  func_801487F4(s32 *a0);
extern s32  func_80161208();
extern void func_80160A74(s32 *a0);

void func_80160920(unsigned short *param_1)
{
    if ((((int (*)(void))func_801487F4)() & 8) == 0) {
        ((code *)D_80181798)[*param_1](param_1);
        ((void (*)(unsigned short *))func_80160A74)(param_1);
    } else {
        if (((int (*)(unsigned short *))func_80161208)(param_1) == 0 && param_1[0x5c] == 0x8000) {
            ((void (*)(unsigned short *, int))func_80154150)(param_1, 0x25);
            ((void (*)(unsigned short *))func_80146CA0)(param_1);
        }
    }
    return;
}
