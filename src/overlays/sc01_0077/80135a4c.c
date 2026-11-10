/* sc01_0077: func_80135A4C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80135A4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
struct V3;
struct V3 { s16 x; s16 y; s16 z; };
typedef struct { u8 b[8]; } Blk8;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
typedef struct { u16 f0, f2, f4; s16 f6; } Box;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { s16 x, y, z; } V3;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_801152A8[];
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern s32 func_80133AB0(s16 flag, s16 x, s16 y, s32 arg3);
extern u8 D_801870B0;
extern u8 D_801870AC;
extern s16 *D_801870B4;
extern u16 D_801D9500;
extern s16 func_80135480(void *param_1, s32 param_2, s16 *param_3, s16 *param_4);

s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3) {
    typedef struct { s8 c[8]; } Blk8;
    extern s16 func_80135480(void *param_1, s32 param_2, s16 *param_3, s16 *param_4);
    extern s32 func_80135EB0(void *arg0, s32 arg1_);
    extern s32 func_80136A94(s32 a0, s32 a1, s32 a2, s32 a3);
    extern s32 func_80133AB0(s16, s16, s16, s32);
    extern u8 D_801870AC;
    extern u8 D_801870B0;
    extern s16 *D_801870B4;
    extern s16 D_801D94FC;
    extern u16 D_801D9500;
    extern s32 D_801D9504;
    extern s32 D_801D9524;
    extern u8 D_801152A8[];
    extern u8 D_801152B0;
    s32 *p;
    register s32 s7 __asm__("$23");
    s32 flag;
    s32 acc;
    s16 i;
    s32 eq;
    s32 ret;
    s32 frame_pad[8];
    (void)&frame_pad;
    switch (((s32 (*)(void *, s32, s16 *, s16 *))func_80135480)((void *)a0, a1, (s16 *)a2, (s16 *)a3)) {
    case 0:
        return 0;
    case 1:
        s7 = a0 + 0x34;
        p = (s32 *)((a1 & 0xFFFFFFF) | 0x80000000);
        flag = 0;
        break;
    case 2:
        s7 = a0 + 0x34;
        p = (s32 *)((a1 & 0xFFFFFFF) | 0x80000000);
        flag = 1;
        break;
    case 3:
        s7 = a0 + 0x34;
        p = (s32 *)&D_801D9524;
        flag = 0;
        break;
    case 4:
        s7 = (s32)&D_801D9504;
        p = (s32 *)&D_801D9524;
        flag = 1;
        break;
    }
    acc = 0;
    if (a1 < 0) {
        if (func_80135EB0(p, -0x8000) == 0) {
            p = (s32 *)*p;
            if (p == 0) return 0;
        loop:
            if (func_80135EB0(p, -0x8000) == 0) goto next;
        }
    docall:
        func_80136A94(flag, a0, a3, s7);
        return 1;
    next:
        p = (s32 *)*p;
        __asm__ __volatile__("");
        if (p != 0) goto loop;
        return 0;
    }
    i = 0;
    *(s16 *)((*(u8 **)&D_801870AC) + 6) = -0x7FFF;
    *(s16 *)((*(u8 **)&D_801870B0) + 6) = 0x7FFF;
    D_801D9500 = 0;
    D_801D94FC = 0;
    {
        s32 t = 0;
        if (((V3 *)a2)->x == ((V3 *)a3)->x && ((V3 *)a2)->y == ((V3 *)a3)->y) {
            s32 zt = (((V3 *)a2)->z == ((V3 *)a3)->z);
            __asm__("addu %0,%1,$zero" : "=r"(t) : "r"(zt));
        }
        eq = t;
    }
    while (1) {
        ret = func_80133AB0(0, (s16)(*(Box **)&D_801870AC)->f0, (s16)(*(Box **)&D_801870AC)->f4, (s32)p);
        if (ret == 0) goto out;
        acc |= ret;
        if (eq != 0) goto out;
        {
            s16 old = i;
            i = i + 1;
            if (old >= 5) return 0;
        }
    }
out:
    if ((s16)acc != 0 || D_801D94FC != 0) {
        if ((*(Box **)&D_801870AC)->f6 >= -0xBCB) {
            *(Blk8 *)D_801152A8 = *(Blk8 *)&D_801152B0;
        }
        (*(Box **)&D_801870B4)->f0 = (*(Box **)&D_801870B0)->f0;
        (*(Box **)&D_801870B4)->f2 = (*(Box **)&D_801870B0)->f2;
        (*(Box **)&D_801870B4)->f4 = (*(Box **)&D_801870B0)->f4;
        goto docall;
    }
    return 0;
}
