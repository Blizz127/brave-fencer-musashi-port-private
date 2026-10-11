/* Overlay range [80159C84,8015A1C8) from MAIN.CD member 0012.
 * SHA256(span)=27cf0012935325f2013089c596b11d30f08da8b2703bde12e38987e6c3b208c2.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80159C84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define rand func_8005C49C

/* File-scope declarations from the vendor translation unit. */
extern u16 D_800B99DA;

extern s32 func_80149FB0(s32 a0);

// @class: other
// @stuck: none — MATCH
/* (draft's standalone scalar typedefs stripped — the TU's common.h set is in scope; §8e splice) */

/* draft decl dropped — carried TU decl in scope (§8e splice reconcile) */
/* draft decl dropped — carried TU decl in scope (§8e splice reconcile) */


extern s32 rand(void);

/* canonical sigs (engine_core.h); arity-mismatched call sites use a fn-ptr cast (§17a-1) */
extern s32 func_80149D9C(s32 a0);
extern void func_80149FA8(void);
/* draft decl dropped — carried TU decl in scope (§8e splice reconcile) */
extern s32 func_80161B18(void *a0);
extern s32 func_80161B84(void *a0);
extern int func_80161BE0(void *a0);
extern s32 func_801496D4(void *a0);
extern void func_80149704(void);
extern s32 func_801619A4(s32 *a0);
extern s32 func_80149AA8(s32 *a0);
extern void func_80149AD4(s32 *a0);
extern s32 func_80149B54(s32 *a0);
extern s32 func_8014A738(void*);
extern void func_8014A830(void);
extern void func_80149BAC(s32 *a0);
extern s32 func_801498E0(s32 *a0);
extern s32 func_80149954(s32 a0);
extern s32 func_80149A64(s32 *a0);
extern void func_800CCCC0(u8 *a0);
extern s32 func_80149CD4(s32 a0);
extern void func_8015E880(s32 *a0);
extern s32 func_801488A8(u8 *a0);
extern void func_8015A230(s32 *a0);
extern void func_80154B4C(u8 *a0, s32 a1);
extern s32 func_8016F1AC(void);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80154190(u8 *a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80155440(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80147A84(s32 a0);
extern void func_801473EC(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern s32 func_80161208();
extern void func_801483E8(unsigned char*);
extern s32 func_80172590(u8 *a0);

void func_80159C84(u8 *p) {

    extern unsigned char D_8018FB0C;
    extern void (*D_8018FBA8[])(void *);
    extern s32 D_800D5F04;
    extern s32 D_800D5F14;
    extern s32 D_800D5F34;
    extern s32 D_800D5F44;
    extern s32 D_800D49F4;
    s32 t;

    if (func_80149D9C((s32)p) != 0) {
        D_8018FBA8[*(u16 *)p](p);
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
        D_8018FBA8[*(u16 *)p](p);
        ((void (*)(u8 *))func_80149704)(p);
        return;
    }

    switch (func_801619A4((s32 *)p)) {
    case 0:
    case 1:
    case 2:
    case 6:
        if (func_80149AA8((s32 *)p) != 0) {
            D_8018FBA8[*(u16 *)p](p);
            func_80149AD4((s32 *)p);
            return;
        }
        if (func_80149B54((s32 *)p) != 0) {
            D_8018FBA8[*(u16 *)p](p);
            if (((s32 (*)(u8 *))func_8014A738)(p) != 0) {
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
            D_8018FBA8[*(u16 *)p](p);
            func_800CCCC0(p);
            return;
        }
        break;
    }

    if (func_80149CD4((s32)p) != 0) {
        D_8018FBA8[*(u16 *)p](p);
        func_8015E880((s32 *)p);
        return;
    }
    if (func_801488A8(p) != 0) {
        D_8018FBA8[*(u16 *)p](p);
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
        if ((rand() & 0xF) == 0) {
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
                func_80146DB8((s32 *)p, (s32 *)&D_8018FB0C);
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
            func_80146DB8((s32 *)p, (s32 *)&D_8018FB0C);
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
    if (((s32 (*)(s32))func_80161208)((s32)p) == 0) {   /* §17a-1: canonical is (void); callee reads $a0 */
        ((void (*)(u8 *))func_801483E8)(p);
        func_80172590(p);
    }
}
