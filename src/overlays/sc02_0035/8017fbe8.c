/* SC02.CD member35: func_8017FBE8 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_80047948(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_80143B6C(s32 a0, s32 a1);
extern void func_8012B23C(void *a0);
extern void func_8012CBA4(s32 a0);
extern void func_8012B23C(void *a0);
extern void func_8012CBA4(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012B23C(void *a0);
extern s32 func_80047948(s32 a0);
extern void func_8012CBA4(s32 a0);
extern void func_8012CBF4(s32 a0);
extern void func_8012B23C(void *a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_80143B6C(s32 a0, s32 a1);
extern void func_80131C78(s32 a0);
extern void func_80131E00(void *a0, s32 a1);
void func_801800C0();

void func_8017FBE8(s32 a0) {
    s32 delta;
    s32 ret;
    switch (*(u16 *)(a0 + 0x34)) {
    case 0:
        delta = func_80047948((*(s32 *)(a0 + 0x1C) - 1) << 6) -
                func_80047948(*(s32 *)(a0 + 0x1C) << 6);
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x18) =
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x18) + delta;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1A) =
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1A) - (delta >> 3);
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1C) =
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1C) + delta;
        ret = ((s32(*)(s32))func_8012CBA4)(a0);
        if (ret & 0x1000) {
            func_80131E00((void *)a0, 0x12);
            break;
        }
        if ((ret & 0x2000) == 0) {
            func_8012B23C((void *)a0);
            *(u16 *)(a0 + 0x34) = 2;
            *(s32 *)(a0 + 0x1C) = 0x3C;
            break;
        }
        if (*(s32 *)(a0 + 0x1C) % 3 == 0) {
            func_80143B6C(a0, 1);
        }
        if (func_8012BEE8(a0) != 0) {
            *(u16 *)(a0 + 0x34) = 1;
        }
        break;
    case 1:
        delta = func_80047948((*(s32 *)(a0 + 0x1C) + 1) << 6) -
                func_80047948(*(s32 *)(a0 + 0x1C) << 6);
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x18) =
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x18) + delta;
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1A) =
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1A) - (delta >> 3);
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1C) =
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x1C) + delta;
        *(s32 *)(a0 + 0x1C) = *(s32 *)(a0 + 0x1C) + 1;
        if (*(s32 *)(a0 + 0x1C) >= 0x10) {
            func_80131C78(a0);
        }
        break;
    case 2:
        ret = ((s32(*)(s32))func_8012CBF4)(a0);
        if (ret & 0xFF) {
            func_801800C0(a0);
        } else if (ret & 0x2000) {
            func_80131C78(a0);
        } else if (func_8012BEE8(a0) != 0) {
            func_80131E00((void *)a0, 0xD);
        }
        break;
    }
    if (*(s32 *)(a0 + 0x14) > 0x100000) {
        *(s32 *)(a0 + 0x14) = 0x100000;
    }
}
