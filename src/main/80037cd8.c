/* Exact retail word export for [80037CD8,80037D74); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80037CD8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_8006AEF4;
extern s32 D_800BA0F8;

int func_80037CD8(void *arg) {
    if ((D_8006AEF4 & 0x2) != 0) {
        s32 *handler = (s32 *)&D_800BA0F8;

        if (*handler != 0) {
            int result = ((int (*)(void *))*handler)(arg);

            if (result != 0) {
                u8 flags = D_8006AEF4;
                *handler = (s32)arg;
                D_8006AEF4 = flags & 0xFD;
                return 1;
            }
            return 0;
        }
    }

    D_800BA0F8 = (s32)arg;
    D_8006AEF4 &= 0xFD;
    return 1;
}
