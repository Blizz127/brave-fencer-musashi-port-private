/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB684 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern s32 rand(void);

void func_800CB684(s32 a0, s32 a1) {
    extern s32 rand(void);
    *(u16 *)(a0 + 0x60) = a1 + (rand() & 0x7F);
    *(u16 *)(a0 + 0x62) = a1 + (rand() & 0x7F);
}
