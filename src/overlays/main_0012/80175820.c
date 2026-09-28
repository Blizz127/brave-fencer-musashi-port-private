/* Overlay range [80175820,801758FC) from MAIN.CD member 0012.
 * SHA256(span)=2d02b089db6e55f32be9d0a8f32715183a9ac06a16067d0d455c64cfe1a709a4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80175820 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { u32 *f0; s32 pad[4]; } S_AE7BC_80175820_80175820;
typedef struct { s32 g0; s32 pad[2]; } S_AF634_80175820_80175820;
extern s16 D_800B9A02;
extern short D_800B9A02;
extern s32 (*D_801819EC[])(void *);
extern u8  D_8011F7A8;
extern u8 D_8011F7A8;

s32 func_80175820(void)
{
    extern s16 D_800B9A02;
    extern S_AE7BC_80175820_80175820 D_800AE7BC[];
    extern S_AF634_80175820_80175820 D_800AF634[];
    extern u8 D_8011F7A8;
    u8 *p = (u8 *)&D_8011F7A8;
    u16 *q;
    u32 *ptr;
    u32 old;
    u32 *p2;
    q = (u16 *)&(*(u16 *)&D_800B9A02);
    ptr = D_800AE7BC[*q].f0;
    old = ptr[2];
    ptr[2] = (old & 0xff000000) | (*(u32 *)(p + *q * 4 + 0x20) & 0xffffff);
    __asm__("" ::: "memory");
    p2 = *(u32 **)(p + *q * 4 + 0x18);
    *p2 = (*p2 & 0xff000000) | (old & 0xffffff);
    __asm__("" ::: "memory");
    {
        s32 acc = D_800AF634[*q].g0;
        s32 t = *(s32 *)(p + *q * 4 + 0x18) - 0x14;
        D_800AF634[*q].g0 = acc + ((*(s32 *)(p + *q * 4 + 0x20) - t) >> 2);
    }
}
