/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80158880 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80149020(s32 *a0);
extern void (*D_80181498[])(s32 *);

void func_80158880(s32 *param) {
    func_80149020(param);
    D_80181498[*(u8 *)((s32)param + 0x4F)](param);
}
