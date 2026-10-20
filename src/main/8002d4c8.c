/* Exact retail word export for [8002D4C8,8002D59C); EXE and assembly verified. */
/* Retail [8002D4C8,8002D59C): dispatch a command, then process pending work.
 * GCC 2.7.2 / ASPSX 2.56 -O2 -G0: exact 53-word match, ordinary C.
 */
extern unsigned char D_800A4F17,D_800A4F18;
extern short D_800A4EFC;
extern void func_8002E138(int,int,int),func_8002D904(int),func_8002DC68(int,int);
extern void func_80030F80(void),func_8002D320(void);
extern int func_80031BE0(void);
/* Returns func_80031BE0's result when work was pending, else the (zero) pending byte: retail leaves it in v0 and
 * callers return it onward (R46L4 void-table ABI). */
int func_8002D4C8(unsigned short command, unsigned short argument)
{
    unsigned char *flag;
    int r;
    D_800A4F17 = 1;
    if (command < 0x80)
        func_8002E138(command, argument, 0);
    else if (command >= 0x100) {
        if (command < 0x400)
            func_8002D904(command);
        else
            func_8002DC68(command, argument);
    }
    flag = &D_800A4F17;
    r = D_800A4F18;
    *flag = r;
    if (r) {
        if (D_800A4EFC) --D_800A4EFC;
        func_80030F80();
        func_8002D320();
        r = func_80031BE0();
        D_800A4F18 = 0;
        *flag = 0;
    }
    return r;
}

