/* Overlay range [80137BD8,80137D08) from MAIN.CD member 0012.
 * SHA256(span)=ccde93a6fcd537f58b2b0c57ba03861dd924a3242074839c53bb533a29c865ec.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80137BD8 - 76 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_801392FC();
extern void func_801397B0(s32 a0);
extern void func_80137DD4(s32 a0, u8 *a1, u8 *a2);
extern void func_80139680(s32 a0, u8 *a1);
extern short D_800B9A02;
extern u8 D_800A6518[];
extern s32 D_80127524;
extern u16 D_800B99D8;

void func_80137BD8(s32 a0) {
    u8 buf[8];
    if ((*(s32 *)(a0 + 8) & 0x1000) != 0) {
        func_801392FC(a0, *(u8 *)(a0 + 0x1E),
                      &D_800A6518[(u16)D_800B9A02 * 20]);
        if (*(u8 *)(a0 + 0x20) != 0) {
            func_801397B0(a0);
        }
    }
    if (D_80127524 == a0) {
        if (*(s16 *)(a0 + 4) == 7) {
            buf[0] = 0x39;
            buf[1] = 0xFF;
            buf[2] = 0x71;
            func_80137DD4(a0, buf, &D_800A6518[(u16)D_800B9A02 * 20]);
        } else if (*(s16 *)(a0 + 4) == 3) {
            if ((D_800B99D8 & 4) != 0) {
                func_80139680(a0, &D_800A6518[(u16)D_800B9A02 * 20]);
            }
        }
    }
}
