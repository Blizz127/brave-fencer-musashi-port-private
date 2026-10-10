/* sc03_0098: func_8012CE2C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
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
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
s32 func_80133784(s32 arg0, void *arg1, s32 arg2);

s32 func_8012CE2C(s32 a0) {
    short a[4];
    short b[4];
    s32 pa, pb;
    a[0] = *(u16 *)(a0 + 0x6);
    a[1] = *(u16 *)(a0 + 0xA);
    a[2] = *(u16 *)(a0 + 0xE);
    pa = (s32)a;
    pb = (s32)b;
    __builtin_memcpy((void *)pb, (void *)pa, 8);
    b[1] += 8;
    func_80133784(1, a, pb);
    return a[1] == b[1];
}
