/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013A448 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8013A530();

void func_8013A448(void *a0) {
    s16 *a1 = *(s16 **)((char *)a0 + 0x4);
    if (*(u16 *)((char *)a0 + 0x2) == 0) {
        *(s16 *)((char *)a1 + 0x2A) = 0x400;
        *(s16 *)((char *)a1 + 0x28) = 0x400;
        *(s16 *)((char *)a0 + 0x2) = *(u16 *)((char *)a0 + 0x2) + 1;
    } else {
        *(s16 *)((char *)a1 + 0x28) = *(u16 *)((char *)a1 + 0x28) + 0x200;
        *(s16 *)((char *)a1 + 0x2A) = *(u16 *)((char *)a1 + 0x2A) + 0x200;
        if (*(s16 *)((char *)a1 + 0x28) == 0x1000) {
            *(s16 *)((char *)a0 + 0x0) = 2;
            *(s16 *)((char *)a0 + 0x2) = 0;
        }
    }
    func_8013A530();
}
