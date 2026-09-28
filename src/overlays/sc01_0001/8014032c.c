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
extern u8 D_801848F4[];
extern u8 D_8018490C[];
extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);

s32 func_8014032C(s32 param_1, s32 param_2) {
    extern int (*D_80184C3C[])(void);
    extern int (*D_80184C2C[])(void);
    extern void * D_80184948[];
    extern void * D_80184978[];
    extern void * D_80184988[];
    extern void * D_80184960[];
    extern u8 D_80184918[];
    extern void * D_801849A0[];
    extern void * D_801849B8[];
    extern void * D_801849CC[];
    extern u8 D_8018491F[];
    extern u8 * D_801EC7B4;
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
        if (((s32(*)(s32))func_80029178)(D_801848F4[((short)param_2)]) & 0xFF) {
            result = D_80184948[((short)param_2)];
        }
        break;
    case 1:
        result = D_80184978[((short)param_2)];
        break;
    case 2:
        switch ((*(s16*)&D_80115128)) {
        case 0:
            if (D_80184C3C[((short)param_2)]() == 0) {
                ((short)param_2) = 5;
            } else if (D_80184C2C[((short)param_2)]() != 0) {
                ((short)param_2) = 4;
            }
            result = D_80184988[((short)param_2)];
            break;
        case 1:
            goto case5;
        case 2:
            if (((s32(*)(s32))func_80029178)(D_801EC7B4[((short)param_2)]) & 0xFF) {
                if (((short)param_2) == 5 && (((s32(*)(s32))func_80029178)(0x1C) & 0xFF)) {
                    result = D_801117B4;
                } else {
                    result = D_80184960[((short)param_2)];
                }
            }
            break;
        case 3:
            if (((s32(*)(s32))func_80029178)(D_80184918[((short)param_2)]) & 0xFF) {
                result = D_801849A0[((short)param_2)];
            }
            break;
        case 4:
            result = D_801849B8[((short)param_2)];
            break;
        }
        break;
    case 5:
    case5:
        uVar3 = ((s32(*)(s32))func_800291B4)(D_8018490C[((short)param_2)]) & 0xFF;
        if (uVar3 != 0) {
            result = D_801849CC[uVar3];
        }
        break;
    case 3:
        if (((short)param_2) != 0) {
            cVar1 = ((s32(*)(s32))func_800291B4)(D_8018491F[((short)param_2)]) & 0xFF;
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
