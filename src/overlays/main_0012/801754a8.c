/* Overlay range [801754A8,8017553C) from MAIN.CD member 0012.
 * SHA256(span)=cfd1eb9638e26b320ed3d8fa58c0b71d3e6411be4dc290b250ad72d54afb9a22.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801754A8 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef void (*DispatchFn)(void *);
extern s32 func_80029504(void);
extern unsigned char D_800B9A13;
extern s32 D_80126B9C;
extern s32 (*D_801819EC[])(void *);
extern u8  D_8011F7A8;
extern u8 D_8011F7A8;

void func_801754A8(void) {

    extern u8 D_8011F7A8;
    extern unsigned char D_800B9A13;
    extern s32 D_80126B9C;
    extern DispatchFn D_80181B6C[];
    u8 *p = &D_8011F7A8;
    s32 r = func_80029504();
    s32 flag = 0;

    if (((D_800B9A13 == 0) && ((D_80126B9C & 0x80) == 0)) ||
        (0x4AF < (u32)(r - 10))) {
        flag = 1;
    }
    p[9] = flag;
    D_80181B6C[p[0]]((void *)p);
}
