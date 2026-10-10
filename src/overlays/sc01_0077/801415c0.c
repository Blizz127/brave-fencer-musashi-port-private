/* sc01_0077: func_801415C0 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { u32 *ot; u32 pad[4]; } Env_1412A8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_1412A8;
typedef struct { u32 tag; u32 w1; u32 w2; u32 w3; } Prim_1412A8;
extern u16 D_80115116;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern s32 func_800291B4(s32 arg);
extern short D_800B9A02;
extern s32 func_800291B4(s32 arg);
extern short D_800B9A02;
extern short D_800B9A02;
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern s32 func_800291B4(s32 arg);
extern void func_800291A0(s32, s32);
extern s32 func_800291DC(s32);
extern void func_800291C8(s32, s32);

void func_801415C0(s32 param_1, s32 param_2) {
    register s32 a __asm__("$16");
    register s32 b __asm__("$17");
    s32 c;
    s32 d;
    s32 e;
    a = param_2;
    b = (s16)param_1;
    d = b + 0x2F;
    e = func_800291B4(d) & 0xFF;
    a = (s16)a;
    c = a + 0x2F;
    func_800291A0(d, func_800291B4(c) & 0xFF);
    func_800291A0(c, e);
    b = b * 2 + 0x14;
    e = func_800291DC(b);
    a = a * 2 + 0x14;
    func_800291C8(b, (s16)func_800291DC(a));
    func_800291C8(a, (s16)e);
}
