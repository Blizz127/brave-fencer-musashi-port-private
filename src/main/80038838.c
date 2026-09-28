/* Exact retail word export for [80038838,800388E8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80038838 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

void func_80038838(void *arg0)
{
    register unsigned char *a3 asm("$7");
    register unsigned char *a1 asm("$5");
    register unsigned char *v1;
    register unsigned char *v0 asm("$2");
    register int a2 asm("$6");
    register int v0_c;
    register int const1 asm("$8");
    register int const2 asm("$9");
    register int const3 asm("$3");

    a3 = (unsigned char *)arg0 + 0x1A;
    a2 = 0;
    const1 = 0x40;
    const2 = 0x7F;
    a1 = (unsigned char *)arg0 + 0x1B;

    do {
        v1 = a3 + 0x9;
        v0_c = 0xF;
        a3[0x0] = a2;
        *(unsigned short *)(a1 + 0x1) = const1;
        a1[0x3] = const1;
        a1[0x6] = 0;
        a1[0x0] = const2;

        do {
            v1[0x0] = 0;
            v0_c--;
            v1++;
        } while (v0_c >= 0);

        a2++;
        a1 += 0x1A;
        a3 += 0x1A;
    } while (a2 < 0x10);

    a2 = 0;
    const3 = 0x4000;
    v0 = (unsigned char *)arg0;
    do {
        v0[0x18] = 0;
        *(unsigned short *)(v0 + 0x12) = const3;
        v0 += 0x8;
        a2++;
    } while (a2 <= 0);

    *(int *)((unsigned long)arg0 + 0x8) = 1;
    *(int *)((unsigned long)arg0 + 0x1D0) = 0xE10;
    *(int *)((unsigned long)arg0 + 0x1D4) = 0xE10;
    *(int *)((unsigned long)arg0 + 0x1CC) = 0xE10;
    *(unsigned char *)((unsigned long)arg0 + 0x1F4) = 0;
    *(unsigned short *)((unsigned long)arg0 + 0x1E4) = 0x78;
    *(unsigned char *)((unsigned long)arg0 + 0x1F7) = 0;
    *(unsigned char *)((unsigned long)arg0 + 0x1F8) = 0;
    *(unsigned char *)((unsigned long)arg0 + 0x1F9) = 0;
    *(unsigned char *)((unsigned long)arg0 + 0x1FA) = 0;
    *(unsigned char *)((unsigned long)arg0 + 0x1F6) = 0;
}
