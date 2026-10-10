/* sc01_0077: func_80135888 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80135888.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern void memcpy();
extern int func_80134A74(int param_1, s16 param_2, s16 param_3, int param_4);
extern u8 D_801870B0;
extern u8 D_801870AC;
extern u8 D_801870B8;
extern int func_80134A74(int, s16, s16, int);
extern s16 func_80135480(void *param_1, s32 param_2, s16 *param_3, s16 *param_4);
extern s16 func_80135480(void*, s32, s16*, s16*);
extern s32 func_80135EB0(void *arg0, s32 arg1_);
extern int func_80134A74(int, s16, s16, int);
extern s32 func_80136A94(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_801870AC;
extern u8 D_801870B0;
extern u8 D_801870B8;
extern s32 D_801D9504;
extern s32 D_801D9524;

s32 func_80135888(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 pad_[8];
    register s32 m __asm__("$2");
    s32 sp;
    register s32 p1 __asm__("$17");
    s32 mode;
    register s32 p0 __asm__("$19");
    s32 base;
    register s32 p3 __asm__("$21");
    p0 = arg0;
    p1 = arg1;
    p3 = arg3;
    switch (((s32 (*)(void *, s32, s16 *, s16 *))func_80135480)((void *)arg0, arg1, (s16 *)arg2, (s16 *)arg3)) {
    case 0:
        return 0;
    case 1:
        base = p0 + 0x34;
        m = p1 & 0xFFFFFFF;
        sp = m | 0x80000000;
        mode = 0;
        break;
    case 2:
        base = p0 + 0x34;
        m = p1 & 0xFFFFFFF;
        sp = m | 0x80000000;
        mode = 1;
        break;
    case 3:
        base = p0 + 0x34;
        sp = (s32)&D_801D9524;
        mode = 0;
        break;
    case 4:
        base = (s32)&D_801D9504;
        sp = (s32)&D_801D9524;
        mode = 1;
        break;
    }
    if (p1 < 0) {
        if (func_80135EB0(sp, 0) != 0) {
            func_80136A94(mode, p0, p3, base);
            return 1;
        }
        sp = *(s32 *)sp;
        __asm__ __volatile__("");
        while (sp != 0) {
            if (func_80135EB0(sp, 0) != 0) {
hit:
                func_80136A94(mode, p0, p3, base);
                return 1;
            }
            sp = *(s32 *)sp;
        }
        return 0;
    }
    {
        u16 *pb = (*(u16 * *)&D_801870B0);
        u16 *pa = (*(u16 * *)&D_801870AC);
        s16 *pc = (*(s16 * *)&D_801870B8);
        pc[0] = pb[0] - pa[0];
        pc[1] = pb[1] - pa[1];
        pc[2] = pb[2] - pa[2];
        if (func_80134A74(0, (s16)pa[0], (s16)pa[2], sp) == 0) {
            return 0;
        }
    }
    goto hit;
}
