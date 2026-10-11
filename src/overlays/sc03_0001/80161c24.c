/* sc03_0001: func_80161C24 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_80147324(s32 arg0);
extern void func_801599A4(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8015BDD0(s32 *a0);
extern void func_80147324(s32 a0);
extern void func_8015BF48(s32 *a0);
extern int func_80161208();
extern s32 func_80161208();
extern void func_8015BDD0(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 a0);
extern s32 func_80161208(void);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern s32 func_80161208(void);
extern s32 func_80161208(void);
extern void func_80147324(s32 a0);
extern void func_801599A4(void *a0);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 arg0);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_80147324(s32 a0);
extern void func_8016130C(void*, s32);
void aF80161208(void *a0) __asm__("func_80161208");
void aF80161208(void *a0) __asm__("func_80161208");
extern void func_8016130C(void *a0, s32 a1);
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
extern void func_8016191C(void *a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(int a0, int a1);
int aF8016191C(int param_1, unsigned int param_2) __asm__("func_8016191C");
int aF8016191C(int param_1, unsigned int param_2) __asm__("func_8016191C");
extern void func_801599A4(void *a0);
extern void func_801599A4(void *a0);
extern void func_801599A4(void *a0);
extern void func_80147324();

void func_80161C24(int param_1, int param_2)
{
    extern unsigned short D_8018FFC4[];
    extern unsigned short D_8018FFC6[];
    if ((unsigned int)param_2 < 8) {
        if (*(u8 *)(param_1 + 0xDA) != 0) {
            func_80147324(D_8018FFC4[(unsigned int)param_2 * 2]);
            *(u8 *)(param_1 + 0xDA) = 0;
        } else {
            func_80147324(D_8018FFC6[(unsigned int)param_2 * 2]);
            *(u8 *)(param_1 + 0xDA) = 1;
        }
    }
}
