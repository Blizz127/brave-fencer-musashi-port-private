/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD1A8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80162CCC(void);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_800CD1A8(void) {
    register void *a0r __asm__("$4");
    void *arg0 = a0r;

    func_80146A6C(3, arg0,
                  *(s16 *)((u8 *)arg0 + 6),
                  *(s16 *)((u8 *)arg0 + 0xA),
                  *(s16 *)((u8 *)arg0 + 0xE),
                  0x8880000, 0x1800A000);
    ((void (*)(void *))func_80162CCC)(arg0);
}
