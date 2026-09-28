/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012BDBC - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);
extern s32 ratan2(s32 x, s32 y);
extern s16 D_80126CB8;
extern s16 D_80126CB4;

s32 func_8012BDBC(s32 a0, s32 a1) {
    s32 s0 = a0;
    s32 v0;
    s32 angle;
    v0 = ratan2(*(s16 *)(s0 + 0xE) - D_80126CB8, D_80126CB4 - *(s16 *)(s0 + 0x6));
    v0 = (v0 - 0x400) & 0xFFF;
    v0 = v0 - *(s16 *)(*(s32 *)(s0 + 0x20) + 0x12);
    angle = v0 & 0xFFF;
    if (angle < 0x800) {
        return angle < (s16)a1;
    }
    return (0x1000 - angle) < (s16)a1;
}
