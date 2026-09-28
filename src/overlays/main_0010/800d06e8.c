/* Exact overlay word export for [800D06E8,800D0C48) from MAIN.CD member0010
 * (extracted/overlays/main/0010.bin offset 0x218F0, load base 800AEDF8).
 * SHA256(span)=801567657129829c258dc216b638b69c9a7ac597dda2e3669b5def0c2c6f2cb1.
 * Word export only: the native seam executes the member's own words. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D06E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_800B9A08;
extern s32 func_80029504(void);
extern void func_8002D4C8(s32 arg0, s32 arg1);
extern s32 func_8001AAA0(s32 arg0);
extern s32 D_800A2B70;
extern s32 D_800BA0FC;
extern s32 D_8011529C;
extern s32 D_80114EA0;
extern s32 D_801151F8;
extern s32 D_801201F0;
extern s32 D_80126AE8;
extern s32 D_80127050;
extern s32 D_80127500;
extern s32 D_800A654C;

void func_800D06E8(void) {
    typedef struct {
        u8 pad00[0x36];
        u8 field_0x36;
        u8 field_0x37;
    } Blk80078E78;
    extern Blk80078E78 D_80078E78;
    Blk80078E78 *p = &D_80078E78;
    s32 s0;
    s32 s1;
    s32 r;
    s32 t;
    u8 c;

    switch (D_80127500) {
    case 0:
        switch (D_800B9A08) {
        case 0x1010:
        case 0x1011:
        case 0x1077:
        case 0x1078:
        case 0x1094:
        case 0x1095:
            r = func_80029504();
            if ((u32)(r - 0x460) < 0x32) {
                s1 = 0;
            } else {
                t = (u32)(r - 0x64) < 0x1E;
                s1 = t ^ 1;
            }
            if (s1 == 0) {
                D_800A2B70 = 0;
            }
            c = p->field_0x37;
            s0 = 0;
            if (c == 1) {
                s0 = 1;
            } else if ((u8)(c - 3) < 2) {
                s0 = 2;
            }
            if (D_800A2B70 != 0) {
                D_80127500 += 1;
                break;
            }
            if (s1 == 0) {
                break;
            }
            if (s0 == D_8011529C) {
                break;
            }
            D_8011529C = s0;
            if (D_80127050 != 0) {
                D_80127050 = 0;
                break;
            }
            switch (s0) {
            case 1:
                func_8002D4C8(0x518, 0);
                break;
            case 2:
                func_8002D4C8(0x517, 0);
                break;
            default:
                goto sw1_end;
            }
            D_800A2B70 = s0;
            D_800BA0FC = 0;
            D_80127500 += 1;
            break;
        case 0x3014:
        case 0x301C:
            if (p->field_0x37 != D_8011529C) {
                D_8011529C = p->field_0x37;
                if (p->field_0x37 == 4) {
                    func_8002D4C8(0x683, 0);
                } else if (p->field_0x37 == 0) {
                    func_8002D4C8(0xD, 0x683);
                }
            }
            break;
        }
        break;
    case 1:
        D_800BA0FC += 1;
        if ((u32)D_800BA0FC >= 0x97) {
            switch (D_800A2B70) {
            case 1:
                func_8002D4C8(0xD, 0x518);
                break;
            case 2:
                func_8002D4C8(0xD, 0x517);
                break;
            }
            D_800A2B70 = 0;
            D_80127500 = 0;
        }
        break;
    case 2:
        D_801201F0 -= 1;
        if (D_801201F0 == 0) {
            func_8002D4C8(0xD, 0x683);
            D_80127500 = 0;
        }
        break;
    }

sw1_end:
    switch (D_801151F8) {
    case 0:
        switch (D_800B9A08) {
        case 0x1010:
        case 0x1011:
        case 0x1077:
        case 0x1078:
        case 0x1094:
        case 0x1095:
            r = func_80029504();
            if ((u32)(r - 0x460) < 0x32) {
                s1 = 0x89;
            } else if ((u32)(r - 0x384) < 0x6E) {
                s1 = 0x65;
            } else if ((u32)(r - 0x64) < 0x1E) {
                s1 = 0x28;
            } else {
                s1 = 0x10;
                if (p->field_0x36 == 1) {
                    s1 = 0xF;
                }
            }
            break;
        case 0x1052:
        case 0x1053:
            s1 = 0x27;
            break;
        case 0x3014:
        case 0x301C:
        case 0x301E:
        case 0x3023:
            s1 = 0xA;
            if (p->field_0x37 == 4) {
                s1 = 0x3C;
            }
            break;
        }
        if (s1 != D_800A654C) {
            D_80114EA0 = s1;
            D_80126AE8 = 0x3C;
            D_800A654C = 0;
            D_801151F8 += 1;
            func_8002D4C8(1, 2);
        }
        break;
    case 1:
        D_80126AE8 -= 1;
        if (D_80126AE8 == 0) {
            D_801151F8 += 1;
        }
        break;
    case 2:
        switch (D_80114EA0) {
        case 0xA:
            func_8002D4C8(0x10C, 0);
            break;
        case 0xF:
            func_8001AAA0(0xF);
            break;
        case 0x10:
            func_8001AAA0(0x10);
            break;
        case 0x3C:
            func_8002D4C8(0x13B, 0);
            break;
        }
        D_801151F8 = 0;
        D_800A654C = D_80114EA0;
        break;
    case 3:
    case 4:
        break;
    }
}
