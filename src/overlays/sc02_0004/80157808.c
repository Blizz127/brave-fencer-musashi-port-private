/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80157808 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern int D_801950E8;
extern void (*D_8017FFE8[])(void);

void func_80157808(void *param_1)
{
    D_8017FFE8[*(unsigned short *)((char *)param_1 + 2)]();
    D_801950E8 = D_801950E8 - 1;
    if (D_801950E8 == -1) {
        func_801599A4(param_1);
        func_80159B3C(param_1);
    }
}
