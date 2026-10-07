/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Switches the display to one of the preset screen modes. */
typedef struct {
    u16 w;
    u16 h;
    u16 mode;
} ScreenMode;

extern ScreenMode D_80062A3C[];
extern ScreenMode D_800AF7BC;

extern void func_800525DC(s32 width, s32 height, s32 mode, s32 arg3, s32 arg4);
extern void func_80053178(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80059234(s32 arg0);
extern void func_80053218(void);
extern void func_80014774(void);
extern void func_800147B8(void);

void func_800145EC(u16 mode)
{
    /* The current mode is recorded while the arguments are built. */
    func_800525DC(D_800AF7BC.w = D_80062A3C[mode].w,
                  D_800AF7BC.h = D_80062A3C[mode].h,
                  (D_800AF7BC.mode = D_80062A3C[mode].mode) | 4, 0, 0);
    if (D_800AF7BC.h == 480) {
        func_80053178(0, 0, 0, 0);
    } else {
        func_80053178(0, D_800AF7BC.h, 0, 0);
    }
    func_80059234(1);
    func_80053218();
    func_80014774();
    func_800147B8();
}
