/* Overlay range [80173E1C,80173EF8) from MAIN.CD member 0012.
 * SHA256(span)=8bdb67da56ffdd506fc748d4fe80733bb9ca85e416018134157e176041a48b80.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015954(void *, s32);              /* extern */
void func_80139914(s32);                         /* static */
s32 func_801399F0(s32);                             /* static */
void func_801484B0(void *, void *);        /* static */
void func_80149350(void *, void *, void *); /* static */
void func_80154274(void *, void *);           /* static */
void func_80171A1C(void *);                      /* static */
extern s32 *D_800D5DC0;
extern s32 D_80127508;

void func_80173E1C(void *arg0) {
    s32 sp18;
    s32 sp10;
    s32 temp_a0;
    s32 temp_v0;

    if (D_80127508 != 0) {
        func_801484B0(&sp10, &sp18);
        func_80149350(arg0, &sp10, &sp10);
        func_80015954(&sp10, D_80127508 + 4);
    }
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x198);
    if (temp_a0 != 0) {
        if (func_801399F0(temp_a0) != 0) {
            func_80139914(M2C_FIELD(arg0, s32 *, 0x198));
            M2C_FIELD(arg0, s32 *, 0x198) = 0;
            goto block_7;
        }
    } else {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x200) - 1;
        M2C_FIELD(arg0, s32 *, 0x200) = temp_v0;
        if (temp_v0 == -1) {
block_7:
            func_80154274(arg0, &D_800D5DC0);
            func_80171A1C(arg0);
        }
    }
}
