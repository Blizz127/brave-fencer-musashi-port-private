/* sc01_0077: func_80182A24 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80182268.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct {
    short v0;
    short v1;
    short v2;
    short pad6;
    short w0;
    short w1;
    short w2;
    short padE;
    unsigned char b10;
    unsigned char b11;
    unsigned char b12;
    unsigned char b13;
    unsigned char b14;
    unsigned char b15;
    unsigned char b16;
    unsigned char b17;
    int w18;
} Prim;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012C51C(void *a0, s32 a1);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012B2CC(int);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B2CC(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B2CC(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern int func_8012BEE8(int a0);
extern void func_8012B2CC(int a0);
extern void func_8012A828(int a0, void *a1);
extern int func_8005C49C(void);
extern void func_80182988();
extern void func_8012A828(int, void *);
void func_80182988(int param_1);
extern void func_8012A828(s32 a0, void *a1);
void func_801829E0(int param_1);
struct Prim { s16 f0, f2, f4, f6, f8, fA, fC, fE; s32 f10; };

s32 func_80182A24(s32 arg0) {
    extern s32 func_8012E544(s32 a0);
    extern void func_8018301C(s32 a0);
    extern void func_80184ED8(s32 a0, s32 a1);
    extern s32 D_8018AA6C[];
    extern s32 D_801AFDD0;
    s32 cond;
    s32 flag;
    s32 d;
    u16 mode;
    s32 st34;
    mode = *(u16 *)(arg0 + 0x70);
    cond = 1;
    if ((u32)(mode - 0x505) >= 2) {
        cond = ((mode & 0xff00) == 0x700);
    }
    if (cond == 0) {
        goto flag_zero;
    }
    cond = func_8012E544(0x298);
    if (cond == 0) {
        goto lab_ab0;
    }
    if (*(u16 *)(cond + 2) == 2) {
        goto compute;
    }
flag_zero:
    flag = 0;
    goto lab_ab0;
compute:
    d = *(s16 *)(cond + 0xe) - *(s16 *)(arg0 + 0xe);
    flag = (d < 0x20);
    if (d < 0) {
        d = -d;
        flag = (d < 0x20);
    }
lab_ab0:
    if (flag != 0) {
        func_8018301C(arg0);
        return;
    }
    st34 = *(u16 *)(arg0 + 0x34);
    switch (st34) {
    case 0:
        if (*(u16 *)(arg0 + 0x72) & 0x4000) {
            s32 c = *(u8 *)(arg0 + 0x102) + 1;
            *(u8 *)(arg0 + 0x102) = c;
            __asm__ __volatile__("" ::: "memory");
            if ((((s32(*)())func_8005C49C)() & 1) < (c & 0xff)) {
                ((void(*)(s32))func_80182988)(arg0);
            }
        }
        break;
    case 1: {
        s32 s1c = *(s32 *)(arg0 + 0x1c);
        if (s1c == 0xc) {
            struct Prim sp;
            s16 buf[4];
            s32 tv0;
            func_8012F214(arg0, (s32)&(*(s32 *)&D_8018AA6C), (s32)buf);
            sp.f6 = 0x20;
            sp.f8 = 2;
            sp.fA = 0;
            sp.f10 = 0;
            sp.fE = 0;
            sp.f0 = buf[0];
            sp.f2 = buf[1];
            sp.f4 = buf[2];
            sp.fC = *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x12);
            tv0 = func_8012C51C(&sp, arg0);
            if (tv0 != 0) {
                *(u16 *)(*(s32 *)(tv0 + 0x20) + 0x12) = *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x12);
                func_8012B2CC(tv0);
            }
        } else if (s1c == 0xf) {
            func_80184ED8(arg0, (s32)&(*(s32 *)&D_8018AA6C));
        }
        if (func_8012BEE8(arg0) != 0) {
            s32 c = *(u8 *)(arg0 + 0x102) + 1;
            *(u8 *)(arg0 + 0x102) = c;
            if ((u32)(c & 0xff) >= 3) {
                ((void(*)(s32))func_801829E0)(arg0);
                return;
            }
            *(s32 *)(arg0 + 0x1c) = 0x1e;
            return;
        }
        break;
    }
    case 2:
        if (*(u16 *)(arg0 + 0x72) & 0x4000) {
            *(s16 *)(arg0 + 2) = 0xb;
            *(u16 *)(arg0 + 0x34) = 0;
            *(s16 *)(arg0 + 0x5e) = 0;
            *(u16 *)(arg0 + 0x5c) = 0xaa10;
            func_8012A828(arg0, &D_801AFDD0);
            *(u8 *)(arg0 + 0x102) = 0;
        }
        break;
    }
}
