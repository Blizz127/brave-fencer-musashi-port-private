/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013B7AC - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 f0; u8 pad[0x18]; } E_3B7AC_8013B7AC;
extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8013B7AC(int a0) {
    extern E_3B7AC_8013B7AC D_801A57C0[];
 D_801A57C0[a0].f0 = 0; }
