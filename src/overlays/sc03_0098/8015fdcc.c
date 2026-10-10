/* sc03_0098: func_8015FDCC from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 arg0);
extern void func_80139914(s32 a0);
extern void func_80147324(s32 a0);
extern s32 func_801399F0(s32);
extern void func_80139914(s32);
extern s32 func_801399F0(s32 a0);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 arg0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_80147324(s32 a0);
extern void func_80147324(s32 arg0);
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 arg0);
extern void func_80146CA0(void *a0);
extern s32 func_801399F0(s32 a0);
extern void func_80147324(s32 a0);
extern void func_80139914(s32 a0);
extern s32 func_80028DE0(void);
extern u8 func_80165700(s32 a0, s32 a1);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80146CA0(void *a0);
u8 func_80165700(s32 a0, s32 a1);

void func_8015FDCC(s32 a0) {
    s32 s0 = a0;
    if (func_801399F0(*(s32 *)(s0 + 0x198)) != 0) {
        func_80147324(0x19);
        func_80139914(*(s32 *)(s0 + 0x198));
        *(s32 *)(s0 + 0x198) = 0;
        if (func_80028DE0() == 0) {
            if ((func_80165700(s0, *(u8 *)(s0 + 0x1A0)) & 0xFF) != 0) {
                func_801466F0(0x24, s0, 0, 0, 0, 0, 0, 0);
                func_80147324(0x989);
            }
        }
        func_80146CA0((void *)s0);
    }
}
