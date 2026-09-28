/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CF038 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_800B99E8;
extern s32 D_800D3C0C;
extern void func_800167B8(s32 a0);
extern void func_800118AC(void);

void func_800CF038(void) {
    extern void func_800CF180(void);
    extern void func_800CF114(void);
    extern u16 D_800B99E8;
    extern s32 func_800149E0(s32 a0);
    extern s32 D_800D3C0C;
    extern void func_800167B8(s32 a0);
    extern void func_800118AC(void);
    s32 temp;

    func_800CF180();
    func_800CF114();
    D_800B99E8 = D_800B99E8 + 1;
    temp = func_800149E0(0);
    if (D_800D3C0C != 0) {
        if ((s16)D_800B99E8 >= 0x81 || (temp & 0x840)) {
            func_800167B8(4);
            func_800118AC();
        }
    }
}
