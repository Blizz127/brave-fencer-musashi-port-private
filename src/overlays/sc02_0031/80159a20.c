/* SC02 resident retail span [80159A20,80159B08). Offset 0x318C8 at base 80128158.
 * SHA256(span)=b4cbb3274df47d702dd5c4267c4e612a6d667d48c6af875b0cf2915482fbbd81.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * the C is the Druthulu shared/ov func_80159A20 shape (h_exact e36724ea) with its dispatch table retargeted to this member's D_801873B0 and the switch lowered to 0x801B5C34 via --rodata-base; oracle MATCH 58/58.
 * Not MAIN10.
 */
#include "psx_types.h"

typedef void (*CB_80159A20)(void *);
extern CB_80159A20 D_801873B0[];

void func_80150B28(void);
void func_80158638(unsigned char *param_1);
void func_8015126C(unsigned char *param_1);
void func_8014900C(unsigned char *param_1);

void func_80159A20(unsigned char *param_1)
{
    func_80150B28();
    func_80158638(param_1);
    func_8015126C(param_1);
    func_8014900C(param_1);
    D_801873B0[*(u16 *)param_1 & 0x7fff](param_1);
    *(u32 *)(param_1 + 0x44) |= 0x8000000;
    switch (*(u16 *)param_1) {
    case 2:
    case 3:
    case 0xb:
    case 0xc:
        goto mask;
    default:
        return;
    case 0x19:
        if (param_1[0xdd] != 1) {
            if (param_1[0xdd] == 4) {
                goto mask;
            }
            return;
        }
        if (*(u16 *)(param_1 + 2) == 3) {
            goto mask;
        }
        return;
    }
mask:
    *(u32 *)(param_1 + 0x44) &= 0xf7ffffff;
}
