/* Exact retail overlay 0010 export [800CF990,800CFAD0), offset 0x20B98. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CF990 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    s32 word0;
    s32 word4;
} CdFileLoc;
extern u16 D_800B99F6;
extern s16 D_80114E74;
extern s16 D_800D3408[];
extern CdFileLoc D_800AE830[];
extern s16 D_800B9A00;
extern u16 D_800AF7B8;
extern void func_8001C0C8(void);
extern void func_80015310(void);
extern s32 func_8001ABBC(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4);
extern void func_800167B8(s32 arg0);
extern void func_80011C10(void);
extern void func_800CFAD0(void);
extern u16 func_800167F0(s32 arg0);
extern void func_80011B7C(s32 arg0);

void func_800CF990(void) {
    switch (D_800B99F6) {
    case 0:
        func_8001C0C8();
        func_80015310();
        if (func_8001ABBC(0, 0, (u8 *)&D_800AE830[D_800D3408[D_80114E74]], 0, 0) != 0) {
            func_800167B8(0);
            func_80011C10();
        }
        break;
    case 1:
        func_800CFAD0();
        if (func_800167F0(0) != 0) {
            func_80011C10();
        }
        break;
    case 2: {
        s32 v;
        func_800CFAD0();
        v = *(u16 *)&D_800B9A00 + 1;
        D_800B9A00 = v;
        if ((s16)v >= 0x5B) {
            if (D_800AF7B8 != 0) {
                func_80011B7C(6);
            }
        }
        break;
    }
    }
}
