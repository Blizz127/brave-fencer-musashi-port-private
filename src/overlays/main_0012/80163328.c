/* Overlay range [80163328,801633A8) from MAIN.CD member 0012.
 * SHA256(span)=2f7f30733400879be4c0933bd8d062320c830c9bbb39deb88de7b52f3c21f66d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80163328 - byte-exact against retail at -O2 (tools/register_match.py). */
struct Vec4s;
struct Vec4s { s16 a, b, c, d; };
typedef struct {
    s16 f0, f1, f2, f3;
} Vec4s;
extern s32 D_80115100;
extern s32 D_80115200;
extern u16 D_80126B18[];

void func_80163328(void) {
    u32 i;
    s32 *table;
    u16 *src;
    s32 *flags;
    i = 0;
    table = &D_80115100;
    src = D_80126B18;
    flags = &D_80115200;
    do {
        if (*flags & 1) {
            u8 *dst = (u8 *)*table;
            *(struct Vec4s *)(dst + 0x7C) = *(struct Vec4s *)src;
            *(s16 *)((u8 *)*table + 0x82) = 0;
        }
        table += 1;
        src += 4;
        i += 1;
        flags += 1;
    } while (i < 3);
}
