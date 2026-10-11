/* sc03_0001: func_80188F6C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80188830.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
extern void func_80029444(void);
extern void func_801754A8(void);
extern void func_80141C04(void);

void func_80188F6C(void) {
    extern u16 D_80115112;
    extern u16 D_80115116;
    extern void (*D_801C1890[])(void);
    u16 i;
    func_80029444();
    func_801754A8();
    i = D_80115112;
    D_801C1890[i]();
    func_80141C04();
    D_80115116++;
}
