/* Overlay range [8014305C,801430F4) from MAIN.CD member 0012.
 * SHA256(span)=24b6c371940348d6bf7c514526134086a6d041a8e4bea5ad34e35cfb96aae5dd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014305C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012A828(s32 a0, void * a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8001CA1C(s32 a0, s32 a1);
void func_80142B2C(void *arg0);
extern void func_80142B2C(void *arg0);

void func_8014305C(int param_1)
{

    extern unsigned char D_8017F9C4[];
    extern unsigned char D_8017FA24[];
    register int s0_param __asm__("$16") = param_1;
    register int s1_copy __asm__("$17");
    int iVar2;
    short sVar1;

    iVar2 = ((int (*)(void))func_8012C1B8)();
    *(int *)(s0_param + 0x20) = iVar2;
    s1_copy = iVar2;
    if (iVar2 == 0) {
        ((void (*)(int))func_8012CAE4)(s0_param);
    } else {
        ((void (*)(int, void *))func_8001CA1C)(s1_copy, D_8017F9C4);
        sVar1 = (*(unsigned short *)(s0_param + 0x70) & 0xf) * 0x600 + 0xc00;
        *(short *)(s1_copy + 0x1a) = sVar1;
        *(short *)(s1_copy + 0x18) = sVar1;
        *(short *)(s0_param + 0xfc) = 0;
        func_8012A828(s0_param, D_8017FA24);
        ((void (*)(int))func_80142B2C)(s0_param);
    }
}
