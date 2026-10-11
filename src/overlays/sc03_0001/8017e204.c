/* sc03_0001: func_8017E204 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);

void func_8017E204(void *arg0) {
    extern void (*D_80191074[])(void);
    s32 base = (s32)arg0;
    s32 r1;
    s32 r2;
    s32 h;
    s32 t;
    *(s32 *)(base + 0x0) = (s32)D_80191074;
    *(s32 *)(base + 0x4) = 0;
    *(s32 *)(base + 0x8) = 0;
    *(s16 *)(base + 0xC) = 0;
    *(s16 *)(base + 0xE) = 0;
    *(s16 *)(base + 0x10) = 0;
    r1 = func_8005C49C();
    r2 = func_8005C49C();
    h = *(s16 *)(base + 0x16) * 80;
    t = (r1 & 7) * 5 - 0xA0;
    *(s16 *)(base + 0x12) = h + t + (r2 & 0xF);
    *(s16 *)(base + 0x14) = -((func_8005C49C() & 0xF) * 2);
    *(s32 *)(base + 0x1C) = 0;
    *(s32 *)(base + 0x20) = 0;
    *(s32 *)(base + 0x18) = (*(u16 *)(base + 0x16) & 2) * 30;
}
