/* Overlay range [801458CC,801458E0) from MAIN.CD member 0012.
 * SHA256(span)=62f0fee431a91fb9ec6acebb2bed976bb4878f0c2039b29a4b09ccbcc70ffe6f.
 * Word export for the native seam. */
#include "psx_types.h"

__asm__(
"\n"
".set\tnoreorder\n"
".set noreorder\n"
".globl func_801458CC\n"
".type func_801458CC, @function\n"
"func_801458CC:\n"
"move $sp, $fp\n"
"lw   $fp, 0($sp)\n"
"addiu $sp, $sp, 8\n"
"jr   $ra\n"
"nop\n"
".size func_801458CC, .-func_801458CC\n"
".set reorder\n"
".set\treorder\n"
);

