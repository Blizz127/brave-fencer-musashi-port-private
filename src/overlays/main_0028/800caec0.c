/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEC0 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern s32 rand(void);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_80147324(s32);
extern s32 func_80146994(s32, s32, s32, s32);
extern void func_801655E4(s32);
extern s32 func_80165910(void);

void func_800CAEC0(s32 a0) {
    if (func_80165910() == 0) {
        func_801655E4(a0);
    }
    func_80146994(0x35, a0, 0, 0);
    func_80147324(0x838);
    func_801466F0(0xE, a0, 0, 0, 0, ((((rand() % 16) + 0x10) << 12) / 360), 0, 1);
    func_801466F0(0xE, a0, 0, 0, 0, -((((rand() % 16) + 0x10) << 12) / 360), 0, 1);
    func_801466F0(0xE, a0, 0, 0, 0, ((((rand() % 16) + 0x10) << 12) / 360), 1, 1);
    func_801466F0(0xE, a0, 0, 0, 0, -((((rand() % 16) + 0x10) << 12) / 360), 1, 1);
    *(u8 *)(a0 + 0x197) += 1;
}
