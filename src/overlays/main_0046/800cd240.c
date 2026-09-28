/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD240 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);

s32 func_800CD240(void *arg0) {
    s32 s0;

    s0 = (s32)arg0;
    __asm__ __volatile__("" : "=r"(s0) : "0"(s0));
    if (*(s16 *)(s0 + 0x1C8) != 0) {
        return 0;
    }
    func_801599A4((void *)s0);
    func_80159B3C((void *)s0);
    return 1;
}
