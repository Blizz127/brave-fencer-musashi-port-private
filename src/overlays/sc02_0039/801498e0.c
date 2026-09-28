/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801498E0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 *func_80146750(u16 *param_1);
unsigned short *func_80146750(unsigned short *a0);
extern s32 func_80149AA8(s32 *a0);
extern s32 func_80149B54(s32 *a0);

s32 func_801498E0(s32 *a0) {
    s16 st[4];
    s32 stw[3];
    if (func_80149AA8(a0) != 0 || func_80149B54(a0) != 0) {
        st[0] = 8;
        stw[0] = (s32)a0;
        st[1] = 0;
        st[2] = -0x1E;
        st[3] = 0;
        stw[1] = 0;
        stw[2] = 0;
        func_80146750(st);
        return 1;
    }
    return 0;
}
