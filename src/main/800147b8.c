/* Native retail instruction export [800147B8,80014928).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Retail [800147B8,80014928): initialize paired draw/display environments.
 * GCC 2.7.2 / ASPSX 2.56 -O2 -G0, link base 800147B8: exact 92/92 words.
 * Empty constraints preserve the initial height in two word-sized values and
 * retain retail tail scheduling. Register bindings and constraints emit no
 * instruction assembly; they do not claim original source spelling.
 */
extern unsigned char D_800AF630[];
extern unsigned short D_800AF7BC, D_800AF7BE;
extern short D_800AF672, D_800AF670, D_800AF6CC, D_800AF6CE;
extern short D_800AF6D6, D_800AF6D4, D_800AF67A, D_800AF678;
extern unsigned char D_800AF6DA, D_800AF67E, D_800AF6DC, D_800AF680;
extern void func_80058A4C(void *, int, int, int, int);
extern void func_80058B04(void *, int, int, int, int);
extern void func_80014960(void);
void func_800147B8(void)
{
    unsigned char *base = D_800AF630;
    unsigned int original = D_800AF7BE;
    int offset;
    register int y __asm__("$5");
    __asm__("" : "=r"(offset), "=r"(original) : "0"(original), "1"(original));
    if (offset == 480) offset = 0;
    func_80058A4C(base + 0x38, 0, 10, D_800AF7BC, original - 20);
    func_80058B04(base + 0x14C, 0, 0, D_800AF7BC, D_800AF7BE);
    func_80058A4C(base + 0x94, 0, offset + 10, D_800AF7BC, D_800AF7BE - 20);
    func_80058B04(base + 0x160, 0, offset, D_800AF7BC, D_800AF7BE);
    {
    register unsigned int width __asm__("$3") = D_800AF7BC;
    register unsigned int height __asm__("$4") = D_800AF7BE;
    register int compare __asm__("$2");
    width >>= 1;
    D_800AF672 = height >> 1;
    __asm__ volatile("" : "=r"(width), "=r"(height) : "0"(width), "1"(height) : "memory", "$2");
    compare = 240;
    __asm__ volatile("" : "=r"(compare) : "0"(compare));
    D_800AF670 = width;
    D_800AF6CC = width;
    if (height == compare) y = 360;
    else y = 240;
    }
    __asm__ volatile("" : "=r"(y) : "0"(y));
    D_800AF6D6 = 256;
    D_800AF6D4 = 256;
    D_800AF67A = 256;
    D_800AF678 = 256;
    D_800AF6CE = y;
    D_800AF6DA = 0;
    D_800AF67E = 0;
    D_800AF6DC = 1;
    D_800AF680 = 1;
    func_80014960();
}

