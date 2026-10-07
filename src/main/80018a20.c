/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Polls one controller port and handles its connection state: idle/stable
 * states read the pad (port 0 also runs the 10-frame idle counter); newly
 * identified pads (state 2, or 6 with actuator info) on port 0 get their
 * actuator buffer and alignment set. Returns 0 after a read, 1 otherwise;
 * other states return no defined value. */
typedef struct {
    u8 unk0[0x4A];
    u8 motor0;
    u8 motor1;
} PadState;     /* 0x4C bytes */

extern PadState D_80078D98[2];
extern u32 D_800AE610;
extern s32 D_800A5E78;
extern u8  D_80062BBC[2];
extern u8  D_80062BAC[];
extern u8  D_80062BB4[];
extern u8  D_800747B8[2];

extern s32  func_8005D184(s32 slot);
extern s32  func_8005D244(s32 slot, s32 term, s32 offset);
extern void func_8005D538(s32 slot, u8 *act, s32 len);
extern s32  func_8005D4B8(s32 slot, u8 *align);
extern void func_80018F88(PadState *pad);
extern s32  func_80028D58(void);
extern void func_80018FC8(void);

s32 func_80018A20(s32 port)
{
    PadState *pad = &D_80078D98[port];
    s32 slot;

    switch (port) {
    case 0:
        slot = 0;
        break;
    case 1:
        slot = 0x10;
        break;
    }
    switch (func_8005D184(slot)) {
    case 0:
        if (port == 0 && D_800AE610++ >= 10) {
            D_800AE610 = 0;
            D_800A5E78 = 0;
        }
    case 1:
        func_80018F88(pad);
        return 0;
    case 2:
        if (port != 0) {
            return 1;
        }
        D_800AE610 = 0;
        if (func_8005D244(slot, 2, 0) != 0) {
            return 1;
        }
        if (func_80028D58() == 0) {
            if (pad->motor0 | pad->motor1) {
                D_80062BBC[1] = 1;
            } else {
                D_80062BBC[1] = 0;
            }
            pad->motor1 = 0;
            pad->motor0 = 0;
        } else {
            func_80018FC8();
        }
        func_8005D538(slot, D_80062BBC, 2);
        func_8005D4B8(slot, D_80062BAC);
        return 1;
    case 6:
        if (port != 0) {
            return 1;
        }
        D_800AE610 = 0;
        if (func_8005D244(slot, 2, 0) == 0) {
            return 1;
        }
        if (func_80028D58() == 0) {
            D_800747B8[0] = pad->motor0;
            D_800747B8[1] = pad->motor1;
            pad->motor1 = 0;
            pad->motor0 = 0;
        } else {
            func_80018FC8();
        }
        func_8005D538(slot, D_800747B8, 2);
        func_8005D4B8(slot, D_80062BB4);
        return 1;
    }
}
