/* Complete SC02 retail span [80148094,801483E8).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern s32 ratan2(s32 a0, s32 a1);
extern s32 csqrt(s32 a0);
extern void func_80013F3C(s32 a0);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern s32 func_80012A60(s32 a0, s32 a1);

void func_80148094(s32 param_1, s16 *param_2, s32 *param_3) {
    s32 s4 = *(s32 *)(param_1 + 0x20);
    s32 out[3];
    s32 buf[8];
    s32 t1;
    s32 sVar1;
    s32 fac;
    s32 r;

    if (*param_2 != 0 || param_2[2] != 0) {
        t1 = ratan2(-(s32)param_2[2], -(s32)*param_2) + 0x400;
        func_80013F3C((s32)buf);
        func_80012558((s32)buf, (s32)*(s16 *)(s4 + 0x12));
        func_800484EC((s32)buf, param_1 + 0x24, (s32)out);
        sVar1 = (s16)func_80012A60((s16)t1, (s16)(ratan2(out[2], out[0]) + 0x400));
        out[0] = *(s32 *)(param_1 + 0x24);
        if (out[0] < 0) {
            out[0] = -out[0];
        }
        out[2] = *(s32 *)(param_1 + 0x2C);
        if (out[2] < 0) {
            out[2] = -out[2];
        }
        {
            s32 q = csqrt((s32)*param_2 * (s32)*param_2 + (s32)param_2[2] * (s32)param_2[2]);
            if (q < 0) {
                q += 0x3F;
            }
            fac = ratan2((s32)param_2[1], q >> 6);
        }
        if (sVar1 < 0x200) {
            if (out[0] == out[2]) {
                r = *(s32 *)(param_1 + 0x24) * -fac;
                if (r < 0) {
                    r += 0x3FF;
                }
                out[0] = r >> 10;
                out[1] = 0;
                r = *(s32 *)(param_1 + 0x2C) * -fac;
                if (r < 0) {
                    r += 0x3FF;
                }
                out[2] = r >> 10;
            } else if (out[0] > out[2]) {
                r = *(s32 *)(param_1 + 0x24) * -fac;
                if (r < 0) {
                    r += 0x3FF;
                }
                out[0] = r >> 10;
                out[1] = 0;
                out[2] = *(s32 *)(param_1 + 0x2C);
            } else {
                out[0] = *(s32 *)(param_1 + 0x24);
                out[1] = 0;
                r = *(s32 *)(param_1 + 0x2C) * -fac;
                if (r < 0) {
                    r += 0x3FF;
                }
                out[2] = r >> 10;
            }
        } else if (sVar1 >= 0x201) {
            if (out[0] == out[2]) {
                r = *(s32 *)(param_1 + 0x24) * -fac;
                if (r < 0) {
                    r += 0x3FF;
                }
                out[0] = *(s32 *)(param_1 + 0x24) + (r >> 10);
                out[1] = 0;
                r = *(s32 *)(param_1 + 0x2C) * -fac;
                if (r < 0) {
                    r += 0x3FF;
                }
                out[2] = *(s32 *)(param_1 + 0x2C) + (r >> 10);
            } else if (out[0] > out[2]) {
                r = *(s32 *)(param_1 + 0x24) * -fac;
                if (r < 0) {
                    r += 0x3FF;
                }
                out[0] = *(s32 *)(param_1 + 0x24) + (r >> 10);
                out[1] = 0;
                out[2] = *(s32 *)(param_1 + 0x2C);
            } else {
                out[0] = *(s32 *)(param_1 + 0x24);
                out[1] = 0;
                r = *(s32 *)(param_1 + 0x2C) * -fac;
                if (r < 0) {
                    r += 0x3FF;
                }
                out[2] = *(s32 *)(param_1 + 0x2C) + (r >> 10);
            }
        } else {
            out[0] = *(s32 *)(param_1 + 0x24);
            out[1] = 0;
            out[2] = *(s32 *)(param_1 + 0x2C);
        }
        param_3[0] = out[0];
        param_3[1] = out[1];
        param_3[2] = out[2];
        return;
    }
    param_3[0] = *(s32 *)(param_1 + 0x24);
    param_3[1] = *(s32 *)(param_1 + 0x28);
    param_3[2] = *(s32 *)(param_1 + 0x2C);
}

