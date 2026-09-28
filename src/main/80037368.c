/* Exact retail word export for [80037368,800373D0); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80037368 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_80076251;   
extern u8 D_80076220[];
extern u8 D_80076250[];

void *func_80037368(int *out) {
    int count = 0;
    u8 *ptr = D_80076220;
    int i;

    for (i = 0; i < 0x50; i += 0x10) {
        *ptr = 0;
        ptr++;

        if ((&D_80076251)[i] != 0) {
            D_80076220[count] = D_80076250[i];
            count++;
        }
    }

    *out = count;
    return D_80076220;
}
