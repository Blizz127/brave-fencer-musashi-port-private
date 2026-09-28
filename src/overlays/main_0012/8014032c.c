/* Overlay range [8014032C,80140608) from MAIN.CD member 0012.
 * SHA256(span)=eef0d8567d5bcc0a77ecb8d8ce621eb5988f7cd9e0d37a66d2c52656272e5495.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014032C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern short D_80115128;
extern u8 D_8017F41C[];
extern u8 D_8017F434[];
extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);




/* indexed data arrays (overlay) */


/* address-return symbols (main RAM) */

s32 func_8014032C(s32 param_1, s32 param_2) {
    extern int (*D_8017F764[])(void);
    extern int (*D_8017F754[])(void);
    extern void * D_8017F470[];
    extern void * D_8017F4A0[];
    extern void * D_8017F4B0[];
    extern void * D_8017F488[];
    extern u8 D_8017F440[];
    extern void * D_8017F4C8[];
    extern void * D_8017F4E0[];
    extern void * D_8017F4F4[];
    extern u8 D_8017F447[];
    extern u8 * D_801841FC;
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
        if (((s32(*)(s32))func_80029178)(D_8017F41C[((short)param_2)]) & 0xFF) {
            result = D_8017F470[((short)param_2)];
        }
        break;
    case 1:
        result = D_8017F4A0[((short)param_2)];
        break;
    case 2:
        switch ((*(s16*)&D_80115128)) {
        case 0:
            if (D_8017F764[((short)param_2)]() == 0) {
                ((short)param_2) = 5;
            } else if (D_8017F754[((short)param_2)]() != 0) {
                ((short)param_2) = 4;
            }
            result = D_8017F4B0[((short)param_2)];
            break;
        case 1:
            goto case5;
        case 2:
            if (((s32(*)(s32))func_80029178)(D_801841FC[((short)param_2)]) & 0xFF) {
                if (((short)param_2) == 5 && (((s32(*)(s32))func_80029178)(0x1C) & 0xFF)) {
                    result = D_801117B4;
                } else {
                    result = D_8017F488[((short)param_2)];
                }
            }
            break;
        case 3:
            if (((s32(*)(s32))func_80029178)(D_8017F440[((short)param_2)]) & 0xFF) {
                result = D_8017F4C8[((short)param_2)];
            }
            break;
        case 4:
            result = D_8017F4E0[((short)param_2)];
            break;
        }
        break;
    case 5:
    case5:
        uVar3 = ((s32(*)(s32))func_800291B4)(D_8017F434[((short)param_2)]) & 0xFF;
        if (uVar3 != 0) {
            result = D_8017F4F4[uVar3];
        }
        break;
    case 3:
        if (((short)param_2) != 0) {
            cVar1 = ((s32(*)(s32))func_800291B4)(D_8017F447[((short)param_2)]) & 0xFF;
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
