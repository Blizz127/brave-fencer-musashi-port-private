/* Overlay range [8013CF68,8013D064) from MAIN.CD member 0012.
 * SHA256(span)=02604d37404b415b90fef7df7b91404a218b57e4126a84f7e090cb23792f71bd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80028620(s32, void *, u8, u8);     /* extern */
extern s32 D_80185B29;
extern s32 D_80185B2A;
extern s32 D_80185B2B;
extern s32 D_80185B2D;
extern s32 D_80185B2E;
extern s32 D_80185B2F;
extern s32 D_800A5E8C;
extern s32 D_800A5E90;
extern s32 *D_800A5E94;
extern u8 D_800A5E95;
extern u8 D_800A5E96;
extern u8 D_80185B28;
extern u8 D_80185B2C;
extern u8 D_80185B30;

void func_8013CF68(void) {
    M2C_FIELD(&D_800A5E94, s32 *, -0xC) = 0;
    D_800A5E8C = 0x1E;
    D_800A5E90 = 0;
    M2C_FIELD(&D_800A5E94, u8 *, 0) = (u8) D_80185B28;
    D_800A5E95 = D_80185B29;
    D_800A5E96 = D_80185B2A;
    func_80028620(0, &D_800A5E94 - 0xC, D_80185B29, D_80185B2A);
    M2C_FIELD(&D_800A5E94, s32 *, 4) = 0;
    M2C_FIELD(&D_800A5E94, s32 *, 8) = 7;
    M2C_FIELD(&D_800A5E94, s32 *, 0xC) = 0x14;
    M2C_FIELD(&D_800A5E94, u8 *, 0x10) = (u8) D_80185B2B;
    M2C_FIELD(&D_800A5E94, u8 *, 0x11) = (u8) D_80185B2C;
    M2C_FIELD(&D_800A5E94, u8 *, 0x12) = (u8) D_80185B2D;
    func_80028620(1, &D_800A5E94 + 4, D_80185B2C, D_80185B2D);
    M2C_FIELD(&D_800A5E94, s32 *, 0x14) = 0;
    M2C_FIELD(&D_800A5E94, s32 *, 0x18) = -0x12;
    M2C_FIELD(&D_800A5E94, s32 *, 0x1C) = 0;
    M2C_FIELD(&D_800A5E94, u8 *, 0x20) = (u8) D_80185B2E;
    M2C_FIELD(&D_800A5E94, u8 *, 0x21) = (u8) D_80185B2F;
    M2C_FIELD(&D_800A5E94, u8 *, 0x22) = (u8) D_80185B30;
    func_80028620(2, &D_800A5E94 + 0x14, D_80185B2F, D_80185B30);
}
