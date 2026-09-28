/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014032C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32);
extern short D_80115128;
extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);
extern u8 D_80180198[];
extern u8 D_801801B0[];

s32 func_8014032C(s32 param_1, s32 param_2) {
    extern int (*D_801804E0[])(void);
    extern int (*D_801804D0[])(void);
    extern void * D_801801EC[];
    extern void * D_8018021C[];
    extern void * D_8018022C[];
    extern void * D_80180204[];
    extern u8 D_801801BC[];
    extern void * D_80180244[];
    extern void * D_8018025C[];
    extern void * D_80180270[];
    extern u8 D_801801C3[];
    extern u8 * D_8019FA94;
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
        if (((s32(*)(s32))func_80029178)(D_80180198[((short)param_2)]) & 0xFF) {
            result = D_801801EC[((short)param_2)];
        }
        break;
    case 1:
        result = D_8018021C[((short)param_2)];
        break;
    case 2:
        switch ((*(s16*)&D_80115128)) {
        case 0:
            if (D_801804E0[((short)param_2)]() == 0) {
                ((short)param_2) = 5;
            } else if (D_801804D0[((short)param_2)]() != 0) {
                ((short)param_2) = 4;
            }
            result = D_8018022C[((short)param_2)];
            break;
        case 1:
            goto case5;
        case 2:
            if (((s32(*)(s32))func_80029178)(D_8019FA94[((short)param_2)]) & 0xFF) {
                if (((short)param_2) == 5 && (((s32(*)(s32))func_80029178)(0x1C) & 0xFF)) {
                    result = D_801117B4;
                } else {
                    result = D_80180204[((short)param_2)];
                }
            }
            break;
        case 3:
            if (((s32(*)(s32))func_80029178)(D_801801BC[((short)param_2)]) & 0xFF) {
                result = D_80180244[((short)param_2)];
            }
            break;
        case 4:
            result = D_8018025C[((short)param_2)];
            break;
        }
        break;
    case 5:
    case5:
        uVar3 = ((s32(*)(s32))func_800291B4)(D_801801B0[((short)param_2)]) & 0xFF;
        if (uVar3 != 0) {
            result = D_80180270[uVar3];
        }
        break;
    case 3:
        if (((short)param_2) != 0) {
            cVar1 = ((s32(*)(s32))func_800291B4)(D_801801C3[((short)param_2)]) & 0xFF;
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
