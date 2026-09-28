/* Main-exec range [8001C14C,8001C1E4) from the SLUS executable.
 * SHA256(span)=51c5bfb6e4cc0e1887bff6cce570eaf306259298d87d20368ab93cf1c10a64e4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001C14C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern void func_80016714(void *a0, s32 a1);
extern u8 D_800AF630[];

void func_8001C14C(void) {
    u8 *base;
    u8 *p;

    base = D_800AF630;
    p = base + 0x65A8;
    while (p < base + 0x6688) {
        func_80016714(p, 0x38);
        p += 0x38;
    }

    p = base + 0x2A8;
    while (p < base + 0x4B8) {
        func_80016714(p, 0x84);
        p += 0x84;
    }
}
