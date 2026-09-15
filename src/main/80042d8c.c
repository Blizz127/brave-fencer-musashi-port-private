/* Main-exec range [80042D8C,80042DB8) from the SLUS executable.
 * SHA256(span)=10a6fc24d646f22be8f184959bea92a50dba690615f6db08e6e1513d70c47e79.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled and verified byte-exact against the registered retail EXE. */
void func_80042D8C(u32 *destination, u32 word_count) {
    while (word_count--)
        *destination++ = 0;
}
