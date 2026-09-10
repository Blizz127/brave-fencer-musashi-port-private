/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151AE4,80151B98).
 * Offset 0x2998C at overlay base 80128158. SHA256(span)=e05d2fb3c09e6ba064409e9faedcfa27bf9952c2972b19ab56461ea863d84229.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151ae4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80149020();
void func_80151C54();
void func_80159B3C();
void func_801542DC();
void func_8014E934();
s32 func_8014F3E8();
s32 func_8014CC28();
void func_8015BDD0();
void func_80165718();
extern s32 D_800D5880;
extern s32 D_800D46E4;
typedef struct {
    u8 pad[0xB4]; s32 uB4;
    u16 b8;
} T;
void func_80151AE4(T *p) {
    func_80149020(p);
    if (p->b8 == 0x8000) {
        func_80151C54(p);
        func_80159B3C(p);
        if (p->uB4 == (s32)&D_800D5880) {
            func_801542DC(p, &D_800D46E4, 0xE);
        }
        func_80165718(p);
        return;
    }
    func_8014E934(p);
    if (func_8014F3E8(p) || func_8014CC28(p)) {
        return;
    }
    func_80151C54(p);
    func_8015BDD0(p);
    func_80165718(p);
}
