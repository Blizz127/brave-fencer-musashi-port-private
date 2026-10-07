/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Marks D_80078E30 as unset (-1); called once per outer-loop pass of main. */
extern s32 D_80078E30;

void func_800191A8(void)
{
    D_80078E30 = -1;
}
