/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012BCCC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern s32 func_80013478(s32 a0, s32 a1);
extern s16 D_80126CBA;

s32 func_8012BCCC(s32 a0) {
    s32 *p = &D_80126B58;
    if (D_80126CBA != 0) {
        return 0x7FFFFFFF;
    }
    return func_80013478(a0 + 4, (s32)p + 0x15C);
}
