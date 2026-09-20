/* Main-exec range [80062388,80062394) from the SLUS executable.
 * SHA256(span)=c28242c524b4002a079049d874fd1774d14c53808b23515f50cb9a0c4550529a.
 * Word export for the native seam. */
#include "psx_types.h"

__asm__(
    ".set noreorder\n"
    ".globl func_80062388\n"
    ".type func_80062388, @function\n"
    "func_80062388:\n"
    "lui $at, 0x8007\n"
    "jr  $ra\n"
    "sw  $a0, 0x2a24($at)\n"
    ".size func_80062388, .-func_80062388\n"
    ".set reorder\n"
);

