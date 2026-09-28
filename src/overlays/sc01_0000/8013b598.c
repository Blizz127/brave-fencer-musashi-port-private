/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013B598 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 f0; u16 f4; u16 f6; u16 f8; u16 fA; s32 fC; u8 pad[0xC]; } Spr_8013B598_8013B598;
typedef struct { u16 f0; u16 f2; u16 f4; } Src_8013B598_8013B598;
extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8013B598(s32 a0, u16 *a1) {
    extern Spr_8013B598_8013B598 D_801A57C0[];

    D_801A57C0[a0].f0 = 1;
    D_801A57C0[a0].f4 = ((Src_8013B598_8013B598 *)a1)->f0;
    D_801A57C0[a0].f6 = ((Src_8013B598_8013B598 *)a1)->f2;
    D_801A57C0[a0].f8 = ((Src_8013B598_8013B598 *)a1)->f4;
    D_801A57C0[a0].fC = 0x100;
}
