/* Main-exec range [8002F150,8002F1CC) from the SLUS executable.
 * SHA256(span)=44815c696a2e671fff3f47f694651b0f6d0c8c7bab37299f5d63f4b1e832a0d1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002F150 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u8 D_800A4694[];

void func_8002F150(s32 arg0) {
    struct F150Rec {
        u8 pad[0x0E];
        u8 flg[8];
        u8 tail[0x3E];
    };
    struct F150Slot {
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
    };

    struct F150Rec *rec = (struct F150Rec *)D_800A4694 + arg0;
    struct F150Slot *slots = (struct F150Slot *)(D_800A4694 + 0x2F4);
    s32 i;
    s32 val;

    for (i = 0, val = -0x18; i < 8; i++) {
        if (rec->flg[i]) {
            slots[i].u28 = slots[i].u20 - 0x100;
            slots[i].u37 |= 1;
            slots[i].u30 = 0;
            slots[i].u38 = 0;
            slots[i].u2C = val;
        }
    }
}
