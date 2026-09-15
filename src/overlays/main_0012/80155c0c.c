/* Overlay range [80155C0C,80155C64) from MAIN.CD member 0012.
 * SHA256(span)=7d545f436d3195157ba0385303bdfb3a1bd6b381eced1b835a05007767904232.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146CA0(void *);                      /* static */
void func_80154274(void *);                   /* static */
extern s32 *D_800D4DD4;

void func_80155C0C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 2);
    if (M2C_FIELD(arg0, u16 *, 0xB8) == 0x8000) {
        func_80154274(&D_800D4DD4);
        func_80146CA0(arg0);
    }
}
