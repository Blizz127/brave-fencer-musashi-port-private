/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012D664 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S8012D664_8012D664 { short a, b, c; };
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s32 func_800132BC(s32 a0, s32 a1);

int func_8012D664(int arg0, int arg1, int arg2) {
    extern int func_8012F568();
    extern int D_8017E018;

    struct S8012D664_8012D664 s;
    int ret;
    int t;

    s.a = (*(unsigned short*)&D_80126B5E);
    s.b = (*(unsigned short*)&D_80126B62) - 0x40;
    s.c = (*(unsigned short*)&D_80126B66);
    ret = ((int(*)())func_800132BC)(arg0, &s);
    t = arg1 + 0x20;
    if (ret < t * t) {
        func_8012F568(1, 1, 0, arg2, arg0, &D_8017E018);
        return 1;
    }
    return 0;
}
