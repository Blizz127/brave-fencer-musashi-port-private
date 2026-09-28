/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012BD3C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80013478(s32 a0, s32 a1);
extern s16 D_80126CB4;
extern s16 D_80126CBA;
extern s32 func_8012BDBC(s32 a0, s32 a1);

s32 func_8012BD3C(s32 a0, s32 a1, s32 a2) {
    s32 v;
    s32 hp;
    hp = a1;
    if (D_80126CBA != 0) {
        v = 0x7FFFFFFF;
    } else {
        v = func_80013478(a0 + 4, (s32)&D_80126CB4);
    }
    if (a2 < v) {
        return 0;
    }
    return func_8012BDBC(a0, (s16)hp);
}
