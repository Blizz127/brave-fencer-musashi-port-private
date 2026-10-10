/* Overlay range [80159464,801594E8) from MAIN.CD member 0012.
 * SHA256(span)=ac5778006c2faf45085b218661db535c6244eff0d158856fc6fa6f6e246f66a4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80159464 - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
typedef struct { s16 id; s16 val; } Entry;
struct Entry {
    u8 f0;
    u8 f1;
    u8 pad[0x1e];
};
extern s16 currentLocationId;
extern short currentLocationId;
extern s32 func_80029A94(s32);

s32 func_80159464(void) {

    extern Entry D_80180FE0[];
    Entry *e;

    e = D_80180FE0;
    while (e->id != 0) {
        if (currentLocationId == e->id) {
            return e->val;
        }
        e++;
    }
    if (func_80029A94(1) != 0) {
        goto ret0;
    }
    if (func_80029A94(0) != 0) {
        goto ret0;
    }
    return -1;
ret0:
    return 0;
}
