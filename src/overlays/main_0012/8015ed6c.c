/* Overlay range [8015ED6C,8015EDA0) from MAIN.CD member 0012.
 * SHA256(span)=727d7dc321053b2ccb4186af02debbc5d8198d81b93a24abe676316cd2297597.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80149048();                            /* static */
extern s8 D_80078EBF;

void func_8015ED6C(void *arg0) {
    D_80078EBF = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) & ~1);
    func_80149048();
}
