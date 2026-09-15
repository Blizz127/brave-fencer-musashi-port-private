/* Overlay range [80146128,80146360) from MAIN.CD member 0012.
 * SHA256(span)=076ae1190d7ca1d64d4a711ebe917b9d26cac5a00d5a59e8619b7bd4c029faf6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015978(void *, void *);                    /* extern */
s32 func_80029104(void *);                          /* extern */
void func_80029344();                                  /* extern */
void func_80146FC4(void *);                               /* static */
void func_80147098(void *);                               /* static */
void func_801473DC(void *);                               /* static */
void func_80148648(void *, s32);                            /* static */
void func_80149228(void *);                               /* static */
void func_80149BEC(void *);                               /* static */
void func_8014A59C(void *);                               /* static */
void func_8014A638(void *);                               /* static */
void func_8014A680(void *);                               /* static */
void func_8014A6A8(void *);                               /* static */
void func_8014A71C(void *);                               /* static */
void func_8014ADE0(void *);                               /* static */
void func_8014B190(void *);                               /* static */
void func_8014B350(void *);                               /* static */
void func_8014B504(void *);                               /* static */
void func_8014B5D0(void *);                               /* static */
void func_8014B7A4(void *);                               /* static */
void func_8014C99C(void *);                               /* static */
void func_80150A70(void *, void *);                          /* static */
void func_80154418(void *);                               /* static */
void func_80154BE4(void *);                               /* static */
s32 func_80155458(void *);                             /* static */
void func_80161A90(void *);                               /* static */
void func_80161D58(void *);                               /* static */
void func_801654A8(void *);                               /* static */
void func_80165694(void *);                               /* static */
void func_8016F14C(void *);                               /* static */
void func_80172588(void *);                               /* static */
extern u8 D_80078EC1;
extern s32 D_80078EC8;
extern s32 D_801150F0;
extern s16 D_801152B8;
extern s32 D_8011F730;
extern s16 D_8012693A;
extern s32 D_80126B58;
extern void *D_80126B78;
extern s32 D_80126B9C;
extern s32 *D_80126BE0;

s32 func_80146128(void) {
    void *temp_s1;
    void *var_a0;

    temp_s1 = D_80126B78;
    func_80146FC4(&D_80126B58);
    D_801150F0.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_801150F0.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    func_80150A70(&D_80126B58, &D_80126BE0);
    func_80147098(&D_80126B58);
    func_8014A638(&D_80126B58);
    D_8011F730 = 0;
    D_801152B8 = 0;
    D_8012693A = 0;
    if (D_80078EC1 == 0x10) {
        if (D_80078EC8 != 0) {
            temp_s1->unk2 = 6;
            D_80126B9C |= 0x800;
        } else {
            goto block_4;
        }
    } else {
block_4:
        temp_s1->unk2 = 1;
        D_80126B58.unk44 = (s32) (D_80126B58.unk44 & ~0x800);
    }
    if (D_80126B58.unk1B0 != 0) {
        D_80126B58.unk1B0 = (s32) (D_80126B58.unk1B0 - 1);
    }
    if (func_80155458(&D_80126B58) == 0) {
        var_a0 = &D_80126B58 + 4;
        if (!(D_80126B58.unk44 & 0x04000000)) {
            if (func_80029104(var_a0) & 0xFF) {
                func_8014ADE0(&D_80126B58);
                func_8014B350(&D_80126B58);
                func_8014B7A4(&D_80126B58);
                func_80161D58(&D_80126B58);
            }
            func_80029344();
            func_80161A90(&D_80126B58);
            func_8014B504(&D_80126B58);
            func_80149BEC(&D_80126B58);
            func_8014B5D0(&D_80126B58);
            func_8014C99C(&D_80126B58);
            func_8014B190(&D_80126B58);
            func_80148648(&D_80126B58, 0);
            func_80149228(&D_80126B58);
            func_8014A59C(&D_80126B58);
            func_8016F14C(&D_80126B58);
            func_80154418(&D_80126B58);
            func_80154BE4(&D_80126B58);
            func_80165694(&D_80126B58);
            func_801654A8(&D_80126B58);
            func_8014A680(&D_80126B58);
            func_8014A6A8(&D_80126B58);
            func_8014A71C(&D_80126B58);
            func_80172588(&D_80126B58);
            func_801473DC(&D_80126B58);
            func_80015978(&D_80126B58 + 4, &D_80126B58 + 0x98);
            return 1;
        }
        goto block_13;
    }
    var_a0 = &D_80126B58 + 4;
block_13:
    func_80015978(var_a0, &D_80126B58 + 0x98);
    return 0;
}
