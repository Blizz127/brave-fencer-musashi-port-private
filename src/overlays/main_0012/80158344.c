/* Overlay range [80158344,80158434) from MAIN.CD member 0012.
 * SHA256(span)=e65a1d28688911fb2f1e7115c87bbf99ed6211d3cae08029b5c411810d3e9923.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146994(s32, void *, s32, s32); /* static */
void func_80146CA0(void *);                      /* static */
void func_80146E90(void *, s32);             /* static */
void func_80147324();                     /* static */
void func_80154274(void *, void *);           /* static */
void func_80155FF8(void *, u8);                  /* static */
void func_80156648(void *);                      /* static */
s32 func_801585AC(void *);                          /* static */
void func_801599A4(void *);                      /* static */
void func_80159B3C(void *);                      /* static */
s32 func_80161208();                                /* static */
extern s32 *D_800D52E8;

void func_80158344(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 2);
    if (func_80161208() == 0) {
        if (func_801585AC(arg0) != 0) {
            func_80156648(arg0);
            M2C_FIELD(arg0, u8 *, 0x1AA) = 0x11U;
            func_80154274(arg0, &D_800D52E8);
            M2C_FIELD(arg0, s32 *, 0x234) = 0;
            func_80147324(0x455);
            func_80146994(4, arg0, 9, 0);
            func_80146994(5, arg0, 0xD, 0);
            func_80146E90(arg0, 0x12C);
            func_80146CA0(arg0);
        }
        if (M2C_FIELD(arg0, u16 *, 0xB8) & 0x8000) {
            func_801599A4(arg0);
            func_80159B3C(arg0);
            return;
        }
        func_80155FF8(arg0, M2C_FIELD(arg0, u8 *, 0x1AA));
    }
}
