/* Exact retail word export for [8005CCC8,8005CD18); EXE and assembly verified. */
#include "psx_types.h"

/* Byte-exact retail bounded byte search [8005CCC8,8005CD18).
 * The post-increment is undone on success, returning the matching byte.
 */
u8 *func_8005CCC8(u8 *source, s32 target, s32 count) {
    if (!source || count <= 0)
        return 0;
    while (--count >= 0) {
        if (*source++ == (u8)target)
            return source - 1;
    }
    return 0;
}
