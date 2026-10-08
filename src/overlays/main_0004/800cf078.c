/* Clean-room re-derivation from the retail disassembly only (B28): intro
 * movie overlay state 3, the per-frame playback step. 800CF3E8 runs every
 * frame; 800CFC1C returns 0 when the movie ends. Once ended and 800EC6A4 is
 * set, it raises 800EC690 and advances the state. */
#include "psx_types.h"

extern s32 D_800EC6A0;
extern s32 D_800EC6A4;
extern s32 D_800EC690;
extern u8 D_800DA48C[];
extern void func_800CF3E8(void);
extern s32 func_800CFC1C(void *);
extern void func_800118AC(void);

void func_800CF078(void) {
    func_800CF3E8();
    if (D_800EC6A0 == 0) {
        if (func_800CFC1C(D_800DA48C) == 0) {
            D_800EC6A0 = 1;
        }
        if (D_800EC6A0 == 0) {
            return;
        }
    }
    if (D_800EC6A4) {
        D_800EC690 = 1;
        func_800118AC();
    }
}
