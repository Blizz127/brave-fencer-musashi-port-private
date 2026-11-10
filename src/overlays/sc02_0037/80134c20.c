/* sc02_0037: func_80134C20 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80131340.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_801152A8[];
extern void *memcpy(void *, const void *, u32);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8();
extern void func_80131CA8(s32 a0, s32 a1);
extern void func_80131CA8(int, int);
extern void func_80131CA8(int a0, int a1);
extern s32 func_80131CF4(s32 a0);
extern void func_80131CA8(s32 a0, s32 a1);
extern s32 func_80131CF4(s32 a0);
s32 aF80131CA8(int a0) __asm__("func_80131CA8");
s32 aF80131CA8(int a0) __asm__("func_80131CA8");
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");
extern void func_80131CA8(int, int);
extern void func_80131CA8(int a0, int a1);
extern void func_80131CA8(int a0, int a1);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern void *memcpy(void *, const void *, u32);
extern s32 func_80047E98(void *a0, void *a1);
s32 func_80134FB8(s32 a0, s32 a1, s32 a2);

s32 func_80134C20(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern u8 D_801152A8[];
    extern s32 func_80134FB8(s32 a0, s32 a1, s32 a2);
    extern void * D_8018419C;
    extern void * D_801841A0;
    extern void * D_801841A4;
    extern void * D_801841A8;
    extern u16 D_801C8428;
    s32 temp_a3;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;
    u16 temp_a1;
    s32 temp_s4;
    s32 c = arg0;
    __asm__ __volatile__("" : "=r"(c) : "0"(c));
    __asm__ __volatile__("" : : "r"(arg0));
    temp_s4 = arg2 + ((*(s16 *)((s8 *)(((void *)arg1)) + (2))) * 8);
    temp_s1 = *(s32 *)(arg3 + ((*(s16 *)((s8 *)(((void *)arg1)) + (4))) * 4));
    var_v0 = 0;
    if (func_80134FB8(temp_s4, (s32) D_801841A0, temp_s1) >= 0) {
        return var_v0;
    }
    temp_v0 = func_80134FB8(temp_s4, (s32) D_8018419C, temp_s1);
    if (temp_v0 < 0) {
        goto block_13;
    }
    temp_v0_2 = func_80134FB8(temp_s4, (s32) D_801841A8, 0);
    temp_a3 = -temp_v0;
    {
        u16 *pB4 = (u16 *)D_801841A4;
        u16 *pAC = (u16 *)D_8018419C;
        s16 *pB8 = (s16 *)D_801841A8;
        pB4[0] = pAC[0] + (temp_a3 * pB8[0]) / temp_v0_2;
        pB4[1] = pAC[1] + (temp_a3 * pB8[1]) / temp_v0_2;
        pB4[2] = pAC[2] + (temp_a3 * pB8[2]) / temp_v0_2;
        var_v0 = 0;
        if (func_80134FB8(arg2 + ((*(s16 *)((s8 *)(((void *)arg1)) + (6))) * 8), (s32) pB4, *(s32 *)(arg3 + ((*(s16 *)((s8 *)(((void *)arg1)) + (8))) * 4))) < -0x2F00) {
            return var_v0;
        }
    }
    var_v0 = 0;
    if (func_80134FB8(arg2 + ((*(s16 *)((s8 *)(((void *)arg1)) + (0xA))) * 8), (s32) D_801841A4, *(s32 *)(arg3 + ((*(s16 *)((s8 *)(((void *)arg1)) + (0xC))) * 4))) < -0x2F00) {
        return var_v0;
    }
    var_v0 = 0;
    if (func_80134FB8(arg2 + ((*(s16 *)((s8 *)(((void *)arg1)) + (0xE))) * 8), (s32) D_801841A4, *(s32 *)(arg3 + ((*(s16 *)((s8 *)(((void *)arg1)) + (0x10))) * 4))) < -0x2F00) {
        return var_v0;
    }
    if ((arg0 << 16) < 0) {
        var_v0 = 0;
        if (func_80134FB8(arg2 + ((*(s16 *)((s8 *)(((void *)arg1)) + (0x12))) * 8), (s32) D_801841A4, *(s32 *)(arg3 + ((*(s16 *)((s8 *)(((void *)arg1)) + (0x14))) * 4))) < -0x2F00) {
            return var_v0;
        }
    }
    if (c & 1) {
        if (!((*(u16 *)((s8 *)(((void *)arg1)) + (0))) & 0x300)) {
            goto block_14;
        }
        return 0;
    }
    temp_a1 = (*(u16 *)((s8 *)(((void *)arg1)) + (0)));
    if (!(temp_a1 & 0x200)) {
        goto block_14;
    }
    D_801C8428 = temp_a1;
block_13:
    return 0;
block_14:
    __builtin_memcpy(D_801152A8, (void *)temp_s4, 8);
    func_80047E98(D_801841A8, D_801841A8);
    {
        u16 *pB8 = (u16 *)D_801841A8;
        u16 *pB4b = (u16 *)D_801841A4;
        pB4b[0] = pB4b[0] - ((pB8[0] << 0x10) >> 0x1B);
        var_v0 = 1;
        pB4b[1] = pB4b[1] - ((pB8[1] << 0x10) >> 0x1B);
        pB4b[2] = pB4b[2] - ((pB8[2] << 0x10) >> 0x1B);
    }
    return var_v0;
}
