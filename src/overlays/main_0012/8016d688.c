/* Overlay range [8016D688,8016D778) from MAIN.CD member 0012.
 * SHA256(span)=b02860517bd752a08718f0026cf8181547e576c5fba1269b9a094428aca806a4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001CD9C(void *, void *);              /* extern */
void func_800233CC(void *, s32);             /* extern */
extern s32 D_80184851;
extern s32 D_80184852;
extern s32 D_80184855;
extern s32 D_80184856;
void *func_801465C0();                              /* static */
extern s8 D_80184854;

void func_8016D688(void *arg0) {
    void *temp_s2;
    void *temp_v0;
    void *temp_v1;

    M2C_FIELD(D_80184851, s8 *, 0) = 0xE0;
    D_80184852 = 0xE0;
    M2C_FIELD(D_80184851, s8 *, -1) = 0xE0;
    D_80184856 = 0;
    D_80184855 = 0;
    D_80184854 = 0;
    temp_s2 = D_80184851 - 1;
    temp_v0 = func_801465C0();
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, void **, 0x20) = temp_v0;
        func_800233CC(temp_s2, 0x28);
        func_8001CD9C(temp_v0, temp_s2);
        M2C_FIELD(temp_v0, s16 *, 0x1A) = 0x1400;
        M2C_FIELD(temp_v0, s32 *, 4) = (s32) (M2C_FIELD(temp_v0, s32 *, 4) | 0x50000000);
        temp_v1 = M2C_FIELD(arg0, void **, 0x30);
        M2C_FIELD(arg0, u16 *, 0x28) = (u16) M2C_FIELD(temp_v1, u16 *, 0x36);
        M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(temp_v1, u16 *, 6);
        M2C_FIELD(arg0, s16 *, 0x16) = (s16) (M2C_FIELD(temp_v1, u16 *, 0xA) - 0x28);
        M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
        M2C_FIELD(arg0, u16 *, 0x1A) = (u16) M2C_FIELD(temp_v1, u16 *, 0xE);
    }
}
