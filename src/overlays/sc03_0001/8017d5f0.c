/* sc03_0001: func_8017D5F0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct M8012AF0C;
struct M8012AF0C { short a, b, c, d; };
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012A568(void (*a0)(void));
extern void func_8012ADE4(u8 *a0);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);

s32 func_8017D5F0(s32 a0, s32 a1) {
    s32 s0 = a0;
    s32 s1 = a1;
    s16 spA[4];
    struct M8012AF0C spB;
    struct M8012AF0C spC;
    spA[0] = *(u16 *)(s0 + 0x3A);
    spA[1] = *(u16 *)(s0 + 0x3E);
    spA[2] = *(u16 *)(s0 + 0x42);
    spB.a = *(u16 *)(s0 + 0x6);
    spB.b = *(u16 *)(s0 + 0xA);
    spB.c = *(u16 *)(s0 + 0xE);
    spC = spB;
    if (func_80135888(*(s32 *)(s1 + 0x20), *(s32 *)(s1 + 0x58), (s32)spA, (s32)&spC) != 0) {
        s32 v1;
        s16 a1v;
        s16 a0v;
        s16 a2v;
        func_8012ADE4((u8 *)s0);
        if (*(s32 *)(s1 + 0x58) == 0) {
            return 1;
        }
        v1 = *(s32 *)(*(s32 *)(s1 + 0x78) + 0x8);
        a1v = *(s16 *)(s1 + 0x6);
        a0v = *(s16 *)(s0 + 0x6);
        if (a0v >= a1v + *(s16 *)(v1 + 0x6)) {
            return 1;
        }
        if (a1v + *(s16 *)(v1 + 0x4) >= a0v) {
            return 1;
        }
        a2v = *(s16 *)(s0 + 0xE);
        a1v = *(s16 *)(s1 + 0xE);
        if (a2v >= a1v + *(s16 *)(v1 + 0xE)) {
            return 1;
        }
        if (a1v + *(s16 *)(v1 + 0xC) < a2v) {
            *(s16 *)(s0 + 0xE) = a2v + 0x40;
        }
        return 1;
    }
    return 0;
}
