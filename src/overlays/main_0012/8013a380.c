/* Overlay range [8013A380,8013A448) from MAIN.CD member 0012.
 * SHA256(span)=0e2df53ded31d4db92d80ce8f74fa8d81d7bd0f1d8ff6b7c26fe8597337bd647.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8013A380 - 50 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_8011DA80[];
extern void func_8013A530();
extern void func_8013A448(void *a0);
extern void func_8013A4C4(struct S8013A4C4 *a0);

void func_8013A380(void) {
    s16 *p;
    s32 i;
    p = (s16 *)D_8011DA80;
    i = 0;
    do {
        if (p != (s16 *)0) {
            switch (*p) {
            case 2:
                ((void (*)(void *))func_8013A530)(p);
                break;
            case 1:
                func_8013A448(p);
                break;
            case 3:
                func_8013A4C4((struct S8013A4C4 *)p);
                break;
            }
        }
        i += 1;
        p += 8;
    } while (i < 2);
}
