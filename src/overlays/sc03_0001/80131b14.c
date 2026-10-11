/* sc03_0001: func_80131B14 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
void func_8012B23C(s32 a0);
void func_8012B2CC(s32 a0);
extern void func_8016AA50(int, int);
extern void func_8016B428(int);
extern void func_80019064(void *);
extern void func_8012B23C(s32 a0);
extern void func_8012B23C(s32 a0);

void func_80131B14() {
    extern void func_8002A520(void *);
    extern void func_8002A790(void *);
    extern u8 D_8018D9CC;
    u8 *a0v;
    u8 *p = a0v;
    s32 e = *(u8 *)(p + 0x5E);
    if (*(s16 *)(p + 0x60) != 0) {
        if (e == 0x1D) {
            *(s16 *)(p + 0x82) = 0;
            *(s16 *)(p + 0x7C) = *(u16 *)(p + 0x06);
            *(s16 *)(p + 0x7E) = *(u16 *)(p + 0x0A);
            *(s16 *)(p + 0x80) = *(u16 *)(p + 0x0E);
        }
        {
            s32 dec;
            s32 q = *(s32 *)(p + 0x78);
            if (q != 0) {
                dec = ((s32)*(s16 *)(p + 0x60) * (s32)*(s16 *)(q + 0x30)) >> 12;
                if (dec <= 0) dec = 1;
            }
            *(u16 *)(p + 0x76) = *(u16 *)(p + 0x76) - dec;
        }
        ((void (*)(void *))func_8016AA50)(p);
        if (*(u16 *)(p + 0x82) & 1) {
            ((void (*)(void *))func_8016B428)(p);
            ((void(*)(void *))func_80019064)(&D_8018D9CC);
        }
    }
    *(u16 *)(p + 0x5C) = *(u16 *)(p + 0x5C) & 0xFFFE;
    if (e != 0x1D) {
        if (*(u8 *)(p + 0xC8)) func_8002A520(p);
        if (*(u8 *)(p + 0xC9)) func_8002A790(p);
    }
    if (*(s16 *)(p + 0x76) <= 0) *(s16 *)(p + 0x5C) = 0;
    {
        s32 r = *(s32 *)(p + 0x20);
        *(s16 *)(r + 0x12) = (*(u16 *)(p + 0x62) + 0x800) & 0xFFF;
        {
            s32 r2 = *(s32 *)(p + 0x20);
            *(s16 *)(r2 + 0x14) = 0;
            *(s16 *)(r2 + 0x10) = 0;
        }
    }
    ((void (*)(void *))func_8012B2CC)(p);
    ((void (*)(void *))func_8012B23C)(p);
}
