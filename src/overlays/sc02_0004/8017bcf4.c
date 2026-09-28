/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017BCF4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_80196350;
void func_8017B0E4(int param_1, int param_2);
extern s16 D_801961B4;
extern void func_8017B0E4(int, int);
extern void func_8012A4BC(void);

void func_8017BCF4(int param_1)
{
    func_8017B0E4(param_1, 6);
    D_801961B4 = D_801961B4 + 1;
    if (0x18 < D_801961B4) {
        func_8012A4BC();
        D_80196350 = 0;
    }
    return;
}
