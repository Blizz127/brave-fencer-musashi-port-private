/* Overlay range [8017209C,80172170) from MAIN.CD member 0012.
 * SHA256(span)=95cd3f4570a4e6ac5d74e40b5d83ece2ceae9c69835ee975cef25f871fdf3480.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017209C - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);
extern s32 ratan2(s32 x, s32 y);
extern void func_80146D90(s32 a0);
extern s32 ratan2(s32 dx, s32 dy);
extern void func_80146D90(int);
extern s32 func_80012DBC(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80146D90(s32);
extern s32 ratan2(s32, s32);
u8 arg1;
extern s32 func_8017248C(s32 a0, s32 a1);
extern s32 func_8017248C(s32, s32);
extern void func_80172170(s32, s32);
extern void func_80172170(s32 a0, s32 a1);

s32 func_8017209C(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 ret;
    register s32 ang  __asm__("$3");     
    register s32 a3p  __asm__("$19");    
    register s32 a2p  __asm__("$20");    
    a3p = arg3;
    a2p = arg2;
    ret = func_8017248C((s32)arg0, (s32)arg1);
    if (ret != 0) {
        func_80146D90((s32)arg0);
        return ret;
    }
    ang = (ratan2((s32)*(s16 *)((u8 *)arg1 + 0) - (s32)*(s16 *)((u8 *)arg0 + 6),
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
