/* Owner re-derivation from retail assembly (clean input set). */
/* Calls func_8012F14C with the address 0x34 into the sub-object at offset 0x20. */
#include "psx_types.h"

extern void func_8012F14C(void *p, s32 a1, s32 a2);

void func_80149350(u8 *obj, s32 a1, s32 a2) {
    /* a1/a2 pass straight through (retail leaves them in place for the jal) */
    func_8012F14C(*(u8 **)(obj + 0x20) + 0x34, a1, a2);
}
