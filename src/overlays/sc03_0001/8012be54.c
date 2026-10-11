/* sc03_0001: func_8012BE54 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u16 D_80126B66;
extern u16 D_80126B5E;
extern void func_8012BE98(s32 a0, u16 *a1);
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
void func_8012BE98(s32 arg0, u16 * arg1);

void func_8012BE54(s32 a0) {
    u16 sp[3];
    sp[0] = D_80126B5E;
    sp[1] = D_80126B62;
    sp[2] = D_80126B66;
    func_8012BE98(a0, sp);
}
