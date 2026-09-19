/* Exact overlay word export for [800D22E4,800D2318) from MAIN.CD member0010
 * (extracted/overlays/main/0010.bin offset 0x234EC, load base 800AEDF8).
 * SHA256(span)=8ba7a8502e27791f8b1444b8d8f5f268230990dbe4372e0a27587eb9b2b6ea56.
 * Word export only: the native seam executes the member's own words. */
#include "psx_types.h"

typedef struct {
    s32 pad;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
} S22E4;

void func_800D22E4(S22E4 *arg0) {
    arg0->f4 += arg0->f10;
    arg0->f8 += arg0->f14;
    arg0->fC += arg0->f18;
}

