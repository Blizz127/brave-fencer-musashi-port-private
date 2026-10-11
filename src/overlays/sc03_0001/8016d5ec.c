/* sc03_0001: func_8016D5EC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C(void);
extern short func_8016CF04();
short func_8016CF04(s32 param_1, s32 param_2);
extern short func_8016CF04();
extern short func_8016CF04();
extern short func_8016CF04();
extern void func_80146C3C();

void func_8016D5EC(s32 *a0) {
    u16 *rec = (u16 *)a0[8];
    rec[0xC] -= 0x60;
    rec[0xD] -= 0x60;
    if ((s16)((s32 (*)(s32, s32))func_8016CF04)((s32)a0, 2) != 0) {
        ((void (*)(s32 *))func_80146C3C)(a0);
    }
}
