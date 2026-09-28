/* Exact retail word export for [8002CDD8,8002CFE4); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002CDD8 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 D_800A4638;
extern u16 D_800A4F22;
extern s16 D_8006A990;
extern u8  D_800A4EE6;
extern u16 D_800A4EE0;
extern u16 D_800A4EE2;
extern u16 D_800A4EE4;
extern u8  D_800A4F16;
extern u8  D_800A4EFE[];
extern u16 D_800A4E8E;
extern u16 D_800A4E8A;
extern s16 D_800A4E86;
extern s8  D_800A4F17;
extern u8  D_800A4F18;
extern u8  D_8006AEF4;

extern void func_8002D904(s32);
extern s32  func_8003D25C(s32, s32, u8 *);
extern void func_80037FC4(void);
extern void func_8002EC10(void);
extern s32  func_8003836C(s32 a0);
extern void func_8002CFE4(void);
extern s32  func_8003C4F0(s32);

void func_8002CDD8(void)
{
    s32 *ctr;
    u16 tmp;
    u16 cur;
    u16 tgt;
    u8  fl;
    s16 t;

    ctr = &D_800A4638;
    tmp = D_800A4F22;
    *ctr = *ctr + 1;
    if (tmp != 0) {
        D_8006A990 = tmp;
        func_8002D904(tmp);
        D_800A4F22 = 0;
    }

    fl = D_800A4EE6;
    if (fl & 1) {
        tgt = D_800A4EE4;
        cur = D_800A4EE0;
        D_800A4F16 = 1;
        if (tgt < cur) {
            D_800A4EE0 = cur - D_800A4EE2;
            if (tgt >= D_800A4EE0) {
                D_800A4EE0 = tgt;
                D_800A4EE6 = fl & 0xFE;
            }
        } else {
            D_800A4EE0 = cur + D_800A4EE2;
            if (D_800A4EE0 >= tgt) {
                D_800A4EE0 = tgt;
                D_800A4EE6 = fl & 0xFE;
            }
        }
    }

    func_8003D25C(0, 0x17, D_800A4EFE);

    if (D_800A4E8E & 8) {
        func_80037FC4();
        t = *(s16 *)&D_800A4E8A;
        if (t != 0) {
            t--;
            D_800A4E8A = t;
            if (t == 0) {
                func_8002EC10();
            }
        }
        if ((s16)func_8003836C(D_800A4E86) == 0) {
            D_800A4E8E &= 0xFFF7;
        }
    }

    if (*(u8 *)&D_800A4F17 == 0) {
        D_800A4F18 = 0;
        func_8002CFE4();
    } else {
        D_800A4F18 = 1;
    }

    if ((D_8006AEF4 & 1) && !(D_8006AEF4 & 2)) {
        if (func_8003C4F0(0) != 0) {
            D_8006AEF4 &= 0xFE;
        }
    }
}
