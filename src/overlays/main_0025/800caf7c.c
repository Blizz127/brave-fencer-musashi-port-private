/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF7C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 func_80148800(s32 *param_1);
extern void func_800CB028(s32 param_1);

void func_800CAF7C(s32 *param_1)
{
    u32 v0;
    u8 v1;

    if (func_80148800(param_1) & 0x20) {
        func_800CB028((s32)param_1);
    } else {
        v1 = *(u8 *)((s32)param_1 + 0xBF);
        switch (v1) {
        case 0:
            v0 = *(u8 *)((s32)param_1 + 0xBE) + 4;
            *(u8 *)((s32)param_1 + 0xBE) = v0;
            if ((v0 & 0xFF) >= 0x50) {
                *(u8 *)((s32)param_1 + 0xBF) = *(u8 *)((s32)param_1 + 0xBF) + 1;
            }
            break;
        case 1:
            if (*(u8 *)((s32)param_1 + 0xBE) == 0) {
                func_800CB028((s32)param_1);
            } else {
                *(u8 *)((s32)param_1 + 0xBE) -= 4;
            }
            break;
        }
    }
}
