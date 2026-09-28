/* Exact retail word export for [80029344,8002941C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80029344 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor typedefs this body depends on (copied from vendor/bfm-decomp). */
typedef struct {
    u16 unk00;
    u8  pad[14];
} T16;  /* 0x10 */
typedef struct {
    s32 words[38];
} Blk98_80029274;

extern u16 D_80078E92;
extern u8 D_80078EAE;
extern Blk98_80029274 D_80078E78;

void func_80029344(void) {
    s32 val;
    u8* blk;

    val = D_80078E92;
    blk = (u8*)&D_80078E78;

    if ((u32)(val - 0x1A4) >= 0x2D0) {
        D_80078EAE = 0;
    } else {
        D_80078EAE = 1;
    }

    if ((s16)val < 0x528) {
        if ((s16)val >= 0x474) {
            blk[0x37] = 3;
        } else {
            if ((s16)val >= 0x3C0) {
                blk[0x37] = 2;
            } else {
                if ((s16)val >= 0x1A4) {
                    blk[0x37] = 1;
                } else {
                    if ((s16)val < 0x12C) {
                        blk[0x37] = 4;
                    } else {
                        blk[0x37] = 0;
                    }
                }
            }
        }
    } else {
        blk[0x37] = 4;
    }

    blk[0x39] = (s16)val / 60;
    blk[0x38] = (s16)val % 60;
}
