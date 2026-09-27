/* Main-exec range [8006252C,800625A4) from the SLUS executable.
 * SHA256(span)=17d8e29033130ee18d93ed14d9bd76e94ac39ad9fbce97733eaa0195dfe706ae.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800625DC;
extern s32 D_80062644;
void func_8005CF08();                            /* static */
void func_8005CF18();                            /* static */
void func_8005E168(s32, void *);             /* static */
void func_8005E178(s32, void *);             /* static */
extern s32 D_80078D08;
extern s32 *D_80078D0C;
extern s32 D_80078D14;

s32 func_8006252C(void) {
    void *temp_s0;

    func_8005CF08();
    temp_s0 = &D_80078D0C - 4;
    M2C_FIELD(&D_80078D0C, void **, 0) = &D_800625DC;
    M2C_FIELD(&D_80078D0C, void **, 4) = &D_80062644;
    D_80078D08 = 0;
    D_80078D14 = 0;
    func_8005E178(1, temp_s0);
    func_8005E168(1, temp_s0);
    func_8005CF18();
    return 1;
}
