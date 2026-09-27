/* Overlay range [801287B8,801288B0) from MAIN.CD member 0012.
 * SHA256(span)=2845ab190f9887efa58b0eb9ae1f2f166d17816e78e1e20d24922422235e1cc8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001212C();                                  /* extern */
void func_800190AC();                                  /* extern */
extern s32 D_80185C10;
void func_80129010();                                  /* static */
void func_8012956C();                                  /* static */
void func_80129CF8();                                  /* static */
void func_801379FC();                                  /* static */
void func_8013BC7C(s32 (*)());                           /* static */
void func_8013BCDC();                                  /* static */
void func_8013CA14();                                  /* static */
void func_8014FDF4(void *);                               /* static */
void func_801505FC(void *);                               /* static */
void func_801508B4(void *);                               /* static */
void func_801627E8();                                  /* static */
void func_80162B1C();                                  /* static */
void func_80165CA0();                                  /* static */
void func_80165E90();                                  /* static */
void func_8016E95C();                                  /* static */
void func_801754A8();                                  /* static */
void func_8017849C();                                  /* static */
extern u16 D_800B99DA;
extern u8 D_800B9A64;
extern s32 *D_80126B58;

void func_801287B8(void) {
    func_80129CF8();
    func_8017849C();
    func_8014FDF4(&D_80126B58);
    func_801505FC(&D_80126B58);
    func_801508B4(&D_80126B58);
    func_80165E90();
    func_801627E8();
    func_80162B1C();
    func_80165CA0();
    func_80129010();
    func_8013CA14();
    func_800190AC();
    func_8012956C();
    func_8016E95C();
    func_801754A8();
    if (D_80185C10 == 0) {
        func_8013BC7C(D_80185C10);
    }
    func_8013BCDC();
    func_801379FC();
    D_800B99DA += 1;
    if (D_800B9A64 != 0) {
        func_8001212C();
    }
}
