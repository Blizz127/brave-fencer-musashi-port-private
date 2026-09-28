/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013FFD8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32);
extern short D_80115128;
extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);

s32 func_8013FFD8(s16 arg0, s32 arg1, s32 *arg2) {

    extern int D_8018556C;
    extern u8  D_80185584[];
    extern u8  D_80185590[];
    extern u8  D_80185597[];
    extern unsigned short D_80185598[];
    extern unsigned short D_801854C0[];
    extern u8 *D_801854D8;
    extern char *D_80185494;
    extern s16 D_801854A8;
    extern u8 D_80185518[];
    extern u8 D_8018551C;
    extern u8 *D_80185528;
    extern s32 D_8010F3C4[];
    extern s32 D_8010EDE8[];
    extern u8  D_80115143;
    extern void * D_801BD6E4;
    extern void * D_801BD6E0;
    s32 ret;

    *arg2 = 0x808080;
    ret = 0;

    switch (arg0) {                                    
    case 0: {
        s16 s0 = (s16) arg1;
        if (s0 < 6) {
            if ((((s32 (*)(u8))func_80029178)(((u8 *)&D_8018556C)[s0]) & 0xFF) == 0) {
                return 1;
            }
            ret = ((s32 *)D_801854C0)[s0];
        }
        break;
    }
    case 1: {
        s16 v1 = (s16) arg1;
        if (v1 < 4) {
            ret = ((s32 *)&D_801854D8)[v1];
        }
        break;
    }
    case 2:
        switch ((*(s16 *)&D_80115128)) {                          
        case 0: {
            s16 v1 = (s16) arg1;
            if (v1 < 5) {
                ret = ((s32 *)&D_80185494)[v1];
            }
            break;
        }
        case 1: {
            s16 v1 = (s16) arg1;
            if (v1 < 0xC) {
                s32 v3 = ((s32 (*)(u8, s32))func_800291B4)(D_80185584[v1], arg1) & 0xFF;
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
                if ((((s32 (*)(u8))func_80029178)((*(u8 * *)&D_801BD6E4)[s0]) & 0xFF) == 0) {
                    return 1;
                }
                ret = (*(s32 * *)&D_801BD6E0)[s0];
            }
            break;
        }
        case 3: {
            s16 s0 = (s16) arg1;
            if (s0 < 6) {
                if ((((s32 (*)(u8))func_80029178)(D_80185590[s0]) & 0xFF) == 0) {
                    return 1;
                }
                ret = ((s32 *)&D_801854A8)[s0];
            }
            break;
        }
        case 4: {
            s16 v1 = (s16) arg1;
            if (v1 < 5) {
                ret = ((s32 *)&D_80185528)[v1];
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
                if ((((s32 (*)(u8, s32))func_800291B4)(D_80185597[s0], arg1) & 0xFF) == 0) {
                    *arg2 = 0x804040;
                }
                ret = D_8010F3C4[s0];
            } else {
                ret = (*(s32 *)&D_80185518);
            }
        }
        break;
    }
    case 5: {
        s16 v1 = (s16) arg1;
        if (v1 < 3) {
            ret = ((s32 *)&D_8018551C)[v1];
        }
        break;
    }
    case 6: {
        s16 s0 = (s16) arg1;
        if (s0 < 0x28) {
            s32 idx;
            if ((((s32 (*)(u8, s32))func_800291B4)(((u8 *)D_80185598)[s0], arg1) & 0xFF) == 0) {
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
            ret = ((s32 *)&D_80185528)[v1];
        }
        break;
    }
    }
    return ret;
}
