/* SC02.CD member31 [80145EE8,80146014); exact word export. */
/* SC02 member31 [80145EE8,80146014): gated mode0 and unconditional mode1 setup. */
extern unsigned char func_80029178(int);
extern void func_80146014(void *);
extern unsigned char D_80186630[],D_80186660[],D_801866B0[],D_801866E0[],D_80186710[];
void func_80145EE8(int mode)
{
    switch(mode) {
    case 0:
        if (func_80029178(0x1F)) func_80146014(D_80186630);
        if (func_80029178(0x21)) func_80146014(D_80186660);
        if (func_80029178(0x1E)) func_80146014(D_801866B0);
        if (func_80029178(0x1D)) func_80146014(D_801866E0);
        if (func_80029178(0x20)) func_80146014(D_80186710);
        break;
    case 1:
        func_80146014(D_80186630);
        func_80146014(D_80186660);
        func_80146014(D_801866B0);
        func_80146014(D_801866E0);
        func_80146014(D_80186710);
        break;
    }
}
