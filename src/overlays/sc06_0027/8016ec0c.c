/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016EC0C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
        /* 0x00 */ s16 x;
        /* 0x02 */ s16 y;
        /* 0x04 */ s32 u04;
        /* 0x08 */ s16 u08;
        /* 0x0A */ s16 u0A;
        /* 0x0C */ s16 u0C;
        /* 0x0E */ s16 u0E;
        /* 0x10 */ u8 r;
        /* 0x11 */ u8 g;
        /* 0x12 */ u8 b;
        /* 0x13 */ u8 pad13;
        /* 0x14 */ s32 u14;
        /* 0x18 */ u8 u18;
        /* 0x19 */ u8 pad19[3];
    } T8016EC0C;
extern void func_80017B98(void *a0);
extern u8 D_80181380[];
extern void func_8012A568(void (*a0)(void));

void func_8016EC0C(s32 a0, s32 a1)
{
    /* §100 draft-LOCAL type: a file-scope typedef is an EXEMPLAR-ONLY bank — extract_unit/
       remap_hseq carry only the BODY, so every sibling fails `T8016EC0C undeclared`
       (measured on ov_SC01_000). Block scope travels with the body; byte-neutral. */
 /* 0x1C */
    T8016EC0C s;
    u16 *p;
    s32 x;
    s32 y;
    s32 v;

    s.r = s.g = s.b = a1;
    s.u18 = D_80181380[*(u8 *)(a0 + 3)];
    s.u0C = 0x640;
    s.u0E = 0x1C8;
    s.u14 = 0;
    s.u08 = 0x28;
    s.u0A = 8;
    x = *(u16 *)(a0 + 4);
    s.x = x + 0x10;
    y = *(u16 *)(a0 + 6);
    s.u04 = 0x10;
    s.y = y;
    func_80017B98(&s);
    s.u08 = 8;
    y += 0xA;
    p = (u16 *)(a0 + 8);
    while (*p != 0xFFFF) {
        v = *p;
        switch (v) {
        case 0x1850:
        case 0x1858:
            s.x = x + 4;
            s.y = y - 7;
            break;
        case 0x3872:
            x += 2;
            p++;
            continue;
        default:
            s.x = x;
            s.y = y;
            x += 8;
            break;
        }
        s.u0C = *(u8 *)p + 0x500;
        s.u0E = (*p >> 8) + 0x100;
        p++;
        func_80017B98(&s);
    }
}
