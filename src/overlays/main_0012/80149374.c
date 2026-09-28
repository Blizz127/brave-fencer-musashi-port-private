/* Overlay range [80149374,801493D0) from MAIN.CD member 0012.
 * SHA256(span)=0c36e904c5b85fe1b8357401a8af42467b327a6aea634b1191601da6f541a9f8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80149374 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef unsigned long long u64;
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015954(s32 a0, s32 a1);
extern void func_80015978(s32, s32*);
extern void func_80015978(int a0, int *a1);

void func_80149374(s32 arg0, s32 arg1)
{
    u64 sp10;
    u64 sp18;
    ((void (*)(s32, void*))func_80015978)(arg1, &sp10);
    {
        void *q = &sp18;
        ((void (*)(s32, void*, void*))func_8012F14C)(*(s32*)(arg0 + 0x20) + 0x34, &sp10, q);
        __asm__ __volatile__("" : "=r"(q));   
    }
    ((void (*)(void*, s32))func_80015954)(&sp18, arg1);
}
