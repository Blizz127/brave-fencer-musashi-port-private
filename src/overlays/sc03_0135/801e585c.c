/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E585C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern void func_80029124(s32 a0, s32 a1);

void *func_801E585C(void) {
    typedef struct { s32 x, y, z; } SV4;
    extern u8 D_80078EB1;
    extern u8 D_80078E78[];
    extern u32 D_801E6C68;
    extern u32 D_801E6D8C;
    extern s32 D_801EADF0;
    extern void func_801E5A7C(void);
    extern s32 func_80029504(void);
    extern s32 func_801E5A1C(s32, s32, s32);
    extern void func_801E5A34(s32, s32, s32);
    extern void func_80029124(s32 a0, s32 a1);
    extern void func_801E5AAC(void);
    extern void func_801E5AFC(void);
    extern void func_801E5B3C(void);
    extern SV4 D_801EAC70;
    s32 v;
    u8 *p;

    p = D_80078E78;
    func_801E5A7C();
    v = func_80029504();

    if (v >= 0xC8) {
        if (v < 0x258) {
            if (func_801E5A1C(D_80078EB1, 0xD, 0x18)) {
                if ((u32)(v - 0x136) < 0x46) {
                    func_801E5A34(0xA, (s32)&D_801E6C68, (s32)func_801E5AFC);
                    func_80029124(0x112, 1);
                } else {
                    func_801E5A34(0xA, 0, 0);
                }
            } else {
                func_801E5A34(0xA, 0, 0);
            }
            if (func_801E5A1C(p[0x39], 0xD, 0x18)) {
                if ((u32)(v - 0x136) < 0x46) {
                    func_801E5A34(0xB, (s32)&D_801E6D8C, (s32)func_801E5B3C);
                } else {
                    func_801E5A34(0xB, 0, 0);
                }
            } else {
                func_801E5A34(0xB, 0, 0);
            }
        } else {
            func_801E5A34(0xA, 0, 0);
            func_801E5A34(0xB, 0, 0);
        }
    } else {
        func_801E5A34(0xA, 0, 0);
        func_801E5A34(0xB, 0, 0);
    }
    func_801E5AAC();
    if (D_801EADF0 == 0) {
        return 0;
    }
    return &D_801EAC70;
}
