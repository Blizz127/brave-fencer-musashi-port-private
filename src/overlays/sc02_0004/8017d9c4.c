/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D9C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern s32 rand(void);
extern int rand(void);
extern u8 *func_8012913C(s32 arg);

void func_8017D9C4(void *a0)
{
    u8 *var_s0;
    u8 *var_s1;

    var_s1 = a0;
    var_s0 = func_8012913C(5);
    if (var_s0 != ((void *)0) ) {
        *(u16 *)(var_s0 + 6) = *(u16 *)(var_s1 + 6);
        *(u16 *)(var_s0 + 0xA) = *(u16 *)(var_s1 + 0xA);
        *(u16 *)(var_s0 + 0xE) = *(u16 *)(var_s1 + 0xE);
        *(u16 *)(var_s0 + 0x2E) = rand() & 3;
    }
}
