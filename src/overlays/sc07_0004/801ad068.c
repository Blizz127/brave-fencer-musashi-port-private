/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AD068 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012BEE8(s32 a0);
extern void func_80016714(void *a0, s32 a1);
extern void func_8012C218(void *a0);
extern void func_80016450(s32 a0, s32 a1);
extern void func_801ADE1C(void *a0, u16 *a1, s8 *a2, u8 *a3);
extern void func_801AD220();
extern u8 D_801B07F0[];
extern u8 D_801F8A98[];
extern u8 D_801F8AB8[];
extern u8 D_801F8AE8[];
extern s32 D_801F8D18;
extern s32 D_801F8D58;
typedef struct { s32 v; } __attribute__((packed, aligned(1))) Align1W_801AD068;
typedef struct {
    u8 pad[0xE0];
    s32 dE0;  /* 0xE0 */
    s32 dE4;  /* 0xE4 */
} Obj_801AD068;

void func_801AD068(void *arg0) {
    if (func_8012BEE8((s32)arg0) != 0) {
        func_80016714(*(void **)((u8 *)arg0 + 0xCC), 0x38);
        func_80016714(*(void **)((u8 *)arg0 + 0xD0), 0x38);
        func_8012C218(arg0);
    } else {
        /* target keeps this guard value in $v1; unpinned it lands in $a0 (5 mismatches) */
        register s32 v1 __asm__("$3") = *(s32 *)((u8 *)arg0 + 0x1C);
        s32 t;      /* address-taken => lives in 0x10($sp); every assignment is a real store */
        s32 *p;

        if (v1 < 15) {
            s32 v0;

            /* arms textually swapped vs. the natural reading so gcc emits the real
               `j .L801AD0D8` + delay slot instead of a delay-slot-fused shortcut */
            if (v1 >= 12) {
                v0 = 0xF - v1;
                v0 = v0 << 5;
            } else {
                v0 = v1 << 3;
            }
            func_80016450(v0 & 0xF8, 1);
        }

        *(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x20) + 0x18) += 0x1C0;
        *(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x20) + 0x1C) =
            *(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x20) + 0x18);
        *(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x20) + 0x1A) += 0x80;
        *(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x20) + 0x12) += 0x100;

        func_801ADE1C(D_801B07F0, (u16 *)D_801F8A98, (s8 *)D_801F8AB8, (u8 *)D_801F8AE8);

        /* the two func_8005CF38-backs are ASYMMETRIC IN THE TARGET and the asymmetry is spelled here:
           D_801F8D18 is reached through a NAMED POINTER LOCAL, so its address is materialised
           (lui+addiu $a0) before the func_8005CF28 and the func_8005CF28 folds onto it (`lw 0($a0)`), sharing one
           base with the swl/swr. D_801F8D58 is named bare, so the func_8005CF28 %lo-folds
           (`lw %lo(D_801F8D58)($v0)`) and the store re-materialises its own base ($a1). */
        p = &D_801F8D18;
        t = *p;
        t -= ((Obj_801AD068 *)arg0)->dE0;
        *(Align1W_801AD068 *)p = *(Align1W_801AD068 *)&t;
        func_801AD220(arg0, *(void **)((u8 *)arg0 + 0xCC));

        t = D_801F8D58;
        t -= ((Obj_801AD068 *)arg0)->dE4;
        *(Align1W_801AD068 *)&D_801F8D58 = *(Align1W_801AD068 *)&t;
        func_801AD220(arg0, *(void **)((u8 *)arg0 + 0xD0));
    }
}
