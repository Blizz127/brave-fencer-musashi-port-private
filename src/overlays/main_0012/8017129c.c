/* Overlay range [8017129C,80171384) from MAIN.CD member 0012.
 * SHA256(span)=bad3e3f04e71314c6a9e1b5d336999c4036e542334f8fd7d79bdd257cf501883.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017129C - byte-exact against retail at -O2 (tools/register_match.py). */
struct B16;
struct B16 { s32 w[4]; };
typedef struct { s32 a, b, c, d; } S16;
extern void func_801719A4(int a0, int a1);
extern void *D_8011F738;
extern s32 func_80171990(u8 *a0);
extern struct B16 D_800A5E88;
extern struct B16 D_800A5E98;
extern struct B16 D_800A5EA8;
extern void func_801719A4(int, int);
extern s32 func_80171990(u8*);
extern void func_80171384(void*);

void func_8017129C(int param_1) {
    S16 *p;
    func_801719A4(param_1, 1);
    p = (*(S16 * *)&D_8011F738);
    p[0] = (*(S16 *)&D_800A5E88);
    p[1] = (*(S16 *)&D_800A5E98);
    p[2] = (*(S16 *)&D_800A5EA8);
    *(unsigned short *)(*(int *)(param_1 + 0x20) + 0x2C) |= 0x20;
    *(int *)(*(int *)(param_1 + 0x20) + 0x80) = (int)p;
    ((void (*)(int))func_80171990)(param_1);
    ((void (*)(int))func_80171384)(param_1);
}
