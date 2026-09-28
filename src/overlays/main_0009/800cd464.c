/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD464 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800116A0(void);
extern s32 D_800CDD2C;
extern s32 D_800CDD34;
extern void func_800CD674(s32, s32, s32);

void func_800CD464(void) {
    func_800CD674(0, D_800CDD2C, D_800CDD34);
    D_800CDD2C--;
    if (D_800CDD2C >= -0x10F) {
        return;
    }
    D_800CDD2C = -0x110;
    func_800116A0();
}
