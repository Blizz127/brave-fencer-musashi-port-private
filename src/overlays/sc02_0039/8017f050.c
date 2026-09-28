/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017F050 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C2C4(s32 a0);
extern s32 func_8012AD50(void *arg0);
extern s32  func_8012AD50(void *a0);
extern s32 func_8012AD50(void *a0);

void func_8017F050(void *a0)
{
    register void *s0 __asm__("$16") = a0;
    register s32 zr __asm__("$0");
    s32 v0 = ((s32 (*)(void))func_8012C1B8)();
    s32 p;

    *(s32 *)((u8 *)s0 + 0x20) = v0;

    if (!v0) {
        func_8012CAE4(s0);
    } else {
        s32 t;

        func_8001C2C4(v0);
        t = *(s16 *)((u8 *)s0 + 0xFC);
        p = (s32)s0 + zr;
        *(s16 *)(p + 0xFE) = 0;
        *(s16 *)(p + 0x102) = 0;
        *(s32 *)(p + 0x1C) = t;
        func_8012AD50((void *)p);
    }
}
