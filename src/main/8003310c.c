/* Exact retail word export for [8003310C,800331D4); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8003310C - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 func_8003310C(s32);
extern u16 D_800A46E8[];
extern void func_8003324C(s32);

s32 func_8003310C(s32 arg0) {
    struct {
        u8 found;
        s32 r;
        u16 vmin;
    } st;
    u16 *p;
    u16 *q;
    s32 i;

    p = D_800A46E8;
    i = 0;
    st.found = 0;

    for (; i < 8;) {
        q = p + 1;
        if (*p == 0) {
            return i + 1;
        }
        if (!st.found) {
            st.found = 1;
            st.vmin = *q;
            st.r = i;
        } else {
            if (*q < st.vmin) {
                st.vmin = *q;
                st.r = i;
            }
        }
        i++;
        p += 0x2A;
    }

    if ((u16)arg0 < st.vmin) {
        return 0;
    }
    func_8003324C((u16)st.r);
    return st.r + 1;
}
