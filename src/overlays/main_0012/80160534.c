/* Overlay range [80160534,801607B8) from MAIN.CD member 0012.
 * SHA256(span)=7766da2917fc0cfd5b2b4315816b227928b287a5a11b71e6f505fa6d7c0a3cc2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800CF8B4();                                /* extern */
extern s32 D_80180A1C;
s32 func_80146E98(void *);                          /* static */
void func_80147078(void *, s32);                         /* static */
void func_801473EC(void *);                            /* static */
void func_80147AD4(void *, s32, s32, s32);             /* static */
s32 func_801487F4(void *);                          /* static */
s32 func_80148800(void *);                          /* static */
void func_80149020();                                  /* static */
void func_80149034(void *);                            /* static */
s32 func_801491C4(void *);                          /* static */
s32 func_80149AA8(void *);                          /* static */
void func_80149AD4(void *);                            /* static */
s32 func_80149B54(void *);                          /* static */
void func_80149BAC(void *);                            /* static */
s32 func_8014D738(void *);                          /* static */
void func_80159B70(void *);                            /* static */
void func_8015C714(void *);                            /* static */
void func_8015E9B8(void *);                            /* static */
void func_8015F00C(void *);                            /* static */
void func_80161208(void *);                            /* static */
extern u8 D_80078EBF;
extern u8 D_80078EC0;
extern u16 D_801152A0;

void func_80160534(void *arg0) {
    func_80149020();
    func_80149034(arg0);
    if ((D_80078EC0 & 0x7F) && (func_80148800(arg0) & 0x90)) {
        if (D_80078EBF == 0x80) {
            *(D_80180A1C + (arg0->unk0 * 4))(arg0);
            func_80147078(arg0, 0x13);
            func_8015F00C(arg0);
            return;
        }
        if (func_80149B54(arg0) != 0) {
            *(D_80180A1C + (arg0->unk0 * 4))(arg0);
            func_80149BAC(arg0);
            return;
        }
        goto block_6;
    }
block_6:
    if (func_80149AA8(arg0) != 0) {
        *(D_80180A1C + (arg0->unk0 * 4))(arg0);
        func_80149AD4(arg0);
        return;
    }
    if (func_80146E98(arg0) != 0) {
        if (func_801487F4(arg0) & 8) {
            *(D_80180A1C + (arg0->unk0 * 4))(arg0);
            func_80147078(arg0, 0x11);
            func_8015E9B8(arg0);
            return;
        }
        *(D_80180A1C + (arg0->unk0 * 4))(arg0);
        func_80147078(arg0, 0);
        func_80159B70(arg0);
        return;
    }
    if (func_800CF8B4() != 0) {
        arg0->unk20->unk12 = (s16) ((D_801152A0 + func_801491C4(arg0)) & 0xFFF);
    }
    func_80147AD4(arg0, arg0->unk234, arg0->unk238, arg0->unk23C);
    func_801473EC(arg0);
    if (func_8014D738(arg0) != 0) {
        *(D_80180A1C + (arg0->unk0 * 4))(arg0);
        func_80147078(arg0, 9);
        func_8015C714(arg0);
        return;
    }
    func_80161208(arg0);
}
