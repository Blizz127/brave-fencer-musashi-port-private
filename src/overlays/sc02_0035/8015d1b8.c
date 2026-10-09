/* SC02.CD member35 [8015D1B8,8015D380): twin of main_0012 8015D1B8 (src/overlays/main_0012/8015d1b8.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [8015D1B8,8015D380) from MAIN.CD member 0012.
 * SHA256(span)=81db4d4bfb325b0f3c05091d15903c66be41d0374cfc347a7acd016774ec565f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015D1B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 func_80149FB0(s32);
extern void func_80147324(s32 a0);
extern u16  func_80148800(s32 *a0);
extern void func_80149724(s32 *);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146DB8(s32*, s32*);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_8014FA04(s32);
extern void func_8014E6A0(void);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void*);
extern void func_8015D380(s32);
extern s32  func_801725F4(u8 *a0);


void func_8015D1B8(s32 *a0)
{

    extern void (*D_80186B6C[])(void*);
    extern s32 D_80186D4C;
    extern s32 D_80186D50;
    extern s32 D_80186D94;
    extern s32 D_800D4C14;
    s32 sum;
    s32 keep;
    s32 obj;
    s16 cur;
    s16 prev;
    s16 d;
    s32 off;
    s32 *p;
    s32 dummy[2]; /* L1: dead, but its stack slot is what makes the frame 0x38 */

    ((void (*)(void))func_80149FB0)();
    obj = *(s32 *)((u8 *)a0 + 0x20);
    sum = *(u16 *)(obj + 0x10) + *(u16 *)((u8 *)a0 + 0x236);
    *(u16 *)(obj + 0x10) = sum & 0xFFF;
    keep = sum; /* L2: AFTER the store — this is what keeps the $s0 copy alive */

    cur = *(s16 *)(*(s32 *)((u8 *)a0 + 0x20) + 0x10);
    prev = *(s16 *)((u8 *)a0 + 0x244);
    if (cur - prev >= 0) {
        d = cur - prev;
    } else {
        d = prev - cur;
    }
    if (d > 0x800) {
        func_80147324(0x5E9);
    }
    *(u16 *)((u8 *)a0 + 0x244) = *(u16 *)(*(s32 *)((u8 *)a0 + 0x20) + 0x10);

    if (func_80148800(a0) & 0x40) {
        ((void (**)(s32*))D_80186B6C)[*(u16 *)a0](a0);
        ((void (*)(s32 *))func_80149724)(a0);
        func_80154274(a0, (s32)&D_800D4C14);
        func_80146E90(a0, 0x10);
        {
            u32 t = keep & 0xFFF; /* L3: unsigned value, signed guard -> bgez + srl */
            if ((s32)t < 0) {
                t += 0x1FF;
            }
            p = &D_80186D94; /* L4 + scheduling: the `la` must precede the srl/sll pair */
            off = (t >> 9) * 8;
        }
        *p = *(s32 *)((u8 *)&D_80186D4C + off);
        ((void (*)(s32 *, s32))func_80146DB8)(a0, (s32)(p - 2)); /* 0x801893D8 == &D_80186D94[-2] (no label there) */
        func_801477E8(a0, *(s32 *)((u8 *)&D_80186D50 + off));
        func_80147324(0x5EA);
    } else {
        ((void (*)(s32 *))func_8014FA04)(a0);
        if (((s32 (*)(s32 *))func_8014E6A0)(a0) == 0) {
            ((void (**)(s32*))D_80186B6C)[*(u16 *)a0](a0);
            func_80147078(a0, 0);
            ((void (*)(s32 *))func_80159B70)(a0);
        } else {
            ((void (*)(s32 *))func_8015D380)(a0);
            func_801725F4(a0);
        }
    }
}
