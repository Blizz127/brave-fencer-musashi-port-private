/* Exact retail word export for [8005C358,8005C388); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (12/12 words at 0x8005C358). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

u8 *func_8005C358(u8 *p, s32 value, s32 n) {
    u8 *start;

    if (p == 0) {
        return 0;
    }
    if (n <= 0) {
        return 0;
    }
    start = p;
    do {
        *p = (u8) value;
        n -= 1;
        p += 1;
    } while (n > 0);
    return start;
}
