/* Overlay range [8014A238,8014A2E4) from MAIN.CD member 0012.
 * SHA256(span)=97348bbea520eaf143f6c41a39ae6c9fd2e26da924e89bb9a4a89cd2dda90d3f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014A238 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    u16 f_0;
    u8 pad_2[0xA8];
    s16 f_AA;
    u8 pad_AC[0x60];
} Entry8014A238;
extern u8 D_801202A0[];
extern s32 func_8014C278(s32 a0, s32 a1, s32 a2);
extern s32 func_8014C2B0(void *a0, void *a1, s32 a2);

s32 func_8014A238(s32 arg0) {
    u32 i;
    Entry8014A238 *p;
    for (i = 0; i < 0x60; i++) {
        p = &((Entry8014A238 *)D_801202A0)[i];
        if ((p->f_0 != 0) && (p->f_AA != 0) &&
            (func_8014C278(arg0, (s32)p, 0x30) != 0) &&
            (func_8014C2B0((void *)arg0, (void *)p, 0x200) != 0)) {
            return (s32)p;
        }
    }
    return 0;
}
