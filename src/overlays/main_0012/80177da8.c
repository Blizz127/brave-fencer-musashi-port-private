/* Overlay range [80177DA8,80177EA4) from MAIN.CD member 0012.
 * SHA256(span)=bb577e1f8b8414c92759c3efb4d346d279dcd474ddf760bccb3b21baff22bfbf.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80177DA8 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef unsigned int uint;

void func_80177DA8(p, v, idx)
u8 *p;
u32 v;
s16 idx;
{

    extern u8 D_80181B64[];
    u8 *r;
    u16 c;
    u16 flag;
    u32 n;
    u8 m;
    s16 i;
    u8 t;
    u32 x;
    u32 uv;
    u32 w1;
    u32 w2;

    flag = 0x100;
    i = 0;
    t = D_80181B64[idx];
    c = (t << 6) | 0x4016;
    *(u16 *)(p + 0xE) = c;
    p += 0x14;
    *(u16 *)(p + 0xE) = c;
    p += 0x14;
    r = p;
    do {
        n = (v << 16) >> 28;
        m = n;
        if (n != 0 || i == 2 || i == 0xFF) {
            flag = 0;
        }
        v <<= 4;
        i++;
        *(s16 *)(r + 0xA) = flag | (*(s16 *)(r + 0xA) & ~0x100);
        *(u8 *)(r + 0xC) = m * 8 + 8;
        r += 0x14;
    } while (i < 3);
    *(u16 *)(p + 0xE) = c;
    p += 0x14;
    *(u16 *)(p + 0xE) = c;
    p += 0x14;
    *(u16 *)(p + 0xE) = c;
    p += 0x14;
    x = ((t << 6) | 0x4016) << 16;
    uv = idx << 4;
    w1 = uv | 0x1000;
    *(u32 *)(p + 0xC) = x | w1;
    w2 = uv | 0x1008;
    *(u32 *)(p + 0x20) = x | w2;
}


 

uint *func_80177EA4(uint *param_1, int param_2, uint param_3, int param_4)
{
    uint uVar1;
    register int iVar2 __asm__("$4");
    register uint *p1 __asm__("$9");
    register uint *puVar3 __asm__("$8");
    register int iVar4 __asm__("$10");
    register uint uVar5 __asm__("$11");
    register uint mask __asm__("$12");
    register int nx __asm__("$2");
    register int p4s __asm__("$7");
    int cont;
    p1 = param_1; uVar5 = 0x1000000; iVar4 = 0; mask = 0xffffff;
    p4s = param_4 << 0x10;
    puVar3 = p1 + 3;
    do {
        register uint c74 __asm__("$4");
        register uint c3 __asm__("$3");
        register uint m __asm__("$2");
        c74 = 0x74808080;
        m = (uint)(p1 + -5) & mask;
        __asm__ __volatile__("" : "=r"(m) : "0"(m));
        c3 = 0x3000000;
        *p1 = m | c3;
        puVar3[-2] = c74;
        if ((short)iVar4 != 0) {
            register int six __asm__("$2");
            six = 6;
            if ((short)iVar4 == six) { iVar2 = 1; uVar5 = 0; }
            else {
                register int t __asm__("$2");
                t = param_2 >> 0x10 & 0xf;
                iVar2 = t + 1;
                param_2 = param_2 << 4;
            }
            {
                register int iv2c __asm__("$3");
                register int one __asm__("$2");
                iv2c = iVar2;
                __asm__ __volatile__("" : "=r"(iv2c) : "0"(iv2c));
                one = 1;
                if (iv2c != one) uVar5 = 0;
            }
            uVar1 = p4s | (param_3 & 0xffff) | uVar5;
        } else { iVar2 = 0; uVar1 = p4s | (param_3 & 0xffff); }
        puVar3[-1] = uVar1;
        __asm__ __volatile__("" : : "r"(iVar2) : "memory");
        {
            register uint c6b __asm__("$3");
            register uint r __asm__("$2");
            c6b = 0x6b564000;
            r = (uint)(iVar2 << 3) | c6b;
            *puVar3 = r;
        }
        puVar3 = puVar3 + 5; p1 = p1 + 5; param_3 = param_3 + 8;
        {
            register int sx __asm__("$2");
            nx = iVar4 + 1;
            iVar4 = nx;
            sx = nx << 0x10;
            cont = (sx >> 0x10) < 7;
        }
    } while (cont);
    return p1;
}
