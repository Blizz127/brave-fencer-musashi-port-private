/* sc03_0098: func_8017C5F0 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8001D074(s32 a0, s32 a1);
extern void func_8001D074(s32, s32);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);
extern void func_80049A1C(void *a0, void *a1);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern void func_800D20C0();
extern void func_8012A568(void (*a0)(void));
extern void func_80049A1C(void *a0, void *a1);
extern void func_8001D074(s32 a0, s32 a1);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);
extern void func_8001D074(s32 a0, s32 a1);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern void func_80049A1C(void *a0, void *a1);

void func_8017C5F0(s32 a0) {
    extern u8 D_801C5538;
    extern u8 D_801C5539;
    extern u8 D_801C553A;
    extern u8 D_801C553C;
    extern u8 D_801C553D;
    extern u8 D_801C553E;
    extern s32 D_801C573C[];
    s32 v0;
    u8 *p;
    s16 sp[8];
    v0 = ((s32 (*)(s32, s32))func_8001D074)(0x7E, 0x100);
    if (v0 == 0) {
        return;
    }
    p = &D_801C5538;
    *(s32 *)(a0 + 0xD0) = v0;
    func_8001CD50(v0, (s32)p);
    D_801C5539 = 0xFF;
    D_801C553A = 0xFF;
    *p = 0xFF;
    D_801C553E = 8;
    D_801C553C = 8;
    D_801C553D = 0x18;
    func_800233CC(p, 0x100);
    sp[0] = *(u16 *)(a0 + 0x6);
    sp[1] = *(u16 *)(a0 + 0xA) - 0x38;
    sp[2] = *(u16 *)(a0 + 0xE);
    func_800D20C0(&sp[0], &sp[4], 5);
    D_801C573C[0] = sp[0];
    D_801C573C[1] = sp[1];
    D_801C573C[2] = sp[2];
    func_800D23D0(&sp[4]);
    func_80049A1C(&sp[4], &D_801C573C[-5]);
    *(s32 *)(v0 + 0x34) = (s32)&D_801C573C[-5];
    *(s16 *)(v0 + 0x1A) = 0;
    *(s16 *)(v0 + 0x18) = 0;
    *(s32 *)(v0 + 0x4) |= 0x50000000;
    *(u16 *)(a0 + 0x2) += 1;
}
