/* sc02_0037: func_80135260 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80131340.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
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
int func_80134A74(int param_1, s16 param_2, s16 param_3, int param_4);
extern int func_80134A74(int, s16, s16, int);
s16 func_80135480(void *param_1, s32 param_2, s16 *param_3, s16 *param_4);

s32 func_80135260(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    extern s16 func_80135480(void*, s32, s16*, s16*);
    extern s32 func_80135EB0(void *arg0, s32 arg1_);
    extern s32 func_80136A94(s32 a0, s32 a1, s32 a2, s32 a3);
    extern u16 * D_8018419C;
    extern u16 * D_801841A0;
    extern u16 * D_801841A8;
    extern s32 D_801C842C;
    extern s32 D_801C844C;
    u8 dead[56];
    s32 *p;
    s32 flag;
    s32 q;
    u16 *pa;
    u16 *pb;
    u16 *pc;
    u16 *pd;
    u16 *pe;
    u16 t;
    switch (((s32 (*)(void *, s32, s16 *, s16 *))func_80135480)((void *)arg0, arg1, ((s16 *)arg2), ((s16 *)arg3))) {
    case 0:
        return 0;
    case 1:
        q = arg0 + 0x34;
        p = (s32 *)((arg1 & 0xFFFFFFF) | 0x80000000);
        flag = 0;
        break;
    case 2:
        q = arg0 + 0x34;
        p = (s32 *)((arg1 & 0xFFFFFFF) | 0x80000000);
        flag = 1;
        break;
    case 3:
        q = arg0 + 0x34;
        p = &D_801C844C;
        flag = 0;
        break;
    case 4:
        q = (s32)&D_801C842C;
        p = &D_801C844C;
        flag = 1;
        break;
    }
    if (arg1 >= 0) {
        goto elsepath;
    }
    if (func_80135EB0(p, 0) != 0) {
        goto hit;
    }
    p = (s32 *)*p;
    if (p == 0) {
        return 0;
    }
loop:
    if (func_80135EB0(p, 0) == 0) {
        goto body;
    }
hit:
    func_80136A94(flag, arg0, (s32)((s16 *)arg3), q);
    return 1;
body:
    p = (s32 *)*p;
    if (p != 0) {
        goto loop;
    }
    return 0;
elsepath:
    pa = D_801841A0;
    pb = D_8018419C;
    pc = D_801841A8;
    pc[0] = pa[0] - pb[0];
    pc[1] = pa[1] - pb[1];
    pc[2] = pa[2] - pb[2];
    if (func_80134A74(0, (s16)pb[0], (s16)pb[2], (int)p) != 0) {
        goto hit;
    }
    pd = D_8018419C;
    pe = D_801841A0;
    t = pe[0];
    if (((pd[0] & 0xFF80) == (t & 0xFF80)) && ((pd[2] & 0xFF80) == (pe[2] & 0xFF80))) {
        return 0;
    }
    if (func_80134A74(0, (s16)t, (s16)pe[2], (int)p) != 0) {
        goto hit;
    }
    return 0;
}
