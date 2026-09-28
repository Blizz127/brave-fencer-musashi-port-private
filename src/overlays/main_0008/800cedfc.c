/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CEDFC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CEF50(void);
extern u16 D_800B99E4;
extern void (*D_800CF0FC[])(void);

void func_800CEDFC(void) {
    func_800CEF50();
    D_800CF0FC[D_800B99E4]();
}
