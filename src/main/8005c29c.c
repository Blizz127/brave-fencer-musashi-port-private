/* Main-exec range [8005C29C,8005C2C8) from the SLUS executable.
 * SHA256(span)=bc4c08f514cc2afda0a05a2a41045b0d2c220a0f419f99d69759e72118c6450b.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Byte-exact graphics reset helper [8005C29C,8005C2C8). Byte storage and
 * unsigned countdown also permit this same body to run on bounded native RAM. */
void func_8005C29C(u8 *destination, s32 value, u32 count) {
    while (count--)
        *destination++ = value;
}
