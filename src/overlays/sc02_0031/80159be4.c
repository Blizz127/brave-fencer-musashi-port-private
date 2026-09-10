/* SC02 resident retail span [80159BE4,80159C84). Offset 0x31A8C at base 80128158.
 * SHA256(span)=543f44e9425b7f7e3971a9548b65376811d7dd75e8d678dbeeb4e350ec49e00a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910); the C
 * is the Druthulu shared/ov func_80159BE4 shape (h_exact d4682fe2/1cf147fb
 * differ only in the data symbol) retargeted to this member's D_80187270.
 * Oracle MATCH 40/40. Not MAIN10.
 */
#include "psx_types.h"

extern int D_80187270;
void func_80146DB8(s32 arg0, void *arg1);
void func_80154150(s32 arg0, s32 arg1);
void func_80154A74(s32 arg0, s32 arg1);
void func_801553C0(s32 arg0);
void func_801553A8(s32 arg0);
void func_80172590(s32 arg0);
void func_80146CA0(s32 arg0);

void func_80159BE4(s32 arg0)
{
    func_80146DB8(arg0, &D_80187270);
    if ((*(unsigned int *)(arg0 + 0x44) & 0x200) != 0) {
        func_80154150(arg0, 5);
        func_80154A74(arg0, 0x1C);
    } else {
        func_80154150(arg0, 4);
        func_80154A74(arg0, 0x11);
    }
    *(int *)(arg0 + 0x234) = 0;
    *(int *)(arg0 + 0x238) = 0;
    func_801553C0(arg0);
    func_801553A8(arg0);
    func_80172590(arg0);
    func_80146CA0(arg0);
}
