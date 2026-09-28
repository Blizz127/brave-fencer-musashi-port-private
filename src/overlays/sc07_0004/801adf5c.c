/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ADF5C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801298F4(void *arg0);
extern void func_8012AD50(void *a0);
extern void func_80059A1C(s32, void *);
extern s32 D_801F76B0;
extern s32 D_801F74A8;
extern u8 D_801F8B18;
extern void *D_800B9AC4;
extern void *D_800B9AC8;
extern s32 D_800B9A88;
extern s16 D_800B9A90;
extern s16 D_800B9A92;
extern s16 D_800B9AA0;
extern s16 D_800B9AA2;
extern s16 D_800B9AA4;
extern s16 D_800B9AA6;
extern s16 D_800B9AAE;
extern s16 D_800B9AB4;
extern s16 D_800B9AB6;
extern s16 D_800B9AB8;
extern s16 D_800B9ABA;

void func_801ADF5C(void *a0)
{
    void *s0;
    struct { s16 x, y, w, h; } rect;

    register void *p __asm__("$3");

    s0 = a0;

    /* D_800B9AC4/D_800B9AC8 are fields of the struct rooted at D_800B9A78
     * (see engine_core.h's Ent_956C / func_8012956C); the func_801298F4
     * call target is that struct's base, computed as p - 0x4C so the
     * compiler reuses the already-materialized D_800B9AC4 address instead
     * of emitting a second relocation. A plain `&D_800B9AC4 - 0x4C`
     * constant-folds at compile time into a FRESH symbolic constant
     * (its own lui/addiu, computed before the stores) instead of runtime
     * register arithmetic, so the address is pinned into a real pseudo
     * with the same zero-byte re-tie idiom func_8012956C uses for its
     * `base` pointer. */
    p = &D_800B9AC4;
    __asm__("" : "=r"(p) : "0"(p));
    *(void **)p = &D_801F76B0;
    D_800B9AC8 = &D_801F74A8;
    __asm__ __volatile__("");
    func_801298F4((void *)((u8 *)p - 0x4C));

    {
        register s32 mask __asm__("$7");
        register s16 one __asm__("$6");
        register s32 rv0 __asm__("$2");
        register s32 rv1 __asm__("$3");
        register s32 ra1 __asm__("$5");

        mask = 0xF7FFFFFF;
        __asm__ __volatile__("");
        one = 1;
        __asm__ __volatile__("");
        rv0 = 0x2000;
        __asm__ __volatile__("");
        rv1 = 0x118;
        __asm__ __volatile__("");

        D_800B9AA4 = (s16)rv0;
        D_800B9AA6 = (s16)rv0;

        rv0 = 0x8C;
        __asm__ __volatile__("");

        D_800B9A90 = (s16)rv1;
        D_800B9A92 = (s16)rv1;
        D_800B9AB4 = (s16)rv1;
        D_800B9AB6 = (s16)rv1;

        __asm__ __volatile__("");

        rv1 = D_800B9A88;
        __asm__ __volatile__("");
        ra1 = 0x100;
        __asm__ __volatile__("");

        D_800B9AA0 = (s16)rv0;
        D_800B9AA2 = (s16)rv0;

        rv0 = 0x1E0;
        __asm__ __volatile__("");

        rect.x = (s16)ra1;
        rect.w = (s16)ra1;

        ra1 = (s32)&D_801F8B18;
        __asm__ __volatile__("");

        D_800B9AAE = one;
        D_800B9ABA = 0;
        D_800B9AB8 = 0;

        rect.y = (s16)rv0;
        rect.h = one;

        D_800B9A88 = rv1 & mask;

        func_80059A1C((s32)&rect, (void *)ra1);
    }

    func_8012AD50(s0);
}
