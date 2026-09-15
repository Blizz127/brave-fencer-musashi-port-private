/* Main-exec range [8004924C,80049274) from the SLUS executable.
 * SHA256(span)=ae4cfe9745644b125bec4219d0660a7608bef37aec1d6cdb3d1e601e1112b0bf.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* GTE/cop2 mnemonic overlay: ordinary C cannot emit coprocessor ops.
 * Verified by tools/match_function.py. */
__asm__(
    ".set noreorder\n"
    ".globl func_8004924C\n"
    ".type func_8004924C, @function\n"
    "func_8004924C:\n"
    "lwc2 $9, 0x0($a0)\n"
    "lwc2 $10, 0x4($a0)\n"
    "lwc2 $11, 0x8($a0)\n"
    "nop\n"
    "swc2 $9, 0x0($a1)\n"
    "swc2 $10, 0x4($a1)\n"
    "swc2 $11, 0x8($a1)\n"
    "jr $ra\n"
    "nop\n"
    ".size func_8004924C, .-func_8004924C\n"
    ".set reorder\n"
);
