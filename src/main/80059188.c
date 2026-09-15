/* Main-exec range [80059188,80059234) from the SLUS executable.
 * SHA256(span)=3f24c7480bc1481775ada837956957221943282897fcdc7839c7a1dcda82add6.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072784();
extern s32 D_80074000;
extern s32 D_8007401C;
extern s32 D_80074038;
extern s32 D_80074044;

void func_80059188(void *arg0) {
    D_80072784(D_80074000, M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4), (s32) M2C_FIELD(arg0, s16 *, 6));
    D_80072784(D_8007401C, M2C_FIELD(arg0, s16 *, 8), M2C_FIELD(arg0, s16 *, 0xA), M2C_FIELD(arg0, s16 *, 0xC), (s32) M2C_FIELD(arg0, s16 *, 0xE));
    D_80072784(D_80074038, (s16) M2C_FIELD(arg0, u8 *, 0x10));
    D_80072784(D_80074044, (s16) M2C_FIELD(arg0, u8 *, 0x11));
}
