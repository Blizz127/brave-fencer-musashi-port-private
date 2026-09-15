/* Overlay range [8014B084,8014B12C) from MAIN.CD member 0012.
 * SHA256(span)=959d1420d5cf4f69afdbb86b5a7e123a2e0dcfcf50b05d1293936943f0ed6409.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002AC98();                                  /* extern */
void func_800D10EC(u8);                                /* extern */
void func_80145C54();                                  /* static */
extern u16 D_80078EAC;
extern u8 D_80078EBA;

void func_8014B084(void) {
    s32 temp_a0_2;
    s32 temp_hi;
    u16 temp_v0;
    u8 temp_a0;
    u8 temp_a0_3;

    temp_v0 = D_80078EAC + 1;
    temp_a0 = D_80078EBA + 1;
    D_80078EAC = temp_v0;
    D_80078EBA = temp_a0;
    if ((u32) (temp_v0 & 0xFFFF) >= 0x16EU) {
        D_80078EAC = 1;
    }
    temp_a0_2 = temp_a0 & 0xFF;
    temp_hi = (temp_a0 & 0xFF) / 7;
    temp_a0_3 = temp_a0_2 - (((u32) (temp_hi + ((u32) (temp_a0_2 - temp_hi) >> 1)) >> 2) * 7);
    D_80078EBA = temp_a0_3;
    func_800D10EC(temp_a0_3);
    func_8002AC98();
    func_80145C54();
}
