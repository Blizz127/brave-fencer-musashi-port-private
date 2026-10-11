/* sc03_0001: func_80187420 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern u8 D_80078EB1;
extern u8 D_80078E78[];
extern void func_8012F2E8(s32 a0, s32 a1, s32 a2);
extern s32 func_8012CB64(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
s32 aF801848DC(void *a0) __asm__("func_801848DC");
extern s32 func_801875C4(s32 arg0);
s32 func_801875C4(s32 arg0);

s32 func_80187420(s32 a0) {
    extern u8 D_80078E78[];
    extern u8 D_80078EB1;
    extern u16 D_80078EAC;
    extern s32 D_801EF2D8;
    extern s16 D_801C0A9C[];
    extern s16 D_801C0AD0[];
    extern s32 D_801C099C[][8];
    u8 *p;
    s32 s0;
    s32 t;
    s32 q;
    s32 r;
    s32 b;
    s32 c;
    s32 idx;
    p = D_80078E78;
    s0 = D_801C0A9C[*(s16 *)(*(s32 *)(a0 + 0xD0) + 0x10)];
    if (s0 == -1) {
        D_801EF2D8 = 0;
        return 0;
    }
    t = func_801875C4(a0);
    q = t / 24;
    r = t % 24;
    b = D_80078EB1;
    c = D_80078EAC;
    if (t == 0) {
        idx = D_801C0AD0[b] - 1;
    } else if (c - q >= 5) {
        idx = 7;
    } else if (c == q && b - r >= 2) {
        idx = 6;
    } else {
        idx = p[0x39];
        idx = D_801C0AD0[idx] - 1;
    }
    ((struct { s32 w; } *)&D_801EF2D8)->w = 1;
    return D_801C099C[idx][s0];
}
