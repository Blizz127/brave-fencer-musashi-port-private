/* sc02_0037: func_801298F4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
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
extern unsigned short D_800B99F0;

void func_801298F4(void *arg0) {
    register u8 *a __asm__("$7");
    s32 base4C;
    register u32 b __asm__("$4");
    register u16 f38 __asm__("$6");
    register u16 f3E __asm__("$5");
    u32 sh;
    u8 *p;
    a = (u8 *) arg0;
    base4C = *(s32 *)(a + 0x4C);
    p = *(u8 **)(a + 0x50);
    f38 = *(u16 *)(a + 0x38);
    f3E = *(u16 *)(a + 0x3E);
    base4C += 8;
    p += 4;
    b = *p++; *(s16 *)(a + 0x2) = (u16) b;
    b = *p++; *(s16 *)(a + 0x4) = (u16) b;
    b = *p++; *(u8 *)(a + 0x0) = b;
    b = *p++; *(s32 *)(a + 0x8) = base4C;
    *(s32 *)(a + 0xC) = (s32) p;
    *(u8 *)(a + 0x1) = b;
    sh = ((u32)(u8) *(u8 *)(base4C + 0x6) >> 7) << 0x18;
    base4C = *(u16 *)(a + 0x3A);
    b = *(u16 *)(a + 0x3C);
    *(s16 *)(a + 0x14) = f38;
    *(s16 *)(a + 0x1A) = f3E;
    *(s16 *)(a + 0x16) = base4C;
    *(s16 *)(a + 0x18) = b;
    *(s32 *)(a + 0x10) = sh | 0x08000000;
    if (D_800B99F0 == 0) {
        *(s16 *)(a + 0x1E) = 0;
        *(s16 *)(a + 0x1C) = 0;
    }
    *(u8 *)(a + 0x22) = 0x80;
    *(u8 *)(a + 0x21) = 0x80;
    *(u8 *)(a + 0x20) = 0x80;
    *(s16 *)(a + 0x28) = 0xA0;
    *(s16 *)(a + 0x2A) = 0x78;
    *(s32 *)(a + 0x24) = (s32) a;
    *(s16 *)(a + 0x2E) = 0x1000;
    *(s16 *)(a + 0x2C) = 0x1000;
    *(s32 *)(a + 0x30) = 0;
}
