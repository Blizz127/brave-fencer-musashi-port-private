/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801457A4 - byte-exact against retail at -O0 (tools/register_match.py). */
extern int D_8017DC90;

void *func_801457A4(s32 param_1) {
    switch (param_1) {
    case 0x1010:
    case 0x1052:
    case 0x1077:
    case 0x1094:
    case 0x2013:
    case 0x2015 ... 0x201a:
    case 0x2055 ... 0x205b:
    case 0x207a ... 0x2080:
    case 0x2097 ... 0x209d:
        return (void *)(&D_8017DC90)[param_1 & 0xffff0fff];
    default:
        return (void *)D_8017DC90;
        break;
    }
}
