/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016FED0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_80171928(void *);
extern s32 func_80171CC4(void *a0, void *a1);
extern s32 func_80172664(s32 *a0);

void func_8016FED0(s32 *a0) {
    if (func_80172664(a0) != 0) {
        *(u16 *)((u8 *)a0 + 0xAA) |= 0x40;
    }
    if (func_80171CC4(a0, &D_8011F738) != 0) {
        func_80171928(a0);
    }
}
