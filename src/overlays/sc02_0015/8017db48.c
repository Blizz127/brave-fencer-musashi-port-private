/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017DB48 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8017DB48(void *a0) {
        *(short *)((char *)a0 + 0x2) = *(unsigned short *)((char *)a0 + 0x2) + 1;
        *(int *)((char *)a0 + 0x14) = 0x20000;
    }
