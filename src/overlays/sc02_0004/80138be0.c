/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80138BE0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_8017E2E0[])(void);

void func_80138BE0(int p)
{
    if (*(unsigned short *)(p + 0xe) != 0) {
        *(unsigned short *)(p + 0xe) -= 1;
    }
    D_8017E2E0[*(short *)(p + 4)]();
}
