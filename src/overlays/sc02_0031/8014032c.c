/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014032C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern short D_80115128;
extern u8 D_80185D0C[];
extern u8 D_80185D24[];
extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);

s32 func_8014032C(s32 param_1, s32 param_2) {
    extern int (*D_80186054[])(void);
    extern int (*D_80186044[])(void);
    extern void * D_80185D60[];
    extern void * D_80185D90[];
    extern void * D_80185DA0[];
    extern void * D_80185D78[];
    extern u8 D_80185D30[];
    extern void * D_80185DB8[];
    extern void * D_80185DD0[];
    extern void * D_80185DE4[];
    extern u8 D_80185D37[];
    extern u8 * D_801B63B4;
    extern u8 D_801117EC[];
    extern u8 D_801117B4[];
    extern u8 D_80112BC8[];
    extern u8 D_80112B58[];
    extern u8 D_80112BA8[];
    extern u8 D_80112B90[];


    int cVar1;
    unsigned int uVar3;
    void *result;

    result = D_801117EC;
    switch (((short)param_1)) {
    case 0:
        if (((s32(*)(s32))func_80029178)(D_80185D0C[((short)param_2)]) & 0xFF) {
            result = D_80185D60[((short)param_2)];
        }
        break;
    case 1:
        result = D_80185D90[((short)param_2)];
        break;
    case 2:
        switch ((*(s16*)&D_80115128)) {
        case 0:
            if (D_80186054[((short)param_2)]() == 0) {
                ((short)param_2) = 5;
            } else if (D_80186044[((short)param_2)]() != 0) {
                ((short)param_2) = 4;
            }
            result = D_80185DA0[((short)param_2)];
            break;
        case 1:
            goto case5;
        case 2:
            if (((s32(*)(s32))func_80029178)(D_801B63B4[((short)param_2)]) & 0xFF) {
                if (((short)param_2) == 5 && (((s32(*)(s32))func_80029178)(0x1C) & 0xFF)) {
                    result = D_801117B4;
                } else {
                    result = D_80185D78[((short)param_2)];
                }
            }
            break;
        case 3:
            if (((s32(*)(s32))func_80029178)(D_80185D30[((short)param_2)]) & 0xFF) {
                result = D_80185DB8[((short)param_2)];
            }
            break;
        case 4:
            result = D_80185DD0[((short)param_2)];
            break;
        }
        break;
    case 5:
    case5:
        uVar3 = ((s32(*)(s32))func_800291B4)(D_80185D24[((short)param_2)]) & 0xFF;
        if (uVar3 != 0) {
            result = D_80185DE4[uVar3];
        }
        break;
    case 3:
        if (((short)param_2) != 0) {
            cVar1 = ((s32(*)(s32))func_800291B4)(D_80185D37[((short)param_2)]) & 0xFF;
            if (cVar1 == 0) {
                result = D_80112B58;
            } else {
                result = D_80112BA8;
                if (cVar1 == 1) {
                    result = D_80112B90;
                }
            }
        } else {
            result = D_80112BC8;
        }
        break;
    case 6:
    case 7:
    default:
        result = 0;
        break;
    }
    return result;
}
