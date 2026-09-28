/* Overlay range [801457A4,801458C4) from MAIN.CD member 0012.
 * SHA256(span)=4d483a9851eee2f5fd1e2aa24a54eae26379a4a8156eaf023a2f0c692cf0eea4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801457A4 - byte-exact against retail at -O0 (tools/register_match.py). */
extern int D_8017E338;

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
        return (void *)(&D_8017E338)[param_1 & 0xffff0fff];
    default:
        return (void *)D_8017E338;
        break;
    }
}
