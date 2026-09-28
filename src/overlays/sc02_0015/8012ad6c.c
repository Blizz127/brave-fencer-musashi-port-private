/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012AD6C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8012AD6C(void *a0) {
    *(short *)((char *)a0 + 0x34) = *(unsigned short *)((char *)a0 + 0x34) + 1;
}
