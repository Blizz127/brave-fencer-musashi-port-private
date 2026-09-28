/* Exact retail word export for [8003D25C,8003D32C); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003D25C - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { u16 r[6]; u16 envx; u16 pad; } SpuVoiceReg;
extern volatile SpuVoiceReg *D_8006B54C;
extern u32 D_8006B0E4;
s32 func_8003D25C(s32 min, s32 max, u8 *status)
{
    s32 i;
    u16 env;

    if (min < 0) {
        min = 0;
    }
    if (min >= 24) {
        return -3;
    }
    if (max >= 24) {
        max = 23;
    }
    if (max < 0 || max < min) {
        return -3;
    }
    for (i = min; i < max + 1; i++) {
        env = D_8006B54C[i].envx;
        if (D_8006B0E4 & (1 << i)) {
            if (env) {
                status[i] = 1;
            } else {
                status[i] = 3;
            }
        } else {
            if (env) {
                status[i] = 2;
            } else {
                status[i] = 0;
            }
        }
    }
    return 0;
}
