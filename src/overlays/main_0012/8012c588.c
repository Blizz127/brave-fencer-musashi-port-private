/* Overlay range [8012C588,8012C658) from MAIN.CD member 0012.
 * SHA256(span)=34a26b7250a53782d970c26dd3362b0af8c768269cdb76c490e6dcf56d7bcd81.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8012C588 - 52 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_801202A0[];
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);

s32 func_8012C588(s32 a0, s32 a1) {
    s32 p;
    s32 end;
    s32 v0;
    s32 q;
    s16 sp[10];
    if (a1 != 0 && *(u16*)a1 != 0) {
        sp[0] = *(u16*)(a1 + 0x6);
        sp[1] = *(u16*)(a1 + 0xA);
        sp[2] = *(u16*)(a1 + 0xE);
    } else {
        sp[2] = 0;
        sp[1] = 0;
        sp[0] = 0;
    }
    sp[3] = a0;
    q = (s32)&sp[0];
    sp[5] = 0;
    sp[4] = 0;
    *(s32*)&sp[8] = 0;
    sp[7] = 0;
    sp[6] = 0x7FFF;
    end = (s32)D_801202A0 + 0x6480;
    if (a1 == 0) {
        p = (s32)D_801202A0;
    } else {
        p = a1 + 0x10C;
    }
    if (p != end) {
        for (;;) {
            if (*(u16*)p == 0) {
                goto found;
            }
            p += 0x10C;
            if (p == end) {
                break;
            }
        }
    }
    p = 0;
found:
    v0 = 0;
    if (p != 0) {
        v0 = func_8012C890(q, p, a1);
    }
    return v0;
}
