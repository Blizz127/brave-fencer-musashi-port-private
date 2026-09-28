/* Exact retail word export for [80038210,80038308); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80038210 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_800B9CD8[];
extern u8 D_800C1320[];
extern u8 *D_800A6428;

extern s32 func_80038698(void *arg0);
extern s32 func_800387C0(void *arg0);
extern void func_80038838(void *arg0);

s32 func_80038210(s32 a0, s16 a1, s32 a2)
{
    u8 *entry;
    s32 i;
    s32 k;
    u8 *q;
    s32 v1;

    entry = D_800B9CD8;
    for (i = 0; i < 2; i++, entry += 0x1FC) {
        if (entry[0x1FB] == 0) {
            D_800A6428 = entry + 0x1BA;
            *(s32 *)entry = a0;
            *(s16 *)(entry + 0x1EC) = a1;
            *(s32 *)(entry + 0x1E8) = a2;
            *(u8 **)(entry + 0x1D8) = D_800C1320;
            *(u8 **)(entry + 0x1DC) = D_800C1320 + 0x20;
            *(u8 **)(entry + 0x1E0) = D_800C1320 + 0x820;
            if (func_80038698(entry) != 0) {
                return -1;
            }
            if (func_800387C0(entry) != 0) {
                return -1;
            }
            func_80038838(entry);
            v1 = *(s32 *)entry;
            entry[0x1FB] = 1;
            *(s32 *)(entry + 4) = v1;
            entry[0x1FA] = 0;
            for (k = 0xF, q = entry + 0xF; k >= 0; k--, q--) {
                q[0x1BA] = 0;
            }
            return i;
        }
    }
    return -1;
}
