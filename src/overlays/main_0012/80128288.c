/* Exact retail overlay0012 [80128288,801282CC), file offset 28130. */
#include "psx_types.h"

/* Recovered across splat's fall-through label at 0x80128290 and verified
 * byte-exact against the registered main_0012 retail blob.  The dispatch
 * table declaration is constrained only by the observed code generation. */

extern u16 D_800B99F6;
extern void (*D_8017E618[])(void);

void func_80128288(void) {
    if (D_800B99F6 < 9U) {
        D_8017E618[D_800B99F6]();
    }
}

