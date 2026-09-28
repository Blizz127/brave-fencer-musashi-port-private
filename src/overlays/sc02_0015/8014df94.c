/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014DF94 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8014E284(s32 a0, s16 *a1, s16 *a2);
extern s32 func_8014E048(s32 a0, u16 *a1, u16 *a2);

void func_8014DF94(s32 arg0) {
    s16 a[3];
    s16 b[3];
    register s32 u88 __asm__("$4");
    register s32 u8C __asm__("$5");
    s32 t;
    s32 t2;
    u88 = *(u16 *)(arg0 + 0x88);
    a[0] = u88;
    a[1] = *(u16 *)(arg0 + 0x8A) - 0x10;
    u8C = *(u16 *)(arg0 + 0x8C);
    a[2] = u8C;
    t = *(u16 *)(arg0 + 6);
    b[0] = t;
    b[1] = *(u16 *)(arg0 + 0xA) - 0x10;
    t = t - u88;
    t2 = *(u16 *)(arg0 + 0xE);
    u88 = u88 - t;
    b[0] = t;
    __asm__ __volatile__("" : : : "memory");
    b[0] = u88;
    b[2] = t2;
    __asm__ __volatile__("" : : : "memory");
    t2 = t2 - u8C;
    u8C = u8C - t2;
    b[2] = t2;
    __asm__ __volatile__("" : : : "memory");
    b[2] = u8C;
    if (*(s32 *)(arg0 + 0x170) == 0) {
        func_8014E284(arg0, a, b);
    } else {
        func_8014E048(arg0, a, b);
    }
}
