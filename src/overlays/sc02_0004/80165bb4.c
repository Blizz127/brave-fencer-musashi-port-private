/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165BB4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(int, int);
extern void func_80154150(int, int);
extern void func_80154A74(s32, s32);
extern void func_80154150(s32, s32);

void func_80165BB4(u8 *a0) {
    func_80154150((s32)a0, 0x22);
    func_80154A74((s32)a0, 0x1A);
    *(u8 *)(a0 + 0x197) = *(u8 *)(a0 + 0x197) + 1;
}
