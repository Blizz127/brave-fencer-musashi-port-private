/* Overlay range [8014AC10,8014ACC0) from MAIN.CD member 0012.
 * SHA256(span)=efa92082737fa88553c026514006c59ae3efc5abfb2eadb838b145dbfc8717e1.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014AC10 - 44 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80016714(void *a0, s32 a1);
extern s32 D_8011D030;

void func_8014AC10(s32 arg0) {
    u8 *p;
    u8 *end;
    u8 *t;
    s32 one;
    void *a0;
    s32 a1;
    p = (u8 *)&D_8011D030;
    t = p + 0xA50;
    if (p < t) {
        one = 1;
        end = t;
        do {
            if (*(u16 *)p == arg0) {
                a0 = *(void **)(p + 0x20);
                if (a0 != 0) {
                    a1 = 0x38;
                    if (*(u16 *)a0 == one) {
                        a1 = 0x84;
                    }
                    func_80016714(a0, a1);
                }
                func_80016714(p, 0x58);
            }
            p += 0x58;
        } while (p < end);
    }
}
