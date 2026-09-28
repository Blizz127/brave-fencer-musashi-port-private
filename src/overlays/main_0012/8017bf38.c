/* Exact overlay word export for [8017BF38,8017BF70) from MAIN.CD
 * member0012 (extracted/overlays/main/0012.bin offset 0x7BDE0, base 80128158).
 * Live STOP 8017BF38: table 80181D6C[0], jal 8017C008.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017BF38 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8017BF38(void) {
    extern void func_8017C008(s32 a0, s32 a1);
    extern u16 D_801853F0;
    u16 *p = &D_801853F0;

    func_8017C008(0, 0);
    *p = *p + 1;
}
