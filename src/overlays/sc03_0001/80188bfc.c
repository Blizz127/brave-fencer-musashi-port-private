/* sc03_0001: func_80188BFC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80188830.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct Un8_8018613C {
    u8 b0, b1, b2, b3, b4, b5, b6, b7;
};
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012BD14(s32 a0);
extern s32 func_8012BD14(s32 a0);

void func_80188BFC(void *a0)
{
    extern u8 D_801202A0[];
    u8 *s0;
    s32 s1;
    u8 *s3;
    u8 *s4;
    u8 *s2;
    u8 *v0;
    u8 *v1;
    u8 *a0p;
    s2 = (u8 *)a0;
    s0 = D_801202A0;
    s1 = 0x7FFF;
    s3 = s0 + 0x6480;
    while (s0 != s3) {
        if (*(u16 *)s0 == 0x61) {
            s32 v1_val = func_8012BD14((s32)s0);
            if (v1_val < s1) {
                s1 = v1_val;
                s4 = s0;
            }
        }
        s0 += 0x10C;
    }
    s0 = s4;
    if (s1 == 0x7FFF) {
        *(s16 *)((s32)s2 + 0x5C) = 0;
    } else {
        *(s32 *)(s2 + 0x4) = *(s32 *)(s0 + 0x4);
        *(s32 *)(s2 + 0x8) = *(s32 *)(s0 + 0x8);
        *(s32 *)(s2 + 0xC) = *(s32 *)(s0 + 0xC);
        v1 = *(u8 **)(s2 + 0x20);
        v0 = *(u8 **)(s0 + 0x20);
        *(struct Un8_8018613C *)(v1 + 0x10) = *(struct Un8_8018613C *)(v0 + 0x10);
        a0p = *(u8 **)(s2 + 0x20);
        *(u16 *)(a0p + 0x12) = *(u16 *)(a0p + 0x12) - *(u16 *)(s0 + 0xFE);
        *(s16 *)((s32)s2 + 0x5C) = 0x800;
    }
}
