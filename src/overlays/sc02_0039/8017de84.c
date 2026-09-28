/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017DE84 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8001C810(s32 a0, s32 a1);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C2C4(s32 a0);
extern void func_8001C1E4(s32 a0, s32 a1);
extern s32 func_8012AD50(void *arg0);
extern u8 D_8019CDBC[];
extern u8 D_8019D81C[];
extern u8 D_8019B57C[];

void func_8017DE84(void *a0)
{
    register void *s0 __asm__("$16") = a0;
    s32 v0 = ((s32 (*)(void))func_8012C1B8)();

    *(s32 *)((u8 *)s0 + 0x20) = v0;

    if (!v0) {
        func_8012CAE4(s0);
    } else {
        s32 mode = *(u16 *)((u8 *)s0 + 0x70) & 3;
        s32 v1;
        s32 e;
        s32 argmode;
        s32 callarg0;

        *(s16 *)((u8 *)s0 + 0xFE) = mode;
        v1 = mode;
        __asm__("" : "=r"(v1) : "0"(v1));

        if (v1 == 1)
            goto case1;
        if (v1 >= 2)
            goto check4;
        if (v1 == 0)
            goto case0;
        goto tail;

    check4:
        if (v1 >= 4)
            goto tail;
        goto case23;

    case0:
        func_8001C810(*(s32 *)((u8 *)s0 + 0x20), (s32)D_8019CDBC);
        callarg0 = 0x199;
        e = *(s32 *)((u8 *)s0 + 0x20);
        __asm__("" : "=r"(e) : "0"(e));
        argmode = 2;
        goto shared;

    case1:
        func_8001C810(*(s32 *)((u8 *)s0 + 0x20), (s32)D_8019D81C);
        callarg0 = 0x199;
        e = *(s32 *)((u8 *)s0 + 0x20);
        __asm__("" : "=r"(e) : "0"(e));
        argmode = 3;

    shared:
        {
            s32 t = *(s32 *)(e + 4);
            t |= 0x8040;
            *(s32 *)(e + 4) = t;
            func_8012C658(callarg0, argmode, (s32)s0);
        }
        goto tail;

    case23:
        func_8001C2C4(*(s32 *)((u8 *)s0 + 0x20));
        v0 = *(s32 *)((u8 *)s0 + 0x64);
        func_8001C1E4(*(s32 *)((u8 *)s0 + 0x20), *(s32 *)(v0 + 0x20));
        *(s16 *)((u8 *)s0 + 0xA) = 0x90;
        *(s32 *)((u8 *)s0 + 0x58) = (s32)D_8019B57C | 0x40000000;
        *(s16 *)((u8 *)s0 + 0x5C) = 0x4400;
        *(s16 *)((u8 *)s0 + 0x6) = 0;
        *(s16 *)((u8 *)s0 + 0xE) = 0;
        *(u8 *)((u8 *)s0 + 0x75) = 4;

    tail:
        v0 = *(u16 *)((u8 *)s0 + 0x70) & 0xFF0;
        *(s16 *)((u8 *)s0 + 0x100) = v0;
        e = *(s32 *)((u8 *)s0 + 0x20);
        v0 = *(s32 *)(e + 4) | 0x8000;
        *(s32 *)(e + 4) = v0;
        func_8012AD50(s0);
    }
}
