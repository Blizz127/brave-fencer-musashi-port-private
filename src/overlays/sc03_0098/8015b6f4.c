/* sc03_0098: func_8015B6F4 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8015AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80146994(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80147300(u16 arg0);
extern void func_80147324(s32 arg0);
extern s32 func_80149AA8(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80156648(s32 *a0);
extern void func_80154A74(int, int);
extern void func_80154A74(s32 a0, s32 a1);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80154150(s32 a0, s32 a1);
extern s32 func_80149AA8(s32 *a0);
extern void func_80156648(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80147324(s32 arg0);
extern void func_80147300(u16 arg0);
extern s32 D_800D4A9C;

int func_8015B6F4(int param_1)
{
    int b4;
    register unsigned int f44 __asm__("$2");
    register unsigned int bc __asm__("$4");
    if (((int (*)(void))func_80149AA8)() == 0) return 0;
    ((void (*)(int))func_80156648)(param_1);
    b4 = *(int *)(param_1 + 0xb4);
    *(unsigned char *)(param_1 + 0x1aa) = 6;
    __asm__ __volatile__("" ::: "memory");
    f44 = *(unsigned int *)(param_1 + 0x44);
    bc = *(unsigned char *)(param_1 + 0xbc);
    *(int *)(param_1 + 0x23c) = b4;
    *(unsigned int *)(param_1 + 0x44) = f44 | 2;
    *(unsigned char *)(param_1 + 0x244) = bc;
    if (*(int *)(param_1 + 0xb4) == (int)&D_800D4A9C) {
        func_80154150(param_1, 0xb);
    } else {
        func_80154150(param_1, 0xc);
    }
    func_80154A74(param_1, 0x22);
    *(unsigned char *)(param_1 + 0xda) = 0;
    ((void (*)(int, int, int, int))func_80146994)(4, param_1, 5, 0);
    func_80147324(0x400);
    ((void (*)(int))func_80147300)(0x5f3);
    return 1;
}
