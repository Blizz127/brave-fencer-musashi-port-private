/* Overlay range [80171E08,80171EC8) from MAIN.CD member 0012.
 * SHA256(span)=8a98ddece7588ac0b407a78ed6732d833627e4b6ddb65b2ccd5bf9d27e124ac3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80171E08 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);
extern s32 ratan2(s32 x, s32 y);
extern void func_80146D90(s32 a0);
extern s32 ratan2(s32 dx, s32 dy);
extern void func_80146D90(int);
extern s32 func_80012DBC(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80146D90(s32);
extern s32 ratan2(s32, s32);
extern void func_80171EC8(s32 a0);
extern s32 func_8017248C(s32 a0, s32 a1);

s32 func_80171E08(s32 arg0, s32 arg1, s32 arg2) {
    s32 r;
    s32 a1v;
    r = func_8017248C(arg0, arg1);
    if (r != 0) {
        func_80146D90(arg0);
        return r;
    }
    a1v = (ratan2((s32)*(s16 *)(arg1 + 0x0) - (s32)*(s16 *)(arg0 + 0x6),
                  (s32)*(s16 *)(arg1 + 0x4) - (s32)*(s16 *)(arg0 + 0xE)) + 0x800) & 0xFFF;
    if (arg2 != 0) {
        a1v = (s16)func_80012DBC((s32)*(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12),
                                 a1v, (s32)(s16)arg2, 1);
    }
    *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12) = a1v;
    func_80171EC8(arg0);
    return 0;
}
