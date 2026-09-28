/* Overlay range [8014A738,8014A830) from MAIN.CD member 0012.
 * SHA256(span)=aa4b990f2613b720adab343799213226cc04518ca1330f5e1e6062f9c97b3730.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014A738 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
        u8 pad0[6];
        u16 x;
        u8 pad8[6];
        u16 z;
        u8 pad10[0xB1];
        u8 state;
        u8 padC2[0x4A];
    } Ent_801202A0;
typedef struct {
        s16 vx;
        s16 vy;
        s16 vz;
        s16 pad;
    } Vec_8014A738;
extern s32 func_80029178(s32);
extern u8 D_801202A0[];
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);

s32 func_8014A738(void *arg0) {
    extern u8 D_801202A0[];
    Vec_8014A738 d;
    u32 i;
    Ent_801202A0 *base;
    if ((func_80029178(0x83) & 0xFF) == 0) {
        return 0;
    }
    base = (Ent_801202A0 *)D_801202A0;
    for (i = 0; i < 0x60; i++) {
        if (base[i].state == 7) {
            d.vx = ((Ent_801202A0 *)arg0)->x - base[i].x;
            d.vz = ((Ent_801202A0 *)arg0)->z - base[i].z;
            if (d.vx >= 0) {
                if (d.vx < 0x40) {
                    goto zcheck;
                }
            } else {
                if (-d.vx < 0x40) {
                    goto zcheck;
                }
            }
            continue;
        zcheck:
            if (d.vz >= 0) {
                if (d.vz < 0x40) {
                    goto found;
                }
            } else {
                if (-d.vz < 0x40) {
                    goto found;
                }
            }
            continue;
        found:
            return 1;
        }
    }
    return 0;
}
