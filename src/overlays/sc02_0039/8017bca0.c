/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017BCA0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_801A0D88;
void func_8017B0E4(int param_1, int param_2);
extern s16 D_801A0BE4;
extern void func_8017B0E4(int, int);

void func_8017BCA0(int param_1) {
    func_8017B0E4(param_1, 0xC);
    D_801A0BE4 = D_801A0BE4 + 1;
    if (D_801A0BE4 >= 0x1F) {
        D_801A0D88 = 2;
    }
}
