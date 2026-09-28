/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80157808 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern int D_8019FB18;
extern void (*D_80181408[])(void);

void func_80157808(void *param_1)
{
    D_80181408[*(unsigned short *)((char *)param_1 + 2)]();
    D_8019FB18 = D_8019FB18 - 1;
    if (D_8019FB18 == -1) {
        func_801599A4(param_1);
        func_80159B3C(param_1);
    }
}
