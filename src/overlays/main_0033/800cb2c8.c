/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB2C8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB2C8(void *arg0) {
    extern void func_80146CA0(s32 *);
    extern s32 func_80012ABC(s32, s32, s32);
    extern void func_8001382C(s32, void *, void *);
    extern void func_80162FC0(s32 *);

    void *s1;
    register void *p __asm__("$4");
    register s32 raw __asm__("$3");
    register s32 t __asm__("$2");
    s32 r;
    s32 buf[3];

    s1 = *(void **)((u8 *)arg0 + 0x20);
    p = *(void **)((u8 *)arg0 + 0x4C);
    raw = *(u8 *)((u8 *)s1 + 0x24);
    t = raw - 0x10;
    if (t < 0) {
        func_80146CA0((s32 *)arg0);
        return;
    }
    raw = t;
    __asm__("" : "=r"(raw) : "0"(raw));
    t = raw;
    *(u8 *)((u8 *)s1 + 0x24) = *(u8 *)((u8 *)s1 + 0x25) = *(u8 *)((u8 *)s1 + 0x26) = t;
    r = func_80012ABC(*(s16 *)((u8 *)s1 + 0x12),
                      *(s16 *)(*(void **)((u8 *)p + 0x20) + 0x12), 0x10);
    *(s16 *)((u8 *)s1 + 0x12) = r;
    func_8001382C((s16)r, (u8 *)arg0 + 0x24, buf);
    *(s32 *)((u8 *)arg0 + 0x10) = buf[0];
    *(s32 *)((u8 *)arg0 + 0x14) = buf[1];
    *(s32 *)((u8 *)arg0 + 0x18) = buf[2];
    func_80162FC0((s32 *)arg0);
}
