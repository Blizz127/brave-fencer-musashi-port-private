/* Overlay range [80142C9C,80142D38) from MAIN.CD member 0012.
 * SHA256(span)=58f763a882e7fda336a88faf5c62dda89a6a09dfeebb81744cf9cd2c34b62834.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* Verified byte-exact against retail by tools/match_function.py
 * (39/39 words at 0x80142C9C). The raw call result is kept in its own
 * variable with the `& 0x6000` sunk below the range check, letting the
 * scheduler place the `andi` in the branch delay slot. Types and
 * signatures are whatever reproduces the bytes; they are not evidence
 * of the original declaration. */

s32 func_8012CBF4();                                /* static */

void func_80142C9C(void *arg0) {
    s32 temp_v0;
    s32 raw;

    if (M2C_FIELD(arg0, s16 *, 0x102) < 2) {
        raw = func_8012CBF4();
        if (M2C_FIELD(arg0, s32 *, 0x14) > 0x180000) {
            M2C_FIELD(arg0, s32 *, 0x14) = 0x180000;
        }
        temp_v0 = raw & 0x6000;
        if ((temp_v0 != 0) || (M2C_FIELD(arg0, s16 *, 0xA) >= 0x101)) {
            if (M2C_FIELD(arg0, s16 *, 0x102) == 0) {
                M2C_FIELD(arg0, s32 *, 0x14) = -0x80000;
            }
            M2C_FIELD(arg0, s16 *, 0x102) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 0x102) + 1);
        }
    }
}
