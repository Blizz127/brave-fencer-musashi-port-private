/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80155458 - byte-exact against retail at -O2 (tools/register_match.py). */
extern int (*D_8017FB48[])(void);

s32 func_80155458(s32 param_1)
{
    int idx;

    idx = *(unsigned char *)(param_1 + 0x4e);
    if (idx != 0) {
        idx = idx - 1;
        if ((*D_8017FB48[idx])() == 0) {
            *(unsigned char *)(param_1 + 0x4e) = 0;
        }
    }
    return *(unsigned char *)(param_1 + 0x4e);
}
