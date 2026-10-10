/* Overlay range [8015D380,8015D414) from MAIN.CD member 0012.
 * SHA256(span)=e26a7087f4a56e27a716d05d5154c1081428bbd5e7857a381c11540ee48758ca.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015D380 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
typedef struct { s16 vx, vy, vz, pad; } Svec_801372B0;
extern void *memcpy(void *, const void *, unsigned int);
extern void *memcpy(void *, const void *, u32);
extern void ApplyMatrixSV(void *m, Svec_801372B0 *in, Svec_801372B0 *out);
extern void ApplyMatrixSV(void*, Svec_801372B0*, Svec_801372B0*);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_80013F3C(s32 a0);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800126C4(s32 a0, s32 a1);

void func_8015D380(s32 a0) {

    extern s32 D_801814D4;
    s16 out[4];
    s32 buf[8];
    register s32 s1 __asm__("$17") = a0;
    register s32 *s0 __asm__("$16") = buf;
    ((void (*)(void *))func_80013F3C)((void *)s0);
    ((void (*)(void *, s32))func_80012558)((void *)s0, *(s16 *)(*(s32 *)(s1 + 0x20) + 0x12));
    ((void (*)(void *, s32))func_800126C4)((void *)s0, *(s16 *)(*(s32 *)(s1 + 0x20) + 0x10));
    ((void (*)(void *, void *, void *))ApplyMatrixSV)((void *)s0, (void *)&D_801814D4, (void *)out);
    memcpy((void *)(s1 + 0x138), (void *)out, 8);
}
