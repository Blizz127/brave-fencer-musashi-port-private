/* Overlay range [80131CF4,80131D68) from MAIN.CD member 0012.
 * SHA256(span)=5e4fce9b9a54c616d357f19428c3cd2da6ee4cda625803d02ac3cfb394096c4b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80131CF4 - byte-exact against retail at -O2 (tools/register_match.py). */
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");

s32 aF80131CF4(s32 *a0, s32 a1) {
    s32 v0;
    s32 k;
    if (a0 == 0) {
        return 0;
    }
    goto enter;
found:
    return a0[1];
enter:
    if (a0[0] == 0) {
        return 0;
    }
    __asm__ __volatile__("" : "=r"(k) : "0"(0xD) : "memory");
    v0 = a0[0];
    do {
        if (v0 == k) {
            a0 = (s32 *)a0[1];
        } else {
            if (v0 == a1) {
                goto found;
            }
            a0 = (s32 *)((u8 *)a0 + 8);
        }
        v0 = a0[0];
    } while (v0 != 0);
    return 0;
}
