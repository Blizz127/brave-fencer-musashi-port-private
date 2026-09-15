/* Overlay range [80173EF8,80174158) from MAIN.CD member 0012.
 * SHA256(span)=f5369391b547e95e2d19b71b6c1685db962c23f2f371956ac7f2411f39aad6ed.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80029124(s32, s32);                /* extern */
s32 func_80029178();                         /* extern */
void func_80029514();                     /* extern */
void func_8002A088();                     /* extern */
void func_8002A2D4();                     /* extern */
void func_8002A544();                     /* extern */
void func_8002A7B4();                     /* extern */
s32 func_800D0EC4(s16);                             /* extern */
void func_800D0F0C(s32, s16);                    /* extern */
void func_800D128C(s32, s32);                /* extern */
void func_80145EE8();                     /* static */
void func_80147060();                            /* static */
void func_80171A1C(void *);                      /* static */
void func_80174158(void *);                      /* static */
void func_80174188(void *);                      /* static */
void func_801741A8(void *);                      /* static */
extern s16 D_80126938;
extern s16 D_80126B3A;

void func_80173EF8(void *arg0) {
    s16 var_a0;

    if (M2C_FIELD(arg0, u16 *, 0xB8) & 0x8000) {
        D_80126938 = 1;
        func_80147060();
        var_a0 = D_80126B3A;
        if (D_80126B3A != 0x79) {
            if (D_80126B3A < 0x7A) {
                if (D_80126B3A != 0x70) {
                    if (D_80126B3A < 0x71) {
                        if (D_80126B3A != 0) {
                            goto block_21;
                        }
                    } else {
                        var_a0 = 0x8A;
                        if (D_80126B3A != 0x78) {
block_21:
                            func_800D0F0C(func_800D0EC4(var_a0), D_80126B3A);
                        } else {
                            func_80029124(0x8A, 1);
                            func_80029514(0xC8);
                            func_80174158(arg0);
                            func_8002A088(0x64);
                            func_8002A2D4(0x20);
                            func_8002A544(0x20);
                            func_8002A7B4(0x18);
                        }
                    }
                } else {
                    func_800D128C(var_a0 & 0xFF, 0);
                }
            } else {
                switch (D_80126B3A) {               /* irregular */
                case 0x7A:
                    func_80029124(0x8C, 1);
                    func_80029514(0x384);
                    func_80174158(arg0);
                    func_8002A088(0xF0);
                    func_8002A2D4(0x30);
                    func_8002A544(0x60);
                    func_8002A7B4(0x48);
                    break;
                case 0x7B:
                    func_80029124(0x8D, 1);
                    func_80029514(0x4B0);
                    func_80174158(arg0);
                    func_8002A088(0x140);
                    func_8002A2D4(0x40);
                    func_8002A544(0x80);
                    func_8002A7B4(0x60);
                    break;
                case 0x7C:
                    if (!(func_80029178(0x11D) & 0xFF)) {
                        func_80174188(arg0);
                    }
                    func_8002A088(0x190);
                    func_8002A2D4(0x50);
                    func_8002A544(0xA0);
                    func_8002A7B4(0x80);
                    func_801741A8(arg0);
                    func_80029124(0x8E, 1);
                    break;
                }
            }
        } else {
            func_80029124(0x8B, 1);
            func_80029514(0x258);
            func_80174158(arg0);
            func_8002A088(0xA0);
            func_8002A2D4(0x28);
            func_8002A544(0x40);
            func_8002A7B4(0x30);
        }
        func_80145EE8(0);
        func_80171A1C(arg0);
    }
}
