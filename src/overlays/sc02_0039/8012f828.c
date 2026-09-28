/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012F828 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80131CA8(int a0, int a1);
extern void func_80131170();
extern void func_80131CA8();
extern unsigned char D_8017F46C[];

void func_8012F828(int param_1)
{
    *(unsigned char *)(param_1 + 0xC1) = 4;
    if (*(unsigned int *)(param_1 + 0xB4) & 8) {
        func_80131170(param_1, D_8017F46C, 0xB);
    }
    func_80131CA8(param_1, 9);
}
