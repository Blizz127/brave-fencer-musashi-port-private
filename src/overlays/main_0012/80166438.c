/* Overlay range [80166438,801665B4) from MAIN.CD member 0012.
 * SHA256(span)=63bdec445e71a25724399ecfb5c567df22bd158b1f4ad7311549163e63cad476.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800D1FC8(void *, s32);             /* extern */
void *func_800D21C4(void *, void *, s32);    /* extern */
void func_80128EA8(void *, void *, void *);   /* static */
void func_80146C3C(void *);                      /* static */
void func_801665B4(void *);                      /* static */
extern s32 *D_800D387C;
extern s32 *D_800D3888;

void func_80166438(void *arg0) {
    s32 var_a2;
    s16 temp_v0_2;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_2;
    void *temp_v0;

    var_a2 = 0x9B;
    if (!(M2C_FIELD(arg0, s32 *, 0x30) & 0x10000000)) {
        var_a2 = 0x9C;
    }
    temp_v0 = func_800D21C4(arg0, &D_800D387C, var_a2);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, void **, 0x20) = temp_v0;
        temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x30) & 0x7FFF;
        M2C_FIELD(temp_v0, s16 *, 0x1A) = temp_v0_2;
        M2C_FIELD(temp_v0, s16 *, 0x18) = temp_v0_2;
        if (M2C_FIELD(arg0, s32 *, 0x30) & 0x8000) {
            func_800D1FC8(arg0, 6);
        }
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x30);
        if (temp_v1 < 0) {
            var_v0 = M2C_FIELD(temp_v0, s32 *, 4) | 0x50000000;
            goto block_8;
        }
        var_v0 = 0x60000000;
        if (temp_v1 & 0x08000000) {
block_8:
            M2C_FIELD(temp_v0, s32 *, 4) = var_v0;
        }
        if (!(M2C_FIELD(arg0, s32 *, 0x30) & 0x40000000)) {
            var_v0_2 = M2C_FIELD(temp_v0, s32 *, 4) | 0x40;
        } else {
            var_v0_2 = M2C_FIELD(temp_v0, s32 *, 4) & ~0x40;
        }
        M2C_FIELD(temp_v0, s32 *, 4) = var_v0_2;
        if (M2C_FIELD(arg0, s32 *, 0x30) & 0x20000000) {
            M2C_FIELD(temp_v0, s8 *, 0x24) = (s8) (((u32) M2C_FIELD(arg0, u32 *, 0x2C) >> 0x14) & 0xF0);
            M2C_FIELD(temp_v0, s8 *, 0x25) = (s8) (M2C_FIELD(arg0, u16 *, 0x2E) & 0xF0);
            M2C_FIELD(temp_v0, s8 *, 0x26) = (s8) (((u32) M2C_FIELD(arg0, u32 *, 0x2C) >> 0xC) & 0xF0);
        }
        func_80128EA8(temp_v0, arg0 + 0x24, &D_800D3888);
        M2C_FIELD(arg0, s16 *, 0x16) = (s16) M2C_FIELD(arg0, u32 *, 0x2C);
        M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
        func_801665B4(arg0);
        return;
    }
    func_80146C3C(arg0);
}
