/* sc01_0077: func_8013CF68 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;

void func_8013CF68()
{
    extern void func_80028620();
    extern u8 D_800A5E94[];
    extern s32 D_800A5E8C;
    extern s32 D_800A5E90;
    extern u8 D_800A5E95;
    extern u8 D_800A5E96;
    extern u8 D_801DA9B8;
    extern u8 D_801DA9B9;
    extern u8 D_801DA9BA;
    extern u8 D_801DA9BB;
    extern u8 D_801DA9BC;
    extern u8 D_801DA9BD;
    extern u8 D_801DA9BE;
    extern u8 D_801DA9BF;
    extern u8 D_801DA9C0;
    u8 t0, t1, t2;
    u8 *base;
    __asm__("la %0, D_800A5E94" : "=r"(base));
    *(s32 *)(base - 0xC) = 0;
    t0 = D_801DA9B8; t1 = D_801DA9B9; t2 = D_801DA9BA;
    D_800A5E8C = 0x1E;
    D_800A5E90 = 0;
    base[0] = t0; D_800A5E95 = t1; D_800A5E96 = t2;
    func_80028620(0, base - 0xC);
    *(s32 *)(base + 4) = 0; *(s32 *)(base + 8) = 7;
    t0 = D_801DA9BB; t1 = D_801DA9BC; t2 = D_801DA9BD;
    *(s32 *)(base + 0xC) = 0x14;
    base[0x10] = t0; base[0x11] = t1; base[0x12] = t2;
    func_80028620(1, base + 4);
    *(s32 *)(base + 0x14) = 0;
    t0 = D_801DA9BE; t1 = D_801DA9BF; t2 = D_801DA9C0;
    *(s32 *)(base + 0x18) = -0x12;
    *(s32 *)(base + 0x1C) = 0;
    base[0x20] = t0; base[0x21] = t1; base[0x22] = t2;
    func_80028620(2, base + 0x14);
}
