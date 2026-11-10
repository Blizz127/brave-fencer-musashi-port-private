/* Overlay range [8016380C,801638A0) from MAIN.CD member 0012.
 * SHA256(span)=0a7d4a7a216997bf7d91dec02ad651041ab42c38888ad03baf3bcbc8e7674348.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016380C - byte-exact against retail at -O2 (tools/register_match.py). */
struct M8;
struct S8016380C;
struct M8 { u8 b[8]; };
struct S8016380C {
    u8 _pad[0x44];
    struct M8 m;
};
typedef struct { char _b[8]; } M8;
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015954(s32 a0, s32 a1);
extern s32 func_80133784(s32 arg0, void *arg1, s32 arg2);
extern void func_80015978(s32, s32*);
extern void func_80015978(int a0, int *a1);
extern int func_80133784(int a0, void *a1, int a2);
extern s32 func_80133784(s32 a0, void *src, s32 dst);
extern void func_80015954(s32, s32);
u16 a2;

s32 func_8016380C(struct S8016380C *a0, s32 a1) {
    struct M8 local;
    s32 ret;
    local = a0->m;
    func_80015978((s32)((u8 *)a0 + 4), (s32 *)a1);
    ret = func_80133784(1, &local, a1);
    if (ret != 0) {
        func_80015954(a1, (s32)((u8 *)a0 + 4));
        return ret;
    }
    return 0;
}
