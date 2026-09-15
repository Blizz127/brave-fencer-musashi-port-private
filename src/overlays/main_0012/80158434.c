/* Overlay range [80158434,80158548) from MAIN.CD member 0012.
 * SHA256(span)=72a356bc4f7bfaee66e693be25e39dedc63b40ac93bc5c834cab417550e03206.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_801806B0;
void func_80146CA0(void *);                      /* static */
void func_80146DB8(void *, s32 (*)());       /* static */
s32 func_80146E98(void *);                          /* static */
void func_801473EC(void *);                      /* static */
void func_80147460(void *);                      /* static */
void func_801474EC(void *);                      /* static */
void func_801477E8(void *, s32);             /* static */
void func_80147AD4(void *, s32, s32, s32); /* static */
void func_80148038(void *, s32);             /* static */
void func_8014CBF8();                            /* static */
void func_80154274(void *, void *);           /* static */
void func_80155FF8(void *, u8);                  /* static */
s32 func_801615C4(void *, s32);                 /* static */
extern s32 *D_800D533C;

void func_80158434(void *arg0) {
    s32 temp_v0;
    s32 var_v0;

    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 2);
    if (M2C_FIELD(arg0, u16 *, 0xB8) & 0x4000) {
        M2C_FIELD(arg0, s32 *, 0x234) = (s32) (M2C_FIELD(arg0, s32 *, 0x234) + 1);
        func_8014CBF8();
        func_801474EC(arg0);
        func_801477E8(arg0, 0xFFFA0000);
        func_80146DB8(arg0, D_801806B0);
    }
    if (M2C_FIELD(arg0, s32 *, 0x234) != 0) {
        func_80148038(arg0, 0x10000);
        func_80147460(arg0);
        func_80147AD4(arg0, 0, 0, 0);
        func_801473EC(arg0);
    }
    temp_v0 = func_801615C4(arg0, 0);
    if (temp_v0 != 0) {
        var_v0 = temp_v0 & 0x2000;
        if (temp_v0 != 1) {
            goto block_8;
        }
        goto block_9;
    }
    var_v0 = func_80146E98(arg0);
block_8:
    if (var_v0 != 0) {
block_9:
        func_80154274(arg0, &D_800D533C);
        func_80146CA0(arg0);
        return;
    }
    func_80155FF8(arg0, M2C_FIELD(arg0, u8 *, 0x1AA));
}
