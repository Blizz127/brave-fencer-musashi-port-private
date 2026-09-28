/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD404 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8013C9C4(void *a0);

void func_800CD404(void *a0) {
    extern void func_80146578(void);
    extern void func_8001CD50(s32 a0, s32 a1);
    extern void func_80146E90(s32 *a0, s32 a1);
    extern void func_80146CA0(void *);
    extern void func_800CD670(s32 a0, void *a1);
    extern void func_800CD650(void);
    extern void func_800CD6D4(void);
    extern s32 D_800D3428;
    extern u8 D_800CD764[];
    extern u8 D_800CD964[];

    typedef struct {
        s32 w[8];
    } Block32;

    register s32 s0 __asm__("$16");
    register s32 s1 __asm__("$17");
    register s32 s2 __asm__("$18");
    register s32 s3 __asm__("$19");

    s32 v;

    s1 = (s32)a0;
    s2 = *(s32 *)(s1 + 0x4C);
    {
        register s32 base __asm__("$3");
        register s32 val __asm__("$2");
        base = (s32)&D_800CD764;
        val = *(s32 *)(s1 + 0x50) << 6;
        s3 = val + base;
    }
    func_8013C9C4(&D_800D3428);
    s0 = (s32)((void *(*)(void))func_80146578)();
    *(s32 *)(s1 + 0x20) = s0;

    if (s0 != 0) {
        func_8001CD50(s0, s3);
        *(u16 *)(s0 + 0x1E) = 0xCCC;
        *(s32 *)(s0 + 4) |= 0x50000000;
        *(u16 *)(s0 + 0x18) = 0;
        *(u16 *)(s0 + 0x1A) = 0;
        {
            register s32 dstp __asm__("$3");
            register s32 srcp __asm__("$2");
            dstp = (*(s32 *)(s1 + 0x50) << 5) + (s32)&D_800CD964;
            *(s32 *)(s0 + 0x34) = dstp;
            srcp = *(s32 *)(*(s32 *)(s1 + 0x4C) + 0x20);
            srcp = *(s32 *)(srcp + 0x34);
            *(Block32 *)dstp = *(Block32 *)srcp;
        }
        *(u16 *)(s1 + 6) = *(u16 *)(s2 + 6);
        v = *(u16 *)(s2 + 0xA);
        *(u16 *)(s1 + 0xA) = v;
        *(u16 *)(s1 + 0x60) = v;
        *(u16 *)(s1 + 0xE) = *(u16 *)(s2 + 0xE);
        *(u16 *)(s1 + 0x62) = *(s32 *)(s2 + 0x1C);
        func_80146E90((s32 *)s1, 0x20);
        func_800CD670(s1, (void *)s3);
        ((void (*)(void *, void *))func_800CD6D4)((void *)s1, (void *)s3);
        func_80146CA0((void *)s1);
    } else {
        ((void (*)(void *))func_800CD650)((void *)s1);
    }
}
