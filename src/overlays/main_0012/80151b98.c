/* Overlay range [80151B98,80151C54) from MAIN.CD member 0012.
 * SHA256(span)=72ed76d592a22ec8701dc38705e37d1e24803d640fb4bcf9db5e6b8442afb19f.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80151B98 - 47 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80149020(s32 *a0);
extern void func_80151C54(s32 a0);
extern void func_80159B3C(void *a0);
extern s32 func_801535F4(void *arg0);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80165718(s32 a0);

void func_80151B98(int param_1)
{
    int iVar1;
    ((int (*)(int))func_80149020)(param_1);
    if (*(unsigned short *)(param_1 + 0xb8) == 0x8000) {
        func_80151C54(param_1);
        ((void (*)(int))func_80159B3C)(param_1);
        goto LAB_80151c38;
    }
    iVar1 = ((int (*)(int))func_801535F4)(param_1);
    if (iVar1 == 1) goto LAB_80151c04;
    if (iVar1 < 2) return;
    if (iVar1 == 2) goto LAB_80151c1c;
    return;
LAB_80151c04:
    func_80151C54(param_1);
    ((void (*)(int))func_80159B3C)(param_1);
    goto LAB_80151c30;
LAB_80151c1c:
    func_80151C54(param_1);
    ((void (*)(int))func_8015BF48)(param_1);
LAB_80151c30:
    func_8014C010(param_1, 1);
LAB_80151c38:
    func_80165718(param_1);
    return;
}
