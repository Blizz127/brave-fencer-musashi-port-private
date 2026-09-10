#include "psx_types.h"

/* Exact test-and-clear continuation [80061B58,80061C60).  The recovered
 * stores are intentionally kept as words so the source CPU sees the same
 * helper calls and SYS2-visible return path as retail. */
__asm__(
    ".set noreorder\n"
    ".globl func_80061B58\n"
    ".type func_80061B58, @function\n"
    "func_80061B58:\n"
    ".size func_80061B58, .-func_80061B58\n"
    ".set reorder\n"
);

