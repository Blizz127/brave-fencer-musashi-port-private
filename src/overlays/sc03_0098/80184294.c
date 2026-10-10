/* sc03_0098: func_80184294 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
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
    } Data_t_80184294;
extern s32 *D_80126B78;
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern u8 D_801152A8[];
extern u8 D_801152A8[];
extern s32 func_80133784(s32 a0, void *src, s32 dst);
extern void func_8012A568(void (*a0)(void));
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 *D_80126B78;
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern void func_8012CBA4(s32 a0);
extern void func_80181CFC(s32 a0, s32 a1);
extern void func_8012CBA4(s32 a0);
extern s32 *D_80126B78;
extern u8 D_8019E1F8[];
extern u8 D_801152A8[];
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
s32 aF80181CFC(s32 arg0, s32 arg1) __asm__("func_80181CFC");
s32 aF80181CFC(s32 arg0, s32 arg1) __asm__("func_80181CFC");
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

void func_80184294(s32 *s0) {
    extern u8 D_801A1590[];
    Data_t_80184294 buf_src, buf_dst;
    s32 v0;
    func_8012B1B4((s32)s0, (s32)D_801A1590);
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
