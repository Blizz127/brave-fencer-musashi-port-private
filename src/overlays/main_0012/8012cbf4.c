/* Owner re-derivation from retail assembly (clean input set). */
/* Calls func_8012CC88 with the object, 0x11 and the table D_800D3918. */
#include "psx_types.h"

extern u8 D_800D3918[];
extern int func_8012CC88(void *obj, s32 id, void *table);

/* B28: returns func_8012CC88's result; the retail tail call leaves it in v0,
 * which callers read. Byte-identical (gcc-2.7.2-psx -O2). */
int func_8012CBF4(void *obj) {
    return func_8012CC88(obj, 0x11, D_800D3918);
}
