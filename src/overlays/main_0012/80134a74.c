/* Overlay range [80134A74,80134C20) from MAIN.CD member 0012.
 * SHA256(span)=dc7552ea8c14e044b3d1b3faf4a7a63bcee3d2895170f5ba3d95ad265b050613.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80134A74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

int func_80134A74(int param_1, s16 param_2, s16 param_3, int param_4)
{
    extern u16 D_80184130;
    extern s32 func_80134C20(s32, s32, s32, s32);

    u16 *param_4p = (u16 *)param_4;
    register u32 zr __asm__("$0");
    u32 uVar6, uVar2, uVar2c;
    register u32 uVar6c __asm__("$9");
    u16 *puVar4, *ptmp;
    register u32 n __asm__("$18");
    register u32 p0 __asm__("$4");
    register int v14 __asm__("$3");
    u16 *puVar7, uVar1;
    u32 hi, hic;
    int iVar5, iVar9, iVar8, uVar3, uVar10;

    uVar6 = ((int)((param_2 & 0xffff) + 0x8000) >> 7 & 0x1ff) - (u32)param_4p[0];
    uVar6c = uVar6 + zr;
    if ((uVar6 & 0xffff) < (u32)param_4p[2]) {
        uVar2 = ((int)((param_3 & 0xffff) + 0x8000) >> 7 & 0x1ff) - (u32)param_4p[1];
        __asm__("addu %0,%1,$zero" : "=r"(uVar2c) : "r"(uVar2));
        if ((uVar2 & 0xffff) < (u32)param_4p[3]) goto work;
        return 0;
    found:
        D_80184130 = *puVar7;
        return 1;
    work:
        uVar10 = *(int *)(param_4p + 6);
        uVar3 = *(int *)(param_4p + 8);
        iVar9 = *(int *)(param_4p + 0xc);
        iVar8 = *(int *)(param_4p + 0xe);
        ptmp = (u16 *)((((uVar2c & 0xffff) * (u32)param_4p[2] + (uVar6c & 0xffff)) * 2 & 0xffff) * 2 + *(int *)(param_4p + 4));
        v14 = *(int *)(param_4p + 10);
        __asm__ __volatile__("" :: "r"(uVar6c));
        p0 = (u32)*ptmp;
        n = (u32)ptmp[1];
        puVar4 = (u16 *)(v14 + p0 + n * 2) - 1;
        goto test;
    body:
        uVar1 = *puVar4;
        hi = uVar1 & 0x8000;
        hic = hi + zr;
        if (hi == 0)
            puVar7 = (u16 *)(iVar9 + (u32)uVar1 * 0x12);
        else
            puVar7 = (u16 *)(iVar8 + (uVar1 & 0x7fff) * 0x16);
        puVar4 = puVar4 - 1;
        iVar5 = func_80134C20((short)(hic | param_1), (s32)puVar7, uVar3, uVar10);
        if (iVar5 != 0) goto found;
    test:
        {
            u32 m;
            __asm__("addu %0,%1,$zero" : "=r"(m) : "r"(n));
            n--;
            if ((m & 0xffff) != 0) goto body;
        }
    }
    return 0;
}
