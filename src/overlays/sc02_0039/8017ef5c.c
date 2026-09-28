/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017EF5C - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
        u16 x;  
        u16 y;  
        u16 z;  
        u16 w;  
    } V4_8017FAC0_8017D708;
extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);

s32 func_8017EF5C(s32 a0, s32 a1) {
    s16 half;
    V4_8017FAC0_8017D708 p1;
    V4_8017FAC0_8017D708 p2;
    s32 i, j;
    s32 val;

    half = *(u16 *)(a1 + 0x2) >> 1;
    p2.x = half;
    p1.x = -half;

    for (i = 0; i < *(u16 *)a1; i++) {
        val = *(u16 *)(a1 + 0x8 + i * 2);
        p2.y = val;
        p1.y = val;
        for (j = 0; j < *(u16 *)a1; j++) {
            val = *(u16 *)(a1 + 0x8 + j * 2);
            p2.z = val;
            p1.z = val;
            if (func_8012DEB8(a0, (s32)&p1, (s32)&p2) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
