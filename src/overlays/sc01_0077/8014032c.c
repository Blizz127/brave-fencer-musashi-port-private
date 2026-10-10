/* sc01_0077: func_8014032C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern short D_80115128;
extern s16 D_80115128;
extern u8 D_80187BB8[];
extern u8 D_80187BD0[];
extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);
extern short D_80115128;
extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);
extern short D_80115128;

s32 func_8014032C(s32 param_1, s32 param_2) {
    extern int (*D_80187F00[])(void);
    extern int (*D_80187EF0[])(void);
    extern void * D_80187C0C[];
    extern void * D_80187C3C[];
    extern void * D_80187C4C[];
    extern void * D_80187C24[];
    extern u8 D_80187BDC[];
    extern void * D_80187C64[];
    extern void * D_80187C7C[];
    extern void * D_80187C90[];
    extern u8 D_80187BE3[];
    extern u8 * D_801D95CC;
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
        if (((s32(*)(s32))func_80029178)(D_80187BB8[((short)param_2)]) & 0xFF) {
            result = D_80187C0C[((short)param_2)];
        }
        break;
    case 1:
        result = D_80187C3C[((short)param_2)];
        break;
    case 2:
        switch ((*(s16*)&D_80115128)) {
        case 0:
            if (D_80187F00[((short)param_2)]() == 0) {
                ((short)param_2) = 5;
            } else if (D_80187EF0[((short)param_2)]() != 0) {
                ((short)param_2) = 4;
            }
            result = D_80187C4C[((short)param_2)];
            break;
        case 1:
            goto case5;
        case 2:
            if (((s32(*)(s32))func_80029178)(D_801D95CC[((short)param_2)]) & 0xFF) {
                if (((short)param_2) == 5 && (((s32(*)(s32))func_80029178)(0x1C) & 0xFF)) {
                    result = D_801117B4;
                } else {
                    result = D_80187C24[((short)param_2)];
                }
            }
            break;
        case 3:
            if (((s32(*)(s32))func_80029178)(D_80187BDC[((short)param_2)]) & 0xFF) {
                result = D_80187C64[((short)param_2)];
            }
            break;
        case 4:
            result = D_80187C7C[((short)param_2)];
            break;
        }
        break;
    case 5:
    case5:
        uVar3 = ((s32(*)(s32))func_800291B4)(D_80187BD0[((short)param_2)]) & 0xFF;
        if (uVar3 != 0) {
            result = D_80187C90[uVar3];
        }
        break;
    case 3:
        if (((short)param_2) != 0) {
            cVar1 = ((s32(*)(s32))func_800291B4)(D_80187BE3[((short)param_2)]) & 0xFF;
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
