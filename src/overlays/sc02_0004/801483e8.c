/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801483E8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015978(s32, s32*);
extern void func_80015978(int a0, int *a1);
extern int func_80133784(int a0, void *a1, int a2);

void func_801483E8(unsigned char *self) {
    unsigned short src[4];
    short dst[4];
    int ret;
    func_80015978((int)(self + 4), (int *)src);
    dst[0] = src[0];
    dst[1] = src[1] + 8;
    dst[2] = src[2];
    ret = func_80133784(1, src, (int)dst);
    if (ret == 0x2000 &&
        *(short *)(self + 6) == dst[0] &&
        *(short *)(self + 0xA) == dst[1] &&
        *(short *)(self + 0xE) == dst[2] &&
        *(unsigned char *)&dst[3] == 0) {
        func_80015978((int)(self + 4), (int *)(self + 0xA0));
    }
}
