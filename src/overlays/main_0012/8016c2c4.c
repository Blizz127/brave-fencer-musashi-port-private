/* Overlay range [8016C2C4,8016C374) from MAIN.CD member 0012.
 * SHA256(span)=abf92bad51f64de026212d584ae769bf6b0819723c1e0f1e966102cd743a06e1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016C2C4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015954(s32 a0, s32 a1);
extern void func_80146C3C(u8 *a0);
extern void func_80149350(s32 arg0, s32 a1, s32 a2);
extern void func_80015954(s32, s32);
extern void func_80146C3C();
extern void func_80146C3C(u8*);
extern void func_80149350(s32 arg0, s32 a1, s32 a2);
extern s32 func_8016C374(s32 a0, s32 a1, s32 a2, s32 a3);

void func_8016C2C4(s32 param)
{

    extern u8 D_801847FC[];
    extern u8 D_80184804[];
    extern u8 D_801847B4[];
    register s32 s1 __asm__("$17");
    register s32 s0 __asm__("$16");
    u16 buf[3];
    s16 v;
    s32 r;
    s32 arg;

    s1 = param;
    s0 = *(s32 *)(s1 + 0x20);
    arg = *(s32 *)(s1 + 0x34);
    buf[0] = *(u16 *)(s1 + 0x12);
    buf[1] = *(u16 *)(s1 + 0x16);
    buf[2] = *(u16 *)(s1 + 0x1a);
    ((void (*)(s32, void *, void *))func_80149350)(arg, buf, buf);
    ((void (*)(void *, s32))func_80015954)(buf, s1 + 4);
    v = *(s16 *)(s1 + 0x10) + 0x10;
    *(s16 *)(s1 + 0x10) = v;
    v = *(s16 *)(s0 + 0x1a) + v;
    *(s16 *)(s0 + 0x1a) = v;
    *(s16 *)(s0 + 0x18) = v;
    r = ((s32 (*)(s32, void *, void *, void *))func_8016C374)(s1, D_801847FC, D_80184804, D_801847B4);
    if (r == 0) {
        ((void (*)(s32))func_80146C3C)(s1);
    }
}
