/* Main-exec range [8003D32C,8003D3B4) from the SLUS executable.
 * SHA256(span)=e8c46efaac053e5fa91e53d45868efb43026f12e9203ebd84bfb4686561cbcc0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003D32C - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { u16 r[6]; u16 envx; u16 pad; } SpuVoiceReg;
extern volatile SpuVoiceReg *D_8006B54C;
extern u32 D_8006B0E4;
void func_8003D32C(u8 *status)
{
    s32 n = 24;
    s32 i;
    u16 env;

    for (i = 0; i < n; i++) {
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
}
