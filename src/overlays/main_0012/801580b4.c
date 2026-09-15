/* Overlay range [801580B4,801581AC) from MAIN.CD member 0012.
 * SHA256(span)=b8663fcb562445a6f0e2a40d82dd5f4fc9800cc5de3fed65fae0c183f1338c01.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146CA0(void *);                      /* static */
void func_80147324();                     /* static */
void func_801473EC(void *);                      /* static */
void func_80147460(void *);                      /* static */
void func_801477E8();                     /* static */
void func_80147AD4(void *, s32, s32, s32); /* static */
void func_80148038(void *, s32);             /* static */
void func_80154274(void *, void *);           /* static */
void func_80155FF8(void *, u8);                  /* static */
void func_80156648(void *);                      /* static */
s32 func_80161418(void *);                          /* static */
extern s32 *D_800D524C;

void func_801580B4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 2);
    if (M2C_FIELD(arg0, u16 *, 0xB8) & 0x4000) {
        func_801477E8(0xFFF40000);
        M2C_FIELD(arg0, s32 *, 0x234) = (s32) (M2C_FIELD(arg0, s32 *, 0x234) + 1);
    }
    if (M2C_FIELD(arg0, s32 *, 0x234) != 0) {
        func_80148038(arg0, 0x10000);
        func_80147460(arg0);
    }
    func_80147AD4(arg0, 0, 0, 0);
    func_801473EC(arg0);
    if (func_80161418(arg0) == 0) {
        if (M2C_FIELD(arg0, u16 *, 0xB8) == 0x8000) {
            func_80156648(arg0);
            M2C_FIELD(arg0, u8 *, 0x1AA) = 0xFU;
            func_80154274(arg0, &D_800D524C);
            func_80147324(0x455);
            func_80146CA0(arg0);
            return;
        }
        func_80155FF8(arg0, M2C_FIELD(arg0, u8 *, 0x1AA));
    }
}
