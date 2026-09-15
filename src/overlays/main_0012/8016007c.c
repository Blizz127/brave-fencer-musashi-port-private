/* Overlay range [8016007C,801600D0) from MAIN.CD member 0012.
 * SHA256(span)=b405897257a35b73974177f076b9cf7876e369e43e17cdadf7c03a6f647ef1de.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80154A74();                     /* static */
extern s8 D_800B9A17;
extern s16 D_801270C0;

void func_8016007C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x184) = 0;
    M2C_FIELD(arg0, s16 *, 0x18A) = 0;
    M2C_FIELD(arg0, s16 *, 0x188) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) & ~0x10);
    D_800B9A17 = 1;
    func_80154A74(0x11);
    D_801270C0 = 1;
}
