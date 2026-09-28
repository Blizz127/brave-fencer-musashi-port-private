/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD558 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800116A0(void);
extern s32 D_800CDD34;
void func_800116A0(void);
extern s32 D_800CDD30;
extern void func_800CD92C(s32, s32, s32);

void func_800CD558(void) {
    func_800CD92C(-0x400, 0, D_800CDD34);
    D_800CDD30 = -0x340;
    D_800CDD34 += 8;
    if (D_800CDD34 >= 0x80) {
        func_800116A0();
    }
}
