/* Exact retail word export for [8005CD18,8005CD48); EXE and assembly verified. */
#include "psx_types.h"

/* Byte-exact retail string length helper [8005CD18,8005CD48). */
s32 func_8005CD18(u8 *source) {
    s32 length = 0;
    if (!source)
        return 0;
    while (*source++)
        length++;
    return length;
}
