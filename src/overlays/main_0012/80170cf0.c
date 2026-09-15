/* Overlay range [80170CF0,80170D68) from MAIN.CD member 0012.
 * SHA256(span)=4110076ec7398b3d4ceba2226712998d947ec99582ff6beab01773b0f1e01f95.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801718AC(s32);                         /* static */
extern s32 (*D_8011F738)();
extern s32 D_8011F73C;
extern s32 D_8011F740;

void func_80170CF0(void *arg0) {
    s32 var_a0;
    u8 temp_v1;

    D_8011F738();
    temp_v1 = M2C_FIELD(arg0, u8 *, 0x217);
    switch (temp_v1) {                              /* irregular */
    case 1:
        var_a0 = D_8011F73C;
block_6:
        func_801718AC(var_a0);
        return;
    case 2:
        var_a0 = D_8011F740;
        goto block_6;
    }
}
