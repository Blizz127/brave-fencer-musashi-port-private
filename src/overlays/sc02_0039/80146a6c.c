/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80146A6C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146AFC(void*);
void aF80146A6C(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6) __asm__("func_80146A6C");

void aF80146A6C(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6)
{
    u8 sp[0x18];
    *(s16 *)(sp + 0x0) = a0;
    *(s32 *)(sp + 0x8) = a1;
    *(s16 *)(sp + 0x2) = a2;
    *(s16 *)(sp + 0x4) = a3;
    *(s16 *)(sp + 0x6) = a4;
    *(s32 *)(sp + 0xC) = a5;
    *(s32 *)(sp + 0x10) = a6;
    ((s32 (*)(void *))func_80146AFC)(sp);
}
