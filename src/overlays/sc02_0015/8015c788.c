/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015C788 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80155440(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80154A74(int, int);

void func_8015C788(s32 a0) {
    func_80154150(a0, 0x12);
    func_80154A74(a0, 0x17);
    func_801553A8((s32 *)a0);
    func_80155440((s32 *)a0);
    func_80146E90((s32 *)a0, 0xA);
    func_80146CA0((void *)a0);
}
