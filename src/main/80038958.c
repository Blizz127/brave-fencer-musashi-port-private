/* Main-exec range [80038958,80038A00) from the SLUS executable.
 * SHA256(span)=9e6c3e4acab007ee005c23f68820d682fee0bb2e6a2236bc95d2ce6fa5a9050f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80038958 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 *D_800762B0;
extern u8 D_800762B4[];
extern u8 D_800C6E2A[];

void func_80038958(void) {
    register u8 *a3 __asm__("$7");
    register u8 *a2 __asm__("$6");
    register s32 a1 __asm__("$5");
    register u8 *a0 __asm__("$4");
    register s32 t0 __asm__("$8");
    register s32 v0 __asm__("$2");
    register s32 v1 __asm__("$3");

    a3 = D_800762B0;
    a2 = D_800762B4;
    a1 = 0;
    t0 = 3;
    a0 = D_800C6E2A;

    while (a1 < 0x10) {
        v0 = *a3;
        if (v0 == 0 || v0 == t0) {
            if (*a2 == 0) {
                v0 = *a0;
                a0[1] = 0;
                if (v0 != 0) {
                    v0 = *(s16 *)(a0 - 0x54);
                    v1 = v0 << 1;
                    v1 = v1 + v0;
                    v1 = v1 << 2;
                    v1 = v1 + v0;
                    v0 = *(s32 *)(a0 - 0xA);
                    v1 = v1 << 1;
                    v0 = v0 + v1;
                    v0 = v0 + a1;
                    *(u8 *)(v0 + 0x23) = 0;
                    a0[0] = 0;
                }
            }
        }
        a1++;
        a0 += 0x60;
        a3++;
        a2++;
    }
}
