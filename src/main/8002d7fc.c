/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Stores the sound driver word at D_800A4E7C. */
extern s32 D_800A4E7C;

void func_8002D7FC(s32 value)
{
    D_800A4E7C = value;
}
