/* SC02.CD member35: func_80182704 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
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
typedef struct {
        u16 a, b, c, d;
    } Data_t_80182704;
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern s32 func_80133784(s32 a0, void *src, s32 dst);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern void func_8012CBA4(s32 a0);
extern void func_8018016C(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);

void func_80182704(s32 *s0) {
    extern u8 D_8019C19C[];
    Data_t_80182704 buf_src, buf_dst;
    s32 v0;
    func_8012B1B4((s32)s0, (s32)D_8019C19C);
    v0 = ((s32 (*)(s32))func_8012CBA4)((s32)s0);
    if (v0 & 0x6000) {
        return;
    }
    buf_src.a = *(u16 *)((u8 *)s0 + 0x3A);
    buf_src.b = *(u16 *)((u8 *)s0 + 0x3E);
    buf_src.c = *(u16 *)((u8 *)s0 + 0x42);
    buf_dst = buf_src;
    buf_dst.b += 8;
    v0 = func_80133784(1, &buf_src, (s32)&buf_dst);
    if (v0 == 0) {
        return;
    }
    *(s32 *)((u8 *)s0 + 0x04) = *(s32 *)((u8 *)s0 + 0x38);
    *(s32 *)((u8 *)s0 + 0x08) = *(s32 *)((u8 *)s0 + 0x3C);
    *(s32 *)((u8 *)s0 + 0x0C) = *(s32 *)((u8 *)s0 + 0x40);
}
