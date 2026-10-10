/* sc01_0077: func_8013EE10 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
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
typedef struct { s32 f0; } E4;
extern unsigned short D_80115112;
extern unsigned short D_80115112;
extern s32 D_80115188;
extern s16 D_80187E94;
extern s16 D_80187E96;
extern unsigned short D_80115112;
extern void func_8013FAF8(s16 a0, s16 a1);
extern short D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern unsigned short D_80115112;
extern void func_8013FAF8(s16 a0, s16 a1);
extern void func_801376E8(int a0, int a1);
extern unsigned char *func_80141CA4(void);
extern short D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern unsigned short D_80115112;
extern unsigned char D_80187E98;
extern void func_8013FAF8(s16 a0, s16 a1);
extern short D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern u16 D_80115112;
void func_8013FAF8(s16 arg0, s16 arg1);
unsigned char *func_80141CA4(void);

void func_8013EE10() {
    extern E4 aD80115188[] __asm__("D_80115188");
    extern E4 D_80115168[];
    extern unsigned short D_80115118;
    short i;
    u16 *p;
    u16 old;
    s16 *r;
    u16 *c;
    s32 sp10[2];
    D_801151D0 = *(s32 *)&D_801151C8[(u16)D_800B9A02 * 4];
    func_8013FAF8(0, 5);
    for (i = 0; i < 5; i++) {
        s32 t = D_80115168[i].f0 * 3 >> 2;
        aD80115188[i].f0 = t;
        D_80115168[i].f0 = D_80115168[i].f0 - t;
    }
    r = &D_80187E96;
    if (*r < 3) {
        *r = *r + 1;
    }
    D_80187E94 = (u16)D_80187E94 + 2;
    p = &D_80115118;
    old = *p;
    *p = old + 1;
    if (old >= 5) {
        ((void (*)(int, unsigned char *))func_801376E8)((int)func_80141CA4(), &D_80187E98);
        for (i = 0; i < 5; i++) {
            s32 *q = (s32 *)((char *)p - 8);
            *(s32 *)((char *)&q[i] + 0x78) = 0;
            D_80115168[i].f0 = 0;
        }
        c = &D_80115112;
        *c += 1;
    }
    (void)sp10;
}
