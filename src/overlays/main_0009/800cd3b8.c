/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD3B8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8001B244(s32);
extern void func_8001AD38(const char*);
extern void func_800116A0(void);
extern s32 D_800CDD2C;
extern s32 D_800CDD34;
extern const char D_800CD34C[];

void func_800CD3B8(void) {
    if (func_8001B244(0x8E) == 0) {
        return;
    }

    func_8001AD38(D_800CD34C);
    D_800CDD2C = 0;
    D_800CDD34 = 0;
    func_800116A0();
}
