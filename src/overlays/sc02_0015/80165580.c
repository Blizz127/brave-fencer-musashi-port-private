/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165580 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC1;
extern u8 D_80078EC5;
extern void (*D_80180EA8[])(void);
extern void func_80165B28(void *a0);

void func_80165580(s32 _arg0)
{
    if (D_80078EC5 & 0x80) {
        ((void (*)(void))func_80165B28)();
    } else {
        D_80180EA8[D_80078EC1 & 0x7F]();
    }
}
