/* Overlay range [801376E8,801377B4) from MAIN.CD member 0012.
 * SHA256(span)=afb544cb16105bcc8aa1bd6c3f1d3dec4fe29f8fd6245350329fa6baa1d7b5d0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Verified byte-exact against retail by tools/match_function.py
 * (51/51 words at 0x801376E8). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"
#include "m2c_macros.h"

void func_801377B4(s32, s32, void *);          /* static */
void func_80139BE0(void *);                   /* static */
extern s32 *D_801269F0;
extern s8 D_801269FD;
extern s32 *D_80126A14;
extern s16 D_80126A1C;
extern s16 D_80126A20;
extern s16 D_80126A22;
extern s16 D_80126A24;
extern u16 D_80126A26;

void *func_801376E8(s32 arg0, void *arg1) {
    func_801377B4(arg0, 0x6200, &D_801269F0);
    D_80126A1C = 0x1C;
    D_801269FD = 0;
    if (arg1 != 0) {
        M2C_FIELD(&D_80126A14, u16 *, 0) = (u16) M2C_FIELD(arg1, u16 *, 0);
        M2C_FIELD(&D_80126A14, u16 *, 2) = (u16) M2C_FIELD(arg1, u16 *, 2);
    }
    func_80139BE0(&D_801269F0);
    D_80126A20 = (M2C_FIELD(&D_80126A14, u16 *, 0) + 0x28) - ((s32) (D_80126A24 + 0x28) >> 1);
    D_80126A22 = M2C_FIELD(&D_80126A14, u16 *, 2) - ((s32) (D_80126A26 << 0x10) >> 0x11);
    return &D_801269F0;
}
