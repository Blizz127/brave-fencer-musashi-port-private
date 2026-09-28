/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016F0E4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147060(u8 * a0);
extern void func_80148634(void *a0);
extern void func_801511A8(u8 *a0);
extern u8 D_800B9A17;
extern void func_8017196C(s32 *a0, s8 a1);
extern void func_80147060(u8 *a0);
void aF8016F0E4(u8 *p) __asm__("func_8016F0E4");

void aF8016F0E4(u8 *p) {
    extern s16 D_80078EB4;                        
    extern u8 D_800B9A17;
    *(s32 *)(p + 0x1F8) = 0;
    *(s32 *)(p + 0x1FC) = 0;
    func_8017196C((s32 *)p, 0);
    func_80147060(p);
    func_801511A8(p);
    if (*(u16 *)&D_80078EB4 != 0) {
        D_800B9A17 = 1;
    }
    func_80148634(p);
}
