/* Main-exec range [8005A4A0,8005A4D0) from the SLUS executable.
 * SHA256(span)=955ec17b2f85144ca366bfe83130cfd7a0bbde5436a4aea9a86df71ba9e553a1.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef struct { u8 pad[0x38]; s32 (*fn)(); } T;
extern T *D_80072780;
s32 func_8005A4A0(void) {
    return (u32)D_80072780->fn() >> 31;
}
