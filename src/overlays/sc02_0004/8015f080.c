/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015F080 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80146994(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80146CA0(void *a0);
extern void func_80149020(s32 *a0);
extern void func_80149048(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80156648(s32 *a0);
extern void func_80154A74(int, int);
extern void func_80154150(int, int);
extern void func_80154A74(s32, s32);
extern void func_80154150(s32, s32);

void func_8015F080(s32 a0) {
    func_80154150(a0, 0x17);
    func_80154A74(a0, 0x15);
    func_80146994(0x5, a0, 0x7, 0);
    *(s32 *)(a0 + 0x238) = -1;
    *(s32 *)(a0 + 0x234) = 0;
    *(s32 *)(a0 + 0x44) = *(s32 *)(a0 + 0x44) & -2;
    func_80149048((s32 *)a0);
    func_80156648((s32 *)a0);
    *(s8 *)(a0 + 0x1AA) = 8;
    func_80149020((s32 *)a0);
    *(s16 *)(a0 + 0xF6) = 0x19EB;
    func_80146CA0((void *)a0);
}
