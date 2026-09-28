/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013339C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8013339C(short *param_1, short *param_2)
{
    short sVar4;
    short sVar5;
    short sVar6;
    sVar4 = 1;
    if (*param_2 != 0) {
        sVar4 = *param_2;
    }
    sVar5 = 1;
    if (param_2[1] != 0) {
        sVar5 = param_2[1];
    }
    sVar6 = 1;
    if (param_2[2] != 0) {
        sVar6 = param_2[2];
    }
    param_1[0] = (short)(((int)param_1[0] << 0xc) / (int)sVar4);
    param_1[3] = (short)(((int)param_1[3] << 0xc) / (int)sVar4);
    param_1[6] = (short)(((int)param_1[6] << 0xc) / (int)sVar4);
    param_1[1] = (short)(((int)param_1[1] << 0xc) / (int)sVar5);
    param_1[4] = (short)(((int)param_1[4] << 0xc) / (int)sVar5);
    param_1[7] = (short)(((int)param_1[7] << 0xc) / (int)sVar5);
    param_1[2] = (short)(((int)param_1[2] << 0xc) / (int)sVar6);
    param_1[5] = (short)(((int)param_1[5] << 0xc) / (int)sVar6);
    param_1[8] = (short)(((int)param_1[8] << 0xc) / (int)sVar6);
}
