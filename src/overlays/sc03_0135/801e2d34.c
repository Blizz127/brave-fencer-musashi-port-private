/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2D34 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801E2D34(void) {
    extern s16 D_80115126;
    extern s16 D_8011512C;
    extern s16 D_801EA954;
    extern s16 D_801EA958;
    extern s16 D_801EA95C;
    extern s16 func_8014168C(s16 a0);
    extern s32 D_801E63B0;
    extern s32 D_801E6448;
    extern s32 D_801E64E8;
    extern s32 D_801EAC3C;
    extern u32 D_801EAC40;
    extern s32 func_80014ED4(s32);
    extern s32 func_80015018(s32);
    extern void func_8002AF18(void);
    extern u16 D_8011511A;
    extern unsigned short D_80115118;
    extern u8 D_801EA960[];
    extern u8 D_801EAC47[];
    extern u8 D_801EAC4D;
    extern void func_8002AF70(void *, s32);
    extern s32 func_8002D4C8(s32, s32);
    extern void func_801E4890(void);
    extern void func_801E48B8(s32);

    s32 *p;
    s32 *p2;
    u16 *ph;
    s16 *q;
    s32 pad;
    s32 flag;
    s32 st;
    s32 t;
    s32 t2;
    s32 sv;
    s32 x;
    s32 r;
    s32 unused[4];

    flag = 0;
    pad = func_80014ED4(0);
    func_80015018(0);
    func_8014168C(D_8011511A);

    if (pad & 0x40) {
        st = D_8011512C;
        switch (st) {
        case 1:
            if (D_80115126 == 0) {
                if (D_801EAC47[D_8011511A] == 1) {
                    D_801E6448 = 0x19;
                } else {
                    func_8002D4C8(0x472, 0);
                    return 0;
                }
            } else if (D_801EAC47[D_8011511A] == 1) {
                D_801E6448 = 0x16;
            } else {
                D_801E6448 = 0x19;
            }
            D_8011512C = 2;
            func_8002D4C8(0x45D, 0);
            return 0;
        case 2:
            func_801E4890();
            if (D_80115126 == 0) {
                D_801E64E8 = 0x14;
                D_801EAC3C = 2;
                D_801EAC40 = D_8011511A - 1;
            } else {
                D_801EAC40 = D_8011511A - 1;
                func_801E48B8(1);
                func_8002AF70(D_801EA960, D_801EAC40);
                D_801E64E8 = 0xE;
                D_801EAC3C = 1;
            }
            D_8011512C = 3;
            func_8002D4C8(0x45D, 0);
            return 0;
        case 4:
        case 7:
        Lcheck47:
            if (D_80115118 < 0x47) {
                goto Lreset;
            }
            return 0;
        case 9:
            p = &D_801E6448;
            if (*p == 0x1D || *p == 0x21) {
                goto Lmsg473ret1;
            }
            D_801EA954 = 0;
            D_801EA95C = 1;
            D_8011512C = 0;
            *p = D_801E63B0;
            func_8002D4C8(0x45D, 0);
            return 0;
        case 5:
            goto Lload;
        case 0:
        case 3:
        case 6:
        case 8:
        case 10:
        case 11:
        case 12:
            break;
        default:
            goto Ltail;
        }
        return 0;
    } else if (pad & 0x10) {
        st = D_8011512C;
        switch (st) {
        case 0:
            if (D_801E6448 != 0xB) {
                return 0;
            }
             
        case 1:
        Lmsg473:
            func_8002D4C8(0x473, 0);
            t = D_801EA958;
            sv = t;
            if (t == 0) {
                return 1;
            }
            x = (t == 1) ? 0x1D : 0x21;
            r = 0;
            t = 9;
            D_8011512C = t;
            D_801E6448 = x;
            t = 0xFF;
            goto Lstore;
        case 2:
            if (D_80115126 == 0) {
                D_801E6448 = 0xC;
            } else {
                D_801E6448 = 0xD;
            }
            D_8011512C = 1;
            func_8002D4C8(0x473, 0);
            return 0;
        case 5:
        case 8:
            if (D_80115126 != 0) {
                goto Lmsg473;
            }
        Lmsg473ret1:
            func_8002D4C8(0x473, 0);
            return 1;
        case 9:
            p2 = &D_801E6448;
            if (*p2 == 0x1D || *p2 == 0x21) {
                if (D_801EA95C == 0) {
                    *p2 = 0x1A;
                    func_8002D4C8(0x45D, 0);
                    return 0;
                }
                D_801EA954 = 0;
                D_8011512C = 0;
                *p2 = D_801E63B0;
                func_8002AF18();
                func_8002D4C8(0x45D, 0);
                return 0;
            }
            *p2 = (D_801EA958 == 1) ? 0x1D : 0x21;
            func_8002D4C8(0x473, 0);
            return 0;
        case 4:
        case 7:
            goto Lcheck47;
        case 3:
        case 6:
        case 10:
        case 11:
        case 12:
            break;
        default:
            goto Ltail;
        }
        return 0;
    } else if (pad & 0x20) {
        st = D_8011512C;
        if (st == 5) {
            D_801E64E8 = 0x17;
            D_8011512C = 6;
            func_8002D4C8(0x45D, 0);
            D_801EAC3C = 3;
            return 0;
        }
        goto Ltail;
    }
Lload:
    st = D_8011512C;
Ltail:
    if (st == 4 || st == 7 || st >= 10) {
        ph = &D_80115118;
        if (*ph != 0) {
            *ph = *ph - 1;
            goto Lmid;
        }
    Lreset:
        D_80115118 = 0;
        if (D_80115126 == 0) {
            if (D_8011512C == 4) {
                return -1;
            }
            D_801E6448 = 0xC;
        } else {
            t2 = D_801EA958;
            sv = t2;
            if (t2 != 0 && D_8011512C == 4) {
                t = (t2 == 1) ? 0x1D : 0x21;
                r = 0;
                D_801E6448 = t;
                t = 9;
                D_8011512C = t;
                t = 0xFF;
            Lstore:
                D_801EA954 = sv;
                D_801EAC4D = t;
                return r;
            }
            D_801E6448 = 0xD;
            q = &D_8011512C;
            if (*q == 0xC) {
                *q = 1;
                return 0;
            }
        }
        D_8011512C = 1;
        return 0;
    }
Lmid:
    if (D_8011512C != 1) {
        return 0;
    }
    if (pad & 0x1000) {
        t = D_8011511A;
        D_8011511A = t - 2;
        flag = 1;
        if (D_8011511A == 0 || D_8011511A >= 5) {
            D_8011511A = t + 2;
        }
    }
    if (pad & 0x4000) {
        ph = &D_8011511A;
        t2 = *ph;
        *ph = t2 + 2;
        flag = 1;
        if (*ph >= 5) {
            *ph = t2 - 2;
        }
    }
    if (pad & 0x8000) {
        ph = &D_8011511A;
        t2 = *ph;
        *ph = t2 + 1;
        flag = 1;
        if (*ph & 1) {
            *ph = t2 - 1;
        }
    }
    if (pad & 0x2000) {
        ph = &D_8011511A;
        t2 = *ph;
        *ph = t2 - 1;
        flag = 1;
        if (!(*ph & 1)) {
            *ph = t2 + 1;
        }
    }
    r = flag;
    if (r) {
        func_8002D4C8(0x45A, 0);
    }
    return 0;
}
