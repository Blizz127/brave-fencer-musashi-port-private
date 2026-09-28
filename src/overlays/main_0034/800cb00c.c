/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB00C - byte-exact against retail at -O2 (tools/register_match.py). */
typedef void (*Fn7_800CB00C)(void *, void *, void *, void *, s32, s32, s32);

void func_800CB00C(s32 arg0, s32 arg1, s32 arg2)
{
     






    extern void func_800CB1F8();
    extern void func_800CB3C0();
    extern void func_800CBA18();
    extern void func_800CB5D0();
    extern void func_800CB7BC();
    extern void func_800CBC2C();
    extern void func_800CBE28();

    s32 v0;
    s32 a3;
    s32 s3;
    s32 s2;
    s32 s1;
    u32 s6;
    u32 code;
    s32 s0;

    v0 = *(s32 *)(arg0 + 8);
    a3 = *(s32 *)(arg0 + 0xC);
    s3 = *(s32 *)v0;
    s2 = *(s32 *)(v0 + 8);
    s1 = *(s32 *)(v0 + 0x10);

    do {
        s6 = *(u32 *)a3;
        s0 = *(s32 *)(a3 + 4);
        a3 += 8;
        code = s6 >> 24;
        switch ((code & 0xFC) - 0x20) {
        case 0:
            ((Fn7_800CB00C)func_800CB1F8)((void *)s1, (void *)s3, (void *)s2,
                                          (void *)a3, s0, arg2,
                                          *(s32 *)(arg1 + 4));
            s1 += s0 << 4;
            break;
        case 8:
            ((Fn7_800CB00C)func_800CB3C0)((void *)s1, (void *)s3, (void *)s2,
                                          (void *)a3, s0, arg2,
                                          *(s32 *)(arg1 + 4));
            s1 += (s0 * 5) << 2;
            break;
        case 12:
            ((Fn7_800CB00C)func_800CBA18)((void *)s1, (void *)s3, (void *)s2,
                                          (void *)a3, s0, arg2,
                                          *(s32 *)(arg1 + 4));
            s1 += s0 << 5;
            break;
        case 16:
            ((Fn7_800CB00C)func_800CB5D0)((void *)s1, (void *)s3, (void *)s2,
                                          (void *)a3, s0, arg2,
                                          *(s32 *)(arg1 + 4));
            s1 += (s0 * 5) << 2;
            break;
        case 24:
            ((Fn7_800CB00C)func_800CB7BC)((void *)s1, (void *)s3, (void *)s2,
                                          (void *)a3, s0, arg2,
                                          *(s32 *)(arg1 + 4));
            s1 += (s0 * 3) << 3;
            break;
        case 20:
            ((Fn7_800CB00C)func_800CBC2C)((void *)s1, (void *)s3, (void *)s2,
                                          (void *)a3, s0, arg2,
                                          *(s32 *)(arg1 + 4));
            s1 += (s0 * 7) << 2;
            break;
        case 28:
            ((Fn7_800CB00C)func_800CBE28)((void *)s1, (void *)s3, (void *)s2,
                                          (void *)a3, s0, arg2,
                                          *(s32 *)(arg1 + 4));
            s1 += (s0 * 9) << 2;
            break;
        }
        a3 = (s6 & 0xFFFFFF) | (s32)0x80000000;
    } while ((s6 & 0xFFFFFF) != 0);
}
