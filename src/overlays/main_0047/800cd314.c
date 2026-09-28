/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD314 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CD314(void *arg0) {
    extern u8 D_8011F75C[];
    extern volatile s32 D_8011F758;
    extern u8 D_800CD7A4;
    extern void func_80147324(s32 a0);
    extern void func_800233CC(void *a0, u16 a1);
    extern void func_80146C3C(void);

    typedef struct { s32 w[8]; } Blk32;

    register s32 s0 __asm__("$16");
    register s32 t __asm__("$2");
    register s32 tb __asm__("$3");
    s32 cnt;
    s32 p;
    s32 idx;

    s0 = (s32)arg0;
    cnt = *(s32 *)(s0 + 0x1C);
    p = *(s32 *)(s0 + 0x20);

    if (cnt < 0x20) {
        if ((cnt & 7) == 0) {
            *(Blk32 *)(s0 + 0x38) = *(Blk32 *)D_8011F75C;
            *(s32 *)(p + 4) = (*(s32 *)(p + 4) & 0x7FFFFFFF) | (*(s32 *)(D_8011F758 + 4) & (s32)0x80000000);
            *(u16 *)(p + 0x18) = *(u16 *)(D_8011F758 + 0x18);
            *(u16 *)(p + 0x1A) = *(u16 *)(D_8011F758 + 0x1A);
            t = *(s32 *)(s0 + 0x4C);
            *(s16 *)(s0 + 6) = t;
            tb = *(s32 *)(s0 + 0x54);
            *(s16 *)(s0 + 0xE) = tb;
            *(s32 *)(s0 + 0x30) = 0;
            t = *(s32 *)(s0 + 0x50);
            *(s16 *)(s0 + 0xA) = t - 8;
            func_80147324(0x8E2);
        }
        idx = *(s32 *)(s0 + 0x30);
        idx += 0x10;
        *(s32 *)(s0 + 0x30) = idx;
        func_800233CC((void *)&D_800CD7A4, idx);
        *(s32 *)(s0 + 0x1C) = *(s32 *)(s0 + 0x1C) + 1;
        return;
    }
    __asm__ __volatile__("" ::: "a0");
    ((void (*)(s32))func_80146C3C)(s0);
}
