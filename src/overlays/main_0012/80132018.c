/* Overlay range [80132018,801320D0) from MAIN.CD member 0012.
 * SHA256(span)=e3b7c919086f00af129dabf9e1ddb3d20b6101ad0e2aa808ccd1f13ef5d29531.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001C214(s32, s32);                /* extern */
extern s32 D_8017E8A8[];
extern s32 D_8017E8AC;
s32 func_8012C1B8();                                /* static */
void func_8012CAE4(void *);                      /* static */

void func_80132018(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_8012C1B8();
    M2C_FIELD(arg0, s32 *, 0x20) = temp_v0;
    if (temp_v0 == 0) {
        func_8012CAE4(arg0);
        return;
    }
    func_8001C214(temp_v0, 0);
    M2C_FIELD(arg0, s16 *, 0x5C) = 0x80;
    M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
    M2C_FIELD(arg0, void **, 0x58) = (void *) (((M2C_FIELD(arg0, u16 *, 0x70) & 0xFFF) * 0x14) + D_8017E8AC);
    M2C_FIELD(arg0, s16 *, 0xFC) = (s16) (((u16) M2C_FIELD(arg0, u16 *, 0x70) >> 0xC) << 9);
    M2C_FIELD(arg0, s32 *, 0xDC) = (s32) *(D_8017E8A8 + ((M2C_FIELD(arg0, u16 *, 0x70) & 0xFFF) * 0x14));
}
