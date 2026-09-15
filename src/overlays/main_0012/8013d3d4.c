/* Overlay range [8013D3D4,8013D53C) from MAIN.CD member 0012.
 * SHA256(span)=2c74119d27de1bd32a00f9f27d0f4ccf07872642d0a4d933be779aaf6cfce4c0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017EB18;
extern s32 D_8017EB6C;
extern s32 D_8017EBC0;
extern s32 D_8017EC14;
extern s32 D_8017EC68;
extern s32 D_8017EC94;
extern s32 D_801841A0;
extern s32 D_801841A4;
extern s32 D_801841A8;
extern s32 D_801841D0;
extern s32 D_801841D4;
extern s32 D_801841D8;
extern s32 D_80185B64;
void func_8013CF68();                            /* static */
void func_8013D53C();                            /* static */
void func_8013D8FC();                            /* static */
void func_8013DD68();                            /* static */
extern s32 *D_80078E78;

void func_8013D3D4(s32 arg1) {
    s32 (*var_v0)();
    s32 temp_v1;

    temp_v1 = (arg1 >> 2) & 3;
    D_801841D0 = arg1;
    D_801841D4 = temp_v1;
    D_801841D8 = (s32) ((arg1 >> 4) & 1);
    if (temp_v1 == 0) {
        D_801841A0 = D_8017EBC0;
        D_801841A4 = D_8017EC68;
        var_v0 = D_8017EB18;
    } else {
        D_801841A0 = D_8017EC14;
        D_801841A4 = D_8017EC94;
        var_v0 = D_8017EB6C;
    }
    D_801841A8 = var_v0;
    func_8013D53C();
    if (arg1 & 1) {
        if (D_801841D8 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if (D_801841D0 & 2) {
            M2C_FIELD(D_80185B64, s32 *, 0) = 0x140;
            M2C_FIELD(D_80185B64, s32 *, 0xC) = 0x80;
            if (M2C_FIELD(&D_80078E78, u8 *, 0x37) == 4) {
                M2C_FIELD(D_80185B64, s32 *, 0) = 0x140;
                M2C_FIELD(D_80185B64, s32 *, 0xC) = 0;
            }
            if (M2C_FIELD(&D_80078E78, u8 *, 0x37) == 0) {
                M2C_FIELD(D_80185B64, s32 *, 0) = 0x140;
                M2C_FIELD(D_80185B64, s32 *, 0xC) = 0x80;
            }
        }
    }
}
