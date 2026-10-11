/* sc03_0001: func_80157D20 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
s32 aF80156600(void) __asm__("func_80156600");
s32 func_80156600(void* _arg0);
void func_80156648(s32 *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80156648(s32 *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80156648(s32 *a0);
extern void func_80156648(s32 *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80157D74(u16 *a0);
void func_80157D74(u16 *a0);

void func_80157D20(void)
{
    extern u16 D_8018F848[];
    register void *a0v __asm__("$4");
    register s32 a1v __asm__("$5");
    void *param_1 = a0v;
    s32 param_2 = a1v;
    ((void (*)(void))func_80156648)();
    ((void (*)(void *, s32))func_80147078)(param_1, D_8018F848[param_2]);
    ((void (*)(void *))func_80157D74)(param_1);
}
