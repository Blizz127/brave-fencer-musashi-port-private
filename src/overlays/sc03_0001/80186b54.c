/* sc03_0001: func_80186B54 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018631C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef struct { u8 b[8]; } Blk8;
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
extern void func_8012A568(void (*a0)(void));
extern void func_80172710(void);
extern s32 func_80178BF8();
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern s32 func_80178BF8();
extern void func_8012C218(void *arg0);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8(void);
extern void func_80172710(void);
extern s32 func_8018739C(void);
extern s32 func_80178BF8();
s32 aF80186828(void *a0) __asm__("func_80186828");
extern void func_8012C218(void *a0);

void func_80186B54(unsigned int ent, unsigned int arg1) {
    typedef struct { s8 c[8]; } Blk8;
    Blk8 *src;
    Blk8 *dst;
    int val;
    int next;
    next = *(int *)(ent + 0x64);
    dst = (Blk8 *)(*(int *)(ent + 0x20) + 0x10);
    src = (Blk8 *)(*(int *)(next + 0x20) + 0x10);
    *dst = *src;
    val = *(int *)(ent + 0x1c) + 1;
    *(int *)(ent + 0x1c) = val;
    if (val >= 0x5a) {
        func_8012C218((void *)ent);
    } else {
        if (val >= 0x3c) {
            *(unsigned int *)(*(int *)(ent + 0x20) + 4) ^= 0x80000000;
        }
    }
}
