/* Exact retail word export for [8002E5F8,8002E638); EXE and assembly verified. */
#include "psx_types.h"

/* Decompiled by hand from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_80043974(s8 *);                              /* static */
extern s8 D_800A4F19;

/* Sibling of func_8002E5BC with a different fill. The buffer must be
 * unsigned: `0x80` overflows `s8` and compiles to `-0x80`, while
 * retail loads `+0x80`. */
void func_8002E5F8(void) {
    u8 buf[4];

    buf[0] = 0x80;
    buf[1] = 0;
    buf[2] = 0x80;
    buf[3] = 0;
    func_80043974(buf);
    D_800A4F19 = 1;
}
