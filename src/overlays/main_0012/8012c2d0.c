/* Overlay range [8012C2D0,8012C2E0) from MAIN.CD member 0012.
 * SHA256(span)=46ab55de2b62c0abfcc301481c157818413892f00266f9e74c6432c79bc45da5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012C2D0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801202A0[];
extern u8 D_80120194[];

s32 func_8012C2D0(void)
{
    s32 p;
    s32 it;
    it = (s32)D_80120194;
    __asm__ __volatile__("" : "=r"(it) : "0"(it));
    p = it + 0x658C;
    goto test;
copy:
    return it;
test:
    it = (s32)D_801202A0;
    __asm__ __volatile__("" : "=r"(it) : "0"(it));
    if (it == p) goto zero;
body:
    if (*(u16 *)it == 0) goto copy;
    it += 0x10C;
    if (it != p) goto body;
zero:
    return 0;
}
