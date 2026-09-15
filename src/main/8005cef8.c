/* Main-exec range [8005CEF8,8005CF04) from the SLUS executable.
 * SHA256(span)=38790d1aeb4d336da0f746d61d8da4152afc210c2c260c98ac350db6321e05cd.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Retail startup service boundary; native service behavior remains unbound. */
__asm__(
    ".set noreorder\n"
    ".globl func_8005CEF8\n"
    ".type func_8005CEF8, @function\n"
    "func_8005CEF8:\n"
    "addiu $t2,$zero,0xB0\n"
    "jr $t2\n"
    "addiu $t1,$zero,0x19\n"
    ".size func_8005CEF8, .-func_8005CEF8\n"
    ".set reorder\n"
);
