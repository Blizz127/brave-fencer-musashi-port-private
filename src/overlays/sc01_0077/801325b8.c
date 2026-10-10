/* Overlay range [801325B8,8013277C) from MAIN.CD member 0012.
 * SHA256(span)=4d5e9f8d67646fdf60569c7cd1db10a35269af8983f8fcd94ab0b0038217268c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801325B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define gteMIMefunc func_8004806C
#define memcpy func_8005C324

/* func_801325B8 — shared body (overlay slot 0x80128158, h_exact 8fd22bf4). ONE source: instantiated by #include at each
 * member's site in address order; the members are recorded in config/dedup.us.yaml (Phase 35). */
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
