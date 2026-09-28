/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80159C84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_801473EC(s32 *a0);
extern s32 func_801488A8(u8 *a0);
extern s32 func_801496D4(void *a0);
extern void func_80149704(void);
extern s32 func_8016F1AC(void);
extern s32 func_80149AA8(s32 *a0);
extern s32 func_801498E0(s32 *a0);
extern s32 func_80149954(s32 s0);
extern s32 func_80149A64(s32 *a0);
extern void func_80149AD4(s32 *a0);
extern s32 func_80149B54(s32 * arg0);
extern void func_80149BAC(s32 *a0);
extern s32 func_80149CD4(s32 a0);
extern s32 func_80149D9C(s32 a0);
extern void func_80149FA8(void);
extern s32 func_80149FB0(s32 a0);
extern void func_8014A830(void);
extern void func_8014C010(s32 a0, s32 a1);
extern u16 D_800B99DA;
extern void func_80147324(s32 a0);
extern void func_80155440(s32 *a0);
extern void func_80154190(u8 *a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154B4C(u8 *a0, s32 a1);
extern void func_8015E880(s32 *a0);
extern s32 func_80161208();
extern void func_80147A84(int);
extern void func_80154A74(int, int);
extern int func_8005C49C(void);
extern s32 func_80172590(u8 *a0);
extern unsigned char D_80181208;

s32 func_80159C84(s32 p) {
    extern s32 func_80161B18(void *a0);
    extern s32 func_80161B84(void *a0);
    extern int func_80161BE0(void *a0);
    extern s32 func_801619A4(s32 *a0);
    extern s32 func_8014A738(u8 *a0);
    extern void func_800CCCC0(u8 *a0);
    extern void func_8015A230(s32 *a0);
    extern void func_801483E8(void);
    extern void (*D_801812A4[])(u8 *);
    extern s32 D_800D5F04;
    extern s32 D_800D5F14;
    extern s32 D_800D5F34;
    extern s32 D_800D5F44;
    extern s32 D_800D49F4;


    s32 t;

    if (((s32 (*)(void))func_80149D9C)() != 0) {
        D_801812A4[*(u16 *)((u8 *)p)](((u8 *)p));
        ((void (*)(u8 *))func_80149FA8)(((u8 *)p));
        return;
    }

    ((void(*)(u8 *))func_80149FB0)(((u8 *)p));
    if (func_80161B18(((u8 *)p)) != 0) {
        return;
    }
    if (func_80161B84(((u8 *)p)) != 0) {
        return;
    }
    if (func_80161BE0(((u8 *)p)) != 0) {
        return;
    }
    if (func_801496D4(((u8 *)p)) != 0) {
        D_801812A4[*(u16 *)((u8 *)p)](((u8 *)p));
        ((void (*)(u8 *))func_80149704)(((u8 *)p));
        return;
    }

    switch (func_801619A4((s32 *)((u8 *)p))) {
    case 0:
    case 1:
    case 2:
    case 6:
        if (func_80149AA8((s32 *)((u8 *)p)) != 0) {
            D_801812A4[*(u16 *)((u8 *)p)](((u8 *)p));
            func_80149AD4((s32 *)((u8 *)p));
            return;
        }
        if (((s32(*)(s32 *))func_80149B54)((s32 *)((u8 *)p)) != 0) {
            D_801812A4[*(u16 *)((u8 *)p)](((u8 *)p));
            if (func_8014A738(((u8 *)p)) != 0) {
                ((void (*)(u8 *))func_8014A830)(((u8 *)p));
                return;
            }
            func_80149BAC((s32 *)((u8 *)p));
            return;
        }
        break;
    case 3:
        func_801498E0((s32 *)((u8 *)p));
        break;
    case 4:
        ((s32(*)(s32))func_80149954)((s32)((u8 *)p));
        break;
    case 5:
        if (func_80149A64((s32 *)((u8 *)p)) != 0) {
            D_801812A4[*(u16 *)((u8 *)p)](((u8 *)p));
            func_800CCCC0(((u8 *)p));
            return;
        }
        break;
    }

    if (func_80149CD4((s32)((u8 *)p)) != 0) {
        D_801812A4[*(u16 *)((u8 *)p)](((u8 *)p));
        func_8015E880((s32 *)((u8 *)p));
        return;
    }
    if (func_801488A8(((u8 *)p)) != 0) {
        D_801812A4[*(u16 *)((u8 *)p)](((u8 *)p));
        func_8015A230((s32 *)((u8 *)p));
        return;
    }

    if ((*(u32 *)(((u8 *)p) + 0x44) & 0x200) == 0 && *(u16 *)(((u8 *)p) + 0xD4) == 0x8000) {
        if (*(s32 *)(((u8 *)p) + 0x234) >= 3) {
            t = (s32)&D_800D5F44;
            if (*(s32 *)(((u8 *)p) + 0xD0) == t) {
                func_80154B4C(((u8 *)p), (s32)&D_800D5F34);
                goto after_b4c;
            }
        } else {
            t = (s32)&D_800D5F14;
            if (*(s32 *)(((u8 *)p) + 0xD0) == t) {
                func_80154B4C(((u8 *)p), (s32)&D_800D5F04);
                goto after_b4c;
            }
        }
        if ((((s32(*)())func_8005C49C)() & 0xF) == 0) {
            func_80154B4C(((u8 *)p), t);
        }
    }
after_b4c:

    if (*(u16 *)(((u8 *)p) + 0xB8) & 0x8000) {
        if ((*(u32 *)(((u8 *)p) + 0x44) & 0x200) == 0) {
            if (func_8016F1AC() != 0) {
                *(s32 *)(((u8 *)p) + 0x234) = 0;
                *(s32 *)(((u8 *)p) + 0x238) = 0;
            }
            switch (*(s32 *)(((u8 *)p) + 0x234)) {
            case 0:
                if ((*(s32 *)(((u8 *)p) + 0x238))++ >= 4) {
                    *(s32 *)(((u8 *)p) + 0x238) = 0;
                    *(s32 *)(((u8 *)p) + 0x234) = *(s32 *)(((u8 *)p) + 0x234) + 1;
                    func_80154150((s32)((u8 *)p), 1);
                    break;
                }
                func_80146DB8((s32 *)((u8 *)p), &(*(s32*)&D_80181208));
                func_80154190(((u8 *)p), 0);
                break;
            case 1:
                *(s32 *)(((u8 *)p) + 0x238) = 0;
                *(s32 *)(((u8 *)p) + 0x234) = *(s32 *)(((u8 *)p) + 0x234) + 1;
                func_80154150((s32)((u8 *)p), 0);
                break;
            case 2:
                if ((*(s32 *)(((u8 *)p) + 0x238))++ >= 2) {
                    if ((*(u32 *)(((u8 *)p) + 0x44) & 4) != 0) {
                        *(s32 *)(((u8 *)p) + 0x234) = 0;
                        *(s32 *)(((u8 *)p) + 0x238) = 0;
                        func_80154150((s32)((u8 *)p), 0);
                        break;
                    }
                    *(s32 *)(((u8 *)p) + 0x238) = 0;
                    *(s32 *)(((u8 *)p) + 0x234) = *(s32 *)(((u8 *)p) + 0x234) + 1;
                    func_80154150((s32)((u8 *)p), 2);
                    break;
                }
                func_80154190(((u8 *)p), 0);
                break;
            case 3:
                func_80147324(0x445);
                *(s32 *)(((u8 *)p) + 0x234) = *(s32 *)(((u8 *)p) + 0x234) + 1;
                func_80155440((s32 *)((u8 *)p));
                func_80154150((s32)((u8 *)p), 3);
                func_80154A74((s32)((u8 *)p), 0x13);
                break;
            case 4:
                break;
            default:
                break;
            }
        } else {
            func_80146DB8((s32 *)((u8 *)p), &(*(s32*)&D_80181208));
            func_80154150((s32)((u8 *)p), 5);
            func_80154A74((s32)((u8 *)p), 0x1C);
        }
    }

    if (*(s32 *)(((u8 *)p) + 0xB4) == (s32)&D_800D49F4) {
        ((void(*)(s32))func_80147A84)((s32)((u8 *)p));
        func_801473EC((s32 *)((u8 *)p));
        if ((D_800B99DA & 3) == 0) {
            func_8014C010((s32)((u8 *)p), 1);
        }
    }
    if (func_80161208((s32)((u8 *)p)) == 0) {
        ((void (*)(u8 *))func_801483E8)(((u8 *)p));
        func_80172590(((u8 *)p));
    }
}
