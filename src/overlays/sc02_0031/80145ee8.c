/* SC02.CD member31 [80145EE8,80146014); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80145EE8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029178(s32 arg);
extern void func_80146014(s32 a0);
extern unsigned char D_80186630[];
extern unsigned char D_80186660[];
extern unsigned char D_801866B0[];
extern unsigned char D_801866E0[];
extern unsigned char D_80186710[];

void func_80145EE8(s32 param_1)
{
    switch (param_1) {
    case 0:
        if (((unsigned char (*)(int))func_80029178)(0x1F) != 0) {
            ((void (*)(void *))func_80146014)(D_80186630);
        }
        if (((unsigned char (*)(int))func_80029178)(0x21) != 0) {
            ((void (*)(void *))func_80146014)(D_80186660);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1E) != 0) {
            ((void (*)(void *))func_80146014)(D_801866B0);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1D) != 0) {
            ((void (*)(void *))func_80146014)(D_801866E0);
        }
        if (((unsigned char (*)(int))func_80029178)(0x20) == 0) {
            return;
        }
        ((void (*)(void *))func_80146014)(D_80186710);
        break;
    case 1:
        ((void (*)(void *))func_80146014)(D_80186630);
        ((void (*)(void *))func_80146014)(D_80186660);
        ((void (*)(void *))func_80146014)(D_801866B0);
        ((void (*)(void *))func_80146014)(D_801866E0);
        ((void (*)(void *))func_80146014)(D_80186710);
        break;
    }
}
