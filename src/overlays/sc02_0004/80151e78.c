/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80151E78 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_80146CA0(void *a0);
void func_80149020(s32 *a0);
extern void func_80146CA0(void *a0);
extern void func_80149020(s32 *a0);
extern s32 func_80172630(u8 *a0);

void func_80151E78(s32 *a0) {
    u8 *p = (u8 *)a0 + 0xDE;
    u8 v;
    func_80149020(a0);
    v = *p;
    *p = v + 0xFF;
    if (v == 0) {
        *p = 0x10;
        func_80146CA0(a0);
    }
    func_80172630((u8 *)a0);
}
