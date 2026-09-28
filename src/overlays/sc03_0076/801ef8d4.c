/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EF8D4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern unsigned short D_80115112;
extern void func_800D24A0(s32);
extern void func_801EF918(void);
extern void func_8002AF18(void);
extern u16 D_80115112;

void func_801EF8D4(void) {
    u16 *p = &D_80115112;
    ((void (*)(u32))func_800D24A0)(0x5);
    func_801EF918();
    func_8002AF18();
    *p = *p + 1;
}
