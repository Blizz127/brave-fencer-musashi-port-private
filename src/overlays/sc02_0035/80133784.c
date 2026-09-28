/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80133784 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { u16 f0, f2, f4; s16 f6; } Box_80133784;
extern s32 D_801BD608;

s32 func_80133784(s32 arg0, void *arg1, s32 arg2) {
    extern s32 func_80047D3C(s32);
    extern s32 func_80133AB0(s16, s16, s16, s32);
    extern Box_80133784 * D_80184A60;
    extern Box_80133784 * D_80184A64;
    extern s16 D_801BD614;
    extern u16 D_801BD618;

    register s32 s1 __asm__("$17");
    s32 s2;
    register s16 s3 __asm__("$19");
    register s32 s4 __asm__("$20");
    register s16 a0v __asm__("$4");
    register s16 arg0s __asm__("$21");
    s32 dx, dy, dz;
    s32 r, ret;

    a0v = ((s16)arg0);
    s1 = 0;
    s3 = 0;
    s4 = 0;
    s2 = 0;
    arg0s = a0v;
    D_80184A60->f6 = -0x7FFF;
    D_80184A64->f6 = 0x7FFF;
    D_80184A60->f0 = ((Box_80133784 *)arg1)->f0;
    D_80184A60->f4 = ((Box_80133784 *)arg1)->f4;
    D_80184A64->f0 = ((Box_80133784 *)arg2)->f0;
    D_80184A64->f4 = ((Box_80133784 *)arg2)->f4;
    D_801BD618 = 0;
    D_801BD614 = 0;

    if ((s16)a0v == 0) {
        s16 sx = ((Box_80133784 *)arg2)->f0 - ((Box_80133784 *)arg1)->f0;
        s16 sy = ((Box_80133784 *)arg2)->f2 - ((Box_80133784 *)arg1)->f2;
        s16 sz = ((Box_80133784 *)arg2)->f4 - ((Box_80133784 *)arg1)->f4;
        if (sx == 0 && sy == 0) {
            s32 zt = (sz == 0);
            __asm__("addu %0,%1,$zero" : "=r"(s2) : "r"(zt));
        }
        D_80184A60->f2 = ((Box_80133784 *)arg1)->f2 - 4;
        r = func_80047D3C(sx * sx + sz * sz);
        if (r < 3) {
            r = 4;
        } else if (r < 5) {
            r += 1;
        }
        D_80184A64->f2 = ((Box_80133784 *)arg2)->f2 + r + 1;
    } else {
        D_80184A60->f2 = ((Box_80133784 *)arg1)->f2;
        if ((s16)a0v == 2) {
            D_80184A64->f0 = D_80184A60->f0;
            D_80184A64->f2 = D_80184A60->f2 + 6;
            s2 = 1;
            D_80184A64->f4 = D_80184A60->f4;
        } else {
            D_80184A64->f2 = ((Box_80133784 *)arg2)->f2;
        }
    }

    while (1) {
        s32 ret0;
        register s32 retc __asm__("$3");
        __asm__ __volatile__("");
        ret0 = func_80133AB0(arg0s, (s16)D_80184A60->f0, (s16)D_80184A60->f4, (*(s32*)&D_801BD608));
        __asm__("addu %0,%1,$zero" : "=r"(retc) : "r"(ret0));
        ret = retc;
        if (ret == 0) goto after;
        s4 |= ret;
        if (s2 != 0) goto after;
        {
            s16 oldc = s3;
            s3 = s3 + 1;
            if (oldc >= 5) break;
        }
    }

    D_80184A64->f0 = D_80184A60->f0;
    D_80184A64->f2 = D_80184A60->f2;
    s1 = 0x2000;
    D_80184A64->f4 = D_80184A60->f4;
    goto store_out;

after:
    if ((s16)s4 != 0 || D_801BD614 != 0) {
        s16 t;
        __asm__ __volatile__("" :: "r"(s4));
        t = D_80184A60->f6;
        if (t >= -0xBCB) {
            if (t < -0x578) {
                s1 |= 0x4000;
            } else {
                s1 |= 0x8000;
            }
        }
        if ((s16)D_80184A64->f6 < -0xBCB) {
            s1 |= 0x2000;
        }
    store_out:
        ((Box_80133784 *)arg2)->f0 = D_80184A64->f0;
        ((Box_80133784 *)arg2)->f2 = D_80184A64->f2;
        ((Box_80133784 *)arg2)->f4 = D_80184A64->f4;
        ((Box_80133784 *)arg2)->f6 = D_801BD618;
        return s1 & 0xFFFF;
    }
    ((Box_80133784 *)arg2)->f6 = D_801BD618;
    return 0;
}
