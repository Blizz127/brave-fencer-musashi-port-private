/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80179B74 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80195DA8[0x200];
extern s16 D_801961AC;

void func_80179B74(u16 *p) {
    s32 pad[10];
    s16 c;

    (void)&pad;
    c = *p++;
    D_80195DA8[D_801961AC] = c;
    D_801961AC = (D_801961AC + 1) & 0x1FF;
    switch (c) {
    case 0:
        break;
    case 1:
    case 5:
        { s16 t = *p++; D_80195DA8[D_801961AC] = t; D_801961AC = (D_801961AC + 1) & 0x1FF; }
        { s16 t = *p++; D_80195DA8[D_801961AC] = t; D_801961AC = (D_801961AC + 1) & 0x1FF; }
        { s16 t = *p++; D_80195DA8[D_801961AC] = t; D_801961AC = (D_801961AC + 1) & 0x1FF; }
        break;
    case 0x13:
        { s16 t = *p++; D_80195DA8[D_801961AC] = t; D_801961AC = (D_801961AC + 1) & 0x1FF; }
        { s16 t = *p++; D_80195DA8[D_801961AC] = t; D_801961AC = (D_801961AC + 1) & 0x1FF; }
        break;
    case 2:
    case 3:
    case 4:
    case 6:
    case 0x12:
    case 0x14:
    case 0x1F:
        { s16 t = *p++; D_80195DA8[D_801961AC] = t; D_801961AC = (D_801961AC + 1) & 0x1FF; }
        break;
    case 0x17:
    case 0x1C:
    case 0x1D:
    case 0x20:
        { s16 t = *p++; D_80195DA8[D_801961AC] = t; D_801961AC = (D_801961AC + 1) & 0x1FF; }
        { s16 t = *p++; D_80195DA8[D_801961AC] = t; D_801961AC = (D_801961AC + 1) & 0x1FF; }
        { s16 t = *p++; D_80195DA8[D_801961AC] = t; D_801961AC = (D_801961AC + 1) & 0x1FF; }
        { s16 t = *p++; D_80195DA8[D_801961AC] = t; D_801961AC = (D_801961AC + 1) & 0x1FF; }
        break;
    case 0x22:
        break;
    }
}
