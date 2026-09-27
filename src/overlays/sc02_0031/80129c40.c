/* SC02.CD member31 PAC0 decoded [80129C40,80129CF8). No C match claim. */
/* Decoded-region byte match; not registered in the main oracle. */
/* SC02 member 31 [80129C40,80129CF8): initialize eight blocks and clear flags. */
extern unsigned char D_80126DB8[],D_80126948[],D_80114EE8[],D_80126E60[];
extern unsigned char D_801150D6,D_801152C0,D_80127504;
extern void func_80016714(void *,int),func_800144D4(void);
void func_80129C40(void)
{
    unsigned char *base;
    func_80016714(D_80126DB8,0xA4);
    func_80016714(D_80126948,0xA4);
    base = D_80114EE8;
    func_80016714(base,0xA4);
    func_80016714(base+0xA4,0xA4);
    func_80016714(base+0x148,0xA4);
    base = D_80126E60;
    func_80016714(base,0xA4);
    func_80016714(base+0xA4,0xA4);
    func_80016714(base+0x148,0xA4);
    D_801150D6 = 0;
    D_801152C0 = 0;
    D_80127504 = 0;
    func_800144D4();
}

