/* Main-exec range [80039B20,80039C5C) from the SLUS executable.
 * SHA256(span)=bf46d17a0ebb02ea228a545c7de09963b48cd0c71de6cf222c28707ab413430b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80039B20 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 D_80073140[][1];  
extern u8 *D_800762B0;
extern s32 D_800C7D20;
extern u8 D_800762B4[];
extern s32 D_800A2B98;
extern u8 D_800C6DD0[];
extern u8 D_800C6DD4[];

void func_80039B20(s32 *arg0, s16 arg1) {
    register s32 i __asm__("$6");
    register s32 off __asm__("$7");
    u8 c;
    s32 t1;

    i = 0;
    t1 = (s32)arg0 + arg1 * 26;
    c = *(u8 *)((*arg0)++);
    off = 0;
    do {
        if (*(u8 *)(t1 + i + 0x23) != 0 && (*(s16 *)(D_800C6DD4 + off) == c)) {
            u8 *p = D_800C6DD0 + (s16)i * 0x60;
            if (p[0x5A] != 0) {
                s16 f6 = *(s16 *)(p + 6);
                s32 off2 = f6 * 26;
                s32 base = *(s32 *)(p + 0x50);
                *(u8 *)(base + off2 + (s16)i + 0x23) = 0;
                p[0x5A] = 0;
            }
            {
                s32 base1 = (s32)D_80073140;
                __asm__ __volatile__("" : "=r"(base1) : "0"(base1));
                D_800C7D20 &= ~((s32 *)base1)[i];
                D_800A2B98 |= ((s32 *)base1)[i];
            }
            D_800762B0[i] = 2;
            D_800762B4[i] = 0;
        }
        i++;
        off += 0x60;
    } while (i < 0x10);
}
