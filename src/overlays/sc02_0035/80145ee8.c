/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80145EE8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32 arg);
extern void func_80146014(s32 a0);
extern unsigned char D_80185E90[];
extern unsigned char D_80185EC0[];
extern unsigned char D_80185F10[];
extern unsigned char D_80185F40[];
extern unsigned char D_80185F70[];

void func_80145EE8(s32 param_1)
{
    switch (param_1) {
    case 0:
        if (((unsigned char (*)(int))func_80029178)(0x1F) != 0) {
            ((void (*)(void *))func_80146014)(D_80185E90);
        }
        if (((unsigned char (*)(int))func_80029178)(0x21) != 0) {
            ((void (*)(void *))func_80146014)(D_80185EC0);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1E) != 0) {
            ((void (*)(void *))func_80146014)(D_80185F10);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1D) != 0) {
            ((void (*)(void *))func_80146014)(D_80185F40);
        }
        if (((unsigned char (*)(int))func_80029178)(0x20) == 0) {
            return;
        }
        ((void (*)(void *))func_80146014)(D_80185F70);
        break;
    case 1:
        ((void (*)(void *))func_80146014)(D_80185E90);
        ((void (*)(void *))func_80146014)(D_80185EC0);
        ((void (*)(void *))func_80146014)(D_80185F10);
        ((void (*)(void *))func_80146014)(D_80185F40);
        ((void (*)(void *))func_80146014)(D_80185F70);
        break;
    }
}
