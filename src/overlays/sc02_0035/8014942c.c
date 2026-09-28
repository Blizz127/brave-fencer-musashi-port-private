/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014942C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012F038(int param_1, short *param_2, short *param_3);

void func_8014942C(s32 arg0) {
    ((void (*)())func_8012F038)(*(s32 *)(arg0 + 0x20) + 0x34);
}
