/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AB8C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char c[4]; } Blk4_801A7358;
typedef struct { char c[4]; } Blk4_801AB8C0;
extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_800233CC(void *a0, unsigned short a1);
extern s32 func_8001CA88(s32 a0, void *a1);
extern void func_801A881C(s32 a0);
extern u8 D_801F8978[3];
extern Blk4_801AB8C0 D_801F897C;
extern Blk4_801A7358 D_801A01E8;
extern u8 D_801A0214;

void func_801AB8C0(s32 s1)
{
    s32 a0;
    s32 a1;
    s32 v1;
    u8 *s0;

    if ((*(s32 *)(s1 + 0x20) = func_8012C1B8()) == 0) {
        func_8012CAE4((void *)s1);
        return;
    }

    if (*(s16 *)(s1 + 0x70) == 0) {
        s0 = D_801F8978;
        func_800233CC(s0, 0x30);
        *(Blk4_801AB8C0 *)s0 = *(Blk4_801AB8C0 *)&D_801A0214;
        D_801F897C = (*(Blk4_801AB8C0 *)&D_801A01E8);
    }

    func_8001CA88(*(s32 *)(s1 + 0x20), D_801F8978);

    a0 = s1;
    a1 = *(s32 *)(a0 + 0x20);
    *(s32 *)(a1 + 4) |= 0x50000000;
    v1 = *(s32 *)(a0 + 0x20);
    *(s16 *)(v1 + 0x1A) = 0x200;
    *(s16 *)(v1 + 0x18) = 0x200;
    func_801A881C(a0);
}
