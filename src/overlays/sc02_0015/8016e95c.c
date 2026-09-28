/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016E95C - byte-exact against retail at -O2 (tools/register_match.py). */
struct Entry_8016E95C {
    u8 f0;
    u8 f1;
    u8 pad[0x1e];
};
extern s32 D_80115218;
typedef void (*Handler)(struct Entry_8016E95C *);

s32 func_8016E95C() {
    extern Handler D_80181610[];

    struct Entry_8016E95C *p;
    for (p = ((struct Entry_8016E95C *)&D_80115218); p < &((struct Entry_8016E95C *)&D_80115218)[4]; p++) {
        if (p->f0 != 0) {
            D_80181610[p->f1](p);
        }
    }
}
