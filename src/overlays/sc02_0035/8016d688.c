/* SC02.CD member35 [8016D688,8016D778): twin of main_0012 8016D688 (src/overlays/main_0012/8016d688.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [8016D688,8016D778) from MAIN.CD member 0012.
 * SHA256(span)=b02860517bd752a08718f0026cf8181547e576c5fba1269b9a094428aca806a4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016D688 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800233CC(void *, unsigned short);
extern void func_801465C0(void);
extern void func_8001CD9C(int, void *);
extern unsigned char D_801BDD39[];
extern unsigned char D_801BDD3A;
extern unsigned char D_801BDD3C;
extern unsigned char D_801BDD3D;
extern unsigned char D_801BDD3E;

void func_8016D688(int param_1)
{
    int iVar2;
    int iVar3;

    D_801BDD39[0] = 0xE0;
    D_801BDD3A = 0xE0;
    D_801BDD39[-1] = 0xE0;
    D_801BDD3E = 0;
    D_801BDD3D = 0;
    D_801BDD3C = 0;
    iVar2 = ((int (*)(void))func_801465C0)();
    if (iVar2 != 0) {
        *(int *)(param_1 + 0x20) = iVar2;
        func_800233CC(&D_801BDD39[-1], 0x28);
        func_8001CD9C(iVar2, &D_801BDD39[-1]);
        *(unsigned short *)(iVar2 + 0x1A) = 0x1400;
        *(unsigned int *)(iVar2 + 4) = *(unsigned int *)(iVar2 + 4) | 0x50000000;
        iVar3 = *(int *)(param_1 + 0x30);
        *(unsigned short *)(param_1 + 0x28) = *(unsigned short *)(iVar3 + 0x36);
        *(unsigned short *)(param_1 + 0x12) = *(unsigned short *)(iVar3 + 6);
        *(short *)(param_1 + 0x16) = *(unsigned short *)(iVar3 + 0xA) - 0x28;
        *(unsigned short *)(param_1 + 0x1A) = *(unsigned short *)(iVar3 + 0xE);
        *(unsigned short *)(param_1 + 2) = *(unsigned short *)(param_1 + 2) + 1;
    }
}
