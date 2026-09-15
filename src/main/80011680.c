/* Main-exec range [80011680,800116E0) from the SLUS executable.
 * SHA256(span)=c63c3968381ffeabbf11ceb59085c691aa2e9f7b4ec6087ea2cad6c81b08382e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80011818();                     /* static */
void func_8002D4C8(s32, s32);            /* static */
extern s32 *D_800AF630;

void func_80011680(void) {
    M2C_FIELD(&D_800AF630, s8 *, 0xA434) = 0;
    func_8002D4C8(0x29, 0);
    func_80011818(5);
}
