/* Main-exec range [80042154,800422B4) from the SLUS executable.
 * SHA256(span)=405b7bc8510d6b7f8a7ac71da1575110516473a4d742f12485af9a0877c3acf1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80042154 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u8 D_800B9B40[];
extern u32 D_8006BA84;
extern s16 D_8006BA88;
extern u32 D_800C7C98[];
extern u32 D_800C7CE0[];
extern void func_800401A0(s32);
extern void func_800422B4(s32);
extern void func_8003C498(u32);
extern void func_800422E8(u8 *, u32);
s32 func_80042154(u8 *addr, u32 size, s32 vabid)
{
    s16 cur;
    u32 n;
    s16 vab = vabid;

    if ((u16)vabid > 16 || D_800B9B40[vab] != 2) {
        func_800401A0(0);
        return -1;
    }
    if (D_8006BA84 == 0) {
        D_8006BA88 = vab;
        D_8006BA84 = D_800C7C98[vab];
        func_800422B4(0);
        func_8003C498(D_800C7CE0[vab]);
    }
    cur = D_8006BA88;
    if (cur != vab) {
        func_800401A0(0);
        return -1;
    }
    n = size;
    if (D_8006BA84 < n) {
        n = D_8006BA84;
    }
    func_800401A0(1);
    func_800422E8(addr, n);
    D_8006BA84 -= n;
    if (D_8006BA84 != 0) {
        return -2;
    }
    D_8006BA88 = -1;
    D_8006BA84 = 0;
    D_800B9B40[cur] = 1;
    return cur;
}
