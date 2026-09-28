/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB06C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80161208();
extern s32 func_80165A20(s32 a0);
extern void func_80146CA0(void *a0);

void func_800CB06C(void *arg0) {
    s32 p;
    s32 q;
    register void *a __asm__("$4");
    if (func_80161208(arg0) != 0) {
        func_80165A20(arg0);
        return;
    }
    *(s32 *)((u8 *)arg0 + 0x238) += 0x1c000;
    p = *(s32 *)((u8 *)arg0 + 0x20);
    *(u16 *)((u8 *)p + 0x10) =
        (*(u16 *)((u8 *)p + 0x10) - *(u16 *)((u8 *)arg0 + 0x23a)) & 0xfff;
    q = *(s32 *)((u8 *)arg0 + 0x20);
    if (*(s16 *)((u8 *)q + 0x10) < 0xc00) {
        a = arg0;
        __asm__ __volatile__("" : : "r"(a));
        *(u16 *)((u8 *)q + 0x10) = 0xc00;
        *(u16 *)((u8 *)a + 0xb8) = 1;
        func_80146CA0(a);
    }
}
