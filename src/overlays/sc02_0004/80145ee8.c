/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80145EE8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32 arg);
extern void func_80146014(s32 a0);
extern unsigned char D_8017F69C[];
extern unsigned char D_8017F6CC[];
extern unsigned char D_8017F71C[];
extern unsigned char D_8017F74C[];
extern unsigned char D_8017F77C[];

void func_80145EE8(s32 param_1)
{
    switch (param_1) {
    case 0:
        if (((unsigned char (*)(int))func_80029178)(0x1F) != 0) {
            ((void (*)(void *))func_80146014)(D_8017F69C);
        }
        if (((unsigned char (*)(int))func_80029178)(0x21) != 0) {
            ((void (*)(void *))func_80146014)(D_8017F6CC);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1E) != 0) {
            ((void (*)(void *))func_80146014)(D_8017F71C);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1D) != 0) {
            ((void (*)(void *))func_80146014)(D_8017F74C);
        }
        if (((unsigned char (*)(int))func_80029178)(0x20) == 0) {
            return;
        }
        ((void (*)(void *))func_80146014)(D_8017F77C);
        break;
    case 1:
        ((void (*)(void *))func_80146014)(D_8017F69C);
        ((void (*)(void *))func_80146014)(D_8017F6CC);
        ((void (*)(void *))func_80146014)(D_8017F71C);
        ((void (*)(void *))func_80146014)(D_8017F74C);
        ((void (*)(void *))func_80146014)(D_8017F77C);
        break;
    }
}
