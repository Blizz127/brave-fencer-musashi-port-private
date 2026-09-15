/* Overlay range [80164BDC,80164CD4) from MAIN.CD member 0012.
 * SHA256(span)=eaf60335c17114f4d664c4049c15e71afbfbaca8b1a5309c594c64e3d245ef61.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001CD50(void *, s8 *);                /* extern */
void func_800233CC(s8 *, s32);               /* extern */
extern s32 D_80184359;
extern s32 D_8018435A;
extern s32 D_8018435B;
extern s32 D_8018435D;
extern s32 D_8018435E;
extern s32 D_8018435F;
void *func_80146578();                              /* static */
void func_80146CA0(void *);                      /* static */
void func_80164DB0(void *);                      /* static */
void func_80164DD0(void *);                      /* static */
extern s8 D_80184358;
extern s8 D_8018435C;

void func_80164BDC(void *arg0) {
    void *temp_v0;

    temp_v0 = func_80146578();
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    if (temp_v0 != 0) {
        func_8001CD50(temp_v0, &D_80184358);
        func_800233CC(&D_80184358, 0x60);
        M2C_FIELD(temp_v0, s32 *, 4) = (s32) (M2C_FIELD(temp_v0, s32 *, 4) | 0x50000000);
        D_80184359 = 0xF0;
        D_80184358 = 0xF0;
        D_8018435A = 0xC0;
        D_8018435E = 0;
        D_8018435D = 0;
        D_8018435C = 0;
        D_8018435F = 0;
        D_8018435B = 0;
        M2C_FIELD(temp_v0, s16 *, 0x1E) = 0xCCC;
        M2C_FIELD(temp_v0, s16 *, 0x10) = 0x400;
        M2C_FIELD(arg0, s16 *, 0x60) = 0x700;
        M2C_FIELD(arg0, s16 *, 0x62) = -0x60;
        func_80164DD0(arg0);
        func_80146CA0(arg0);
        return;
    }
    func_80164DB0(arg0);
}
