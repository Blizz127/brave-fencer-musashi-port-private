/* sc03_0001: func_80161374 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80015954(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8015BDD0(s32 *a0);
extern void func_8015BF48(s32 *a0);
extern int func_80161208();
extern s32 func_80161208();
extern void func_8015BDD0(s32 *a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208(void);
extern s32 func_80161208(void);
extern s32 func_80161208(void);
extern void func_801599A4(void *a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_8016130C(void*, s32);
void aF80161208(void *a0) __asm__("func_80161208");
void aF80161208(void *a0) __asm__("func_80161208");
extern void func_8016130C(void *a0, s32 a1);
extern s32 D_801152BC;
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
extern void func_80015954(s32, s32);

int func_80161374(int param_1, unsigned int param_2) {
    extern int D_801152BC;
    if ((param_2 == 0) || (param_2 == 0x8000)) {
        ((void (*)(int))func_801599A4)(param_1);
        ((void (*)(int))func_8015BDD0)(param_1);
        return 1;
    }
    if ((param_2 & 0x4000) != 0) {
        if ((D_801152BC != 0) ||
            (*(short *)(param_1 + 10) >= *(short *)(param_1 + 0x8a))) {
            ((void (*)(int))func_801599A4)(param_1);
            ((void (*)(int))func_8015BF48)(param_1);
            return 1;
        }
        ((int (*)(int, int))func_80015954)(param_1 + 0x88, param_1 + 4);
        return 0;
    }
    return 0;
}
