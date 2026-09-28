/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB6E8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *arg0);
extern void func_800CB8C4(void *a0, void *a1);
extern void func_800CB900();

void func_800CB6E8(void *arg0) {
    s16 w;
    s32 pad[2];

    w = *(u16 *)((u8 *)arg0 + 0x12) + 0x18;
    *(u16 *)((u8 *)arg0 + 0x12) = w;
    if ((s16)w >= -7) {
        *(s16 *)((u8 *)arg0 + 0x12) = -8;
        func_80146CA0(arg0);
    }
    w = *(u16 *)((u8 *)arg0 + 0x18) + 0xB;
    *(u16 *)((u8 *)arg0 + 0x18) = w;
    func_800CB8C4(arg0, pad);
    func_800CB900(arg0, pad, (u8 *)arg0 + 0x10, (u8 *)arg0 + 0x14,
                  (u8 *)arg0 + 0x58, (u8 *)arg0 + 0x5C, (u8 *)arg0 + 0x18);
}
