/* sc03_0001 func_801889AC: own C written from the retail words (no known
 * source definition). Verified byte-exact
 * against retail by tools/verify_registry.py (13/13 words at 0x801889AC).
 * Types and signatures are whatever reproduces the bytes; they are not
 * evidence of the original declaration. */
#include "psx_types.h"

extern void func_801889E0(u8 *obj);

void func_801889AC(u8 *obj) {
    *(s16 *)(obj + 0xF4) = -*(u16 *)(obj + 0xFE);
    *(u8 **)(*(u8 **)(obj + 0x20) + 0x20) = obj + 0xEC;
    func_801889E0(obj);
}
