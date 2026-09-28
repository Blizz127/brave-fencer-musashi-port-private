/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80148094 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_80047B3C(s32 a0);
extern void func_80013F3C(s32 a0);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern s32 func_80012A60(s32 a0, s32 a1);

void func_80148094(int param_1, short *param_2, int *param_3) {
    s32 s4 = *(int *)(param_1 + 0x20);
    s32 out[3];
    s32 buf[8];
    s32 bp;
    s32 t1;
    int sVar1;
    int fac;
    int r;
    if (*param_2 != 0 || param_2[2] != 0) {
        t1 = func_8004CFEC(-(int)param_2[2], -(int)*param_2) + 0x400;
        bp = (s32)buf;
        func_80013F3C(bp);
        func_80012558(bp, (s32)*(short *)(s4 + 0x12));
        func_800484EC(bp, param_1 + 0x24, (s32)out);
        sVar1 = (s16)func_80012A60((s16)t1, (s16)(func_8004CFEC(out[2], out[0]) + 0x400));
        out[0] = *(int *)(param_1 + 0x24);
        if (out[0] < 0) out[0] = -out[0];
        out[2] = *(int *)(param_1 + 0x2c);
        if (out[2] < 0) out[2] = -out[2];
        {
            int q = func_80047B3C((int)*param_2 * (int)*param_2 + (int)param_2[2] * (int)param_2[2]);
            if (q < 0) q += 0x3f;
            fac = func_8004CFEC((int)param_2[1], q >> 6);
        }
        if (sVar1 < 0x200) {
            __asm__("" :: "r"(fac)); /* L1: +1 flow-ref on fac (already live-through here); zero bytes */
            if (out[0] == out[2]) {
                r = *(int *)(param_1 + 0x24) * -fac;
                if (r < 0) r += 0x3ff;
                out[0] = r >> 10;
                out[1] = 0;
                r = *(int *)(param_1 + 0x2c) * -fac;
                if (r < 0) r += 0x3ff;
                out[2] = r >> 10;
            } else if (out[0] > out[2]) {
                r = *(int *)(param_1 + 0x24) * -fac;
                if (r < 0) r += 0x3ff;
                out[0] = r >> 10;
                out[1] = 0;
                out[2] = *(int *)(param_1 + 0x2c);
            } else {
                out[0] = *(int *)(param_1 + 0x24);
                out[1] = 0;
                r = *(int *)(param_1 + 0x2c) * -fac;
                if (r < 0) r += 0x3ff;
                out[2] = r >> 10;
            }
        } else if (sVar1 >= 0x201) { /* L2: ==0x200 arm must be the LAST (fall-through) block */
            if (out[0] == out[2]) {
                r = *(int *)(param_1 + 0x24) * -fac;
                if (r < 0) r += 0x3ff;
                out[0] = *(int *)(param_1 + 0x24) + (r >> 10);
                out[1] = 0;
                r = *(int *)(param_1 + 0x2c) * -fac;
                if (r < 0) r += 0x3ff;
                out[2] = *(int *)(param_1 + 0x2c) + (r >> 10);
            } else if (out[0] > out[2]) {
                r = *(int *)(param_1 + 0x24) * -fac;
                if (r < 0) r += 0x3ff;
                out[0] = *(int *)(param_1 + 0x24) + (r >> 10);
                out[1] = 0;
                out[2] = *(int *)(param_1 + 0x2c);
            } else {
                out[0] = *(int *)(param_1 + 0x24);
                out[1] = 0;
                r = *(int *)(param_1 + 0x2c) * -fac;
                if (r < 0) r += 0x3ff;
                out[2] = *(int *)(param_1 + 0x2c) + (r >> 10);
            }
        } else {
            out[0] = *(int *)(param_1 + 0x24); /* L3: out[0] store before out[1]=0 (delay-fill) */
            out[1] = 0;
            out[2] = *(int *)(param_1 + 0x2c);
        }
        param_3[0] = out[0];
        param_3[1] = out[1];
        param_3[2] = out[2];
        return;
    }
    param_3[0] = *(int *)(param_1 + 0x24);
    param_3[1] = *(int *)(param_1 + 0x28);
    param_3[2] = *(int *)(param_1 + 0x2c);
}
