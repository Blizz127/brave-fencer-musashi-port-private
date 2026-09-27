/* Exact retail word export for [800146B0,80014774); EXE and assembly verified. */
/* Retail [800146B0,80014774): select the display mode, initialize and clear.
 * GCC 2.7.2 / ASPSX 2.56 -O2 -G0, --link-base 0x800146B0: 49/49 words.
 * Empty compiler barriers preserve the observed load/store ordering; the
 * register binding schedules argument 4 into the first load-delay slot.
 * These constraints emit no instructions and do not imply original spelling.
 */
extern unsigned short D_80062A3C[], D_80062A3E[], D_80062A40[];
extern unsigned short D_800AF7BC, D_800AF7BE, D_800AF7C0;
extern void func_800527C4(int, int, int, int, int);
extern void func_80053EEC(int, int, int, int);
extern void func_80059234(int);
extern void func_80053218(void);
extern void func_80014774(void);
extern void func_800147B8(void);
void func_800146B0(unsigned short mode)
{
    unsigned int width, height, flags;
    register int zero __asm__("$7") = 0;
    D_800AF7BC = width = D_80062A3C[mode * 3];
    __asm__("" : : "r"(zero) : "memory");
    D_800AF7BE = height = D_80062A3E[mode * 3];
    __asm__("" : : : "memory");
    D_800AF7C0 = flags = D_80062A40[mode * 3];
    func_800527C4(width, height, flags | 4, zero, 0);
    if (D_800AF7BE == 480)
        func_80053EEC(0, 0, 0, 0);
    else
        func_80053EEC(0, D_800AF7BE, 0, 0);
    func_80059234(1);
    func_80053218();
    func_80014774();
    func_800147B8();
}

