/* Overlay range [8012CAE4,8012CB64) from MAIN.CD member 0012.
 * SHA256(span)=ec3a569833e3ce8ee8e9b2945e0fdb6194bbfe711a03cfd6ecda2403e56bb67f.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8012CAE4 - 32 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80016714(void *a0, s32 a1);
extern u16 D_801274E4[];

void func_8012CAE4(void *a0) {
    u16 *d;
    void *p;
    s32 t;
    s32 a1;
    d = D_801274E4;
    *d |= 1;
    p = *(void **)((s32)a0 + 0x20);
    if (p != 0) {
        t = *(u16 *)p;
        if (t != 1) {
            if (t != 2) {
                goto done;
            }
            a1 = 0x38;
        } else {
            a1 = 0x84;
        }
        func_80016714(p, a1);
    done:;
    }
    func_80016714(a0, 0x10C);
}
