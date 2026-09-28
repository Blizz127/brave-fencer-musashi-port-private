/* Overlay range [8016E95C,8016E9EC) from MAIN.CD member 0012.
 * SHA256(span)=8068f8b9b0b9a4d94620711713dcc8230346992e8a5a7e0f422dd4dabf9ea8b7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016E95C - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { s16 id; s16 val; } Entry;
struct Entry {
    u8 f0;
    u8 f1;
    u8 pad[0x1e];
};
extern s32 D_80115218;
typedef void (*Handler)(struct Entry *);

s32 func_8016E95C() {

    extern s32 D_80115218;
    extern Handler D_8018174C[];

    struct Entry *p;
    for (p = ((struct Entry *)&D_80115218); p < &((struct Entry *)&D_80115218)[4]; p++) {
        if (p->f0 != 0) {
            D_8018174C[p->f1](p);
        }
    }
}
