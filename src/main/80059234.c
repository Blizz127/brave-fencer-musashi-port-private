#include "psx_types.h"

/* Byte-exact recovery of retail ResetGraph [80059234,800593B8).
 * Array views below reproduce access ordering; they are not evidence of the
 * original declarations. All guest aliases must share storage in a native
 * binding. This file is not yet compiled into the native port. */
typedef struct {
    u8 opaque00[0x34];
    s32 (*reset34)(s32);
} GraphicsDispatch;

/* Exact matched instruction stream for the bounded native MIPS seam. This is
 * source-owned audit data, not a retail-media dependency or host replacement. */

extern GraphicsDispatch *D_80072780;
extern s32 (*D_80072784)(const char *, ...);
extern u8 D_80072740[];
extern u8 D_80072788[];
extern u8 D_80072789[];
extern u8 D_8007278A;
extern s16 D_8007278C[];
extern s16 D_8007278E[];
extern s32 D_80072808[];
extern s32 D_8007281C[];
extern char D_80074084[];
extern char D_800740A4[];
extern s32 func_8005C604(const char *, ...);
extern void func_8005C29C(u8 *, s32, u32);
extern void func_80042580(void);
extern void func_8005CE38(u32);
extern s32 func_8005BD7C(s32);

s32 func_80059234(s32 mode) {
    u8 *environment;
    u8 kind;
    switch (mode & 7) {
    case 0:
    case 3:
        func_8005C604(D_80074084, D_80072740, D_80072788);
        /* fall through */
    case 5:
        environment = D_80072788;
        func_8005C29C(environment, 0, 0x80);
        func_80042580();
        func_8005CE38((u32)D_80072780 & 0xffffff);
        kind = func_8005BD7C(mode);
        environment[0] = kind;
        D_80072789[0] = 1;
        D_8007278C[0] = D_80072808[kind];
        D_8007278E[0] = D_8007281C[kind];
        func_8005C29C(environment + 0x10, -1, 0x5c);
        func_8005C29C(environment + 0x6c, -1, 0x14);
        return environment[0];
    default:
        if (D_8007278A >= 2)
            D_80072784(D_800740A4, mode);
        return D_80072780->reset34(1);
    }
}
