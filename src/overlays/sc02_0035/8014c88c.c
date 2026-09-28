/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014C88C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015978(s32, s32*);
extern void func_80015978(int a0, int *a1);
extern void func_8014C8C8(s32 a0, s32 *a1);

void func_8014C88C(s32 a0) {
    s32 sp10;
    func_80015978(a0 + 4, &sp10);
    func_8014C8C8(a0, &sp10);
}
