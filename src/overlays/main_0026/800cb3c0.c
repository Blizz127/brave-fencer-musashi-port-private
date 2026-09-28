/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB3C0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_800CB5F4();

void func_800CB3C0(void *arg0) {
    void *s0;
    s16 w;
    void *v1;

    s0 = *(void **)((u8 *)arg0 + 0x20);
    func_800CB5F4(arg0);
    if (*(s32 *)((u8 *)arg0 + 0x50) != 0) {
        *(u16 *)((u8 *)s0 + 0x1e) += 0x100;
    }
    *(u16 *)((u8 *)arg0 + 0x60) += 0x40;
    w = *(u16 *)((u8 *)s0 + 0x1a) + *(u16 *)((u8 *)arg0 + 0x60);
    *(u16 *)((u8 *)s0 + 0x1a) = w;
    *(u16 *)((u8 *)s0 + 0x18) = w;
    if ((s16)w >= 0x1001) {
        *(u16 *)((u8 *)s0 + 0x1a) = 0x1000;
        *(u16 *)((u8 *)s0 + 0x18) = 0x1000;
        v1 = *(void **)((u8 *)arg0 + 0x4c);
        *(u8 *)((u8 *)v1 + 0xbe) = 1;
        func_80146CA0(arg0);
    }
}
