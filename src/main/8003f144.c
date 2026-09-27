/* Exact retail word export for [8003F144,8003F380); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800414E4(s16, s16);                    /* static */
extern s32 D_800A6584;
extern u8 D_800B9B27;
extern s32 *D_800B9B40;

s32 func_8003F144(s16 arg0, s16 arg1, s32 arg2, void *arg3) {
    s32 temp_v1;
    void *temp_v1_2;

    if (*(&D_800B9B40 + arg0) != 1) {
        return -1;
    }
    func_800414E4(arg0, arg1);
    temp_v1 = (s32) ((arg2 + (D_800B9B27 * 0x10)) << 0x10) >> 0xB;
    M2C_FIELD(arg3, u8 *, 0) = (u8) *(s32 *) (temp_v1 + D_800A6584);
    M2C_FIELD(arg3, u8 *, 1) = (u8) M2C_FIELD((temp_v1 + D_800A6584), u8 *, 1);
    M2C_FIELD(arg3, u8 *, 2) = (u8) M2C_FIELD((temp_v1 + D_800A6584), u8 *, 2);
    M2C_FIELD(arg3, u8 *, 3) = (u8) M2C_FIELD((temp_v1 + D_800A6584), u8 *, 3);
    M2C_FIELD(arg3, u8 *, 4) = (u8) M2C_FIELD((temp_v1 + D_800A6584), u8 *, 4);
    M2C_FIELD(arg3, u8 *, 5) = (u8) M2C_FIELD((temp_v1 + D_800A6584), u8 *, 5);
    M2C_FIELD(arg3, u8 *, 7) = (u8) M2C_FIELD((temp_v1 + D_800A6584), u8 *, 7);
    M2C_FIELD(arg3, u8 *, 6) = (u8) M2C_FIELD((temp_v1 + D_800A6584), u8 *, 6);
    M2C_FIELD(arg3, u8 *, 8) = (u8) M2C_FIELD((temp_v1 + D_800A6584), u8 *, 8);
    M2C_FIELD(arg3, u8 *, 9) = (u8) M2C_FIELD((temp_v1 + D_800A6584), u8 *, 9);
    M2C_FIELD(arg3, u8 *, 0xA) = (u8) M2C_FIELD((temp_v1 + D_800A6584), u8 *, 0xA);
    M2C_FIELD(arg3, u8 *, 0xB) = (u8) M2C_FIELD((temp_v1 + D_800A6584), u8 *, 0xB);
    M2C_FIELD(arg3, u8 *, 0xC) = (u8) M2C_FIELD((temp_v1 + D_800A6584), u8 *, 0xC);
    M2C_FIELD(arg3, u8 *, 0xD) = (u8) M2C_FIELD((temp_v1 + D_800A6584), u8 *, 0xD);
    temp_v1_2 = temp_v1 + D_800A6584;
    M2C_FIELD(arg3, u16 *, 0x10) = (u16) M2C_FIELD(temp_v1_2, u16 *, 0x10);
    M2C_FIELD(arg3, u16 *, 0x12) = (u16) M2C_FIELD(temp_v1_2, u16 *, 0x12);
    M2C_FIELD(arg3, u16 *, 0x14) = (u16) M2C_FIELD(temp_v1_2, u16 *, 0x14);
    M2C_FIELD(arg3, u16 *, 0x16) = (u16) M2C_FIELD(temp_v1_2, u16 *, 0x16);
    return 0;
}
