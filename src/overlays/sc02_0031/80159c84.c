/* SC02 resident retail span [80159C84,8015A1C8). Offset 0x31B2C at base 80128158.
 * SHA256(span)=6813fdefa32f79957afdffc3d1d016d923e5395a7e2e3bbff2bdf2a1db54c10a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * the C is the Druthulu shared/ov func_80159C84 shape (h_exact e2cb2ce3) with its externs hoisted, rand bound to func_8005C49C, the dispatch table retargeted to D_8018730C, D_80181878 to D_80187270, D_800B99DA as u16, and the two switches lowered to 0x801B5C94 via --rodata-base; oracle MATCH 337/337.
 * Not MAIN10.
 */
#include "psx_types.h"

extern u16 D_800B99DA;
extern s32 D_80187270;
void func_801483E8();
void func_80149704();
void func_8014A830();
void func_80161208();
void func_80149D9C(void);
s32 func_8005C49C(void);
void func_80149FA8(void *p);
void func_80149FB0(s32 p);
s32 func_80161B18(void *p);
s32 func_80161B84(void *p);
s32 func_80161BE0(void *p);
s32 func_801496D4(void *p);

extern s32 D_800D5F04;
extern s32 D_800D5F14;
extern s32 D_800D5F34;
extern s32 D_800D5F44;
extern s32 D_800D49F4;

void func_80159C84(u8 *p) {

    extern void (*D_8018730C[])(void *);  /* canonical */
    s32 t;

    if (((s32 (*)(void))func_80149D9C)() != 0) {
        D_8018730C[*(u16 *)p](p);
        ((void (*)(u8 *))func_80149FA8)(p);
        return;
    }

    func_80149FB0((s32)p);
    if (func_80161B18(p) != 0) {
        return;
    }
    if (func_80161B84(p) != 0) {
        return;
    }
    if (func_80161BE0(p) != 0) {
        return;
    }
    if (func_801496D4(p) != 0) {
        D_8018730C[*(u16 *)p](p);
        ((void (*)(u8 *))func_80149704)(p);
        return;
    }

    switch (func_801619A4((s32 *)p)) {
    case 0:
    case 1:
    case 2:
    case 6:
        if (func_80149AA8((s32 *)p) != 0) {
            D_8018730C[*(u16 *)p](p);
            func_80149AD4((s32 *)p);
            return;
        }
        if (func_80149B54((s32 *)p) != 0) {
            D_8018730C[*(u16 *)p](p);
            if (func_8014A738(p) != 0) {
                ((void (*)(u8 *))func_8014A830)(p);
                return;
            }
            func_80149BAC((s32 *)p);
            return;
        }
        break;
    case 3:
        func_801498E0((s32 *)p);
        break;
    case 4:
        func_80149954((s32)p);
        break;
    case 5:
        if (func_80149A64((s32 *)p) != 0) {
            D_8018730C[*(u16 *)p](p);
            func_800CCCC0(p);
            return;
        }
        break;
    }

    if (func_80149CD4((s32)p) != 0) {
        D_8018730C[*(u16 *)p](p);
        func_8015E880((s32 *)p);
        return;
    }
    if (func_801488A8(p) != 0) {
        D_8018730C[*(u16 *)p](p);
        func_8015A230((s32 *)p);
        return;
    }

    if ((*(u32 *)(p + 0x44) & 0x200) == 0 && *(u16 *)(p + 0xD4) == 0x8000) {
        if (*(s32 *)(p + 0x234) >= 3) {
            t = (s32)&D_800D5F44;
            if (*(s32 *)(p + 0xD0) == t) {
                func_80154B4C(p, (s32)&D_800D5F34);
                goto after_b4c;
            }
        } else {
            t = (s32)&D_800D5F14;
            if (*(s32 *)(p + 0xD0) == t) {
                func_80154B4C(p, (s32)&D_800D5F04);
                goto after_b4c;
            }
        }
        if ((func_8005C49C() & 0xF) == 0) {
            func_80154B4C(p, t);
        }
    }
after_b4c:

    if (*(u16 *)(p + 0xB8) & 0x8000) {
        if ((*(u32 *)(p + 0x44) & 0x200) == 0) {
            if (func_8016F1AC() != 0) {
                *(s32 *)(p + 0x234) = 0;
                *(s32 *)(p + 0x238) = 0;
            }
            switch (*(s32 *)(p + 0x234)) {
            case 0:
                if ((*(s32 *)(p + 0x238))++ >= 4) {
                    *(s32 *)(p + 0x238) = 0;
                    *(s32 *)(p + 0x234) = *(s32 *)(p + 0x234) + 1;
                    func_80154150((s32)p, 1);
                    break;
                }
                func_80146DB8((s32 *)p, (s32 *)&D_80187270);
                func_80154190(p, 0);
                break;
            case 1:
                *(s32 *)(p + 0x238) = 0;
                *(s32 *)(p + 0x234) = *(s32 *)(p + 0x234) + 1;
                func_80154150((s32)p, 0);
                break;
            case 2:
                if ((*(s32 *)(p + 0x238))++ >= 2) {
                    if ((*(u32 *)(p + 0x44) & 4) != 0) {
                        *(s32 *)(p + 0x234) = 0;
                        *(s32 *)(p + 0x238) = 0;
                        func_80154150((s32)p, 0);
                        break;
                    }
                    *(s32 *)(p + 0x238) = 0;
                    *(s32 *)(p + 0x234) = *(s32 *)(p + 0x234) + 1;
                    func_80154150((s32)p, 2);
                    break;
                }
                func_80154190(p, 0);
                break;
            case 3:
                func_80147324(0x445);
                *(s32 *)(p + 0x234) = *(s32 *)(p + 0x234) + 1;
                func_80155440((s32 *)p);
                func_80154150((s32)p, 3);
                func_80154A74((s32)p, 0x13);
                break;
            case 4:
                break;
            default:
                break;
            }
        } else {
            func_80146DB8((s32 *)p, (s32 *)&D_80187270);
            func_80154150((s32)p, 5);
            func_80154A74((s32)p, 0x1C);
        }
    }

    if (*(s32 *)(p + 0xB4) == (s32)&D_800D49F4) {
        func_80147A84((s32)p);
        func_801473EC((s32 *)p);
        if ((D_800B99DA & 3) == 0) {
            func_8014C010((s32)p, 1);
        }
    }
    if (((s32 (*)(s32))func_80161208)((s32)p) == 0) {  /* §17a-1 */
        ((void (*)(u8 *))func_801483E8)(p);
        func_80172590(p);
    }
}
