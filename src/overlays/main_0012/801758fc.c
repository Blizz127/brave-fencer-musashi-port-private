/* Overlay range [801758FC,801759D8) from MAIN.CD member 0012.
 * SHA256(span)=d44053038430db6f411e94bdee48e889582ddb028a98560ab513f2e6649c1668.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801758FC - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { u32 *f0; s32 pad[4]; } S_AE7BC_801758FC;
typedef struct { s32 g0; s32 pad[2]; } S_AF634_801758FC;
extern s16 D_800B9A02;
extern short D_800B9A02;
extern s32 (*D_801819EC[])(void *);
extern u8  D_8011F7A8;
extern u8 D_8011F7A8;

s32 func_801758FC(void)
{
    extern s16 D_800B9A02;
    extern S_AE7BC_801758FC D_800AE7BC[];
    extern S_AF634_801758FC D_800AF634[];
    extern u8 D_8011F7A8;
    u8 *p = (u8 *)&D_8011F7A8;
    u16 *q;
    u32 *ptr;
    u32 old;
    u32 *p2;
    q = (u16 *)&(*(u16 *)&D_800B9A02);
    ptr = D_800AE7BC[*q].f0;
    old = ptr[3];
    ptr[3] = (old & 0xff000000) | (*(u32 *)(p + *q * 4 + 0x30) & 0xffffff);
    __asm__("" ::: "memory");
    p2 = *(u32 **)(p + *q * 4 + 0x28);
    *p2 = (*p2 & 0xff000000) | (old & 0xffffff);
    __asm__("" ::: "memory");
    {
        s32 acc = D_800AF634[*q].g0;
        s32 t = *(s32 *)(p + *q * 4 + 0x28) - 0x14;
        D_800AF634[*q].g0 = acc + ((*(s32 *)(p + *q * 4 + 0x30) - t) >> 2);
    }
}
