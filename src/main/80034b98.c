/* Exact retail word export for [80034B98,80034C24); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80034B98 (CdQueueBusy) - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 D_8006AEF8;
extern s32 D_8006AEFC;
extern u8 D_80076214;
extern u8 D_8007620C;

s32 func_80034B98(void) {
    if (D_8006AEF8 != D_8006AEFC) {
        if (D_80076214 == 0) {
            if (D_8007620C & 0x80) {
                return 2;
            }
            if (D_8007620C & 0x20) {
                return 4;
            }
            return 1;
        }
    } else {
        D_8007620C = 0;
        if (D_80076214 == 0) {
            return 0;
        }
    }
    D_80076214 = 0;
    return 8;
}
