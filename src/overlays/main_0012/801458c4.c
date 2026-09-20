/* Overlay range [801458C4,801458CC) from MAIN.CD member 0012.
 * SHA256(span)=9cacc41cfeb6c27db5a55b919d659039599e79af2c134668d94860cb90ef3938.
 * Word export for the native seam (direct-jump thunk). */
#include "psx_types.h"

__asm__(
"\n"
".set\tnoreorder\n"
".set noreorder\n"
".globl func_801458C4\n"
".type func_801458C4, @function\n"
"func_801458C4:\n"
"j   func_801458CC\n"
"nop\n"
".size func_801458C4, .-func_801458C4\n"
".set reorder\n"
".set\treorder\n"
);

