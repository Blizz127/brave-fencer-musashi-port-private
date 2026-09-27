/* Overlay range [801506A4,80150820) from MAIN.CD member 0012.
 * SHA256(span)=738fd1954aefd94024d6a3ac2fbbfcb627bc620094eb57be86986d277a34e11e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017FFE0[];
extern s32 D_8017FFE8[];
extern s32 D_8017FFF0[];
void func_80147324();                     /* static */
void func_8014ACE8(s32, s32, u16);           /* static */
void func_8014ADA8(s32, u16);                    /* static */
void func_8014BB24(s32, u16, s32);           /* static */
void func_80150820(s32, u16);                    /* static */
void func_8015086C(s32);                         /* static */
extern u16 D_80078EB4;

void func_801506A4(s32 arg0, void *arg1) {
    u16 temp_v1;

    temp_v1 = M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(arg1, u16 *, 0x5C) = (u16) (M2C_FIELD(arg1, u16 *, 0x5C) | 1);
    switch (temp_v1) {                              /* irregular */
    case 0x31:
        func_80147324(0x452);
        func_8014ADA8(arg0, *(D_8017FFE0 + (M2C_FIELD(arg1, s16 *, 0x70) * 2)));
        func_8014ACE8(arg0, 3, *(D_8017FFE0 + (M2C_FIELD(arg1, s16 *, 0x70) * 2)));
        return;
    case 0x32:
        if (D_80078EB4 != 0) {
            func_80147324(0x452);
            func_8014BB24(arg0, *(D_8017FFE8 + (M2C_FIELD(arg1, s16 *, 0x70) * 2)), 1);
            func_8014ACE8(arg0, 2, *(D_8017FFE8 + (M2C_FIELD(arg1, s16 *, 0x70) * 2)));
            return;
        }
        return;
    case 0x33:
        func_80147324(0x452);
        func_80150820(arg0, *(D_8017FFF0 + (M2C_FIELD(arg1, s16 *, 0x70) * 2)));
        return;
    case 0xC5:
    case 0x27B:
        func_80147324(0x452);
        func_8015086C(arg0);
        break;
    }
}
