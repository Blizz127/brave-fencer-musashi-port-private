/* Main-exec range [8002F1CC,8002F248) from the SLUS executable.
 * SHA256(span)=be19626151ad7a73a72243ecd4c6df857b74ea7aea47e9162839355e3681116a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002F1CC - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct F1ccRec {
    u8 pad[0x0E];
    u8 flg[8];
    u8 tail[0x3E];
} F1ccRec;

typedef struct F1ccSlot {
    u8 pad[0x20];
    u32 u20;
    u32 u24;
    u32 u28;
    u32 u2C;
    u16 u30;
    u8 mid[5];
    u8 u37;
    u8 u38;
    u8 tail[0x1B];
} F1ccSlot;

extern u8 D_800A4694[];

void func_8002F1CC(s32 arg0) {
    F1ccRec *sp = (F1ccRec *)D_800A4694 + arg0;
    F1ccSlot *slots = (F1ccSlot *)(D_800A4694 + 0x2F4);
    s32 i;
    s32 val;

    for (i = 0, val = 0x18; i < 8; i++) {
        if (sp->flg[i]) {
            slots[i].u28 = slots[i].u20 + 0x100;
            slots[i].u37 |= 1;
            slots[i].u30 = 0;
            slots[i].u38 = 0;
            slots[i].u2C = val;
        }
    }
}
