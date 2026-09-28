/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCEAC - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
extern void func_801599A4(void *arg0);
extern void func_80159B3C(void *arg0);

s32 func_800CCEAC(void *a0)
{
    extern void func_801599A4(void *a0);
    extern void func_80159B3C(void *a0);
    extern s16 currentLocationId;

    if (currentLocationId == 0x306F) {
        if (*(s32 *)((s32)a0 + 0x234) != 0) {
            (*(s32 *)((s32)a0 + 0x234))--;
            return 0;
        }
        func_801599A4(a0);
        func_80159B3C(a0);
        return 1;
    }
    return 0;
}
