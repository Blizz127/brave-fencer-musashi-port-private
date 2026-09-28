/* Main-exec range [800241C0,800242D0) from the SLUS executable.
 * SHA256(span)=a67732548c1586a9aa642082f6af8f6eb84157fc3b9c4303e35f4602af762372.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800241C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u16 D_800636D8[];
extern u16 D_80063818[];
extern s16 D_80063870[];

void func_800241C0(s32 arg0, u16 *arg1, s32 arg2)
{
    s32 pad[2];
    s32 rem;
    register s32 i __asm__("$7");
    s32 cnt;
    register s32 d __asm__("$4");
    register s32 q __asm__("$6");
    register s32 zr __asm__("$0");
    register s32 dd __asm__("$3");
    register s32 srem __asm__("$3");
    s32 i2;
    u16 *pA;
    u16 *pB;
    s16 *pC;

    rem = arg0;
    cnt = 0;
    arg2--;
    i = arg2 + zr;
    if ((arg2 << 16) < 0) goto tail;
    pA = D_80063818;
    pB = D_800636D8;
    pC = D_80063870;
    do {
        if ((i << 16) != 0) {
            *arg1 = pA[0];
        } else {
            *arg1 = pB[0];
        }
        srem = (s16)rem;
        d = pC[(s16)i];
        q = srem / d;
        dd = d + zr;
        if ((s16)q != 0) {
            *arg1 = pB[(s16)q];
            cnt++;
            rem -= q * dd;
        } else if (cnt != 0) {
            *arg1 = pB[0];
        }
        i2 = i - 1;
        i = i2 + zr;
        arg1++;
    } while ((i2 << 16) >= 0);
tail:
    *(s16 *)arg1 = -1;
}
