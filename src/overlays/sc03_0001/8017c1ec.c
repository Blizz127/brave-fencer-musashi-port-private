/* sc03_0001: func_8017C1EC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8001C810(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_8012A828(s32, s32);
extern void func_8012B260(u8 *a0);
extern u8 D_80190F74[];
extern u8 D_80190F7C[];

void func_8017C1EC(s32 a0)
{
    extern u8 D_8018D838[];
    s32 s0;
    s0 = ((s32 (*)(void))func_8012C1B8)();
    if (s0 == 0) {
        ((void (*)(s32))func_8012CAE4)(a0);
        return;
    }
    func_8001C810(s0, (s32)D_80190F74);
    func_8012A828(a0, (s32)D_8018D838);
    *(s32 *)(a0 + 0x20) = s0;
    *(s16 *)(s0 + 0x1A) = 0x3C00;
    *(s16 *)(s0 + 0x18) = 0x3C00;
    *(s16 *)(s0 + 0x10) = -0x20;
    *(s16 *)(s0 + 0x12) = -1;
    *(s32 *)(s0 + 0x4) |= 0x8040;
    *(u16 *)(s0 + 0x2C) |= 0x10;
    ((void (*)(s32))func_8012B260)(a0);
    *(s32 *)(a0 + 0x58) = (s32)D_80190F7C;
    *(u16 *)(a0 + 0x2) += 1;
}
