/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80175DA8 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef void (*code)(unsigned short *);
typedef struct { s32 g0; s32 pad[2]; } S_AF634;
typedef struct {
        u32 tag;     
        u32 code;    
        u16 x;       
        u16 y;       
        u32 uv;      
        u32 wh;      
    } Sp_80175DA8;
extern void func_800183E0(s32 a0);
extern u32 *func_8017742C(u32 *a0, s32 a1, s32 a2);
extern s32 func_8005A600(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

void func_80175DA8(param_1)
    u16 param_1;
{

    extern u8  D_8011F7F0;
    extern u8  D_800B9A13;
    extern S_AF634 D_800AF634[];
    extern S_AF634 D_800AF638[];
    extern u16 D_8018139C[];
    extern u16 D_801813EC[];
    extern u16 D_801813F8;
    extern u8  D_80181478[];
    extern u8  D_8018148C[];
    extern s32 D_801814A4[];
    extern u8  D_800D43D4;
    extern u8  D_800D4414;
    extern u8  D_800D45D4;

    u8 *base = &D_8011F7F0;
    u8 *s = base - 0x48;
    u16 *src = D_8018139C;
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
            *(u16 *)(q1 + 0x20) = D_801813F8;
            arg = (s32)&D_800D45D4;
        } else {
            u16 *tt = D_801813EC;
            s32 k = base[0x48];
            if (k != 0) {
                k--;
                tt += k;
            }
            *(u16 *)(q1 + 0x20) = *tt;
            arg = D_801814A4[base[0x48]];
        }
    }
    func_800183E0(arg);

    {
        u8 *q2 = *(u8 **)(s + (s16)param_1 * 4 + 0x28);
        t = (s32)(*(u16 *)(base + 0x2E) << 16);
        if (t != 0) {
            q2[0x49] = D_8018148C[t >> 20];
        } else {
            q2[0x49] = 0xA0;
        }
    }

    {
        u8 *q3 = *(u8 **)(s + (s16)param_1 * 4 + 0x28);
        v = *(u16 *)(base + 0x40);
        if (v < 100) {
            q3[0x5D] = D_80181478[v / 5];
        } else {
            q3[0x5D] = 0;
        }
    }

    fl = *(s16 *)(base + 0x1E) & 0x8000;
     

    __asm__("");
    arg = (s32)&D_800D43D4;
    if (fl != 0) {
        arg = (s32)&D_800D4414;
    }
    func_800183E0(arg);
}
