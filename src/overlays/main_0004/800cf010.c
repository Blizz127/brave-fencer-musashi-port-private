/* Clean-room re-derivation from the retail disassembly only (B28): intro
 * movie overlay state 2. Starts the stream when the file was found
 * (800D1E58), sets up playback (800CFFEC), clears the done flags, prepares
 * the decoder context again and advances the state. */
#include "psx_types.h"

extern s32 D_800EC684;
extern s32 D_800B9A18;
extern s32 D_800EC6A0;
extern s32 D_800EC6A4;
extern u8 D_800DA48C[];
extern void func_800D1E58(void);
extern void func_800CFFEC(void);
extern void func_800CFB3C(void *);
extern void func_800118AC(void);

void func_800CF010(void) {
    if (D_800EC684) {
        func_800D1E58();
    }
    func_800CFFEC();
    D_800B9A18 = 0;
    D_800EC6A0 = 0;
    func_800CFB3C(D_800DA48C);
    D_800EC6A4 = 1;
    func_800118AC();
}
