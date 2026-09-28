/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012DDA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct Entry_8012DDA4 {
    u16 active;
    unsigned char pad[0x10C - 2];
} Entry_8012DDA4;
extern u8 D_80126720[];

s32 func_8012DDA4()
{
    extern Entry_8012DDA4 * D_80199774;
    extern Entry_8012DDA4 * D_80199770;

    Entry_8012DDA4 *p;
    Entry_8012DDA4 *end = ((Entry_8012DDA4 *)D_80126720);

    while (D_80199774 != end) {
        p = D_80199774;
        if (p->active != 0 && p != D_80199770) {
            D_80199774 = p + 1;
            return p;
        }
        D_80199774++;
    }
    D_80199774 = 0;
    return 0;
}
