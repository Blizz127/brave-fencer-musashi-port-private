/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F2690 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern void func_80029124(s32, s32);
extern void func_801F28B0(void);
extern s32 func_801F2850(s32, s32, s32);
extern void func_801F2868(s32, s32, s32);
extern void func_801F28E0(void);
extern void func_80029124(s32 a0, s32 a1);
extern void func_801F2930(void);
extern void func_801F2970(void);

s32 *func_801F2690(void) {
    extern u8 D_80078EB1;
    extern u8 D_80078E78[];
    extern u32 D_801F3BDC;
    extern u32 D_801F3D00;
    extern s32 D_801F9DD4;
    extern s32 D_801F9F54;
    s32 v;
    u8 *p;

    p = D_80078E78;
    func_801F28B0();
    v = func_80029504();

    if (v >= 0xC8) {
        if (v < 0x258) {
            if (func_801F2850(D_80078EB1, 0xD, 0x18)) {
                if ((u32)(v - 0x136) < 0x46) {
                    func_801F2868(0xA, (s32)&D_801F3BDC, (s32)func_801F2930);
                    func_80029124(0x112, 1);
                } else {
                    func_801F2868(0xA, 0, 0);
                }
            } else {
                func_801F2868(0xA, 0, 0);
            }
            if (func_801F2850(p[0x39], 0xD, 0x18)) {
                if ((u32)(v - 0x136) < 0x46) {
                    func_801F2868(0xB, (s32)&D_801F3D00, (s32)func_801F2970);
                } else {
                    func_801F2868(0xB, 0, 0);
                }
            } else {
                func_801F2868(0xB, 0, 0);
            }
        } else {
            func_801F2868(0xA, 0, 0);
            func_801F2868(0xB, 0, 0);
        }
    } else {
        func_801F2868(0xA, 0, 0);
        func_801F2868(0xB, 0, 0);
    }
    func_801F28E0();
    if (D_801F9F54 == 0) {
        return 0;
    }
    return &D_801F9DD4;
}
