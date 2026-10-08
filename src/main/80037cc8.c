/* Owner re-derivation from retail assembly (clean input set). */
/* Clears the word at 800BA0F8. */
#include "psx_types.h"

extern s32 D_800BA0F8;

void func_80037CC8(void)
{
    D_800BA0F8 = 0;
}
