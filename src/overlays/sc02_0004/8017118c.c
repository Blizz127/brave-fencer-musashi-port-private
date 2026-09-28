/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017118C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171928(void *a0);
extern void func_80171928(void *);
extern void func_80142454(s32 a0);

void func_8017118C(u8 * a0)
{
    func_80142454(-0x80);
    func_80171928(a0);
}
