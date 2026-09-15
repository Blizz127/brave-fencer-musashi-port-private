/* Overlay range [80145B24,80145BF8) from MAIN.CD member 0012.
 * SHA256(span)=8e6b43d6d8746bc27309c9ceb3cc4a60ee6d375dccfc29f2dbb360d5b9c63e09.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80029124(s32, s32);            /* extern */
void func_800291C8(s32, s32);            /* extern */
s32 func_800291DC();                         /* extern */
s32 func_80029504();                                /* extern */
void func_80029514();                     /* extern */
void func_80162120();                            /* static */
void func_80165A50(void *);                   /* static */
extern u8 D_80078EC0;
extern s32 *D_800AF630;
extern s32 *D_80126B58;

void func_80145B24(void) {
    s32 temp_s0;

    temp_s0 = func_80029504();
    if (func_800291DC(8) & 0x8000) {
        func_800291C8(8, 0);
        func_80162120();
    }
    if (temp_s0 >= 0x6A4) {
        func_80029124(0x1A, 0);
        func_80029124(0x8E, 0);
        func_80029124(0x143, 0);
        if (D_80078EC0 & 0x7F) {
            D_80078EC0 = 1;
        }
        func_80165A50(&D_80126B58);
        func_80029514(0x4B0);
    }
    M2C_FIELD(&D_800AF630, s16 *, 0xA3DA) = 0x3000;
}
