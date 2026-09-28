/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016FD08 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146D90(s32 a0);
extern void func_80146D90(int);
extern void *D_8011F738;
extern s32 func_80171990(u8 *a0);
extern s32 func_80172658(s32 *a0);

void func_8016FD08(u8 *s0) {
    s32 *p;
    if (func_80172658((s32 *)s0)) {
        func_80146D90((s32)s0);
        *(u16 *)(s0 + 0xAC) = *(u16 *)(s0 + 0xAC) | 0x40;
        *(u16 *)(s0 + 0xAA) = *(u16 *)(s0 + 0xAA) | 0x40;
        p = (s32 *)&D_8011F738;
        if ((*p = *p - 1) == 0) {
            func_80171990(s0);
        }
    }
}
