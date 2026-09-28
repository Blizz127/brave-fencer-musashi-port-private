/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB254 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_800CAF90(void *a0);

void func_800CB254(void *a0) {
    typedef struct { s32 w[4]; } S16;
    extern u8 D_80078EC1;
    extern void func_80146C3C(void *a0);
    extern void func_800CAF90(void *a0);
    s32 a1;
    s32 n;
    s32 m;
    s32 v0;
    a1 = *(s32 *)((s32)a0 + 0x34);
    if (D_80078EC1 == 5) {
        if ((*(s32 *)((s32)a0 + 0x1C))++ < 10) {
            *(u16 *)((s32)a0 + 0x28) += 0x120;
        } else {
            n = *(u16 *)((s32)a0 + 2);
            n += 1;
            *(u16 *)((s32)a0 + 0x12) = (s16)*(u16 *)(a1 + 0x12) >> 1;
            m = *(u16 *)(a1 + 0x1A);
            *(s32 *)((s32)a0 + 0x30) = 0x20;
            *(s32 *)((s32)a0 + 0x1C) = -0xC0;
            *(u16 *)((s32)a0 + 0x2A) = 0x500;
            *(u16 *)((s32)a0 + 2) = n;
            *(u16 *)((s32)a0 + 0x1A) = (s16)m >> 1;
        }
        v0 = *(s32 *)(a1 + 0x20);
        *(S16 *)((s32)a0 + 0x38) = *(S16 *)(v0 + 0x34);
        *(S16 *)((s32)a0 + 0x48) = *(S16 *)(v0 + 0x44);
        func_800CAF90(a0);
    } else {
        func_80146C3C(a0);
    }
}
