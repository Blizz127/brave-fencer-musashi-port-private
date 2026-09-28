/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB620 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern s32 rand(void);
extern s32 func_800CB6D4(s32 a0);
extern void func_800CB684(s32 a0, s32 a1);

void func_800CB620(s32 arg0) {
    s32 v;
    *(u16 *)(arg0 + 0x10) = *(u16 *)(arg0 + 6);
    *(u16 *)(arg0 + 0x12) = *(u16 *)(arg0 + 0xA);
    *(u16 *)(arg0 + 0x14) = *(u16 *)(arg0 + 0xE);
    v = rand() & 0x1F;
    v <<= 7;
    *(u16 *)(arg0 + 0x64) = v;
    *(u16 *)(arg0 + 0x66) = v;
    func_800CB684(arg0, 0x200);
    func_800CB6D4(arg0);
}
