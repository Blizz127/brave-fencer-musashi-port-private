/* sc03_0001: func_80157B74 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
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

void func_80157B74(int param_1)
{
    if (*(unsigned short *)(param_1 + 0xB8) == 0x8000) {
        ((void (*)(void))func_801599A4)();
        ((void (*)(int))func_80159B3C)(param_1);
    } else {
        ((void (*)(int))func_80161208)(param_1);
    }
}
