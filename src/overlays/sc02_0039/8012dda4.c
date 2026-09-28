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
    extern Entry_8012DDA4 * D_8019F96C;
    extern Entry_8012DDA4 * D_8019F968;

    Entry_8012DDA4 *p;
    Entry_8012DDA4 *end = ((Entry_8012DDA4 *)D_80126720);

    while (D_8019F96C != end) {
        p = D_8019F96C;
        if (p->active != 0 && p != D_8019F968) {
            D_8019F96C = p + 1;
            return p;
        }
        D_8019F96C++;
    }
    D_8019F96C = 0;
    return 0;
}
