/* Overlay range [80137BD8,80137D08) from MAIN.CD member 0012.
 * SHA256(span)=ccde93a6fcd537f58b2b0c57ba03861dd924a3242074839c53bb533a29c865ec.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80137DD4(void *, s8 *, void *);        /* static */
void func_801392FC(u8, void *);                  /* static */
void func_80139680(void *, void *);              /* static */
void func_801397B0(void *);                      /* static */
extern s32 *D_800A6518;
extern u16 D_800B99D8;
extern u16 D_800B9A02;
extern s32 D_80127524;

void func_80137BD8(void *arg0) {
    s8 sp12;
    s8 sp11;
    s8 sp10;
    s16 temp_v1;

    if (M2C_FIELD(arg0, s32 *, 8) & 0x1000) {
        func_801392FC(M2C_FIELD(arg0, u8 *, 0x1E), (D_800B9A02 * 0x14) + &D_800A6518);
        if (M2C_FIELD(arg0, u8 *, 0x20) != 0) {
            func_801397B0(arg0);
        }
    }
    if (D_80127524 == arg0) {
        temp_v1 = M2C_FIELD(arg0, s16 *, 4);
        if (temp_v1 == 7) {
            sp10 = 0x39;
            sp11 = 0xFF;
            sp12 = 0x71;
            func_80137DD4(arg0, &sp10, (D_800B9A02 * 0x14) + &D_800A6518);
            return;
        }
        if ((temp_v1 == 3) && (D_800B99D8 & 4)) {
            func_80139680(arg0, (D_800B9A02 * 0x14) + &D_800A6518);
        }
    }
}
