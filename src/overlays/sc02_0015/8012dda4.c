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
    extern Entry_8012DDA4 * D_8018F014;
    extern Entry_8012DDA4 * D_8018F010;

    Entry_8012DDA4 *p;
    Entry_8012DDA4 *end = ((Entry_8012DDA4 *)D_80126720);

    while (D_8018F014 != end) {
        p = D_8018F014;
        if (p->active != 0 && p != D_8018F010) {
            D_8018F014 = p + 1;
            return p;
        }
        D_8018F014++;
    }
    D_8018F014 = 0;
    return 0;
}
