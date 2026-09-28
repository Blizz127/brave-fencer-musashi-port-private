/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012CAE4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80016714(void *a0, s32 a1);
extern u16   D_801274E4[];
extern void  func_80016714(void *a0, s32 a1);
extern u16 D_801274E4[];

void func_8012CAE4(void *a0) {
    u16 *d;
    void *p;
    s32 t;
    s32 a1;
    d = D_801274E4;
    *d |= 1;
    p = *(void **)((s32)a0 + 0x20);
    if (p != 0) {
        t = *(u16 *)p;
        if (t != 1) {
            if (t != 2) {
                goto done;
            }
            a1 = 0x38;
        } else {
            a1 = 0x84;
        }
        func_80016714(p, a1);
    done:;
    }
    func_80016714(a0, 0x10C);
}
