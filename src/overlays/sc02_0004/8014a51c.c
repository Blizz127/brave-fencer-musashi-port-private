/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014A51C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029178(s32 arg);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32);

int func_8014A51C(int param_1) {
    if (((unsigned char (*)(int))func_80029178)(0x1e) == 0) return 0;
    if (*(unsigned int *)(param_1 + 0x44) & 0x400) return 0;
    if (*(unsigned char *)(param_1 + 0xa8) >= 0x19) return 0;
    if (*(unsigned char *)(param_1 + 0x223) != 0) return 0;
    if ((*(unsigned short *)(param_1 + 0xac) & 0x40) == 0) return 0;
    return 1;
}
