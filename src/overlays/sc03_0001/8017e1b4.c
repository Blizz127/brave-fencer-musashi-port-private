/* sc03_0001 func_8017E1B4: own C written from the retail words (no upstream
 * definition). Verified byte-exact against retail by tools/verify_registry.py.
 * Types and signatures are whatever reproduces the bytes; they are not
 * evidence of the original declaration. */
#include "psx_types.h"

extern void func_8017E204(u8 *rec);
extern u8 D_801EE888[];

void func_8017E1B4(void) {
    s32 i;
    u8 *p;
    for (i = 0, p = D_801EE888; i < 4; i++, p += 0x24) {
        if (*(s32 *)(p + 0x1C) != 0) {
            func_8017E204(p);
            break;
        }
    }
}
