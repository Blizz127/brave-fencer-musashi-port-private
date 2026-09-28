/* Overlay range [8012832C,80128420) from MAIN.CD member 0012.
 * SHA256(span)=22c3ea89192a584021748e27429b706094b404f86db0145d80b33635872b46b1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012832C - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
extern s16 currentLocationId;
extern s32 func_80029504(void);
extern s32 func_800CF854(s32);
extern s32 func_80128998(void);
extern s32 func_801289F0(void);
extern s32 func_801288E8(s32);
extern s32 func_80128940(s32);
extern s32 func_80029178(s32);
extern s32 func_801288B0(void);
extern void func_80011C10(void);

void func_8012832C(void) {
    s32 a0 = func_80029504();
    s32 v0;
    switch (currentLocationId) {
    case 0x300E:
        if (func_800CF854(a0) == 0) {
            v0 = func_80128998();
        } else {
            v0 = func_801289F0();
        }
        break;
    case 0x30A0:
        if (a0 < 0x640) {
            v0 = func_801288E8(a0);
        } else {
            v0 = func_80128940(a0);
        }
        break;
    case 0x3014:
        if (a0 == 0x4B0 && (func_80029178(0x138) & 0xFF) == 0) {
            v0 = func_801288B0();
        } else {
            v0 = 1;
        }
        break;
    default:
        func_80011C10();
        return;
    }
    if (v0 != 0) {
        func_80011C10();
    }
}
