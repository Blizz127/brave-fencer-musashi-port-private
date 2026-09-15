/* Overlay range [80163A94,80163C2C) from MAIN.CD member 0012.
 * SHA256(span)=d7c36acac9637fdf2c369feedad65fa625cb40fce2df74d6413f2d35961da477.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001C214(void *, void *);           /* extern */
void *func_8014659C();                              /* static */
void func_80146A6C(s32, void *, s32, s32, s32, s32, s32); /* static */
void func_80146CA0(void *);                      /* static */
void func_80146DE8(void *, s32, s32, s32); /* static */
void func_80146E90(void *, s32);             /* static */
void func_80147324(s32, s32, s32, s32);      /* static */
void func_80149374(void *, void *);              /* static */
extern s32 *D_800636C8;
extern s32 *D_800DE5A0;

void func_80163A94(void *arg0) {
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;
    void *temp_s1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;

    temp_s1 = M2C_FIELD(arg0, void **, 0x4C);
    M2C_FIELD(temp_s1, s32 *, 0x44) = (s32) (M2C_FIELD(temp_s1, s32 *, 0x44) | 4);
    temp_v0 = func_8014659C();
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    if (temp_v0 != 0) {
        func_8001C214(temp_v0, &D_800DE5A0);
        M2C_FIELD(temp_v0, void **, 0x20) = &D_800636C8;
        M2C_FIELD(temp_v0, s16 *, 0x1C) = 0x1800;
        M2C_FIELD(temp_v0, s16 *, 0x1A) = 0x1800;
        M2C_FIELD(temp_v0, s16 *, 0x18) = 0x1800;
        M2C_FIELD(temp_v0, u16 *, 0x2C) = (u16) (M2C_FIELD(temp_v0, u16 *, 0x2C) | 0x10);
        func_80149374(temp_s1, arg0 + 4);
        temp_v1 = M2C_FIELD(arg0, void **, 0x20);
        temp_v0_2 = M2C_FIELD(temp_s1, void **, 0x20);
        M2C_FIELD(temp_v1, s32 *, 0x34) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x34);
        M2C_FIELD(temp_v1, s32 *, 0x38) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x38);
        M2C_FIELD(temp_v1, s32 *, 0x3C) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x3C);
        M2C_FIELD(temp_v1, s32 *, 0x40) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x40);
        temp_a1 = M2C_FIELD(temp_v0_2, s32 *, 0x48);
        temp_a2 = M2C_FIELD(temp_v0_2, s32 *, 0x4C);
        temp_a3 = M2C_FIELD(temp_v0_2, s32 *, 0x50);
        M2C_FIELD(temp_v1, s32 *, 0x44) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x44);
        M2C_FIELD(temp_v1, s32 *, 0x48) = temp_a1;
        M2C_FIELD(temp_v1, s32 *, 0x4C) = temp_a2;
        M2C_FIELD(temp_v1, s32 *, 0x50) = temp_a3;
        M2C_FIELD(temp_v0, u16 *, 0x10) = (u16) M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x20), u16 *, 0x10);
        M2C_FIELD(temp_v0, u16 *, 0x12) = (u16) M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x20), u16 *, 0x12);
        M2C_FIELD(temp_v0, u16 *, 0x14) = (u16) M2C_FIELD(M2C_FIELD(temp_s1, void **, 0x20), u16 *, 0x14);
        M2C_FIELD(arg0, u16 *, 0x60) = (u16) M2C_FIELD(temp_s1, u16 *, 0x100);
        M2C_FIELD(arg0, u16 *, 0x62) = (u16) M2C_FIELD(temp_s1, u16 *, 0x102);
        M2C_FIELD(arg0, u16 *, 0x64) = (u16) M2C_FIELD(temp_s1, u16 *, 0x104);
        func_80147324(0x448, temp_a1, temp_a2, temp_a3);
        func_80146E90(arg0, 0x10);
        func_80146A6C(0xD, arg0, 0, 0, 0, 0, 0);
        func_80146DE8(arg0, 0, 0, 0xFFE00000);
        func_80146CA0(arg0);
    }
}
