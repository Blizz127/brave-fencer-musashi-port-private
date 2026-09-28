/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AA7E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 vx, vy, vz, pad; } SV_801AA7E4;
typedef struct { s16 m[3][3]; s32 t[3]; } MTX_801AA7E4;
extern void func_8004914C(void *a0);
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_8004978C(s16 *a0, void *a1);
extern void func_8004864C(void *a0, void *a1);
extern void func_80048B6C(void *a0, void *a1);

void func_801AA7E4(u8 *s2)
{
    MTX_801AA7E4 mtx;   /* sp+0x10 */
    SV_801AA7E4 rot;    /* sp+0x30 */
    s32 vec[3];         /* sp+0x38 */

    if (*(s16 *)(s2 + 0x32) == 0) {
        rot.vx = *(u16 *)(*(s32 *)(s2 + 0x20) + 0x10);
        rot.vy = *(u16 *)(*(s32 *)(s2 + 0x20) + 0x12);
        rot.vz = 0;
        func_80049CAC((s32)&rot, (s32)&mtx);

        func_8004914C(&mtx);
        vec[1] = 0;
        vec[0] = 0;
        vec[2] = 0xFFE60000;
        func_80048B6C(&vec, (void *)(s2 + 0x10));

        rot.vz = 0;
        rot.vx = 0;
        rot.vy = 3;
        func_8004864C(&rot, &vec);
    } else {
        func_8004978C((s16 *)(*(s32 *)(s2 + 0x20) + 0x10), &mtx);

        func_8004914C(&mtx);
        vec[0] = 0x480000;
        vec[2] = 0;
        vec[1] = 0;
        func_80048B6C(&vec, (void *)(s2 + 0x10));

        rot.vy = 0;
        rot.vx = 0;
        rot.vz = 8;
        func_8004864C(&rot, &vec);
    }

    *(s16 *)(*(s32 *)(s2 + 0x20) + 0x2E) = vec[0];
    *(s16 *)(*(s32 *)(s2 + 0x20) + 0x30) = vec[1];
    *(s16 *)(*(s32 *)(s2 + 0x20) + 0x32) = vec[2];
}
