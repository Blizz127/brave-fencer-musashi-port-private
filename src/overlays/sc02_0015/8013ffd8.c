/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013FFD8 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern s32 func_80029178(s32);
extern short D_80115128;
extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);

s32 func_8013FFD8(s16 arg0, s32 arg1, s32 *arg2) {

    extern M2C_UNK D_8017F2E0;
    extern s16 D_8017F2F8[];
    extern u8  D_8017F304[];
    extern u8  D_8017F30B[];
    extern u8  D_8017F30C[];
    extern M2C_UNK D_8017F234;
    extern u8 D_8017F24C[];
    extern int D_8017F208;
    extern s32 D_8017F21C[];
    extern s32 D_8017F28C;
    extern s32 D_8017F290[];
    extern u8 *D_8017F29C;
    extern s32 D_8010F3C4[];
    extern s32 D_8010EDE8[];
    extern u8  D_80115143;
    extern void * D_8018F13C;
    extern u8 D_8018F138[];
    s32 ret;

    *arg2 = 0x808080;
    ret = 0;

    switch (arg0) {                                    
    case 0: {
        s16 s0 = (s16) arg1;
        if (s0 < 6) {
            if ((((s32 (*)(u8))func_80029178)(((u8 *)&D_8017F2E0)[s0]) & 0xFF) == 0) {
                return 1;
            }
            ret = ((s32 *)&D_8017F234)[s0];
        }
        break;
    }
    case 1: {
        s16 v1 = (s16) arg1;
        if (v1 < 4) {
            ret = ((s32 *)D_8017F24C)[v1];
        }
        break;
    }
    case 2:
        switch ((*(s16 *)&D_80115128)) {                          
        case 0: {
            s16 v1 = (s16) arg1;
            if (v1 < 5) {
                ret = ((s32 *)&D_8017F208)[v1];
            }
            break;
        }
        case 1: {
            s16 v1 = (s16) arg1;
            if (v1 < 0xC) {
                s32 v3 = ((s32 (*)(u8, s32))func_800291B4)(((u8 *)D_8017F2F8)[v1], arg1) & 0xFF;
                if (v3 == 0) {
                    return 1;
                }
                ret = D_8010EDE8[v3 * 3];
            }
            break;
        }
        case 2: {
            s16 s0 = (s16) arg1;
            if (s0 < 6) {
                if ((((s32 (*)(u8))func_80029178)((*(u8 * *)&D_8018F13C)[s0]) & 0xFF) == 0) {
                    return 1;
                }
                ret = (*(s32 * *)&D_8018F138)[s0];
            }
            break;
        }
        case 3: {
            s16 s0 = (s16) arg1;
            if (s0 < 6) {
                if ((((s32 (*)(u8))func_80029178)(D_8017F304[s0]) & 0xFF) == 0) {
                    return 1;
                }
                ret = D_8017F21C[s0];
            }
            break;
        }
        case 4: {
            s16 v1 = (s16) arg1;
            if (v1 < 5) {
                ret = ((s32 *)&D_8017F29C)[v1];
            }
            break;
        }
        }
        break;
    case 3: {
        s16 t = (s16) arg1;
        if (t <= 0) {
            s16 s0 = t + D_80115143;
            if (s0 != 0) {
                if ((((s32 (*)(u8, s32))func_800291B4)(D_8017F30B[s0], arg1) & 0xFF) == 0) {
                    *arg2 = 0x804040;
                }
                ret = D_8010F3C4[s0];
            } else {
                ret = D_8017F28C;
            }
        }
        break;
    }
    case 5: {
        s16 v1 = (s16) arg1;
        if (v1 < 3) {
            ret = D_8017F290[v1];
        }
        break;
    }
    case 6: {
        s16 s0 = (s16) arg1;
        if (s0 < 0x28) {
            s32 idx;
            if ((((s32 (*)(u8, s32))func_800291B4)(D_8017F30C[s0], arg1) & 0xFF) == 0) {
                *arg2 = 0x804040;
            }
            idx = s0 + 1;
            ret = D_8010F3C4[idx];
        }
        break;
    }
    case 7: {
        s16 v1 = (s16) arg1;
        if (v1 < 5) {
            ret = ((s32 *)&D_8017F29C)[v1];
        }
        break;
    }
    }
    return ret;
}
