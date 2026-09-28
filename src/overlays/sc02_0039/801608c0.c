/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801608C0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80155440(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80154A74(int, int);
extern void func_80154150(int, int);
extern void func_80154A74(s32, s32);
extern void func_80154150(s32, s32);

void func_801608C0(s32 *a0) {
    *(s32 *)((s32)a0 + 0x44) |= 0x41;
    func_801553A8(a0);
    func_80155440(a0);
    func_80154150((s32)a0, 0x24);
    func_80154A74((s32)a0, 0x1D);
    func_80146CA0(a0);
}
