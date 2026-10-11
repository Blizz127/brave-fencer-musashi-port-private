/* sc03_0001: func_8018640C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern s32 func_8018766C(s32 a0, s32 a1);
extern void func_80186288(short *param_1);
extern s32 func_8018766C(s32 arg0, s32 arg1);
extern void func_80186288(short*);

void func_8018640C(void *arg0) {
    if (func_8018766C(8, 0x14) != 0) {
        ((void (*)(void *))func_80186288)(arg0);
    }
}
