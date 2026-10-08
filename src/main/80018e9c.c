/* Clean-room re-derivation from the retail disassembly only (B28): port-1
 * pad hold counter (button 0x100 held: counter 226 steps to 90, then fires). */
#include "psx_types.h"

typedef struct {
    u8 unk0[0x32];
    u16 held;
    u8 unk34[0x18];
} PadState;     /* 0x4C bytes */

extern PadState D_80078D98[2];
extern s32 func_800291B4(s32 id);
extern void func_800291A0(s32 id, s32 value);
extern void func_80028D78(s32 arg);

void func_80018E9C(PadState *pad) {
    s32 count;

    if (pad == &D_80078D98[0]) {
        if (D_80078D98[0].held & 0x100) {
            count = func_800291B4(226) + 1;
            if ((u8)count >= 90) {
                count = 0;
                func_80028D78(1);
            }
            func_800291A0(226, (u8)count);
        } else {
            func_800291A0(226, 0);
        }
    }
}
