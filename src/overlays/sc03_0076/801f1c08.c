/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F1C08 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801F9DCC;

s32 func_801F1C08(void *a0) {
    extern s32 (*D_801F3488[])(void);
    extern s32 D_801F9DCC;
    extern s32 func_801F29E0(void);

    if (D_801F3488[*(u8 *)((s32)a0 + 0x15)]() != 0 && D_801F9DCC != 0) {
        return 1;
    }
    D_801F9DCC = func_801F29E0();
    return 0;
}
