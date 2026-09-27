/* Overlay range [8012AF0C,8012B030) from MAIN.CD member 0012.
 * SHA256(span)=dcd06d314fa5330b4ac886a8536821dbe916435991f6ce109e1de5096ae6cc8d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800132BC(u16 *, u16 *);                    /* extern */
s32 func_80135888(s32, s32, u16 *, void *);      /* static */

s32 func_8012AF0C(void *arg0, void *arg1) {
    u16 sp2C;
    u16 sp2A;
    u16 sp28;
    s32 sp27;
    s32 sp23;
    s32 sp20;
    u16 sp1C;
    u16 sp1A;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 temp_s0;

    sp10 = M2C_FIELD(arg0, u16 *, 0x3A);
    sp12 = M2C_FIELD(arg0, u16 *, 0x3E);
    sp14 = M2C_FIELD(arg0, u16 *, 0x42);
    sp18 = M2C_FIELD(arg0, u16 *, 6);
    sp1A = M2C_FIELD(arg0, u16 *, 0xA);
    sp1C = M2C_FIELD(arg0, u16 *, 0xE);
    sp23 = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    sp27 = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    if (func_80135888(M2C_FIELD(arg1, s32 *, 0x20), M2C_FIELD(arg1, s32 *, 0x58), &sp10, &sp20) != 0) {
        sp28 = M2C_FIELD(arg1, u16 *, 6);
        sp2A = M2C_FIELD(arg1, u16 *, 0xA);
        sp2C = M2C_FIELD(arg1, u16 *, 0xE);
        temp_s0 = func_800132BC(&sp28, &sp10);
        if (temp_s0 >= func_800132BC(&sp28, &sp18)) {
            M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
            M2C_FIELD(arg0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x3C);
            M2C_FIELD(arg0, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0x40);
            return 1;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
