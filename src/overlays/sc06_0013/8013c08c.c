/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013C08C - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
        u8   pad0[8];
        void *f8;
        void *fC;
    } E_13C08C_8013C08C;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8013C0F8(s32 a0);

void func_8013C08C(void *a0, void *a1) {
    void *p = a1;
    ((E_13C08C_8013C08C *)a0)->f8 = a1;
    ((E_13C08C_8013C08C *)a0)->fC = (u8 *)p + 0x14;
    func_8013C0F8((s32)a1);
}
