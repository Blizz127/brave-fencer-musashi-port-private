/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD614 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800116A0(void);
extern s32 D_800CDD34;
void func_800116A0(void);
extern s32 D_800CDD30;
extern void func_800CD92C(s32, s32, s32);
extern void func_800CD92C(s32 a0, s32 a1, s32 a2);
void func_800CD92C(s32, s32, s32);

void func_800CD614(void) {
    s32 v0;
    
    func_800CD92C(D_800CDD30, 0, D_800CDD34);
    v0 = D_800CDD34 - 8;
    D_800CDD34 = v0;
    if (v0 > 0) {
        return;
    }
    func_800116A0();
}
