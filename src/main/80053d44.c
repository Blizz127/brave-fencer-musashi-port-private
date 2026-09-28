/* Exact retail word export for [80053D44,80053E28); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80053D44 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct {
    u32 flags;
    u16 f4, f6, f8, fA;
    u32 *fC;
    u16 f10, f12, f14, f16;
    u32 *f18;
} Hdr;
void func_80053D44(u32 *p, Hdr *h)
{
    u32 *q;
    u32 flag;

    h->flags = flag = *p;
    if ((flag >> 3) & 1) {
        p++;
        q = p + (*p >> 2);
        p++;
        h->f10 = *p;
        h->f12 = ((u16 *)p)[1];
        p++;
        h->f14 = *p;
        h->f16 = ((u16 *)p)[1];
        p++;
        h->f18 = p;
        q++;
        h->f4 = *q;
        h->f6 = ((u16 *)q)[1];
        q++;
        h->f8 = *q;
        h->fA = ((u16 *)q)[1];
        q++;
        h->fC = q;
    } else {
        p += 2;
        h->f4 = *p;
        h->f6 = ((u16 *)p)[1];
        p++;
        h->f8 = *p;
        h->fA = ((u16 *)p)[1];
        p++;
        h->fC = p;
    }
}
