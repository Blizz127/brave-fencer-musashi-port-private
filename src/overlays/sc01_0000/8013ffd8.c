/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013FFD8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);
extern short D_80115128;

s32 func_8013FFD8(s16 arg0, s32 arg1, s32 *arg2) {

    extern unsigned char D_8017FCA4[];
    extern u8  D_8017FCBC[];
    extern u8  D_8017FCC8[];
    extern u8  D_8017FCCF[];
    extern int D_8017FCD0;
    extern u8 D_8017FBF8[];
    extern s32 D_8017FC10[];
    extern s32 D_8017FBCC;
    extern unsigned char D_8017FBE0[];
    extern u8 D_8017FC50;
    extern s32 D_8017FC54[];
    extern u8 *D_8017FC60;
    extern s32 D_8010F3C4[];
    extern s32 D_8010EDE8[];
    extern u8  D_80115143;
    extern void * D_801A4524;
    extern void * D_801A4520;
    s32 ret;

    *arg2 = 0x808080;
    ret = 0;

    switch (arg0) {                                   /* jtbl_801D8898 */
    case 0: {
        s16 s0 = (s16) arg1;
        if (s0 < 6) {
            if ((((s32 (*)(u8))func_80029178)(((u8 *)D_8017FCA4)[s0]) & 0xFF) == 0) {
                return 1;
            }
            ret = ((s32 *)D_8017FBF8)[s0];
        }
        break;
    }
    case 1: {
        s16 v1 = (s16) arg1;
        if (v1 < 4) {
            ret = D_8017FC10[v1];
        }
        break;
    }
    case 2:
        switch ((*(s16 *)&D_80115128)) {                         /* jtbl_801D88B8 */
        case 0: {
            s16 v1 = (s16) arg1;
            if (v1 < 5) {
                ret = ((s32 *)&D_8017FBCC)[v1];
            }
            break;
        }
        case 1: {
            s16 v1 = (s16) arg1;
            if (v1 < 0xC) {
                s32 v3 = ((s32 (*)(u8, s32))func_800291B4)(D_8017FCBC[v1], arg1) & 0xFF;
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
                if ((((s32 (*)(u8))func_80029178)((*(u8 * *)&D_801A4524)[s0]) & 0xFF) == 0) {
                    return 1;
                }
                ret = (*(s32 * *)&D_801A4520)[s0];
            }
            break;
        }
        case 3: {
            s16 s0 = (s16) arg1;
            if (s0 < 6) {
                if ((((s32 (*)(u8))func_80029178)(D_8017FCC8[s0]) & 0xFF) == 0) {
                    return 1;
                }
                ret = ((s32 *)D_8017FBE0)[s0];
            }
            break;
        }
        case 4: {
            s16 v1 = (s16) arg1;
            if (v1 < 5) {
                ret = ((s32 *)&D_8017FC60)[v1];
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
                if ((((s32 (*)(u8, s32))func_800291B4)(D_8017FCCF[s0], arg1) & 0xFF) == 0) {
                    *arg2 = 0x804040;
                }
                ret = D_8010F3C4[s0];
            } else {
                ret = (*(s32 *)&D_8017FC50);
            }
        }
        break;
    }
    case 5: {
        s16 v1 = (s16) arg1;
        if (v1 < 3) {
            ret = D_8017FC54[v1];
        }
        break;
    }
    case 6: {
        s16 s0 = (s16) arg1;
        if (s0 < 0x28) {
            s32 idx;
            if ((((s32 (*)(u8, s32))func_800291B4)(((u8 *)&D_8017FCD0)[s0], arg1) & 0xFF) == 0) {
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
            ret = ((s32 *)&D_8017FC60)[v1];
        }
        break;
    }
    }
    return ret;
}
