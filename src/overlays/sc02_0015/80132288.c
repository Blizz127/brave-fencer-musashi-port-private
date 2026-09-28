/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
#define memcpy func_8005C324
/* func_80132288 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8005C324(int dst, int src, int n) __asm__("func_8005C324");
extern void func_801325B8(int a0, int a1, int a2, int a3, int a4);

void func_80132288(int *param_1, int *param_2, int param_3) {
    int src; int dst;
    param_1[0] = (int)param_2;
    *(short *)((int)param_1 + 4) = 0;
    *(short *)((int)param_1 + 6) = 0;
    param_1[2] = param_3;
    {
        register char *node __asm__("$6") = (char *)*(int *)param_2[0];
        if (*(int *)(node + 4) == 1) src = *(int *)(node + 0xC);
        else src = (int)(node + ((*(unsigned int *)(node + 0xC) >> 2 << 2) + 0xC));
    }
    {
        char *p3 = (char *)param_3;
        if (*(int *)(p3 + 4) == 1) dst = *(int *)(p3 + 0xC);
        else dst = (int)(p3 + ((*(unsigned int *)(p3 + 0xC) >> 2 << 2) + 0xC));
        func_8005C324(dst, src, *(int *)(p3 + 0x10) << 3);
    }
    {
        register int *pn __asm__("$3") = (int *)param_2[0];
        if (pn[2] != 0) {
            {
                register char *node __asm__("$6") = (char *)pn[0];
                if (*(int *)(node + 4) == 1) src = *(int *)(node + 0x14);
                else src = (int)(node + ((*(unsigned int *)(node + 0x14) >> 2 << 2) + 0xC));
            }
            {
                char *p3 = (char *)param_3;
                if (*(int *)(p3 + 4) == 1) dst = *(int *)(p3 + 0x14);
                else dst = (int)(p3 + ((*(unsigned int *)(p3 + 0x14) >> 2 << 2) + 0xC));
                func_8005C324(dst, src, *(int *)(p3 + 0x18) << 3);
            }
        }
    }
    if (*(short *)((int)param_2 + 6) < 0) {
        int *node = (int *)param_2[0];
        func_801325B8(param_3, node[0], node[1], node[2], 0x1000);
    }
}
