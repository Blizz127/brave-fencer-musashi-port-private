/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E4D98 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801E4D98(void *a0) {
    extern void (*D_801E65F0[])(void);
    extern void func_801E5324(void);
    extern s32 D_801EAC68;
    s32 v0;

    v0 = ((s32 (*)(void))D_801E65F0[*(u8 *)((s32)a0 + 0x15)])();
    if (v0 != 0 && D_801EAC68 != 0) {
        return 1;
    }
    D_801EAC68 = ((s32 (*)(void))func_801E5324)();
    return 0;
}
