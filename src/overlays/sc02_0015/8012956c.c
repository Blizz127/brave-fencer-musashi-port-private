/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012956C - byte-exact against retail at -O2 (tools/register_match.py). */
#define GsSortBg func_8005080C
#define GsSortFastBg func_80051044
typedef void (*code)(unsigned short *);
typedef struct { s32 a, b, c, d; } Blk16_956C;
typedef struct {
    u8 pad0[0x1C];
    s16 f1C;
    s16 f1E;
    u8 pad20[0x14];
    u16 f34;
    u16 f36;
    u16 f38;
    u16 f3A;
    u8 pad3C[2];
    s16 f3E;
    u16 f40;
    u16 f42;
    u8 pad44[0x10];
} Ent_956C;
extern s32 D_8018EFF4;
extern s16 D_80114EE0;
extern u8 D_800B9A78;
extern void func_801299C8();
extern void func_80015B6C(s32, s16, s32, s16, s32, s32, s32, s32, s32, s32);
extern void GsSortBg(s32 *, void *, u16, s32 *);
extern void GsSortFastBg(s32 *, void *, u16, s32 *);

void func_8012956C(void) {

    extern s16 D_80114EE0;
    extern u8 D_800B9A78;
    extern u8 D_8018EFF5[];
    extern u8 D_8018EFF6[];
    extern u8 D_8018EFF8[];
    extern u8 D_8018EFF9[];
    extern u8 D_8018EFFA[];
    extern u8 D_80190610;
    extern u8 D_800AF630[];
    extern u8 D_800A6518[];
    register s32 *sp10 __asm__("$21");
    register u8 *afbase __asm__("$22");
    register s32 *sp0 __asm__("$23");
    Ent_956C *base;
    s32 i;
    s16 a1;
    register u32 temp_a3 __asm__("$7");
    register u32 arg0 __asm__("$4");
    register u32 s __asm__("$2");
    register u32 s2 __asm__("$3");
    register u32 t6 __asm__("$8");
    s32 code;

    sp10 = (s32 *)0x1F800010;
    sp0 = (s32 *)0x1F800000;
    afbase = (u8 *)&D_800AF630;
    if (D_80114EE0 == 0) {
        return;
    }
    base = (Ent_956C *)&D_800B9A78;
    __asm__("" : "=r"(base) : "0"(base));
    i = 0;
    do {
        s32 idx = i * 8 + 4;
        code = base->f34;
        if (code == 0x7FFE) {
            goto case_7FFE;
        }
        if (code < 0x7FFF) {
            a1 = i + 3;
            if (code == 0x7FFD) {
                goto case_7FFD;
            }
            goto do_default;
        }
        a1 = i + 3;
        if (code != 0x7FFF) {
            goto do_default;
        }
        goto next;
    case_7FFD:
        if (i == 0) {
            func_801299C8(D_80190610, 1, base);
        }
        func_80015B6C(-0xA0, -0x74, 0x140, 0x8C,
                      D_8018EFF8[0], D_8018EFF8[1], D_8018EFF8[2],
                      D_8018EFF8[4], D_8018EFF8[5], D_8018EFF8[6]);
        func_80015B6C(-0xA0, 0x18, 0x140, 0x3C,
                      D_8018EFF8[4], D_8018EFF8[5], D_8018EFF8[6],
                      D_8018EFF8[8], D_8018EFF8[9], D_8018EFF8[0xA]);
        func_80015B6C(-0xA0, 0x54, 0x140, 0x28,
                      D_8018EFF8[8], D_8018EFF8[9], D_8018EFF8[0xA],
                      D_8018EFF8[0xC], D_8018EFF8[0xD], D_8018EFF8[0xE]);
        goto next;
    case_7FFE:
        func_801299C8(D_80190610, (s16)(i * 2), base);
        func_80015B6C(-0xA0, *(s16 *)&base->f3A, 0x140, base->f3E,
                      ((u8 *)&D_8018EFF4)[idx], D_8018EFF5[idx], D_8018EFF6[idx],
                      D_8018EFF8[idx], D_8018EFF9[idx], D_8018EFFA[idx]);
        goto next;
    do_default:
        __asm__("");
        arg0 = D_80190610;
        s = base->f40;
        temp_a3 = base->f38;
        s += temp_a3;
        base->f1C = s;
        s2 = base->f42;
        t6 = base->f3A;
        s2 += t6;
        base->f1E = s2;
        ((void (*)(s32, s32, void *, s32))func_801299C8)(arg0, a1, base, temp_a3);
        *(Blk16_956C *)sp0 = *(Blk16_956C *)base;
        {
            s32 *dst = sp10;
            s32 *src = (s32 *)((u8 *)base + 0x10);
            s32 *end = (s32 *)((u8 *)base + 0x30);
            do {
                *(Blk16_956C *)dst = *(Blk16_956C *)src;
                src += 4;
                dst += 4;
            } while (src != end);
            *dst = *src;
            sp10[5] = (s32)sp0;
            if (base->f36 == 0) {
                GsSortFastBg(sp10, &D_800A6518[(*(u16 *)(afbase + 0xA3D2)) * 0x14], base->f34, dst);
            } else {
                GsSortBg(sp10, &D_800A6518[(*(u16 *)(afbase + 0xA3D2)) * 0x14], base->f34, dst);
            }
        }
    next:
        base += 1;
        i += 1;
    } while (i < 2);
}
