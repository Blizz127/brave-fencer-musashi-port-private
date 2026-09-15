/* Overlay range [801776EC,80177784) from MAIN.CD member 0012.
 * SHA256(span)=2c4bb06c7a9e724b179e915ba02f846911d70dc1dcc2e0539ea84ba48b4fbbd5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u8 D_8011F7AB;

void func_801776EC(void *arg0) {
    switch (D_8011F7AB) {                           /* irregular */
    default:
        D_8011F7AB = 0;
        /* fallthrough */
    case 0:
        M2C_FIELD(arg0, s8 *, 4) = 0xFF;
        M2C_FIELD(arg0, s8 *, 6) = 0x30;
        M2C_FIELD(arg0, s8 *, 5) = 0x30;
        break;
    case 1:
        M2C_FIELD(arg0, s8 *, 5) = 0xFF;
        M2C_FIELD(arg0, s8 *, 6) = 0x30;
block_9:
        M2C_FIELD(arg0, s8 *, 4) = 0x30;
        break;
    case 2:
        M2C_FIELD(arg0, s8 *, 6) = 0xFF;
        M2C_FIELD(arg0, s8 *, 5) = 0x30;
        goto block_9;
    }
    D_8011F7AB += 1;
}
