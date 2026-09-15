/* Overlay range [80148800,8014880C) from MAIN.CD member 0012.
 * SHA256(span)=6b256d0f903c2ea0c47e0a03667002b297bbe1a731a5cc4000c36c95e09c5ee3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

u16 func_80148800(void *arg0) {
    return M2C_FIELD(arg0, u16 *, 0xAC);
}
