/* sc03_0098: func_8012B260 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
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
extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012B260(u8 *a0) {
    u8 *a1;
    s32 a, b, c;
    u16 t;
    a1 = *(u8 **)(a0 + 0x20);
    a = (u16)*(u16 *)(a0 + 6) + (u16)*(u16 *)(a0 + 0x50);
    *(u16 *)(a1 + 8) = a;
    *(s32 *)(a1 + 0x48) = (s16)a;
    b = (u16)*(u16 *)(a0 + 0xA) + (u16)*(u16 *)(a0 + 0x52);
    *(u16 *)(a1 + 0xA) = b;
    *(s32 *)(a1 + 0x4C) = (s16)b;
    c = (u16)*(u16 *)(a0 + 0xE);
    t = *(u16 *)(a1 + 0x2C) | 1;
    c = c + (u16)*(u16 *)(a0 + 0x54);
    *(u16 *)(a1 + 0xC) = c;
    *(u16 *)(a1 + 0x2C) = t;
    *(s32 *)(a1 + 0x50) = (s16)c;
}
