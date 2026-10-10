/* sc03_0098: func_8017F1A0 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80047948(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_80047948(s32 a0);
extern s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern u16 D_80126B96;
extern u8 D_80199C18[];
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012B414(int a0);

void func_8017F1A0(s32 a0) {
    s32 s2;
    s32 i;
    s32 sum;
    s32 v0;
    u8 *base;
    u8 *p0;
    u8 *p1;
    s32 want;
    u16 setval;
    s2 = a0;
    sum = *(u16 *)(s2 + 0xFE) + *(u16 *)(s2 + 0xFC);
    *(u16 *)(s2 + 0xFE) = sum & 0xFFF;
    if ((sum & 0x7FF) < 0x61) {
        func_8002D4C8(0x6A5, 0);
    }
    v0 = func_80047948(*(s16 *)(s2 + 0xFE));
    *(s16 *)(*(s32 *)(s2 + 0x20) + 0x14) = v0 >> 3;
    if (*(s16 *)(s2 + 0x70) != 0) {
        func_8012B414(s2);
    }
    i = 0;
    want = 1;
    setval = 0x4004;
    base = D_80199C18;
    p1 = base + 8;
    p0 = base;
    for (; i < 5; p1 += 8, i++, p0 += 8) {
        if (func_8012D5E4(s2, (s32)p0, (s32)p1, 0x30) == want) {
            D_80126B96 = setval;
        }
    }
}
