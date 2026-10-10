/* sc01_0077: func_801615C4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
extern void func_80146D90(s32 a0);
extern void func_801599A4(void *a0);
extern void func_8014CC28(s32 a0);
extern void func_8014ED28(s32 _arg0);
extern void func_8014FA04(s32 a0);
extern void func_8015BDD0(s32 *a0);
extern void func_8015BF48(s32 *a0);
void func_8014ED28(s32 a0);
void func_80146D90(s32 a0);
void func_8014CC28(s32 a0);
void func_8014FA04(s32 a0);
extern s32 func_80161208();
extern void func_8014ED28(s32 a0);
extern void func_8014CC28(s32 a0);
extern void func_8015BDD0(s32 *a0);
extern void func_801599A4(void *a0);
extern s32 func_80161208();
extern void func_80146D90(int);
extern void func_8014CC28(s32);
extern void func_80146D90(s32 a0);
extern void func_8014FA04(s32 a0);
extern void func_8014FA04(s32 a0);
extern void func_8014FA04(s32);
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_8014ED28(s32 a0);
extern void func_8014FA04(s32 a0);
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
extern s32 func_80161208();
extern s32 func_80161208();
extern void func_8016130C(void*, s32);
void aF80161208(void *a0) __asm__("func_80161208");
void aF80161208(void *a0) __asm__("func_80161208");
extern void func_8016130C(void *a0, s32 a1);
extern void func_8014CC28(s32 a0);
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
s32 aF8016130C(void *a0, s32 a1) __asm__("func_8016130C");
extern void func_801599A4(void*);
extern void func_8015BDD0(s32*);
extern void func_8015BF48(s32*);
extern void func_8014ED28();
extern void func_80146D90(s32 a0);
extern void func_8014CC28(s32 a0);
extern void func_8014FA04(s32 a0);

s32 func_801615C4(void * arg0, s32 arg1)
{
    u32 acc;
    acc = 0;
    if (((arg1 & 1) == 0) && (((s32 (*)(void))func_8014ED28)() != 0)) {
        func_80146D90(arg0);
    }
    if (*(s32 *)((u8 *)arg0 + 0x34) > 0) {
        acc |= ((s32 (*)(s32))func_8014CC28)(arg0);
    }
    return acc | ((s32 (*)(s32))func_8014FA04)(arg0);
}
