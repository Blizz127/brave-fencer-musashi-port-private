/* Overlay range [8014C118,8014C168) from MAIN.CD member 0012.
 * SHA256(span)=914cdf0e3c0a33b38a643a7c03e21084ee6563c116939ae35a623c9198a40a16.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014C118 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    u16 unk0;
    u8 pad[0x6E];
    s16 unk70;
    u8 pad2[0x9A];
} Entry8014C118;
extern u8 D_801202A0[];

s32 func_8014C118(void * a0, s32 a1, s32 a2)
{
    Entry8014C118 *p;
    s32 i;
    i = 0;
    a2 = (s16)a2;
    p = (Entry8014C118 *)D_801202A0;
    do {
        if (p->unk0 == a1) {
            if (p->unk70 == a2) {
                return (s32)p;
            }
        }
        i++;
        p++;
    } while ((u32)i < 0x60);
    return 0;
}
