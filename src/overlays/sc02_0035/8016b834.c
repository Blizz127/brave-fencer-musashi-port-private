/* SC02.CD member35 [8016B834,8016B91C): twin of main_0012 8016B834 (src/overlays/main_0012/8016b834.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [8016B834,8016B91C) from MAIN.CD member 0012.
 * SHA256(span)=b34f12ba76ae57dba20f6ffdce610051fdbc741d2e03a269025d148563c739e5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016B834 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800233CC(void *, unsigned short);
extern void func_801465C0(void);
extern void func_8001CD9C(int, void *);

int func_8016B834(int param_1, int param_2) {

    extern int *D_801876F0[];
    extern unsigned short D_801876F8[];
    extern unsigned short D_80187700[];
    extern unsigned char D_801BDBA8[];
    int *puVar3;
    int *puVar2;
    int iVar1;

    puVar2 = (int *)(D_801BDBA8 + param_2 * 0x40);
    puVar3 = D_801876F0[*(int *)(param_1 + 0x2c)];
    iVar1 = ((int (*)(void))func_801465C0)();
    if (iVar1 != 0) {
        func_8001CD9C(iVar1, puVar2);
        func_800233CC(puVar2, D_801876F8[param_2]);
        puVar2[0] = *(int *)((int)puVar3 + param_2 * 8);
        puVar2[1] = *(int *)((int)puVar3 + param_2 * 8 + 4);
        *(unsigned int *)(iVar1 + 4) = *(unsigned int *)(iVar1 + 4) | 0x50040000;
        *(short *)(iVar1 + 0x1e) = D_80187700[param_2];
    }
    return iVar1;
}
