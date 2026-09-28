/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB0E4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8011F9D0[];

void func_800CB0E4(void *a0) {
    u16 *p = (u16 *)D_8011F9D0;
    u16 *end = (u16 *)(D_8011F9D0 + 0x208);

    if (p < end) {
        do {
            if (*p == 10) {
                return;
            }
            p += 0x34;
        } while (p < end);
    }
    *(u16 *)((s32)a0 + 0xB8) = *(u16 *)((s32)a0 + 0xBA);
    *(u8 *)((s32)a0 + 0x197) += 1;
}
