/* sc03_0001: func_80141100 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80140608.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern short D_80115128;
extern short D_80115128;
extern short D_80115128;
extern unsigned short D_80115172;
extern unsigned short D_8018E36A;
extern unsigned short D_8018E36E;
extern unsigned short D_8018E372;
extern unsigned short D_8018E376;
extern s32 func_8002A1B4(void);
extern short func_8002A28C(void);
extern short func_8002A27C(void);
extern s32 func_8002A400(void);
extern short func_8002A4D8(void);
extern short func_8002A4C8(void);
extern s32 func_8002A8E0(void);
extern short func_8002A9B8(void);
extern short func_8002A9A8(void);
extern s32 func_8002A670(void);
extern short func_8002A748(void);
extern short func_8002A738(void);
extern int func_801412A8(int, int, int, int, int, int);

int func_80141100(int param_1)
{
    short sVar1;
    int iVar7;
    if (D_80115128 == 0) {
        iVar7 = D_80115172 + 0x31;
        sVar1 = D_8018E36A;
        param_1 = func_801412A8(param_1, ((short (*)(void))func_8002A1B4)(), func_8002A28C(), func_8002A27C(), (short)iVar7, (int)sVar1);
        sVar1 = D_8018E36E;
        param_1 = func_801412A8(param_1, ((short (*)(void))func_8002A400)(), func_8002A4D8(), func_8002A4C8(), (short)iVar7, (int)sVar1);
        sVar1 = D_8018E372;
        param_1 = func_801412A8(param_1, ((short (*)(void))func_8002A8E0)(), func_8002A9B8(), func_8002A9A8(), (short)iVar7, (int)sVar1);
        sVar1 = D_8018E376;
        param_1 = func_801412A8(param_1, ((short (*)(void))func_8002A670)(), func_8002A748(), func_8002A738(), (short)iVar7, (int)sVar1);
    }
    return param_1;
}
