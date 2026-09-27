/* Main-exec range [80059074,80059188) from the SLUS executable.
 * SHA256(span)=5b0d8f67053d59321e94b81f53d174f65378d58d9fe836f243baa3ce30c5ab84.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072784();
extern s32 D_80073F80;
extern s32 D_80073FA8;
extern s32 D_80073FC0;
extern s32 D_80073FD0;
extern s32 D_80073FE8;
extern s32 D_80073FF4;

void func_80059074(void *arg0) {
    u16 temp_v0;

    D_80072784(D_80073FA8, M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4), (s32) M2C_FIELD(arg0, s16 *, 6));
    D_80072784(D_80073FC0, M2C_FIELD(arg0, s16 *, 8), M2C_FIELD(arg0, s16 *, 0xA));
    D_80072784(D_80073FD0, M2C_FIELD(arg0, s16 *, 0xC), M2C_FIELD(arg0, s16 *, 0xE), M2C_FIELD(arg0, s16 *, 0x10), (s32) M2C_FIELD(arg0, s16 *, 0x12));
    D_80072784(D_80073FE8, (s16) M2C_FIELD(arg0, u8 *, 0x16));
    D_80072784(D_80073FF4, (s16) M2C_FIELD(arg0, u8 *, 0x17));
    temp_v0 = M2C_FIELD(arg0, u16 *, 0x14);
    D_80072784(D_80073F80, (temp_v0 >> 7) & 3, (temp_v0 >> 5) & 3, (temp_v0 << 6) & 0x7C0, ((temp_v0 * 0x10) & 0x100) + ((temp_v0 >> 2) & 0x200));
}
