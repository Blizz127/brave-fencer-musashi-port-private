/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD408 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800116A0(void);
extern s32 D_800CDD2C;
extern s32 D_800CDD34;
extern void func_800CD674(s32, s32, s32);

void func_800CD408(void) {
    s32 a1 = D_800CDD2C;
    s32 a2 = D_800CDD34;
    func_800CD674(0, a1, a2);

    a2 = D_800CDD34;
    a2 += 8;
    D_800CDD34 = a2;

    if (a2 < 0x80) {
         
    } else {
        func_800116A0();
    }
}
