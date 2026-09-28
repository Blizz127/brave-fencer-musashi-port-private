/* Overlay range [80178B18,80178B70) from MAIN.CD member 0012.
 * SHA256(span)=dd7eb42cfef2584716efa8e4d6c5c53e3c96401cc83b6f2dfc8fa3ecef01c56d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80178B18 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8017435C(void);
extern void func_801746A4(void);
extern void func_80178CBC(s32 a0, s32 a1);

s32 func_80178B18(s32 param_1, s32 param_2)
{
    extern void func_80178BF8(void);
    extern void func_80178CBC(s32 arg0, s32 arg1);
    extern u16 D_80181CBC;

    int *p = &(*(int *)&D_80181CBC);
    *p = ((int)param_2);
    func_80178BF8();
    func_801746A4();
    func_8017435C();
    ((void (*)(int, void *))func_80178CBC)(((int)param_1), (char *)p - 0xC);
}
