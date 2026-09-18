/* Overlay range [8014CD80,8014CF04) from MAIN.CD member 0012.
 * SHA256(span)=273daaef7cca41d2a7cfc1ab885851dd05f83958abc15d4ff7234d0303bda392.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014CD80 - 97 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern int func_80135A4C();
extern int func_80135888();
extern int func_8014C918();

int func_8014CD80(int param_1, unsigned short *param_2, unsigned short *param_3)
{
    short *psVar4;
    register int iVar3 __asm__("$3");
    unsigned short uVar1;
    unsigned short uVar2;
    psVar4 = *(short **)(param_1 + 0x174);
    if (*(unsigned short *)psVar4 == 0) goto LAB_ce00;
    if (((*(unsigned short *)((int)psVar4 + 0x5c) & 0x400) == 0) ||
        (*(int *)((int)psVar4 + 0x58) == 0) ||
        (*(short *)((int)psVar4 + 0xa) < *(short *)(param_1 + 0xa))) {
        if (*(unsigned short *)psVar4 != 0) {
            *(char *)((int)psVar4 + 0x74) = 0;
        }
LAB_ce00:
        *(int *)(param_1 + 0x174) = 0;
        return 0;
    }
    *param_2 = *(unsigned short *)(param_1 + 0x98);
    param_2[1] = *(unsigned short *)(param_1 + 0x9a) - 3;
    param_2[2] = *(unsigned short *)(param_1 + 0x9c);
    if ((*(unsigned short *)((int)psVar4 + 0x5c) & 8) != 0) {
        param_3[1] = param_2[1] + 0xc;
        iVar3 = func_80135A4C(*(int *)((int)psVar4 + 0x20),
                              *(int *)((int)psVar4 + 0x58), param_2, param_3);
        if (iVar3 == 0) goto LAB_cec4;
        uVar1 = param_3[0];
        *(unsigned short *)(param_1 + 0x78) = uVar1;
        *(unsigned short *)(param_1 + 6) = uVar1;
        uVar1 = param_3[1];
        *(unsigned short *)(param_1 + 0x7a) = uVar1;
        *(unsigned short *)(param_1 + 0xa) = uVar1;
        uVar1 = param_3[2];
        *(unsigned short *)(param_1 + 0x7c) = uVar1;
        *(unsigned short *)(param_1 + 0xe) = uVar1;
    } else {
        iVar3 = func_80135888(*(int *)((int)psVar4 + 0x20),
                              *(int *)((int)psVar4 + 0x58), param_2, param_3);
    }
    if (iVar3 != 0) goto LAB_ced0;
LAB_cec4:
    *(char *)((int)psVar4 + 0x74) = 0;
    *(int *)(param_1 + 0x174) = 0;
    return 0;
LAB_ced0:
    uVar2 = func_8014C918(param_1, *(unsigned char *)((int)psVar4 + 0x75)) & 0xff;
    *(unsigned short *)(param_1 + 0x16e) = uVar2;
    return 1;
}
