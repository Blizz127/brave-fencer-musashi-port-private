/* Main-exec range [8002D59C,8002D678) from the SLUS executable.
 * SHA256(span)=14fa1d0b4f66cd9217c308975c794ba2459e336e078081a78791b47451181aba.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002D59C - byte-exact against retail at -O2 (tools/register_match.py). */

extern s8 D_800A4F17;
extern u8 D_800A4F18;
extern s16 D_800A4EFC;

void func_8002D59C(s32 arg0, s32 arg1, s32 arg2) {
    u16 id;
    u8 v0;
    s8 *p;

    *(u8 *)&D_800A4F17 = 1;
    id = arg0 & 0xFFFF;
    if (id < 0x80) {
        func_8002E138(id, arg1 & 0xFFFF, arg2 & 0xFFFF);
    } else if (id >= 0x100) {
        if (id < 0x400) {
            func_8002D904(id);
        } else {
            func_8002DC68(id | (arg2 << 16), arg1 & 0xFFFF);
        }
    }

    p = &D_800A4F17;
    v0 = D_800A4F18;
    *p = v0;
    if (v0 != 0) {
        s16 cnt = D_800A4EFC;
        if (cnt != 0) {
            D_800A4EFC = cnt - 1;
        }
        func_80030F80();
        func_8002D320();
        func_80031BE0();
        D_800A4F18 = 0;
        *p = 0;
    }
}
