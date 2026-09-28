/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017209C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_8017248C(s32, s32);
extern s32 func_8004CFEC(s32, s32);
extern void func_80146D90(s32);
extern s32 func_80012DBC(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80172170(s32 a0, s32 a1);

s32 func_8017209C(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 ret;
    register s32 ang  __asm__("$3");    /* $v1 */
    register s32 a3p  __asm__("$19");   /* $s3 = arg3 */
    register s32 a2p  __asm__("$20");   /* $s4 = arg2 */
    a3p = arg3;
    a2p = arg2;
    ret = func_8017248C((s32)arg0, (s32)arg1);
    if (ret != 0) {
        func_80146D90((s32)arg0);
        return ret;
    }
    ang = (func_8004CFEC((s32)*(s16 *)((u8 *)arg1 + 0) - (s32)*(s16 *)((u8 *)arg0 + 6),
                         (s32)*(s16 *)((u8 *)arg1 + 4) - (s32)*(s16 *)((u8 *)arg0 + 0xE))
           + 0x800) & 0xFFF;
    if (a3p != 0) {
        ang = (s16)func_80012DBC((s32)*(s16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x12),
                                 ang, (s16)a3p, 1);
    }
    *(s16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x12) = ang;
    func_80172170((s32)arg0, a2p & 0xFF);
    return 0;
}
