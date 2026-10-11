/* sc03_0001: func_801612B8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8014CC28(s32 a0);
extern void func_8014E934(s32 _arg0);
extern void func_8014E934(s32 a0);
extern s32 func_8014F3E8(s32 a0);
extern int func_80161208();
extern s32 func_80161208();
extern void func_8014CC28(s32 a0);
extern s32 func_8014F3E8(s32 a0);
extern void func_8014CC28(s32);
extern s32 func_8014F3E8(s32);
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
void aF80161208(void *a0) __asm__("func_80161208");
void aF80161208(void *a0) __asm__("func_80161208");
extern void func_8014E934(s32 a0);
extern void func_8014CC28(s32 a0);
extern s32 func_8014F3E8(s32 a0);

s32 func_801612B8(void * a0, s32 a1)
{
    s32 p;
    s32 v0;
    s32 v1;
    p = a0;
    if ((a1 & 1) == 0) {
        func_8014E934(p);
    }
    v0 = ((s32 (*)(s32))func_8014CC28)(p);
    __asm__ __volatile__("" : : "r"(v0));
    v1 = ((s32 (*)(s32))func_8014F3E8)(p);
    return v0 | v1;
}
