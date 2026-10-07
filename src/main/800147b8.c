/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Builds the two draw/display environment pairs for the current screen size
 * (D_800AF7BC x D_800AF7BE). A 480-line screen draws both buffers at y 0;
 * otherwise the second pair sits one screen lower. Then fills the drawing
 * offsets, texture windows and background flags of both draw environments. */
extern u8  D_800AF630[];
extern u16 D_800AF7BC;  /* screen width */
extern u16 D_800AF7BE;  /* screen height */
extern u16 D_800AF670;  /* draw env 0: offset x, y */
extern u16 D_800AF672;
extern u16 D_800AF678;  /* draw env 0: texture window w, h */
extern u16 D_800AF67A;
extern u8  D_800AF67E;  /* draw env 0: dither, background */
extern u8  D_800AF680;
extern u16 D_800AF6CC;  /* draw env 1: offset x, y */
extern u16 D_800AF6CE;
extern u16 D_800AF6D4;  /* draw env 1: texture window w, h */
extern u16 D_800AF6D6;
extern u8  D_800AF6DA;  /* draw env 1: dither, background */
extern u8  D_800AF6DC;

extern void func_80058A4C(u8 *env, s32 x, s32 y, s32 w, s32 h);
extern void func_80058B04(u8 *env, s32 x, s32 y, s32 w, s32 h);
extern void func_80014960(void);

/* Reading the first height through this helper keeps that load out of the
 * later shared reads, which gives the retail register allocation (found by
 * permuter; same value as reading D_800AF7BE directly). */
static inline u16 screen_height(void)
{
    return D_800AF7BE;
}

void func_800147B8(void)
{
    u8 *state = D_800AF630;
    s32 y = screen_height();
    u16 ofsY;
    u32 width, height;

    if (y == 480) {
        y = 0;
    }
    func_80058A4C(state + 0x38, 0, 10, D_800AF7BC, D_800AF7BE - 20);
    func_80058B04(state + 0x14C, 0, 0, D_800AF7BC, D_800AF7BE);
    func_80058A4C(state + 0x94, 0, y + 10, D_800AF7BC, D_800AF7BE - 20);
    func_80058B04(state + 0x160, 0, y, D_800AF7BC, D_800AF7BE);

    width = D_800AF7BC;
    height = D_800AF7BE;
    D_800AF670 = width >> 1;
    D_800AF672 = height >> 1;
    D_800AF6CC = width >> 1;
    ofsY = 240;
    if (height == 240) {
        ofsY = 360;
    }
    D_800AF6D6 = 256;
    D_800AF6D4 = 256;
    D_800AF67A = 256;
    D_800AF678 = 256;
    D_800AF6CE = ofsY;
    D_800AF6DA = 0;
    D_800AF67E = 0;
    D_800AF6DC = 1;
    D_800AF680 = 1;
    func_80014960();
}
