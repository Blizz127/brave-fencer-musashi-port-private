/* Overlay range [80168BDC,80168D58) from MAIN.CD member 0012.
 * SHA256(span)=16465872d600a0f874cdc85c1f695309cef91aa754f6d4c4613a46695e9883c1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80168BDC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define ApplyMatrixSV func_80048FBC
#define RotMatrixYXZ func_80049A1C

/* File-scope declarations from the vendor translation unit. */
typedef struct { s16 vx, vy, vz, pad; } Svec_801372B0;

extern void func_800D2318(void);
extern void RotMatrixYXZ(void *a0, void *a1);
extern void ApplyMatrixSV(void*, Svec_801372B0*, Svec_801372B0*);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
void func_80168BDC(s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    short mtx[16];
    short vec[4];
    int r;
    register int i __asm__("$17");     /* loop counter, survives the call -> $s1 */
    register int tmp __asm__("$2");    /* increment temp -> $v0 (the split-IV) */
    func_800D2318();
    vec[0] = *(short *)(param_1 + 0x12);
    vec[1] = *(short *)(param_1 + 0x16);
    vec[2] = 0;
    RotMatrixYXZ(vec, mtx);
    vec[0] = 0;
    if (*(int *)(param_1 + 0x2c) < 0) {
        vec[2] = -8;
        vec[1] = -4;
    } else {
        vec[2] = 2;
        vec[1] = -2;
    }
    ((void (*)(void *, void *, void *))ApplyMatrixSV)(mtx, vec, vec);
    *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + vec[0];
    *(short *)(param_1 + 0xa) = *(short *)(param_1 + 0xa) + vec[1];
    *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + vec[2];
    i = 0;
    if ((short)param_4 > 0) {
        do {
            r = func_80146A6C((unsigned short)param_2, (void *)param_1,
                              (short)*(short *)(param_1 + 6),
                              (short)*(short *)(param_1 + 0xa),
                              (short)*(short *)(param_1 + 0xe),
                              (short)param_3, 0);
            if (r != 0) {
                *(short *)(r + 0x12) = *(short *)(param_1 + 0x12);
                *(short *)(r + 0x16) = *(short *)(param_1 + 0x16);
                *(short *)(r + 0x1a) = *(short *)(param_1 + 0x1a);
            }
            tmp = i + 1;
            i = tmp;
            __asm__ __volatile__("" : "=r"(i) : "0"(i));
        } while ((short)tmp < (short)param_4);
    }
}
