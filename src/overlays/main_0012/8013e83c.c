/* Overlay range [8013E83C,8013E958) from MAIN.CD member 0012.
 * SHA256(span)=642a0e75ff95f63101709af4d2eecd3f2bf4018492c43c5bef4c26396925c4ce.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013E83C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_80029178(s32 arg);
extern u16 D_80115110;

void func_8013E83C() {

    extern u16 D_80115110;
    extern u16 D_8011511A;
    extern int func_80029178(int);
    extern void func_8002D4C8(int, int);
    extern void func_80141C0C(int);
    extern unsigned short D_80115118;
    extern unsigned short D_80115128;
    extern unsigned short D_8011512E;
    extern unsigned int D_80115130;
    extern unsigned short D_80115158;
    extern unsigned short D_8011515A;
    extern unsigned short D_8011515C;
    extern unsigned short D_8011515E;
    extern unsigned short D_80115162;
    extern unsigned short D_80115166;
    extern void * D_801841F8;
    extern void * D_801841FC;
    extern unsigned char D_8017F398;
    extern unsigned char D_8017F3B0;
    extern unsigned char D_8017F424;
    extern unsigned char D_8017F42C;

    D_80115118 = 0;
    D_80115130 = 0;
    if (D_8011511A >= 4) {
        D_8011511A = D_8011511A - 3;
    }
    D_80115158 = 0x106;

    if ((func_80029178(0x1c) & 0xFF) == 0) {
        D_801841F8 = &D_8017F398;
        D_801841FC = &D_8017F424;
    } else {
        D_801841F8 = &D_8017F3B0;
        D_801841FC = &D_8017F42C;
    }

    D_8011515A = 0x104;
    D_8011515C = 0x104;
    D_8011515E = 0x129;
    D_80115162 = 0x103;
    D_80115166 = 0x105;
    D_80115128 = 0;
    D_8011512E = 0;

    if (D_80115110 == 3) {
        func_8002D4C8(0x46e, 0);
    } else {
        func_80141C0C(0);
    }
}
