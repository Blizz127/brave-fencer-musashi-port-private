/* SC02.CD member35: func_8016C83C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern void func_800D22E4(s32 a0);
extern s32 func_80047E98(void *a0, void *a1);
extern s32 func_80047E98(void *a0, void *a1);
extern void func_800D22E4(s32 a0);
extern short func_8016CF04();
short func_8016CF04(s32 param_1, s32 param_2);

void func_8016C83C(s32 a0) {
    s16 d[20];
    s32 a1 = *(s32 *)(a0 + 0x34);
    s32 v0 = *(s32 *)(a0 + 0x1C) - 1;
    s32 dist;
    *(s32 *)(a0 + 0x1C) = v0;
    if (v0 == 0) {
        *(s16 *)(a0 + 2) = 4;
        func_8016CF04(a0, 2);
        return;
    }
    d[0] = *(u16 *)(a1 + 6) - *(u16 *)(a0 + 6);
    d[1] = *(u16 *)(a1 + 0xA) - *(u16 *)(a0 + 0xA);
    d[2] = *(u16 *)(a1 + 0xE) - *(u16 *)(a0 + 0xE);
    dist = func_80047E98(d, d);
    if (dist < 0x790) {
        *(s16 *)(a0 + 2) = 4;
        func_8016CF04(a0, 2);
        return;
    }
    *(s32 *)(a0 + 0x10) = *(s32 *)(a0 + 0x10) + d[0] * 0x40;
    *(s32 *)(a0 + 0x14) = *(s32 *)(a0 + 0x14) + d[1] * 0x40;
    *(s32 *)(a0 + 0x18) = *(s32 *)(a0 + 0x18) + d[2] * 0x40;
    d[0] = *(u16 *)(a0 + 0x12);
    d[1] = *(u16 *)(a0 + 0x16);
    d[2] = *(u16 *)(a0 + 0x1A);
    dist = func_80047E98(d, d);
    {
        s32 lim = 0x1000;
        if (lim < dist) {
            *(s32 *)(a0 + 0x10) = (s32)d[0] << 10;
            *(s32 *)(a0 + 0x14) = (s32)d[1] << 10;
            *(s32 *)(a0 + 0x18) = (s32)d[2] << 10;
        }
    }
    func_800D22E4(a0);
    func_8016CF04(a0, 1);
}
