/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015D57C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80155440(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_801746DC(void);

void func_8015D57C(s32 arg0)
{
    s16 *p;
    func_80154150((s32)arg0, 0x19);
    func_801553A8(arg0);
    func_80155440(arg0);
    func_80146CA0(arg0);
    *(s32 *)((s8 *)arg0 + 0x234) = 0;
    p = *(s16 **)((s8 *)arg0 + 0x178);
    if (p != 0) {
        if (*(u16 *)p == 0x1F8) {
            *(s16 *)((s8 *)p + 0xFC) = 1;
            func_801746DC();
        }
    }
}
