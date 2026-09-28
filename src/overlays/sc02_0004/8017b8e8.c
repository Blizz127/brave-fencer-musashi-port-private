/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B8E8 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { unsigned char b[8]; } S8_8017B8E8;
extern s16 D_8019622C;
extern s16 D_80196224;

s32 func_8017B8E8(s32 src) {
    (*(S8_8017B8E8 *)&D_8019622C) = ((S8_8017B8E8 *)src)[0];
    (*(S8_8017B8E8 *)&D_80196224) = ((S8_8017B8E8 *)src)[1];
}
