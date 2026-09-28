/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB988 - byte-exact against retail at -O2 (tools/register_match.py). */
extern signed char D_800CBB44[];
extern s32 func_80017758(void *a0, void *a1);

s32 func_800CB988(s32 param_1) {
    unsigned char buf[0x34];
    signed char *p;
    short i;
    u8 t;

    p = D_800CBB44;
    i = 0;
    *(short *)(buf + 0x0c) = 0;
    *(short *)(buf + 0x0a) = 0;
    *(short *)(buf + 0x08) = 0;
    *(short *)(buf + 0x1c) = 0;
    *(short *)(buf + 0x14) = 0;
    *(short *)(buf + 0x04) = 0;
    t = *(u8 *)(param_1 + 0x30);
    buf[0x22] = 0;
    buf[0x21] = 0;
    buf[0x20] = 0;
    buf[0x2a] = 0;
    buf[0x29] = 0;
    buf[0x28] = 0;
    buf[0x2e] = 0;
    buf[0x2d] = 0;
    buf[0x2c] = 0;
    *(int *)(buf + 0x30) = 0x50000000;
    buf[0x25] = t;
    buf[0x24] = t;
    buf[0x26] = t >> 1;
    do {
        *(short *)(buf + 0x00) = *p++;
        *(short *)(buf + 0x02) = *p++;
        *(short *)(buf + 0x10) = *p++;
        *(short *)(buf + 0x12) = *p++;
        *(short *)(buf + 0x18) = *p++;
        *(short *)(buf + 0x1a) = *p--;
        func_80017758(buf, (void *)((s32)param_1 + 0x38));
        i++;
    } while (i < 4);
}
