/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB77C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *arg0);
extern void func_800CB8C4(void *a0, void *a1);
extern void func_800CB900();

void func_800CB77C(void *arg0) {
    extern s32 func_80012F74(s32 a0, s32 a1, s32 a2, s32 a3);
    extern void func_80146CA0(void *a0);
    extern void func_800CB8C4(void *a0, void *a1);
    extern void func_800CB900();
    s16 w;
    s32 pad[2];

    w = *(u16 *)((u8 *)arg0 + 0x14) + 8;
    *(u16 *)((u8 *)arg0 + 0x14) = w;
    *(u8 *)((u8 *)arg0 + 0x58) = func_80012F74(*(u8 *)((u8 *)arg0 + 0x58), 0, 10, 1);
    *(u8 *)((u8 *)arg0 + 0x59) = func_80012F74(*(u8 *)((u8 *)arg0 + 0x59), 0, 10, 1);
    *(u8 *)((u8 *)arg0 + 0x5A) = func_80012F74(*(u8 *)((u8 *)arg0 + 0x5A), 0, 10, 1);
    *(u8 *)((u8 *)arg0 + 0x5C) = func_80012F74(*(u8 *)((u8 *)arg0 + 0x5C), 0, 10, 1);
    *(u8 *)((u8 *)arg0 + 0x5D) = func_80012F74(*(u8 *)((u8 *)arg0 + 0x5D), 0, 10, 1);
    *(u8 *)((u8 *)arg0 + 0x5E) = func_80012F74(*(u8 *)((u8 *)arg0 + 0x5E), 0, 10, 1);
    if (*(s32 *)((u8 *)arg0 + 0x58) == 0 && *(s32 *)((u8 *)arg0 + 0x5C) == 0) {
        func_80146CA0(arg0);
    }
    w = *(u16 *)((u8 *)arg0 + 0x18) + 0x2D;
    *(u16 *)((u8 *)arg0 + 0x18) = w;
    func_800CB8C4(arg0, pad);
    func_800CB900(arg0, pad, (u8 *)arg0 + 0x10, (u8 *)arg0 + 0x14,
                  (u8 *)arg0 + 0x58, (u8 *)arg0 + 0x5C, (u8 *)arg0 + 0x18);
}
