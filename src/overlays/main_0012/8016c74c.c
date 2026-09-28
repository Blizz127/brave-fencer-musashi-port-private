/* Overlay range [8016C74C,8016C83C) from MAIN.CD member 0012.
 * SHA256(span)=c7ecaf0e84cb58dbfef578428d65b89ac3e9c5da0200eb79be083fa9d1f2ae4f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016C74C - byte-exact against retail at -O2 (tools/register_match.py). */
#define VectorNormalSS func_80047E98
extern s32 VectorNormalSS(void *a0, void *a1);

void func_8016C74C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 r; s32 lim; s32 sh2;
    sh2 = (s16)a2;
    __asm__ __volatile__("" : "=r"(sh2) : "0"(sh2));
    __asm__ __volatile__("" : : "r"(a3));
    *(s32 *)(a0 + 0x10) = *(s32 *)(a0 + 0x10) + (*(s16 *)(a1 + 0x0) << sh2);
    *(s32 *)(a0 + 0x14) = *(s32 *)(a0 + 0x14) + (*(s16 *)(a1 + 0x2) << sh2);
    *(s32 *)(a0 + 0x18) = *(s32 *)(a0 + 0x18) + (*(s16 *)(a1 + 0x4) << sh2);
    *(s16 *)(a1 + 0x0) = *(u16 *)(a0 + 0x12);
    *(s16 *)(a1 + 0x2) = *(u16 *)(a0 + 0x16);
    *(s16 *)(a1 + 0x4) = *(u16 *)(a0 + 0x1a);
    lim = *(volatile s32 *)&a4;
    __asm__ __volatile__("" ::: "memory");
    r = ((s32 (*)(void *))VectorNormalSS)((void *)a1);
    if (lim < r) {
        *(s32 *)(a0 + 0x10) = *(s16 *)(a1 + 0x0) << (s16)a3;
        *(s32 *)(a0 + 0x14) = *(s16 *)(a1 + 0x2) << (s16)a3;
        *(s32 *)(a0 + 0x18) = *(s16 *)(a1 + 0x4) << (s16)a3;
    }
}
