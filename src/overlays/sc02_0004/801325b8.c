/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
#define memcpy func_8005C324
/* func_801325B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#define gteMIMefunc func_8004806C
extern void *memcpy(void *, const void *, unsigned int);
extern void *memcpy(void *, const void *, u32);
extern void gteMIMefunc();

void func_801325B8(int dst, int src, int m0, int mm, int arg5)
{
    register int p __asm__("$4");
    register int m __asm__("$16");
    register int n __asm__("$17");
    register int dv __asm__("$18");
    int sv;
    int ofs;
    int c;
    m = m0;
    p = src;
    if (*(int *)(p + 4) == 1) {
        sv = *(int *)(p + 0xC);
    } else {
        ofs = (int)((*(unsigned int *)(p + 0xC) >> 2) << 2) + 0xC;
        sv = p + ofs;
    }
    p = dst;
    sv += *(int *)(m + 8) * 8;
    if (*(int *)(p + 4) == 1) {
        dv = *(int *)(p + 0xC);
    } else {
        ofs = (int)((*(unsigned int *)(p + 0xC) >> 2) << 2) + 0xC;
        dv = p + ofs;
    }
    c = *(int *)(m + 8);
    dv += c * 8;
    n = *(int *)(m + 0xC);
    m += 0x10;
    memcpy(dv, sv, n * 8);
    gteMIMefunc(dv, m, n, arg5);
    if (mm != 0) {
        m = mm;
        p = src;
        if (*(int *)(p + 4) == 1) {
            sv = *(int *)(p + 0x14);
        } else {
            ofs = (int)((*(unsigned int *)(p + 0x14) >> 2) << 2) + 0xC;
            sv = p + ofs;
        }
        p = dst;
        sv += *(int *)(m + 8) * 8;
        if (*(int *)(p + 4) == 1) {
            dv = *(int *)(p + 0x14);
        } else {
            ofs = (int)((*(unsigned int *)(p + 0x14) >> 2) << 2) + 0xC;
            dv = p + ofs;
        }
        c = *(int *)(m + 8);
        dv += c * 8;
        n = *(int *)(m + 0xC);
        m += 0x10;
        memcpy(dv, sv, n * 8);
        gteMIMefunc(dv, m, n, arg5);
    }
}
