/* Clean-room re-derivation from the retail disassembly only (B28): intro
 * movie overlay, play one movie to the end (blocking). It sets up the decode
 * environment (800D2394) and the stream (800D2454, callback 800D24D0), and
 * decodes the first frame (800D2704). It clears the display, then loops per
 * frame: start the decode into the current buffer (800D2C0C/800D2C88), fetch
 * the next VLC frame, wait for the frame (800D298C), VSync, and show the
 * finished buffer. The movie stops when it ends (800EC9F4), or on a pad press
 * (80014CAC), which fades out over 16 frames. 24-bit movies (mode != 0) scale
 * widths by 3/2. */
#include "psx_types.h"

typedef struct {
    s16 x, y, w, h;
} Rect16;

typedef struct {
    Rect16 disp;
    Rect16 screen;
    u8 isinter;
    u8 isrgb24;
    u8 pad0;
    u8 pad1;
} DispEnv16;

typedef struct {
    char *name;
    s32 mode;
    s32 unk8;
    s32 unkC;
    s32 x;
    s32 y;
    s32 w;
    s32 h;
} MovieEntry;

typedef struct {
    u32 *buf[2];
    s32 id;
} BufPair;

typedef struct {
    BufPair vlc;
    BufPair img;
    Rect16 rect[2];
    s32 rectid;
    s32 unk2C;
    s16 frame_w;
    s16 frame_h;
} DecEnv;

extern s32 D_800EC9F0;
extern s32 D_800EC9F4;
extern s32 D_800EC9F8;
extern s32 D_800EC9E0;
extern s32 D_800EC9E4;
extern DecEnv D_800EC9A4;
extern u8 D_800EC9FC[];
extern void func_800D24D0(void);
extern void func_800D2394(DecEnv *, s32, s32, s32, s32, MovieEntry *);
extern s32 func_800D2454(void *, void (*)(void), MovieEntry *);
extern s32 func_800D2704(DecEnv *, MovieEntry *);
extern void func_800D298C(DecEnv *, s32);
extern void func_800D2C0C(u32 *, s32);
extern void func_800D2C88(u32 *, s32);
extern void func_800D2D44(s32);
extern void func_800D2AA0(s32);
extern void func_800468FC(void);
extern void func_8002D8D4(void);
extern void func_8002D8A8(void);
extern void func_8002D034(void);
extern void func_800189A8(void);
extern s32 func_80014CAC(s32, s32);
extern void func_80010A98(void);
extern void func_80059658(s32);
extern s32 func_8004239C(s32);
extern void func_80059888(Rect16 *, s32, s32, s32);
extern void func_80058B04(DispEnv16 *, s32, s32, s32, s32);
extern void func_80059FC0(DispEnv16 *);
extern s32 func_80043830(s32, s32, s32);

s32 func_800D1E9C(MovieEntry *e) {
    DispEnv16 env;
    u8 unused[96]; /* retail frame slot, never touched */
    Rect16 clr;
    Rect16 white;
    Rect16 unused2; /* retail frame slot, never touched */
    DecEnv *dec;
    s32 id;
    BufPair *img;

    D_800EC9F0 = 1;
    func_800D2394(&D_800EC9A4, e->mode ? e->x * 3 / 2 : e->x, e->y,
                  e->mode ? e->x * 3 / 2 : e->x, e->y + e->h, e);
    if (func_800D2454(D_800EC9FC, func_800D24D0, e)) {
        func_800D2D44(0);
        func_800468FC();
        func_8002D8D4();
        func_800D2AA0(0);
        func_80010A98();
        return 1;
    }
    if (func_800D2704(&D_800EC9A4, e)) {
        func_800D2D44(0);
        func_800468FC();
        func_8002D8D4();
        func_800D2AA0(0);
        func_80010A98();
        return 1;
    }
    D_800EC9F4 = 0;
    D_800EC9F8 = 0;
    func_80059658(0);
    func_8004239C(0);
    clr.x = 0;
    clr.y = 0;
    clr.w = e->mode ? e->w * 3 / 2 : e->w;
    clr.h = e->h * 2;
    if (e->mode) {
        func_80059888(&clr, 0, 0, 0);
        white.x = 480;
        white.y = 0;
        white.w = 160;
        white.h = 480;
        func_80059888(&white, 255, 255, 255);
    } else {
        func_80059888(&clr, 0, 0, 0);
        white.x = 320;
        white.y = 0;
        white.w = 320;
        white.h = 480;
        func_80059888(&white, 255, 255, 255);
    }
    dec = &D_800EC9A4;
    for (;;) {
        func_800D2C0C(dec->vlc.buf[D_800EC9A4.vlc.id], e->mode ? 3 : 2);
        img = &dec->img;
        func_800D2C88(img->buf[D_800EC9A4.img.id],
                      ((dec->frame_w << 4) * ((dec->frame_h - 1) / 16 + 1)) >> 1);
        if (func_800D2704(dec, e)) {
            func_800D2D44(0);
            func_800468FC();
            func_8002D8D4();
            goto tail;
        }
        func_800D298C(dec, 0);
        func_8004239C(0);
        id = D_800EC9A4.rectid == 0;
        func_80058B04(&env, D_800EC9A4.rect[id].x - (e->mode ? e->x * 3 / 2 : e->x),
                      D_800EC9A4.rect[id].y - e->y,
                      e->mode ? e->w * 3 / 2 : e->w, e->h);
        if (e->mode) {
            env.isrgb24 = e->mode;
            env.disp.w = env.disp.w * 2 / 3;
        }
        func_80059FC0(&env);
        func_80059658(1);
        if (D_800EC9F4 == 1) {
            break;
        }
        func_800189A8();
        if (D_800EC9F8 == 0) {
            if (D_800EC9E0 == 0) {
                if (func_80014CAC(0, 2048)) {
                    D_800EC9E0 = 1;
                    D_800EC9E4 = 16;
                    func_8002D8A8();
                }
            } else if (--D_800EC9E4 == 0) {
                break;
            }
        }
        func_8002D034();
    }
    func_800D2D44(0);
    func_800468FC();
    func_8002D8D4();
    func_80043830(9, 0, 0);
tail:
    func_800D2AA0(0);
    func_80059658(1);
    func_80010A98();
    return 1;
}
