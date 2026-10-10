/* sc01_0077: func_8013D3D4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern s32 D_801D95A0;
extern s32 D_801D95A8;
extern s32 D_801DAA14[];
extern void func_8013CF68(void);
void func_8013CF68();
extern u8 D_80078E78[];
extern void *D_801D9570;
extern void *D_801D9574;
extern void *D_801D9578;
extern s32 D_801D95A0;
extern s32 D_801D95A4;
extern s32 D_801D95A8;
extern s32 D_801DAA14[];
extern u8 D_8018735C[];
extern u8 D_80187404[];
extern u8 D_801872B4[];
extern u8 D_801873B0[];
extern u8 D_80187430[];
extern u8 D_80187308[];
extern void func_8013D53C(void *);
extern void func_8013DD68(void);
extern void func_8013D8FC(void);
extern void func_8013CF68(void);
void func_8013D53C(void *arg0v);
void func_8013D8FC(void);
void func_8013DD68();

void func_8013D3D4(int param_1, int param_2)
{
    u8 *p = D_80078E78;
    D_801D95A0 = param_2;
    D_801D95A4 = (param_2 >> 2) & 3;
    D_801D95A8 = (param_2 >> 4) & 1;
    if (((param_2 >> 2) & 3) == 0) {
        D_801D9570 = D_8018735C;
        D_801D9574 = D_80187404;
        D_801D9578 = D_801872B4;
    } else {
        D_801D9570 = D_801873B0;
        D_801D9574 = D_80187430;
        D_801D9578 = D_80187308;
    }
    func_8013D53C((void *)param_1);
    if ((param_2 & 1) != 0) {
        if (D_801D95A8 != 0) {
            func_8013DD68();
        } else {
            func_8013D8FC();
        }
        func_8013CF68();
        if ((D_801D95A0 & 2) != 0) {
            D_801DAA14[0] = 0x140;
            D_801DAA14[3] = 0x80;
            if (p[0x37] == 4) {
                D_801DAA14[0] = 0x140;
                D_801DAA14[3] = 0;
            }
            if (p[0x37] == 0) {
                D_801DAA14[0] = 0x140;
                D_801DAA14[3] = 0x80;
            }
        }
    }
}
