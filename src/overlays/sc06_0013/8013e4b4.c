/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013E4B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u16 guard;  /* +0 */
    u16 pad;    /* +2 */
    u16 field;  /* +4 */
    u8  rest[14]; /* +6 .. +0x14 */
} Ent;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012C750(s32 a0);
extern u8 *D_801274C8;
extern void *D_801274CC;

void func_8013E4B4(void) {
    u8 *s0;
    Ent *p;
    s32 i;
    s0 = D_801274C8;
    if (s0 != 0) {
        if (*(u16 *)(s0 + 6) != 0) {
            do {
                func_8012C750(s0);
                s0 += 0x14;
            } while (*(u16 *)(s0 + 6) != 0);
        }
    }
    s0 = (u8 *)D_801274CC;
    if (s0 != 0) {
        p = (Ent *)(s0 + 6);
        for (i = 0; p[i].guard != 0; i++) {
            p[i].field &= 0x7FFF;
        }
    }
}
