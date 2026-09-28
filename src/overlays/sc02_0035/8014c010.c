/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014C010 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S8014C010;
struct S8014C010 {
    s16 h0;
    s16 h1;
    s16 h2;
    s16 h3;
    s32 w8;
    s32 wC;
    s32 w10;
};
extern void func_80146AFC(void*);
extern void func_80146AFC(void *a0);

void func_8014C010(s32 a0, s32 a1) {
    struct S8014C010 sp;
    sp.w8 = a0;
    sp.h0 = 2;
    sp.h1 = 0;
    sp.h2 = 0;
    sp.h3 = 0;
    sp.wC = a1;
    sp.w10 = 0;
    func_80146AFC(&sp);
}
