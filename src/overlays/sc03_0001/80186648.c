/* sc03_0001: func_80186648 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80178CBC(s32*, s32);
extern void func_80178CBC(s32 *a0, s32 a1);
extern void func_80178CBC(s32 *, s32);
extern void func_80178CBC(s32 *a0, s32 a1);
extern short D_80192A18;

void func_80186648(short *param) {
        param[1] = 0x4;
        ((void (*)(s32, s32))func_80178CBC)((int)param, (int)&D_80192A18);
    }
