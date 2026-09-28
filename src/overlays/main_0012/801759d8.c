/* Overlay range [801759D8,80175AB8) from MAIN.CD member 0012.
 * SHA256(span)=7faf63be181e30fe9648330727a88b01aac9f6a93d0e09f9302e583c9e638568.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801759D8 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { u32 *f0; s32 pad[4]; } S_AE7BC_801759D8;
typedef struct { s32 g0; s32 pad[2]; } S_AF634_801759D8;
extern s16 D_800B9A02;
extern short D_800B9A02;
extern s32 (*D_801819EC[])(void *);
extern u8  D_8011F7A8;
extern u8 D_8011F7A8;

s32 func_801759D8(void)
{
    extern u8 D_8011F7B1;
    extern s16 D_800B9A02;
    extern S_AE7BC_801759D8 D_800AE7BC[];
    extern S_AF634_801759D8 D_800AF634[];
    extern u8 D_8011F7A8;
    u8 *p = (u8 *)&D_8011F7A8;
    u16 *q;
    u32 *ptr;
    u32 old;
    u32 *p2;
    if (D_8011F7B1 != 0) {
        return;
    }
    q = (u16 *)&(*(u16 *)&D_800B9A02);
    ptr = D_800AE7BC[*q].f0;
    old = ptr[1];
    ptr[1] = (old & 0xff000000) | (*(u32 *)(p + *q * 4 + 0x40) & 0xffffff);
    __asm__("" ::: "memory");
    p2 = *(u32 **)(p + *q * 4 + 0x38);
    *p2 = (*p2 & 0xff000000) | (old & 0xffffff);
    __asm__("" ::: "memory");
    {
        s32 acc = D_800AF634[*q].g0;
        s32 t = *(s32 *)(p + *q * 4 + 0x38) - 0x14;
        D_800AF634[*q].g0 = acc + ((*(s32 *)(p + *q * 4 + 0x40) - t) >> 2);
    }
}
