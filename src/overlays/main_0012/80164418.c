/* Overlay range [80164418,80164530) from MAIN.CD member 0012.
 * SHA256(span)=ec6c50fde455d84eaa73b94778f332494cc2c662267276923f8abb7ddba0bcc9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80164418 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);
extern s32 ratan2(s32 x, s32 y);
extern s32 ratan2(s32 dx, s32 dy);
void func_80162D88(s32 *a0);
void func_80162FC0(s32 *a0);
void func_801630C4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80162D88(s32 *a0);
extern s32 func_80012ABC(s32 a0, s32 a1, s32 a2);
extern void func_801630C4(s32, s32, s32, s32);
extern void func_80162FC0(s32 *a0);

void func_80164418(s32 s0) {
    s16 v[6];
    s32 s1 = *(s32 *)(s0 + 0x20);
    s32 a1 = *(s32 *)(s0 + 0x4C);
    v[0] = *(u16 *)(a1 + 0x6) - *(u16 *)(s0 + 0x6);
    v[1] = *(u16 *)(a1 + 0xA) - (*(u16 *)(s0 + 0xA) + 0x1E);
    v[2] = *(u16 *)(a1 + 0xE) - *(u16 *)(s0 + 0xE);
    v[5] = ratan2(v[0], v[2]);
    if (v[2] < 0) {
        v[2] = -v[2];
    }
    if (v[2] == 0) {
        v[4] = 0;
    } else {
        v[4] = ratan2(-v[1], v[2]);
    }
    *(u16 *)(s1 + 0x14) = (*(u16 *)(s1 + 0x14) + 0x71) & 0xFFF;
    *(s16 *)(s1 + 0x10) = func_80012ABC(*(s16 *)(s1 + 0x10), v[4], 0x2);
    *(s16 *)(s1 + 0x12) = func_80012ABC(*(s16 *)(s1 + 0x12), v[5], 0x2);
    ((s32 (*)(s32, s32, s32, s32))func_801630C4)(s0, 0, 0, 0x8000);
    func_80162FC0((s32 *)s0);
    func_80162D88((s32 *)s0);
}
