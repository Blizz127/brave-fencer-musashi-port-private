/* Owner re-derivation from retail assembly (clean input set). */
/* Clears the halfword at 800A46CC, then runs 8002C8BC. */
#include "psx_types.h"

extern s16 D_800A46CC;
extern void func_8002C8BC(void);

void func_8002FAE0(void)
{
    D_800A46CC = 0;
    func_8002C8BC();
}
