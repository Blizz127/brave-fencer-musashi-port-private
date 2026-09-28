/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC1E8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801655E4(s32 arg0);
extern void func_801466F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
extern void func_80147324(s32 arg0);
extern s32 D_80078EC8;

void func_800CC1E8(s32 arg0) {
    func_801655E4(arg0);
    D_80078EC8 = 0x1C2;
    func_801466F0(0x1A, arg0, *(s16 *)(arg0 + 6), *(s16 *)(arg0 + 0xA), *(s16 *)(arg0 + 0xE), 0, 0, 1);
    func_80147324(0xA63);
    *(u8 *)(arg0 + 0x197) += 1;
}
