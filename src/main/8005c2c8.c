/* Exact retail word export for [8005C2C8,8005C2F8); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (12/12 words at 0x8005C2C8). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

u8 *func_8005C2C8(u8 *p, s32 n) {
    u8 *start;

    if (p == 0) {
        return 0;
    }
    if (n <= 0) {
        return 0;
    }
    start = p;
    do {
        *p = 0;
        n -= 1;
        p += 1;
    } while (n > 0);
    return start;
}
