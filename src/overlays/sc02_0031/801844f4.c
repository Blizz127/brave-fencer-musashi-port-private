/* Complete SC02 retail span [801844F4,80184640).
 * After 843F0; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801844F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80029178(s32 arg);
extern void func_80029124(s32 a0, s32 a1);
extern void func_80178CBC(s32 arg0, s32 arg1);

void func_801844F4(void *a0) {

    extern s32 D_801AB06C;
    extern s32 D_801AB058;
    extern s32 D_801AB054;
    extern s32 D_801AB0EC;
    extern s32 D_801AB080;
    extern s32 D_801AAF4C[];
    extern s32 D_801AAFD0[];
    s32 *s0;
    s32 *p;
    u16 v0;

    s0 = *(s32 **)((char *)a0 + 0xDC);
    v0 = *(u16 *)((char *)s0 + 0x8);

    if (!(v0 & 0x8000)) {
        v0 = (func_80029178(0x1D)) & 0xFF;

        if (v0 != 0) {
            u16 flags2;
            D_801AB06C = *(s32 *)((char *)s0 + 0x4);
            flags2 = *(u16 *)((char *)s0 + 0x8);

            if (!(flags2 & 0x4000)) {
                v0 = *(u16 *)((char *)s0 + 0xC);
                D_801AB054 = 0;
                D_801AB058 = D_801AAFD0[v0];
            } else {
                D_801AB058 = 0;
                v0 = *(u16 *)((char *)s0 + 0xC);
                func_80029124(D_801AAFD0[v0], 1);
                D_801AB054 = 2;
            }
        } else {
            D_801AB06C = *(s32 *)((char *)s0 + 0x0);
            v0 = *(u16 *)((char *)s0 + 0xC);
            D_801AB054 = 0;
            D_801AB058 = D_801AAF4C[v0];
        }

        func_80178CBC((s32)a0, (s32)&D_801AB080);
    } else {
        p = &D_801AB0EC;
        *p = *(s32 *)((char *)s0 + 0x0);
        func_80178CBC((s32)a0, (s32)(p - 7));
    }

    *(u16 *)(a0 + 0x2) = 4;
    *(u16 *)(a0 + 0x70) |= 0x8000;
}
