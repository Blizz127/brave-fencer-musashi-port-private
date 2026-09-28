/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801585EC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_801553A8(s32 *a0);
void func_801553A8(s32 *a0);
void func_801553C0(s32 a0);
extern void func_80154A74(int, int);

void func_801585EC(u8 *a0) {
    *(s32 *)(a0 + 0x44) &= ~2;
    func_80154A74((s32)a0, 0x11);
    func_801553C0((s32)a0);
    func_801553A8((s32 *)a0);
}
