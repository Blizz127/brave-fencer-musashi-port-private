/* Overlay range [80178970,801789AC) from MAIN.CD member 0012.
 * SHA256(span)=2629493751c3db7fa8e0ed0d60b213758d2839bb9cea09184ea57dfdfaf4584a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80178970 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 (*D_801819EC[])(void *);
u32 v;
extern s32 func_801789AC(s32 arg0);

int func_80178970(void)
{

    extern s16 D_80185C08;
    register int r __asm__("$2");
    int v;

    v = ((s32 (*)(void))func_801789AC)();
    r = 0;
    if (v != 0)
        r = D_80185C08 == 0;
    return r;
}
