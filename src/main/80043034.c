/* Main-exec range [80043034,80043060) from the SLUS executable.
 * SHA256(span)=10a6fc24d646f22be8f184959bea92a50dba690615f6db08e6e1513d70c47e79.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Byte-exact word clear used by DMA callback initialization. */
#include "psx_types.h"
void func_80043034(u32 *destination, u32 word_count) {
    while (word_count--)
        *destination++ = 0;
}
