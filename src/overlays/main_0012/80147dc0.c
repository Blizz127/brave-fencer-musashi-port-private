/* Overlay range [80147DC0,80147E44) from MAIN.CD member 0012.
 * SHA256(span)=f517d4fe99ca135587e40de7db5f64d615b8d70414941bedacb8433c30fc14a9.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80147DC0 - 33 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80013F3C(s32 a0);
extern void func_800126C4(s32 a0, s32 a1);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800123F0(s32 a0, s32 a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_80147DC0(s32 a0, s32 a1) {
    s32 pad[4];
    s32 buf[8];
    s32 q = *(s32 *)(a0 + 0x20);
    func_80013F3C((s32)buf);
    func_800126C4((s32)buf, *(s16 *)(q + 0x10));
    func_80012558((s32)buf, *(s16 *)(q + 0x12));
    func_800123F0((s32)buf, *(s16 *)(q + 0x14));
    func_800484EC((s32)buf, a0 + 0x24, a1);
}
