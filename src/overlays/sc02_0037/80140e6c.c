/* sc02_0037: func_80140E6C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8013F350.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef int s32;
typedef s32 M2C_UNK;
extern int func_800D2CA8(int, int);
extern void func_800D2D10(int, int, void *, int);

void func_80140E6C(void) {
    extern unsigned char D_80078E7F;
    extern unsigned char D_80078E7E;
    extern unsigned char D_80078E7D;
    extern M2C_UNK D_80184BA0;
    void *puVar1;
    unsigned int uVar2;
    unsigned int uVar3;
    unsigned int uVar4;
    puVar1 = (*(void * *)&D_80184BA0);
    uVar2 = func_800D2CA8(D_80078E7F, 0x18);
    uVar3 = func_800D2CA8(D_80078E7E, 0xc);
    uVar4 = func_800D2CA8(D_80078E7D, 0);
    func_800D2D10(uVar2 | 0xb00000 | uVar3 | 0xb00 | uVar4, 8, puVar1, 0);
}
