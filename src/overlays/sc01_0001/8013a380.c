/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013A380 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct Inner8013A4C4 {
    u8 pad28[0x28];
    s16 unk28;     /* 0x28 */
    s16 unk2A;     /* 0x2A */
};
struct S8013A4C4 {
    s16 unk0;      /* 0x0 */
    s16 unk2;      /* 0x2 */
    struct Inner8013A4C4 *unk4;  /* 0x4 */
    u8 padE[6];
    s16 unkE;      /* 0xE */
};
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_8011DA80[];
extern void func_8013A530();
extern void func_8013A448(void *a0);
extern void func_8013A4C4(struct S8013A4C4 *a0);

void func_8013A380(void) {
    s16 *p;
    s32 i;
    p = (s16 *)D_8011DA80;
    i = 0;
    do {
        if (p != (s16 *)0) {
            switch (*p) {
            case 2:
                ((void (*)(void *))func_8013A530)(p);
                break;
            case 1:
                func_8013A448(p);
                break;
            case 3:
                func_8013A4C4((struct S8013A4C4 *)p);
                break;
            }
        }
        i += 1;
        p += 8;
    } while (i < 2);
}
