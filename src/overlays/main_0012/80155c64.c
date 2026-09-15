/* Overlay range [80155C64,80155D70) from MAIN.CD member 0012.
 * SHA256(span)=730fe3e31e0901fd13695efa38cfa7a0c81e1443d8e066cee1bdfa48d8666fb8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146CA0(void *);                      /* static */
void func_80146D90(void *);                      /* static */
void func_80147460(void *);                      /* static */
void func_80148038();                     /* static */
void func_8014C010(void *, s32);             /* static */
s32 func_8014CC28(void *);                          /* static */
s32 func_8014ED28(void *);                          /* static */
s32 func_8014FA04(void *);                          /* static */
void func_80154274(void *, void *);           /* static */
void func_80155FF8(void *, u8);                  /* static */
void func_801599A4(void *);                      /* static */
void func_80159B3C(void *);                      /* static */
void func_8015BF48(void *);                      /* static */
extern s32 *D_800D4DF4;

void func_80155C64(void *arg0) {
    s32 temp_v0;

    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 2);
    func_80148038(0x30000);
    func_80147460(arg0);
    if (func_8014ED28(arg0) != 0) {
        func_80146D90(arg0);
    }
    if ((M2C_FIELD(arg0, s32 *, 0x34) > 0) && (func_8014CC28(arg0) != 0)) {
        func_801599A4(arg0);
        func_80159B3C(arg0);
        goto block_9;
    }
    temp_v0 = func_8014FA04(arg0);
    if (temp_v0 & 0x4000) {
        func_801599A4(arg0);
        func_8014C010(arg0, 1);
        func_8015BF48(arg0);
        return;
    }
    if (temp_v0 & 0x2000) {
        func_80154274(arg0, &D_800D4DF4);
        func_80146CA0(arg0);
block_9:
        func_8014C010(arg0, 1);
        return;
    }
    func_80155FF8(arg0, M2C_FIELD(arg0, u8 *, 0x1AA));
}
