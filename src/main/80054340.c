/* Exact retail word export for [80054340,80054430); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80054340 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 func_80054430(s32 *);
extern s32 func_800544F8(s32);
void func_80054340(s32 *in, s32 *out)
{
    s32 n = func_800544F8(func_80054430(in));

    if (n >= 16) {
        n -= 15;
        out[0] = in[0] >> n;
        out[1] = in[1] >> n;
        out[2] = in[2] >> n;
        out[3] = in[3] >> n;
        out[4] = in[4] >> n;
        out[5] = in[5] >> n;
    } else {
        out[0] = in[0];
        out[1] = in[1];
        out[2] = in[2];
        out[3] = in[3];
        out[4] = in[4];
        out[5] = in[5];
    }
}
