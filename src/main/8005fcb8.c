#include "psx_types.h"


extern s32 D_80078C80;
extern void func_80062888(void);
extern void func_8006189C(void);
extern void func_80042644(s32, void *);
extern u8 D_800616D0[];

/* Byte-exact startup state initialization [8005FCB8,8005FD18).  The
 * volatile pointer preserves retail's address calculation and first store;
 * the remaining aliased globals retain their observed direct accesses. */
void func_8005FCB8(void) {
    volatile s32 *state;
    func_80062888();
    state = &D_80078C80;
    state[0] = 0;
    state[1] = 0;
    state[2] = 0;
    state[4] = -1;
    func_8006189C();
    func_80042644(7, D_800616D0);
}
