/* Complete retail export [8013D3D4,8013D53C). */
extern int D_801B6388,D_801B638C,D_801B6390;
extern void *D_801B6358,*D_801B635C,*D_801B6360;
extern unsigned char D_801854B0[],D_80185558[],D_80185408[],D_80185504[],D_80185584[],D_8018545C[],D_80078E78[];
extern int D_801B79F4[];
extern void func_8013D53C(void *),func_8013DD68(void),func_8013D8FC(void),func_8013CF68(void);
void func_8013D3D4(void *resource,int flags)
{
    unsigned char *config=D_80078E78;
    D_801B6388=flags;
    D_801B638C=(flags>>2)&3;
    D_801B6390=(flags>>4)&1;
    if (!D_801B638C) {
        D_801B6358=D_801854B0; D_801B635C=D_80185558; D_801B6360=D_80185408;
    } else {
        D_801B6358=D_80185504; D_801B635C=D_80185584; D_801B6360=D_8018545C;
    }
    func_8013D53C(resource);
    if (flags&1) {
        if (D_801B6390) func_8013DD68(); else func_8013D8FC();
        func_8013CF68();
        if (D_801B6388&2) {
            D_801B79F4[0]=320; D_801B79F4[3]=128;
            if (config[0x37]==4) { D_801B79F4[0]=320; D_801B79F4[3]=0; }
            if (config[0x37]==0) { D_801B79F4[0]=320; D_801B79F4[3]=128; }
        }
    }
}
