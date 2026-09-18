/* Overlay range [8014E83C,8014E934) from MAIN.CD member 0012.
 * SHA256(span)=d18515b0629d26caedba23bf18627bd2549268e7ae183a287091db4a53b954fd.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014E83C - 62 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_801202A0[];

s32 func_8014E83C(s32 arg0, s16 * arg1, s16 * arg2)
{
    register u8 *p   __asm__("$17");  /* $s1 */
    register u8 *q   __asm__("$16");  /* $s0 */
    u8 *end;
    s32 t;
    p = D_801202A0;
    if ((u32)p < (u32)(p + 0x6480)) {
        end = p + 0x6480;
        q = p + 0xE;
        do {
            if (*(u16 *)p != 0 && (*(u16 *)(q + 0x4E) & 0x20) &&
                (t = *(s32 *)(q + 0x4A), t != 0) &&
                func_80135888(*(s32 *)(q + 0x12), t, arg1, arg2) != 0) {
                *(s32 *)(arg0 + 0x180) = (s32)p;
                *(u16 *)(arg0 + 0x6) = *(u16 *)(q - 0x8);
                *(u16 *)(arg0 + 0xA) = *(u16 *)(q - 0x4);
                *(u16 *)(arg0 + 0xE) = *(u16 *)q;
                return 1;
            }
            p += 0x10C;
            q += 0x10C;
        } while ((u32)p < (u32)end);
    }
    return 0;
}
