/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F1CD8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171A1C(void*);
typedef struct { u8 c[8]; } Blk8;
extern const Blk8 D_801EF6C0 ;  /* data at its retail address */
extern s32 func_80171D78(u32, void *);
extern void func_80171A1C(void *);

void func_801F1CD8(u32 arg0) {
    Blk8 buffer;

    buffer = D_801EF6C0;

    if (func_80171D78(arg0, &buffer)) {
        ((void (*)(u32))func_80171A1C)(arg0);
    }
}
