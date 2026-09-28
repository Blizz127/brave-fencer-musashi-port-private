/* Exact retail word export [8002F658,8002F67C); verified against pinned EXE and asm. */
#include "psx_types.h"

/* func_8002F658 - byte-exact against retail at -O2 (tools/register_match.py).
 * Types are the loosest that reproduce the bytes. */

extern s16 D_800A4688;
extern u8 D_800A4698;

s32 func_8002F658(void) {
    if (D_800A4698 != 0) {
        return -1;
    }
    return D_800A4688;
}
