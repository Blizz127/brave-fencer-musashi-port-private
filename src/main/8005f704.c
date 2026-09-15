/* Exact retail word export for [8005F704,8005F728); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80078A48;

void *func_8005F704(s32 arg0) {
    void *var_v0;

    var_v0 = &D_80078A48;
    if (arg0 & 0xF0) {
        var_v0 = &D_80078A48 + 0xF0;
    }
    return var_v0;
}
