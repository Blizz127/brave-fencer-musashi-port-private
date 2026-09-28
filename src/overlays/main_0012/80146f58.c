/* Overlay range [80146F58,80146FC4) from MAIN.CD member 0012.
 * SHA256(span)=651d802d8df86aedc6ff0f05cddf4b3562889bd5f54d1d498110d76ab957cec3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80146F58 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
struct vec;
struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
typedef struct { s16 vx, vy, vz, pad; } Svec_801372B0;
extern s16 func_8012A68C(void);
extern s16 func_8012A758(void);
extern void func_8004978C(s16 *a0, void *a1);
extern void ApplyMatrixSV(void *m, Svec_801372B0 *in, Svec_801372B0 *out);
extern void ApplyMatrixSV(void*, Svec_801372B0*, Svec_801372B0*);

void func_80146F58(s32 a0, s32 a1) {
    s16 vec[3];
    u8 mat[0x20];
    vec[0] = func_8012A68C();
    vec[1] = func_8012A758();
    vec[2] = 0;
    func_8004978C(vec, mat);
    ((void (*)(void *, void *, void *))ApplyMatrixSV)(mat, (void *)a0, (void *)a1);
}
