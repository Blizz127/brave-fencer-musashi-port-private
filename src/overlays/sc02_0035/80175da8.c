/* SC02.CD member35 [80175DA8,80176144): twin of main_0012 80175DA8 (src/overlays/main_0012/80175da8.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [80175DA8,80176144) from MAIN.CD member 0012.
 * SHA256(span)=45cd35c7f3cee1909a20b7e98cbcddfac8e045331074f2a9fb69d31e2bf166e2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175DA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
typedef struct { short vx, vy, vz, pad; } SVECTOR;
typedef void (*code)(unsigned short *);
typedef struct { s32 g0; s32 pad[2]; } S_AF634;
typedef struct {
        u32 tag;    /* 0x00 */
        u32 code;   /* 0x04 */
        u16 x;      /* 0x08 */
        u16 y;      /* 0x0A */
        u32 uv;     /* 0x0C */
        u32 wh;     /* 0x10 */
    } Sp_80175DA8;
void func_8012A568(void (*a0)(void));
extern void func_8012A568(void (*a0)(void));

typedef struct {
    SVECTOR v[4];               /* 0x00 */
    s32 f0, f1, f2, f3, f4, f5; /* 0x20..0x37 */
    u8  f6;                     /* 0x38 */
    u8  pad[7];                 /* -> 0x40 */
} Prim_8016E7C8_80175DA8;

   /* size 0x0C */
extern u32 *func_8017742C(u32 *a0, s32 a1, s32 a2);
extern s32 func_8005A600(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_800183E0(s32 a0);

  /* 0x14 */

void func_80175DA8(param_1)
    u16 param_1;
{

    extern u8  D_8011F7F0;
    extern u8  D_800B9A13;
    extern S_AF634 D_800AF634[];
    extern S_AF634 D_800AF638[];
    extern u16 D_80187B90[];
    extern u16 D_80187BE0[];
    extern u16 D_80187BEC;
    extern u8  D_80187C6C[];
    extern u8  D_80187C80[];
    extern s32 D_80187C98[];
    extern u8  D_800D43D4;
    extern u8  D_800D4414;
    extern u8  D_800D45D4;

    u8 *base = &D_8011F7F0;
    u8 *s = base - 0x48;
    u16 *src = D_80187B90;
    Sp_80175DA8 *p;
    s16 i;
    s32 arg;
    s32 t;
    s32 fl;
    u16 v;

    p = (Sp_80175DA8 *)(D_800AF638[(s16)param_1].g0 + D_800AF634[(s16)param_1].g0 * 4);
    *(Sp_80175DA8 **)(s + (s16)param_1 * 4 + 0x28) = p;
    i = 0;
    do {
        p->tag = ((u32)(p - 1) & 0xFFFFFF) | 0x4000000;
        p->code = *(u32 *)src;
        src += 2;
        if (i < 2) {
            p->x = *src++ + *(u16 *)(s + 0xC);
            p->y = *src++ + *(u16 *)(s + 0xE);
        } else if (i == 2) {
            p->x = *src++ + *(u16 *)(s + 0x10);
            p->y = *src++ + *(u16 *)(s + 0x12);
        } else {
            p->x = *src++ + *(u16 *)(s + 0x14);
            p->y = *src++ + *(u16 *)(s + 0x16);
        }
        p->uv = *(u32 *)src;
        src += 2;
        p->wh = *(u32 *)src;
        src += 2;
        p++;
        i++;
    } while (i < 5);

    *(u8 *)(s + 7) = D_800B9A13;
    p = (Sp_80175DA8 *)func_8017742C((u32 *)p,
                                     (s16)(*(u16 *)(s + 0x10) - 0x98),
                                     (s16)(*(u16 *)(s + 0x12) + 9));
    func_8005A600((s32)p, 0, 0, 0x16, 0);
    p->tag = ((u32)(p - 1) & 0xFFFFFF) | 0x2000000;
    *(Sp_80175DA8 **)(s + (s16)param_1 * 4 + 0x30) = p;
    p++;
    {
        s32 acc = D_800AF634[(s16)param_1].g0;
        D_800AF634[(s16)param_1].g0 =
            acc + (((s32)p - *(s32 *)(s + (s16)param_1 * 4 + 0x28)) >> 2);
    }

    p = *(Sp_80175DA8 **)(s + (s16)param_1 * 4 + 0x28);
    if (base[0x48] != 0) {
        *((u8 *)p + 0xD) = 0;
    } else {
        *((u8 *)p + 0xD) = 0xA0;
    }

    {
        u8 *q1 = *(u8 **)(s + (s16)param_1 * 4 + 0x28);
        *(u16 *)(q1 + 0x22) = 0x6CD6;
        if (base[0x48] & 0x80) {
            *(u16 *)(q1 + 0x20) = D_80187BEC;
            arg = (s32)&D_800D45D4;
        } else {
            u16 *tt = D_80187BE0;
            s32 k = base[0x48];
            if (k != 0) {
                k--;
                tt += k;
            }
            *(u16 *)(q1 + 0x20) = *tt;
            arg = D_80187C98[base[0x48]];
        }
    }
    func_800183E0(arg);

    {
        u8 *q2 = *(u8 **)(s + (s16)param_1 * 4 + 0x28);
        t = (s32)(*(u16 *)(base + 0x2E) << 16);
        if (t != 0) {
            q2[0x49] = D_80187C80[t >> 20];
        } else {
            q2[0x49] = 0xA0;
        }
    }

    {
        u8 *q3 = *(u8 **)(s + (s16)param_1 * 4 + 0x28);
        v = *(u16 *)(base + 0x40);
        if (v < 100) {
            q3[0x5D] = D_80187C6C[v / 5];
        } else {
            q3[0x5D] = 0;
        }
    }

    fl = *(s16 *)(base + 0x1E) & 0x8000;
    /* §5a zero-byte sched fence: without it sched1 hoists the `la D_800D43D4`
       into the lh's load-delay slot, dropping the target's nop (-1 ins). */
    __asm__("");
    arg = (s32)&D_800D43D4;
    if (fl != 0) {
        arg = (s32)&D_800D4414;
    }
    func_800183E0(arg);
}
