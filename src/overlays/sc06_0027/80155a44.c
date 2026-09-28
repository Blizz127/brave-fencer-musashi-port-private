/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80155A44 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029178(s32 arg);
extern u8 func_8014BEF8(void);
extern u16 func_80148800(s32 *a0);
extern void func_80149CB4(void);

int func_80155A44(int param_1)
{
    int x = *(unsigned char *)(param_1 + 0x1AA);
    switch (x) {
    case 0:
    case 1:
        if ((((unsigned char (*)(int))func_80029178)(0x85) & 0xFF) &&
            ((int (*)(int))func_8014BEF8)(param_1) &&
            *(unsigned char *)(param_1 + 0x1C0) &&
            (((int (*)(int))func_80148800)(param_1) & 0x10)) {
            ((void (*)(int, int))func_80149CB4)(param_1, 2);
            return 1;
        }
        break;
    case 2:
        if ((((unsigned char (*)(int))func_80029178)(0x86) & 0xFF) &&
            (((int (*)(int))func_80148800)(param_1) & 0x10)) {
            ((void (*)(int, int))func_80149CB4)(param_1, 3);
            return 1;
        }
        break;
    }
}
