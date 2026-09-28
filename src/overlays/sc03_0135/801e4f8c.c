/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E4F8C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171A1C(void*);
typedef struct { u8 c[8]; } Blk8;
extern s32 func_80171D78(u32, void *);
extern void func_80171A1C(void *);
extern const Blk8 D_801E2848 ;  /* data at its retail address */

void func_801E4F8C(u32 arg0) {
    Blk8 buffer;

    buffer = D_801E2848;

    if (func_80171D78(arg0, &buffer)) {
        ((void (*)(u32))func_80171A1C)(arg0);
    }
}
