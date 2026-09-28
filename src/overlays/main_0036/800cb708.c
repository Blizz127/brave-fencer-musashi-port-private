/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB708 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146CA0(void *a0);
extern s32 func_80146E98(s32);
extern s32 func_80146CA0(void *);
extern s32 func_80146E98(s32 a0);
extern void func_80162F08(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80162FC0(s32 *a0);

void func_800CB708(void *arg0) {
    s32 v0;
    s32 v1;
    s32 a1;

    func_80162F08((s32)arg0, 0, 0, 0);

    v0 = *(s32 *)((s32)arg0 + 0x24);
    v1 = *(s32 *)((s32)arg0 + 0x28);
    a1 = *(s32 *)((s32)arg0 + 0x2C);

    *(s32 *)((s32)arg0 + 0x10) = v0;
    *(s32 *)((s32)arg0 + 0x14) = v1;
    *(s32 *)((s32)arg0 + 0x18) = a1;

    func_80162FC0((s32 *)arg0);

    if (func_80146E98((s32)arg0) != 0) {
        func_80146CA0(arg0);
    }
}
