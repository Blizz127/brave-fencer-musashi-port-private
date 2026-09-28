/* Overlay range [8017DCB0,8017DD28) from MAIN.CD member 0012.
 * SHA256(span)=1c86375acb7f40915e3e3176ee5d35c0f6b0acf52c1c667b16241a0b51a93f46.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017DCB0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern unsigned short *D_80182540[];

void func_8017DCB0(s32 val, s32 n, void *dst, s32 flag) {
    register u32 d __asm__("$3");
    s32 idx;
    s16 i;

    n = (s16)n;
    for (i = 0; i < n; i++) {
        d = (u32)val >> 28;
        idx = d;
        if ((flag << 16) != 0) {
            if (d != 0) {
                flag = 0;
            } else {
                idx = 10;
            }
        }
        val <<= 4;
        *(u16 *)dst = *D_80182540[idx];
        dst = (u16 *)dst + 1;
    }
}
