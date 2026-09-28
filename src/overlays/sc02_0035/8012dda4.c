/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012DDA4 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct Entry_8012DDA4 {
    u16 active;
    unsigned char pad[0x10C - 2];
} Entry_8012DDA4;
extern u8 D_80126720[];

s32 func_8012DDA4()
{
    extern Entry_8012DDA4 * D_801BD5BC;
    extern Entry_8012DDA4 * D_801BD5B8;

    Entry_8012DDA4 *p;
    Entry_8012DDA4 *end = ((Entry_8012DDA4 *)D_80126720);

    while (D_801BD5BC != end) {
        p = D_801BD5BC;
        if (p->active != 0 && p != D_801BD5B8) {
            D_801BD5BC = p + 1;
            return p;
        }
        D_801BD5BC++;
    }
    D_801BD5BC = 0;
    return 0;
}
