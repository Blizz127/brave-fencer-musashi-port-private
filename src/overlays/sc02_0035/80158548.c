/* SC02.CD member35: func_80158548 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern int func_80161208();
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80161208();
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80161208();
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80161208();
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80161208();
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80161208();

void func_80158548(s32 param_1) {
    *(u32 *)(param_1 + 0x44) = *(u32 *)(param_1 + 0x44) | 2;
    if (*(u16 *)(param_1 + 0xb8) & 0x8000) {
        ((void (*)(void))func_801599A4)();
        ((void (*)(s32))func_80159B3C)(param_1);
    } else {
        ((void (*)(s32))func_80161208)(param_1);
    }
}
