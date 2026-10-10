/* sc01_0077: func_8012AF0C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
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
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_800132BC(s32 a0, s32 a1);

s32 func_8012AF0C(s32 a0, s32 a1) {
    s32 s1 = a0;
    s32 s2 = a1;
    s16 spA[4];
    struct M8012AF0C spB;
    struct M8012AF0C spC;
    s16 spD[4];
    spA[0] = *(u16 *)(s1 + 0x3A);
    spA[1] = *(u16 *)(s1 + 0x3E);
    spA[2] = *(u16 *)(s1 + 0x42);
    spB.a = *(u16 *)(s1 + 0x6);
    spB.b = *(u16 *)(s1 + 0xA);
    spB.c = *(u16 *)(s1 + 0xE);
    spC = spB;
    if (func_80135888(*(s32 *)(s2 + 0x20), *(s32 *)(s2 + 0x58), (s32)spA, (s32)&spC) != 0) {
        s32 r0, r1;
        spD[0] = *(u16 *)(s2 + 0x6);
        spD[1] = *(u16 *)(s2 + 0xA);
        spD[2] = *(u16 *)(s2 + 0xE);
        r0 = func_800132BC((s32)spD, (s32)spA);
        r1 = func_800132BC((s32)spD, (s32)&spB);
        if (r0 < r1) return 0;
        *(s32 *)(s1 + 0x4) = *(s32 *)(s1 + 0x38);
        *(s32 *)(s1 + 0x8) = *(s32 *)(s1 + 0x3C);
        *(s32 *)(s1 + 0xC) = *(s32 *)(s1 + 0x40);
        return 1;
    }
    return 0;
}
