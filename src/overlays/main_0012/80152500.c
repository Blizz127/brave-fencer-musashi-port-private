/* Overlay range [80152500,801525F4) from MAIN.CD member 0012.
 * SHA256(span)=d13f7f4d95af45c5ae17d825f65f888e1c7a5daf83b8e1d008c65f0b9b3dad24.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801473EC(void *);                      /* static */
void func_80147460(void *);                      /* static */
void func_80147A84(void *);                      /* static */
void func_80148038(void *, s32);             /* static */
void func_80149020();                            /* static */
void func_8014C010(void *, s32);             /* static */
void func_801525F4(void *);                      /* static */
s32 func_801535F4(void *);                          /* static */
void func_80159B3C(void *);                      /* static */
void func_8015BF48(void *);                      /* static */
void func_80165718(void *);                      /* static */

void func_80152500(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    func_80149020();
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1C);
    if (temp_v0 == 0) {
        if (M2C_FIELD(arg0, u16 *, 0xB8) == 0x8000) {
            func_801525F4(arg0);
            func_80159B3C(arg0);
            goto block_11;
        }
        goto block_4;
    }
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (temp_v0 - 1);
block_4:
    func_80147A84(arg0);
    func_801473EC(arg0);
    func_80148038(arg0, 0x8000);
    func_80147460(arg0);
    temp_v0_2 = func_801535F4(arg0);
    switch (temp_v0_2) {                            /* irregular */
    case 1:
        func_801525F4(arg0);
        func_80159B3C(arg0);
block_10:
        func_8014C010(arg0, 1);
block_11:
        func_80165718(arg0);
        return;
    case 2:
        func_801525F4(arg0);
        func_8015BF48(arg0);
        goto block_10;
    }
}
