/* Exact retail word export for [80033398,8003350C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80033398 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct Ent30D80 {
     s32 unk00;
     u8 pad04[6];
     u16 unk0A;
     u8 pad0C[0x34];
     void (*unk40)(s32, s32);
     s32 unk44;
     u8 pad48[6];
     u8 unk4E;
     u8 pad4F;
     u8 unk50;
     u8 unk51;
} Ent30D80;
extern void func_80033398(u32);
s32 aF800301A4(void) __asm__("func_800301A4");
extern void func_800301A4(void);
struct Ent30D80;
extern u16 D_800A46E8[];
extern void func_80030D80(Ent30D80 *arg0, s16 arg1);
extern void func_80034650(u8 *a0, s32 a1);

void func_80033398(u32 arg0)
{
    






    register s32 zr __asm__("$0");
    u32 s7v;
    u8 *s5v;
    s32 s4v;
    u32 s6v;
    u8 *fpv;
    register u8 *s3v __asm__("$19");
    u8 *s2v;
    register s32 s1v __asm__("$17");
    register u8 *s0v __asm__("$16");
    s32 t0;

    s7v = arg0 + zr;
    s5v = (u8 *)D_800A46E8;
    s4v = 0;
    s6v = arg0 >> 16;
    fpv = s5v + 0x2A0;
    s3v = s5v + 6;

    for (; s4v < 8; s3v += 0x54, s5v += 0x54) {
        if ((*(u16 *)s5v & 0x3F) == 1 &&
            *(u16 *)(s3v - 2) == (u16)s7v &&
            (s6v == 0 || *(u16 *)s3v == s6v)) {
            s2v = (u8 *)D_800A46E8 + (u32)(u16)s4v * 0x54;
            t0 = *(u16 *)s2v & 0x3F;
            switch (t0) {
            case 1:
                s1v = 0;
                s0v = fpv;
                for (; s1v < 8; s1v++, s0v += 0x54) {
                    u8 *p = s2v + s1v;
                    if (p[0xE] != 0) {
                        p[0xE] = 0;
                        *(u32 *)(s0v + 0x40) = 0;
                        if (s0v[0x4E] != 0) {
                            func_80030D80((Ent30D80 *)s0v, 0);
                        }
                    }
                }
                *(u16 *)s2v = 0;
                break;
            case 5:
                func_80034650(s2v, 0);
                break;
            default:
                s4v++;
                continue;
            }
        }
        s4v++;
    }
}
