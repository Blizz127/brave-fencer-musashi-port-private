/* Overlay range [8015795C,80157A8C) from MAIN.CD member 0012.
 * SHA256(span)=ad113a7d6ba6553483b5dd755b07fef94b2e070bbeff48d71d608e681f573cec.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8018067C;
void func_80146CA0(void *);                      /* static */
void func_80146D90(void *);                      /* static */
void func_80146DB8(void *, s32 (*)());       /* static */
void func_80146E90(void *, s32);             /* static */
void func_801473EC(void *);                      /* static */
void func_80147460(void *);                      /* static */
void func_801477E8(void *, s32);             /* static */
void func_80147A10();                     /* static */
void func_80147A84(void *);                      /* static */
void func_80148038(void *, s32);             /* static */
s32 func_8014ED28(void *);                          /* static */
void func_80154274(void *, void *);           /* static */
void func_80154A74(void *, s32);             /* static */
void func_80155FF8(void *, u8);                  /* static */
void func_80157A8C(void *);                      /* static */
s32 func_80161450(void *);                          /* static */
void func_801725A4(void *);                      /* static */
extern s32 *D_800D5178;

void func_8015795C(void *arg0) {
    s32 temp_v0;

    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 2);
    func_80147A10(0x400);
    if (M2C_FIELD(arg0, s32 *, 0x2C) >= 0) {
        M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    }
    func_80147A84(arg0);
    func_801473EC(arg0);
    func_80148038(arg0, 0x1A000);
    func_80147460(arg0);
    if (func_8014ED28(arg0) != 0) {
        func_80146D90(arg0);
    }
    temp_v0 = func_80161450(arg0);
    if (temp_v0 & 5) {
        func_80157A8C(arg0);
        func_80146E90(arg0, 8);
        func_80146CA0(arg0);
    }
    if (temp_v0 == 0) {
        func_80155FF8(arg0, M2C_FIELD(arg0, u8 *, 0x1AA));
        if (M2C_FIELD(arg0, u8 *, 0x1C0) != 0) {
            func_80154A74(arg0, 0x17);
            func_80154274(arg0, &D_800D5178);
            func_80146DB8(arg0, D_8018067C);
            func_801477E8(arg0, 0xFFF40000);
            M2C_FIELD(arg0, s16 *, 2) = 4;
        }
        func_801725A4(arg0);
    }
}
