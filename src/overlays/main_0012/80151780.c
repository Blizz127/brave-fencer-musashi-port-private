/* Overlay range [80151780,80151878) from MAIN.CD member 0012.
 * SHA256(span)=5c2af7d11d57be248a5efd1a4109dbb27e80b77eff05b8e59dc48eaa8c9b9170.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80151780 - 62 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s16 D_8011DB1A;
extern s32 D_80127518;
extern s32 D_801151FC;
extern s32 func_801725CC(u8 *a0);
extern s32 func_80029D3C(s32 a0);
extern void func_80151878(void);
extern void func_80153B58(s32 *a0);

void func_80151780(s32 a0) {
    u8 idx;
    s32 *tbl;
    s32 fp;
    idx = *(u8 *)(a0 + 0xDD);
    tbl = *(s32 **)(a0 + 0x1F0);
    if (idx != 0 && idx < 0x21) {
        fp = tbl[idx - 1];
        if (fp != 0) {
            ((s32 (*)(s32))func_801725CC)(a0);
            {
                register s32 cur __asm__("$4");
                cur = D_8011DB1A;
                if (cur != 1000) {
                    D_8011DB1A = func_80029D3C(cur);
                }
            }
            (*(void (**)(s32))((s32)tbl + (s32)(*(u8 *)(a0 + 0xDD)) * 4 - 4))(a0);
            D_801151FC = D_80127518;
        } else {
            ((void (*)(s32))func_80151878)(a0);
        }
    } else {
        (*(void (**)(s32))((s32)tbl + 8))(a0);
    }
    if ((*(u16 *)(a0 + 0xF0) & 0x200) != 0) {
        ((void (*)(s32))func_80153B58)(a0);
    }
    return;
}
