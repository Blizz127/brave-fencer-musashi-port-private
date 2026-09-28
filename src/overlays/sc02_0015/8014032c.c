/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014032C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32);
extern short D_80115128;
extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);
extern u8 D_8017F2E0[];
extern u8 D_8017F2F8[];

s32 func_8014032C(s32 param_1, s32 param_2) {
    extern int (*D_8017F628[])(void);
    extern int (*D_8017F618[])(void);
    extern void * D_8017F334[];
    extern void * D_8017F364[];
    extern void * D_8017F374[];
    extern void * D_8017F34C[];
    extern u8 D_8017F304[];
    extern void * D_8017F38C[];
    extern void * D_8017F3A4[];
    extern void * D_8017F3B8[];
    extern u8 D_8017F30B[];
    extern u8 * D_8018F13C;
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
        if (((s32(*)(s32))func_80029178)(D_8017F2E0[((short)param_2)]) & 0xFF) {
            result = D_8017F334[((short)param_2)];
        }
        break;
    case 1:
        result = D_8017F364[((short)param_2)];
        break;
    case 2:
        switch ((*(s16*)&D_80115128)) {
        case 0:
            if (D_8017F628[((short)param_2)]() == 0) {
                ((short)param_2) = 5;
            } else if (D_8017F618[((short)param_2)]() != 0) {
                ((short)param_2) = 4;
            }
            result = D_8017F374[((short)param_2)];
            break;
        case 1:
            goto case5;
        case 2:
            if (((s32(*)(s32))func_80029178)(D_8018F13C[((short)param_2)]) & 0xFF) {
                if (((short)param_2) == 5 && (((s32(*)(s32))func_80029178)(0x1C) & 0xFF)) {
                    result = D_801117B4;
                } else {
                    result = D_8017F34C[((short)param_2)];
                }
            }
            break;
        case 3:
            if (((s32(*)(s32))func_80029178)(D_8017F304[((short)param_2)]) & 0xFF) {
                result = D_8017F38C[((short)param_2)];
            }
            break;
        case 4:
            result = D_8017F3A4[((short)param_2)];
            break;
        }
        break;
    case 5:
    case5:
        uVar3 = ((s32(*)(s32))func_800291B4)(D_8017F2F8[((short)param_2)]) & 0xFF;
        if (uVar3 != 0) {
            result = D_8017F3B8[uVar3];
        }
        break;
    case 3:
        if (((short)param_2) != 0) {
            cVar1 = ((s32(*)(s32))func_800291B4)(D_8017F30B[((short)param_2)]) & 0xFF;
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
