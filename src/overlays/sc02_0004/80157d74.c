/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80157D74 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80157DC4(void *a0);
extern void func_80157FC4(void *a0);

void func_80157D74(u16 *a0) {
    switch (a0[0]) {
    case 0x24:
        func_80157DC4(a0);
        break;
    case 0x25:
        func_80157FC4(a0);
        break;
    }
}
