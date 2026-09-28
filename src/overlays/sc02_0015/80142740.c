/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80142740 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8012AD50(void * arg0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32);
extern int func_8012BEE8(int);
extern s32 func_8012AD50(void *a0);

void func_80142740(int param_1)
{
    if (((int (*)(void))func_8012BEE8)() != 0) {
        ((void (*)(int))func_8012AD50)(param_1);
    }
}
